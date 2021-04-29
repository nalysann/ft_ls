/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dir_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:42:33 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/12 20:37:59 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "options.h"
#include "process.h"
#include "ft_ls.h"
#include "libft.h"
#include "sorting.h"
#include "output.h"

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

static void	process_dirs_recursive(t_vector files, unsigned int options)
{
	size_t		i;
	t_file		*file;
	char		*dir_name;

	i = 0;
	while (i < files.size)
	{
		file = vector_get(&files, i++);
		if (!S_ISDIR(file->st.st_mode))
			continue ;
		dir_name = get_full_file_name(file->parent, file->name);
		ft_printf("\n%s:\n", dir_name);
		process_dir_recursive(dir_name, options);
		free(dir_name);
	}
}

void	process_dir_recursive(char *dir_name, unsigned int options)
{
	DIR				*fd;
	struct stat		st;
	struct dirent	*file;
	t_vector		file_stats;
	char			*name;

	fd = open_folder(dir_name);
	if (!fd)
		return ;
	file_stats = vector_on_stack();
	while (1)
	{
		file = readdir(fd);
		if (!file)
			break ;
		if (!(options & OP_A_LOWER) && (!ft_strncmp(file->d_name, ".", 1)))
			continue ;
		name = get_full_file_name(dir_name, file->d_name);
		stat(name, &st);
		push_file_stat(&file_stats, &st, ft_strdup(file->d_name), dir_name);
	}
	sort_files(file_stats, options);
	output_files(file_stats, options);
	process_dirs_recursive(file_stats, options);
	vector_free_deep(&file_stats, del_item);
}
