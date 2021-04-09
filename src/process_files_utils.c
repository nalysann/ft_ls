/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_files_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:16:15 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/09 22:46:41 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "options.h"
#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"

void	output_files(t_vector files, unsigned *options)
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

void	push_file_stat(t_vector *file_stats, struct stat *st, char *filename)
{
	t_file	*file;

	file = (t_file*)ft_memalloc(sizeof(t_file));
	if (file == NULL)
		;// error
	file->st = *st;
	file->name = filename;
	vector_push_back(file_stats, file);
}

DIR		*open_folder(char *name)
{
	DIR	*dir_stream;

	dir_stream = opendir(name);
	if (dir_stream == NULL)
		; // error code??
	return dir_stream;
}
