SELECT title FROM movies, people, stars, ratings
WHERE stars.movie_id = movies.id
AND stars.person_id = people.id
AND ratings.movie_id = movies.id
AND name = 'Chadwick Boseman' ORDER BY rating DESC LIMIT 5;
