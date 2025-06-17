#ifndef FILESYSTEM_H
# define FILESYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
