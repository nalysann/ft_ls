/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_files_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:16:15 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/25 16:46:05 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "options.h"
#include "ft_ls.h"
#include "libft.h"
#include "sorting.h"

#include <stdlib.h>
#include <sys/stat.h>

void	output_files(t_vector files, unsigned int options)
{
	t_file	*file1;
	size_t	i;

	(void)options;
	i = 0;
	while (i < files.size)
	{
		file1 = vector_get(&files, i);
		ft_printf("%s\t", file1->name);
		i++;
	}
	if (files.size)
		ft_putendl("");
}

void	push_file_stat(t_vector *file_stats, struct stat *st, char *filename,
			char *parent)
{
	t_file	*file;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	if (file == NULL)
		;// error
	file->st = *st;
	file->name = filename;
	file->parent = parent;
	vector_push_back(file_stats, file);
}

DIR	*open_folder(char *name)
{
	DIR	*dir_stream;

	dir_stream = opendir(name);
	if (dir_stream == NULL)
		ft_printf("ft_ls: %s: some error\n", name); // error code??
	return (dir_stream);
}

t_vector	get_sorted_dirs(t_vector dirs, unsigned int options)
{
	struct stat	st;
	char		*dir_name;
	t_vector	augmented_dirs;
	size_t		i;

	i = 0;
	augmented_dirs = vector_on_stack();
	while (i < dirs.size)
	{
		dir_name = (char *)vector_get(&dirs, i++);
		stat(dir_name, &st);
		push_file_stat(&augmented_dirs, &st, dir_name, NULL);
	}
	sort_files(augmented_dirs, options);
	vector_free(&dirs);
	dirs = vector_on_stack();
	i = 0;
	while (i < augmented_dirs.size)
	{
		dir_name = ((t_file *)vector_get(&augmented_dirs, i++))->name;
		vector_push_back(&dirs, dir_name);
	}
	vector_free_deep(&augmented_dirs, free);
	return (dirs);
}

void	del_item(void *data)
{
	t_file	*item;

	item = (t_file*)data;
	free(item->name);
	free(item);
}