SELECT title, rating FROM movies, ratings
WHERE ratings.movie_id = movies.id
AND movies.year = 2010
AND rating IS NOT NULL
ORDER BY rating DESC, title;
