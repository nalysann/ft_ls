/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:29:32 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/25 20:38:35 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "libft.h"

void    long_output(t_file *file)
{
    (void)file;
}

void	output_files(t_vector files, unsigned int options)
{
	t_file	*file1;
	size_t	i;

	i = 0;
	if (options & OP_L_LOWER)
	{
		// print number of blocks in directory, only if it is a directory
	}
	while (i < files.size)
	{
		file1 = vector_get(&files, i);
		if (options & OP_L_LOWER)
			long_output(file1);
		else
			ft_printf("%s\t", file1->name);
		i++;
	}
	if (files.size)
		ft_putendl("");
}
