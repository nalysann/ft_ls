/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_file_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:29:32 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/30 23:57:44 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "libft.h"

static char	get_file_type(mode_t mode)
{
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISSOCK(mode))
		return ('s');
	if (S_ISFIFO(mode))
		return ('p');
	return ('-');
}

static void	fill_exec_rights(t_file *file)
{
	if (file->st.st_mode & S_IXUSR)
	{
		file->mode[3] = 'x';
		if (file->st.st_mode & S_ISUID)
			file->mode[3] = 's';
	}
	else if (file->st.st_mode & S_ISUID)
		file->mode[3] = 'S';
	if (file->st.st_mode & S_IXGRP)
	{
		file->mode[6] = 'x';
		if (file->st.st_mode & S_ISGID)
			file->mode[6] = 's';
	}
	else if (file->st.st_mode & S_ISGID)
		file->mode[6] = 'S';
	if (file->st.st_mode & S_IXOTH)
	{
		file->mode[9] = 'x';
		if (file->st.st_mode & S_ISVTX)
			file->mode[9] = 't';
	}
	else if (file->st.st_mode & S_ISVTX)
		file->mode[9] = 'T';
}

void	get_file_mode(t_file *file)
{
	file->mode = ft_strnew(11);
	file->mode[0] = get_file_type(file->st.st_mode);
	ft_memset(file->mode + 1, '-', 9);
	if (file->st.st_mode & S_IRUSR)
		file->mode[1] = 'r';
	if (file->st.st_mode & S_IWUSR)
		file->mode[2] = 'w';
	if (file->st.st_mode & S_IRGRP)
		file->mode[4] = 'r';
	if (file->st.st_mode & S_IWGRP)
		file->mode[5] = 'w';
	if (file->st.st_mode & S_IROTH)
		file->mode[7] = 'r';
	if (file->st.st_mode & S_IWOTH)
		file->mode[8] = 'w';
	fill_exec_rights(file);
	// last chars @
}
