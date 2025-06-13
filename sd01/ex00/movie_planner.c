/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#include "movie_planner.h"

static void delete_preferences(struct Preferences *prefs)
{
	int i = 0;

	while (prefs->preferred_movie[i])
	{
		free(prefs->preferred_movie[i]);
		i++;
	}
	free(prefs);
}

static void delete_movie_list(struct MovieList *movie_list)
{
	int i = 0;

	while (movie_list->proposed_movies[i])
	{
		free(movie_list->proposed_movies[i]);
		i++;
	}
	free(movie_list);
}

struct Plan *create_movie_night_plan(void)
{
	Preferences	*prefs;
	MovieList	*movie_list;
	Plan		*plan;

	prefs = get_user_preferences();
	if (!prefs)
		return (NULL);

	movie_list = find_movies(prefs);
	if (!movie_list)
	{
		delete_preferences(prefs);
		return (NULL);
	}

	plan = build_plan(movie_list);
	if (!plan)
	{
		delete_preferences(prefs);
		delete_movie_list(movie_list);
		return (NULL);
	}

	delete_preferences(prefs);
	delete_movie_list(movie_list);
	return (plan);
}