/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#include "playlist_creator.h"


struct Playlist *create_playlist(void)
{
	struct MoodSettings		*mood;
	struct FilterSettings	*filters;
	struct SongData			*song;
	struct Playlist			*playlist;

//	1. Analyze the user’s mood.
	mood = analyze_user_mood();
	if(!mood)
		return (NULL);

//	2. Build initial filter settings based on default filters.
	filters = default_filters();
	if (!filters)
	{
		free_mood_settings(mood);
		return (NULL);
	}

//	3. Refine filters according to mood variations.
	if (get_mood_variations(mood))
	{
		filters = refine_filters(filters);
		if (!filters)
		{
			free_mood_settings(mood);
			return (NULL);
		}
	}

//	4. Assemble a final playlist using mood and filter settings.
	if (filters_require_popular_song(filters) != 0)
		song = fetch_popular_song();
	else
		song = fetch_niche_song();
	if (!song)
	{
		free_mood_settings(mood);
		free_filter_settings(filters);
		return (NULL);
	}
	playlist = combine_with_mood_playlist(song, mood);
	if (!playlist)
	{
		free_mood_settings(mood);
		free_filter_settings(filters);
		free_song_data(song);
		return (NULL);
	}

	free_mood_settings(mood);
	free_filter_settings(filters);
	free_song_data(song);
	return (playlist);
}
