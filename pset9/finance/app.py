import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Select from the table purchases any stocks the logged-in user has purchases
    # Along with the number of shares he has from each stock
    # And store that in a dict
    stocks = db.execute("SELECT symbol, SUM(shares) AS shares_tot FROM purchases WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0",
                        session["user_id"])
    # Store user's cash in a variable
    user_cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
    total = user_cash
    # Find and store the current price of each stock in the same dict &
    for stock in stocks:
        stock["current_price"] = lookup(stock["symbol"])["price"]
        stock["total_value"] = stock["shares_tot"] * stock["current_price"]
        total = total + stock["total_value"]
    return render_template("index.html", user_cash=user_cash, stocks=stocks, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # Check request method
    if request.method == "GET":
        # Present the buy form
        return render_template("buy.html")
    else:
        # Check if validity of symbol and shares
        shares = request.form.get("shares")
        symbol = request.form.get("symbol")
        quote = lookup(symbol)
        if not symbol:
            return apology("Provide a symbol please", 400)
        if not quote:
            return apology("Symbol didn't match a stock", 400)
        try:
            shares = int(shares)
            if shares <= 0:
                return apology("Please provide a positive integer number for shares", 400)
        except ValueError:
            return apology("Please provide a positive integer number for shares", 400)
        # Stock & shares were provided and was valid
        # Check if he can make the purchase
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        user_cash = user_cash[0]["cash"]
        buy_cash = shares * quote["price"]
        if user_cash < buy_cash:
            return apology("Not enough cash to make the purchase", 400)
        # Make the purchase
        db.execute("UPDATE users SET cash = ? WHERE id = ?",
                   user_cash - buy_cash, session["user_id"])
        db.execute("INSERT INTO purchases (user_id, shares, symbol, timestamp, buy_cash) VALUES(?, ?, ?, CURRENT_TIMESTAMP, ?)",
                   session["user_id"], shares, quote["symbol"], buy_cash)
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Get a history of every purchase or sell
    history = db.execute("SELECT * FROM purchases WHERE user_id = ?", session["user_id"])
    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        quote = lookup(request.form.get("symbol"))
        if quote:
            return render_template("quoted.html", quote=quote)
        else:
            return apology("stock not found", 400)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (sumbitted register form)
    if request.method == "POST":
        # Ensure username, password & pass_confirm were submitted
        if not request.form.get("username"):
            return apology("Username required", 400)
        elif not request.form.get("password"):
            return apology("Password required", 400)
        elif not request.form.get("confirmation"):
            return apology("Password confirmation required", 400)

        # Ensure pass & confirmation match
        if request.form.get("confirmation") != request.form.get("password"):
            return apology("Password and Password Confirmation don't match", 400)

        # Ensure username is not taken
        users = db.execute("SELECT * FROM users")
        for user in users:
            if user["username"] == request.form.get("username"):
                return apology("Username already exists", 400)

        # Register user --> Insert into finance.db
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)",
                   request.form.get("username"), generate_password_hash(request.form.get("password")))

        # Log user in
        for user in users:
            if user["username"] == request.form.get("username"):
                session["user_id"] = user["id"]

        # Redirect Logged in user to /
        return redirect("/")

    # User requested route through GET, send him the register form
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    owned_stocks = db.execute("SELECT symbol, SUM(shares) AS shares_tot FROM purchases WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0",
                              session["user_id"])
    # Get request
    if request.method == "GET":
        return render_template("sell.html", owned_stocks=owned_stocks)
    # Post request
    else:
        quote = lookup(request.form.get("symbol"))
        shares_to_sell = request.form.get("shares")
        # Check for valid symbol selection
        if not quote:
            return apology("Please select a stock symbol to sell", 400)
        # Check if for some reason he has no shares of that stock
        for stock in owned_stocks:
            if stock["symbol"] == quote["symbol"]:
                if stock["shares_tot"] == 0:
                    return apology("You don't own any shares of stock", 400)
        # Check if user submitted a positive integer number of shares to sell
        try:
            shares_to_sell = int(shares_to_sell)
            if shares_to_sell <= 0:
                return apology("Submit a positive integer amount of shares to sell", 400)
        except ValueError:
            return apology("Please provide a positive integer amount of shares to sell", 400)

        # Check if user has the correct amount of shares to sell
        for stock in owned_stocks:
            if stock["symbol"] == quote["symbol"]:
                if stock["shares_tot"] < shares_to_sell:
                    return apology("Not enough shares owned", 400)
        # Checks done. Make the sell
        sell_cash = shares_to_sell * quote["price"]
        # Insert sell row into purhcases
        db.execute("INSERT INTO purchases (user_id, shares, symbol, timestamp, buy_cash) VALUES(?, ?, ?, CURRENT_TIMESTAMP, ?)",
                   session["user_id"], -shares_to_sell, quote["symbol"], sell_cash)
        # Update cash
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash + sell_cash, session["user_id"])
        return redirect("/")


@app.route("/pchange", methods=["GET", "POST"])
@login_required
def pchange():
    # Get method, render form for password change
    if request.method == "GET":
        return render_template("pchange.html")
    else:
        # Checks
        # Check for any empty form inputs
        if not request.form.get("password") or not request.form.get("password_confirm"):
            return apology("Please provide both new password and confirmation")
        # Check if password and confirmation match
        if request.form.get("password") != request.form.get("password_confirm"):
            return apology("Password & Confirmation Password don't match")

        # Register user --> Insert into finance.db
        db.execute("UPDATE users SET hash = ? WHERE id = ?",
                   generate_password_hash(request.form.get("password")), session["user_id"])

        # Redirect Logged in user to /
        return redirect("/")
