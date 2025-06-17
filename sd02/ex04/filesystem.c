/*--------------------------------------------------\\
||         Written by: giusnob and lemarino         ||
||                                                  ||
||            Special thanks to: pdessant           ||
\\--------------------------------------------------*/

#include "filesystem.h"

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*str;
	size_t			i;
	unsigned char	*c;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	str = malloc((nmemb * size));
	if (!str)
		return (NULL);
	i = 0;
	c = (unsigned char *)str;
	while (i < (nmemb * size))
		c[i++] = '\0';
	return (str);
}

FSNode	*create_file(const char *name, int size)
{
	FSNode *file = ft_calloc(sizeof(FSNode), 1);

	file->name = strdup(name);
	if (!file->name)
		return (NULL);
	file->size = size;
	file->type = FILE_NODE;
	file->child = NULL;
	file->sibling = NULL;

	return (file);
}

FSNode	*create_folder(const char *name)
{
	FSNode *folder = ft_calloc(sizeof(FSNode), 1);
	if (!folder)
		return (NULL);

	folder->name = strdup(name);
	if (!folder->name)
	{
		//free(folder);
		return (NULL);
	}
	folder->size = 0;
	folder->type = FOLDER_NODE;
	folder->child = NULL;
	folder->sibling = NULL;

	return (folder);
}

void	add_child(FSNode *parent, FSNode *child)
{
	FSNode	*tmp = NULL;

	if (!parent)
		return ;
	if (!parent->child)
		parent->child = child;
	else
	{
		tmp = parent;
		while (tmp->sibling)
			tmp = tmp->sibling;
		if (!tmp->child)
			tmp->child = child;
		else
			tmp->sibling = child;
	}
}

FSNode	*get_children(const FSNode *parent)
{
	return (parent->child);
}

FSNode	*get_sibling(const FSNode *node)
{
	return (node->sibling);
}
