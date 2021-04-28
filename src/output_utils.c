/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:29:32 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/28 23:26:12 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

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

static void	get_file_mode(t_file *file)
{
	file->mode = ft_strnew(11);
	file->mode[0] = get_file_type(file->st.st_mode);
	ft_memset(file->mode + 1, '-', 9);
	if (file->st.st_mode & S_IRUSR)
		file->mode[1] = 'r';
	if (file->st.st_mode & S_IWUSR)
		file->mode[2] = 'w';
		// todo: execution rights are more complicated

	if (file->st.st_mode & S_IRGRP)
		file->mode[4] = 'r';
	if (file->st.st_mode & S_IWGRP)
		file->mode[5] = 'w';
		//exec
	if (file->st.st_mode & S_IROTH)
		file->mode[7] = 'r';
	if (file->st.st_mode & S_IWOTH)
		file->mode[8] = 'w';
		//exec
	// last chars
}

static void	parse_time(t_file *file, time_t now)
{
	char	*now_str;
	char	*file_time;
	int		now_tmp;
	int		file_tmp;

	now_str = ctime(&now);
	file_time = ctime(&(file->st.st_mtimespec.tv_sec));
	// Thu Nov 24 18:22:48 1986\n\0
	file->month_and_day = ft_strsub(file_time, 4, 6);
	now_tmp = ft_atoi(now_str + 20);
	file_tmp = ft_atoi(file_time + 20);
	if ((now_tmp - file_tmp > 1) || (now_tmp - file_tmp < -1)) // or if month/day/hour diff is small
		file->time_or_year = ft_strsub(file_time, 20, 4);
	else
		file->time_or_year = ft_strsub(file_time, 11, 5);
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
	get_file_mode(file);
	ft_printf("%s\t%s\t%s\t%u\t%s\t%s\t%s\n", file->mode, username, groupname,
		file->st.st_size, file->month_and_day, file->time_or_year, file->name);
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
