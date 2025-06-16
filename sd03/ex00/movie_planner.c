/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
	struct	Preferences	*prefs;
	struct	MovieList	*movie_list;
	struct	Plan		*plan;

	prefs = get_user_preferences();
	if (!prefs)
		return (NULL);

	movie_list = find_movies(prefs);
	if (!movie_list)
	{
		free(prefs);
		return (NULL);
	}

	plan = build_plan(movie_list);

	free(prefs);
	free(movie_list);
	return (plan);
}
