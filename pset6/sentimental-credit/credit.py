from cs50 import get_string

# def function to check for card type


def card_type(string):
    starting = int(string[:2])
    if 51 <= starting <= 55:
        return "MASTERCARD"
    elif starting == 34 or starting == 37:
        return "AMEX"
    elif string[0] == "4":
        return "VISA"
    else:
        return "INVALID"


def valid_checksum(string):
    # slice the number into 2 strings starting from last and second to last char
    odd_digits = [int(char) for char in string[::-2]]
    even_digitsx2 = [int(digit) for char in string[-2::-2] for digit in str(int(char) * 2)]

    # Calculate checksum
    checksum = sum(odd_digits + even_digitsx2)
    return checksum % 10 == 0


# main function


def main():
    # get a number as a string from user
    s_number = get_string("Number: ")

    # check for numeric input
    if not s_number.isnumeric():
        print("INVALID")
        return

    # check if card number valid
    if valid_checksum(s_number) and len(s_number) in (13, 15, 16):
        print(card_type(s_number))
    else:
        print("INVALID")


# run main program
if __name__ == "__main__":
    main()
