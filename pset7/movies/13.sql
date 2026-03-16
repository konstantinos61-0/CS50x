SELECT name FROM people, movies, stars
WHERE stars.person_id = people.id
AND stars.movie_id = movies.id
AND movies.id IN
(SELECT movies.id FROM people, movies, stars
WHERE stars.person_id = people.id
AND stars.movie_id = movies.id
AND name = 'Kevin Bacon' AND birth = 1958)
AND (name IS NOT 'Kevin Bacon' AND birth IS NOT 1958);
