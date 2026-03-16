SELECT title FROM people, movies, stars
WHERE stars.movie_id = movies.id
AND stars.person_id = people.id
AND name = 'Bradley Cooper'
AND movies.id IN
(SELECT movies.id FROM people, movies, stars
WHERE stars.movie_id = movies.id
AND stars.person_id = people.id
AND name = 'Jennifer Lawrence')

