/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_files_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:16:15 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/04 20:41:32 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "options.h"
#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"

void	output_files(t_vector files, unsigned *options)
{
	
	(void)files;
	(void)options;
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
