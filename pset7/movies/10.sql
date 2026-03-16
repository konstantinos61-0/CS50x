SELECT name FROM directors, movies, people, ratings
WHERE directors.movie_id = movies.id
AND directors.person_id = people.id
AND directors.movie_id = ratings.movie_id
AND rating >= 9.0;
