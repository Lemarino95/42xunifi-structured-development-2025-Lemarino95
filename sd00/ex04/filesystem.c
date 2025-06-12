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

/* int main()
{
	FSNode *primo = create_folder("folder1");
	FSNode *secondo = create_file("file1.txt", 5);
	FSNode *terzo = create_folder("folder2");
	FSNode *quarto = create_file("file2.txt", 9);
	FSNode *quinto = create_file("file3.txt", 3);

	add_child(primo, secondo);
	add_child(primo, terzo);
	add_child(terzo, quarto);
	add_child(primo, quinto);

	printf(GREEN"Name: %s, type: %d, size: %d.\n"NO_ALL, primo->name, primo->type, primo->size);
	FSNode *current = primo;
	FSNode *child = get_children(current);
	printf(YELLOW"Name: %s, type: %d, size: %d.\n"NO_ALL, child->name, child->type, child->size);
	FSNode *current2 = primo;
	FSNode *sibling = get_sibling(current2);
	printf(BLUE"Name: %s, type: %d, size: %d.\n"NO_ALL, sibling->name, sibling->type, sibling->size);
	FSNode *current3 = get_children(terzo);
	printf(MAGENTA"Name: %s, type: %d, size: %d.\n"NO_ALL, current3->name, current3->type, current3->size);
	FSNode *current4 = get_sibling(terzo);
	printf(MAGENTA"Name: %s, type: %d, size: %d.\n"NO_ALL, current4->name, current4->type, current4->size);
} */
