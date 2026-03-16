## Week 7 — SQL
This week covers the following core topics: flat-file databases (CSV files), Python's csv module, relational databases, SQL CRUD operations and JOIN, the sqlite SQL database, Python's support for SQL, Race Conditions and SQL injection attacks.

### Songs
In this problem, I wrote SQL queries to answer questions about a database of the 100 most-streamed songs on Spotify in 2018.  
**Distribution Code**: Availble at: https://cdn.cs50.net/2026/x/psets/7/songs.zip (accessed 16/3/2026). It includes:
- `songs.db`: the SQLite database that stores data from Spotify about songs and their artists.
- 1-8 empty `.sql` files: Should be filled with my answers to each question from 1 to 8.
- `answers.txt`: empty file for me to answer the final question

I studied the schema of the songs.db database and wrote one sql query in each `.sql` file to:
1. List the names of all songs in the database.
2. List the names of all songs in increasing order of tempo. 
3. List the names of the top 5 longest songs, in descending order of length. 
4. List the names of any songs that have danceability, energy, and valence greater than 0.75.
5. Return the average energy of all the songs. 
6. List the names of songs that are by Post Malone. 
7. Return the average energy of songs that are by Drake.
8. List the names of the songs that feature other artists.

I also answered the following questions inside `answers.txt`:
- If songs.db contains the top 100 songs of one listener from 2018, how would you characterize their audio aura (as defined by Spotify Wrapped)?
- Hypothesize about why the way you’ve calculated this aura might not be very representative of the listener. What better ways of calculating this aura would you propose?


### Movies
In this problem, I wrote SQL queries to answer questions about a SQLite database that stores data from IMDb about movies, the people who directed and starred in them, and their ratings.  
**Distribution Code**: Availble at: https://cdn.cs50.net/2026/x/psets/7/movies.zip (accessed 16/3/2026). It includes:
- `movies.db`: the SQLite database that stores the movies data from IMDb.
-  13 .sql empty files for me to fill my answers in.
I studied and understood the `movies.db` schema and wrote one sql query in each `.sql` file to:
1. List the titles of all movies released in 2008. 
2. Determine the birth year of Emma Stone. 
3. List the titles of all movies with a release date on or after 2018, in alphabetical order.
4. Determine the number of movies with an IMDb rating of 10.0. 
5. List the titles and release years of  all Harry Potter movies, in chronological order. 
6. Determine the average rating of all movies released in 2012. 
7. List all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title. 
8. List the names of all people who starred in Toy Story. 
9. List the ID and names of all people who starred in a movie released in 2004, ordered by birth year. 
10. List the names of all people who have directed a movie that received a rating of at least 9.0. 
11. List the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated. 
12. List the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred. 
13. List the names of all people who starred in a movie in which Kevin Bacon also starred. 


### Fiftyville
In this problem, TODO.  
**Distribution Code**: Availble at:  (accessed ). I read and understood it and then moved on to implement the following: TODO 
