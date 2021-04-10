/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:42:33 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/10 20:57:46 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "options.h"

#include <dirent.h>
#include <sys/stat.h>

void	process_recursive(t_vector files, t_vector dirs,
								unsigned int *options)
{
(void)files;
(void)dirs;
(void)options;
	// DIR				*fd;
	// struct stat		st;
	// struct dirent	*file;
	// t_vector		file_stats;
}

// void	process_dir(char *dir_name, unsigned int *options)
// {
// 	DIR				*fd;
// 	struct stat		st;
// 	struct dirent	*file;
// 	t_vector		file_stats;

// 	fd = open_folder(dir_name);
// 	if (!fd)
// 		return ;
// 	file_stats = vector_on_stack();
// 	while (1)
// 	{
// 		file = readdir(fd);
// 		if (!file)
// 			break ;
// 		if (!(*options & OP_A_LOWER) && (!ft_strncmp(file->d_name, ".", 1)))
// 			continue ;
// 		stat(file->d_name, &st);
// 		push_file_stat(&file_stats, &st, file->d_name);
// 	}
// 	sort_files(file_stats, options);
// 	output_files(file_stats, options);
// }