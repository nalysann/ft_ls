/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:43:22 by bgilwood          #+#    #+#             */
/*   Updated: 2020/11/01 22:09:20 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "ft_ls.h"
#include "libft.h"

void	print_error(char *dir_name)
{
	write(1, "cannot open directory", 22);
	exit(1);
}

DIR		*open_folder(char *name)
{
	DIR	*dir_stream;

	dir_stream = opendir(name);
	if (dir_stream == NULL)
		print_error(name); // error code??
	return dir_stream;
}

void	add_file_to_list(t_file *dir, long time_modified, __uint8_t namelen,
							char *name)
{
	
}

void	process_file(t_file *dir, struct dirent *file, int flags)
{
	struct stat		st;
	
	if (!(flags & FLAG_A_LOWER))
		;// check name for "." or ".." and exit if it is
	if (flags & FLAG_T_LOWER)
		stat(dir->name, &st);
	add_file_to_list(dir, st.st_mtimespec.tv_nsec, file->d_namlen,
		file->d_name);
}

void	process_dir_recursive(t_file *dir, int flags)
{
	DIR						*fd;
	static struct dirent	*filename;
	static struct stat		st;
	
	fd = open_folder(dir->name);
	ft_bzero(&st, sizeof(struct stat));
	while (1)
	{
		filename = readdir(fd);
		process_file(dir, filename, flags);
	}
	sort_list(dir->sub_dirs, flags);
	print_list(dir->sub_dirs, flags);
	if (flags & FLAG_R_UPPER)
	{
		remove_non_dirs(dir->sub_dirs); // free some memory
		// recursively call self on each remaining list member
	}
}

void	process_dir(char *dir_name, int flags)
{
	DIR			*fd;
	struct stat	*st;
	struct dirent *filename;

	fd = open_folder(dir_name);
	st = (struct stat*)malloc(sizeof(struct stat));
	while (1)
	{
		filename = readdir(fd);
		if (!filename)
			break;
		write(1, filename->d_name, filename->d_namlen);
		stat("includes", st);
		write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	DIR				*fd;
	struct stat		*st;
	t_user_input	*args;
	int				i;

	args = parse_input(argc, argv);
	i = 0;
	while (i < args->num_directories)
	{
		process_dir(args->directory_names[i], args->flags);
		i++;
	}
}
