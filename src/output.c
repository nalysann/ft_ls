/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 23:39:00 by bgilwood          #+#    #+#             */
/*   Updated: 2021/05/10 19:23:08 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "options.h"
#include "pf_utils.h"
#include "output.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

void	parse_user_and_group(t_file *file)
{
	char			*username;
	char			*groupname;
	struct passwd	*user;
	struct group	*group;
	
	user = getpwuid(file->st.st_uid);
	group = getgrgid(file->st.st_gid);
	if (user)
		username = ft_strdup(user->pw_name);
	else
	{
		username = ft_memalloc(11);
		itoa_base_unsigned(file->st.st_uid, "0123456789", username);
	}
	if (group)
		groupname = ft_strdup(group->gr_name);
	else
	{
		groupname = ft_memalloc(11);
		itoa_base_unsigned(file->st.st_gid, "0123456789", username);
	}
	file->user_name = username;
	file->group_name = groupname;
}

void	long_output_prep(t_file *file, time_t now, t_max_lengths *lens)
{
	parse_user_and_group(file);
	parse_time(file, now);
	get_file_mode(file);
	if (ft_strlen(file->group_name) > lens->group_len)
		lens->group_len = ft_strlen(file->group_name);
	if (ft_strlen(file->user_name) > lens->user_len)
		lens->user_len = ft_strlen(file->user_name);
	if (file->st.st_nlink > lens->num_links)
		lens->num_links = file->st.st_nlink;
	if (file->st.st_size > lens->size)
		lens->size = file->st.st_size;
	lens->total += file->st.st_blocks;
}

void	get_max_lengths(t_vector files, t_max_lengths *lens)
{
	size_t	i;
	t_file	*file;
	time_t	now;

	now = time(NULL);
	ft_memset(lens, 0, sizeof(t_max_lengths));
	i = 0;
	while (i < files.size)
	{
		file = vector_get(&files, i++);
		long_output_prep(file, now, lens);
	}
	lens->size_len = 1;
	while (lens->size > 10)
	{
		lens->size_len++;
		lens->size /= 10;
	}
	lens->num_links_len  = 1;
	while (lens->num_links > 10)
	{
		lens->num_links_len ++;
		lens->num_links /= 10;
	}
}

void	output_files(t_vector files, unsigned int options, int is_dir)
{
	t_file			*file;
	size_t			i;
	t_max_lengths	lens;

	i = 0;
	if (options & OP_L_LOWER)
	{
		get_max_lengths(files, &lens);
		if (files.size && is_dir)
			ft_printf("total %i\n", lens.total);
	}
	while (i < files.size)
	{
		file = vector_get(&files, i);
		if (options & OP_L_LOWER)
			long_output(file, &lens);
		else
			ft_printf("%s\t", file->name);
		i++;
	}
	if (files.size && !(options & OP_L_LOWER))
		ft_putendl("");
}
