#ifndef FILESYSTEM_H
# define FILESYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define NO_ALL "\033[0m"
# define NO_COLOR "\e[39m"
# define BLACK "\e[30m"
# define RED "\033[31m"
# define GREEN "\e[32m"
# define BRGREEN "\033[32;1m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[95m"
# define BRCYAN "\033[96m"

typedef enum type
{
	FOLDER_NODE,
	FILE_NODE
}			NodeType;

typedef struct	fsnode
{
	char			*name;
	int				size;
	NodeType		type;
	struct fsnode	*child;//   right
	struct fsnode	*sibling;// left
}				FSNode;


FSNode	*create_file(const char *name, int size);
FSNode	*create_folder(const char *name);
void	add_child(FSNode *parent, FSNode *child);
FSNode	*get_children(const FSNode *parent);
FSNode	*get_sibling(const FSNode *node);

#endif
