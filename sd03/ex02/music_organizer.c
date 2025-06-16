/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#include "music_organizer.h"

// Automated process to scan music files, categorize them, and update a
//   central music database.
struct MusicLibrary *organize_music_library(const char *directory_path)
{
	int					i = 0;
	const char			**file_name = NULL;
	struct MusicLibrary	*library;
	struct	MusicFile	*song;

	file_name = scan_directory(directory_path);
	if (!file_name)
		return (NULL);

	library = create_music_library();
	if (!library)
	{
		free_files_list(file_name);
		return (NULL);
	}

	while (file_name[i])
	{
		song = process_music_file(directory_path, file_name[i]);
		update_music_library(library, song);
		i++;
	}

	free_files_list(file_name);
	return (library);
}


