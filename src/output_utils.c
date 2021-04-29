/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:29:32 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/29 23:09:49 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "pf_utils.h"

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

static int month_order(const char *month_name)
{
	if (!ft_strncmp(month_name, "Jan", 3))
		return 0;
	if (!ft_strncmp(month_name, "Feb", 3))
		return 1;
	if (!ft_strncmp(month_name, "Mar", 3))
		return 2;
	if (!ft_strncmp(month_name, "Apr", 3))
		return 3;
	if (!ft_strncmp(month_name, "May", 3))
		return 4;
	if (!ft_strncmp(month_name, "Jun", 3))
		return 5;
	if (!ft_strncmp(month_name, "Jul", 3))
		return 6;
	if (!ft_strncmp(month_name, "Aug", 3))
		return 7;
	if (!ft_strncmp(month_name, "Sep", 3))
		return 8;
	if (!ft_strncmp(month_name, "Oct", 3))
		return 9;
	if (!ft_strncmp(month_name, "Nov", 3))
		return 10;
	if (!ft_strncmp(month_name, "Dec", 3))
		return 11;
	return 424242; // wtf scenario, hopefully large num will help debug
}

static void	parse_time(t_file *file, time_t now)
{
	char	*now_str;
	char	*file_str;
	int		now_tmp;
	int		file_tmp;

	now_str = ctime(&now);
	file_str = ctime(&(file->st.st_mtimespec.tv_sec));
	// Thu Nov 24 18:22:48 1986\n\0
	file->month_and_day = ft_strsub(file_str, 4, 6);
	now_tmp = ft_atoi(now_str + 20);
	file_tmp = ft_atoi(file_str + 20);
	if ((ft_abs(now_tmp - file_tmp) > 1)
		|| (now_tmp - file_tmp == 0 && 
			ft_abs((month_order(now_str) - month_order(file_str)) > 6))) // other cases of month diff + day time diff
		file->time_or_year = ft_strsub(file_str, 20, 4);
	else
		file->time_or_year = ft_strsub(file_str, 11, 5);
}

void	parse_user_and_group(t_file *file)
{
	char			*username;
	char			*groupname;
	struct passwd	*user;
	struct group	*group;
	
	user = getpwuid(file->st.st_uid);
	group = getgrgid(file->st.st_gid);
	// for some reason user and group are sometimes not same as in ls, investigate...
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

void    long_output(t_file *file, time_t now)
{
	parse_user_and_group(file);
	parse_time(file, now);
	get_file_mode(file);
	ft_printf("%s\t%hu\t%s\t%s\t%u\t%s\t%s\t%s\n", file->mode, file->st.st_nlink, file->user_name,
		file->group_name, file->st.st_size, file->month_and_day,
		file->time_or_year, file->name);
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
