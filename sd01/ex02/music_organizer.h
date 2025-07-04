/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#ifndef MUSIC_ORGANIZER_H
# define MUSIC_ORGANIZER_H

#include <stdlib.h>

typedef struct	MusicFile
{
	char	*directory_path;
	char	*genre;
	char	*artist;
	char	*title;
}				MusicFile;

typedef struct	MusicLibrary
{
	MusicFile	**song_data;
}				MusicLibrary;

// Creates and returns a new music library. Returns NULL on fail
struct MusicLibrary	*create_music_library();

// Scans a directory for music files. Returns a NULL terminated array of filenames.
const char			**scan_directory(const char *directory_path);

// Processes a single music file. Returns a data structure representing the processed file.
struct MusicFile	*process_music_file(const char *directory_path, const char *filename);

// Updates the music library with the processed music file information.
void				update_music_library(struct MusicLibrary *library, struct MusicFile *song);


// Automated process to scan music files, categorize them, and update a
//   central music database.
struct MusicLibrary	*organize_music_library(const char *directory_path);

#endif