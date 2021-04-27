/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:29:32 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/26 22:39:29 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

void	parse_time(t_file *file, time_t now)
{
	(void)file;
	(void) now;
	// todo: fill month and day, fill time or year (that depends on diff between now and file time)
}

void    long_output(t_file *file, time_t now)
{
	char	*username;
	char	*groupname;

	username = ft_strdup(getpwuid(file->st.st_uid)->pw_name);
	groupname = ft_strdup(getgrgid(file->st.st_gid)->gr_name);
	file->user_name = username; // think how to detect not known users and what to do with them
	file->group_name = groupname;
	parse_time(file, now);
	ft_printf("%s\t%s\t%u\t%s\n", username, groupname, file->st.st_size, file->name);
}

void	output_files(t_vector files, unsigned int options)
{
	t_file	*file1;
	size_t	i;
	time_t	now;

	i = 0;
	if (options & OP_L_LOWER)
	{
		// print number of blocks in directory, only if it is a directory
	}
	now = time(NULL);
	while (i < files.size)
	{
		file1 = vector_get(&files, i);
		if (options & OP_L_LOWER)
			long_output(file1, now);
		else
			ft_printf("%s\t", file1->name);
		i++;
	}
	if (files.size)
		ft_putendl("");
}
