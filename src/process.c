#include "args.h"
#include "options.h"
#include "process.h"
#include "sorting.h"

#include "ft_stdio.h"
#include "ft_vector.h"
#include "ft_stdlib.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

static void		process_absent(t_vector absent, unsigned *options)
{
	size_t	i;

	i = 0;
	while (i < absent.size)
		ft_dprintf(STDERR_FILENO,"ft_ls: %s: %s\n", absent.data[i++], strerror(ENOENT));
	if (absent.size > 0)
		*options |= OP_FAIL;
}

static void		process_files(t_vector files, unsigned *options)
{
	size_t			i;
	char			*filename;
	struct stat		*st;
	t_vector		file_stats;

	file_stats = vector_on_stack();
	i = 0;
	while (i < files.size)
	{
		filename = (char *)vector_get(&files, i++);
		st = (struct stat*)ft_memalloc(sizeof(struct stat));
		stat(filename, st);
		push_file_stat(&file_stats, st, filename);
	}
	if (*options != 0)
		sort_files(file_stats, options);
	output_files(file_stats, options);
}

static void		process_dirs(t_vector dirs, unsigned *options)
{
	(void)dirs;
	(void)options;
	// TODO
}

static void		process_recursive(t_vector files,
				t_vector dirs, unsigned *options)
{
	(void)dirs;
	(void)options;
	(void)files;
	// TODO
}

void		process(t_args *args, unsigned *options)
{
	process_absent(args->absent, options);
	process_files(args->files, options);
	if (*options & OP_R_UPPER)
		process_recursive(args->files, args->dirs, options);
	else
		process_dirs(args->dirs, options);
}

//void	print_error(char *dir_name)
//{
//	write(1, "cannot open directory", 22);
//	exit(1);
//}
//
//DIR		*open_folder(char *name)
//{
//	DIR	*dir_stream;
//
//	dir_stream = opendir(name);
//	if (dir_stream == NULL)
//		print_error(name); // error code??
//	return dir_stream;
//}
//
//void	add_file_to_list(t_file *dir, long time_modified, __uint8_t namelen,
//						 char *name, int file_type)
//{
//	t_file	*new_file;
//	char	*string_name;
//
//	new_file = (t_file*)ft_memalloc(sizeof(t_file));
//	if (new_file == NULL)
//		exit_with_error(LIST_ALLOC_MSG, E_LIST_ALLOC);
//	new_file->date = time_modified;
//	new_file->parent = dir;
//	new_file->type = file_type;
//	string_name = (char*)ft_memalloc(namelen + 1);
//	ft_memcpy(string_name, name, namelen);
//	new_file->name = string_name;
//	list_push_back(dir->sub_dirs, new_file);
//}
//
//void	process_dir_recursive(t_file *dir, int flags)
//{
//	DIR						*fd;
//	static struct dirent	*filename;
//	static struct stat		st;
//
//	fd = open_folder(dir->name);
//	ft_bzero(&st, sizeof(struct stat));
//	while (1)
//	{
//		filename = readdir(fd);
//		process_file(dir, filename, flags);
//	}
//	sort_list(dir->sub_dirs, flags);
//	print_list(dir->sub_dirs, flags);
//	if (flags & FLAG_R_UPPER)
//	{
//		remove_non_dirs(dir->sub_dirs); // free some memory
//		// recursively call self on each remaining list member
//	}
//}
//
//void	process_dir(char *dir_name, int flags)
//{
//	DIR			*fd;
//	struct stat	*st;
//	struct dirent *filename;
//
//	fd = open_folder(dir_name);
//	st = (struct stat*)malloc(sizeof(struct stat));
//	while (1)
//	{
//		filename = readdir(fd);
//		if (!filename)
//			break;
//		write(1, filename->d_name, filename->d_namlen);
//		stat("includes", st);
//		write(1, "\n", 1);
//	}
//}
