#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "ft_stdio.h"
#include "ft_vector.h"

#include "cmp.h"
#include "error.h"
#include "file.h"
#include "options.h"
#include "print_files.h"

//#include "sorting.h"
//#include "output.h"

//DIR	*open_folder(char *name)
//{
//	DIR	*dir_stream;
//
//	dir_stream = opendir(name);
//	if (dir_stream == NULL)
//		ft_printf("ft_ls: %s: some error\n", name); // error code??
//	return (dir_stream);
//}
//
//t_vector	get_sorted_dirs(t_vector dirs, unsigned int options)
//{
//	struct stat	st;
//	char		*dir_name;
//	t_vector	augmented_dirs;
//	size_t		i;
//
//	i = 0;
//	augmented_dirs = vector_on_stack();
//	while (i < dirs.size)
//	{
//		dir_name = (char *)vector_get(&dirs, i++);
//		stat(dir_name, &st);
//		push_file_stat(&augmented_dirs, &st, dir_name, NULL);
//	}
//	sort_files(augmented_dirs, options);
//	vector_free(&dirs);
//	dirs = vector_on_stack();
//	i = 0;
//	while (i < augmented_dirs.size)
//	{
//		dir_name = ((t_file *)vector_get(&augmented_dirs, i++))->name;
//		vector_push_back(&dirs, dir_name);
//	}
//	vector_free_deep(&augmented_dirs, free);
//	return (dirs);
//}
//
//void	del_item(void *data)
//{
//	t_file	*item;
//
//	item = (t_file*)data;
//	free(item->name);
//	free(item);
//}

void	sort_files(t_vector file_stats, unsigned *options)
{
	vector_sort(&file_stats, cmp_file_lex);
	// todo
	(void)options;
//	if (*options & OP_T_LOWER)
//		if (*options & OP_U_LOWER)
//			vector_sort(&file_stats, cmp_file_lex);
//		else
//			vector_sort(&file_stats, cmp_file_lex);
//	else
//		vector_sort(&file_stats, cmp_file_lex);
}

void	process_files(t_vector files, unsigned *options, int is_dir)
{
	t_vector	file_stats;
	size_t		i;
	t_file		*file;

	file_stats = vector_on_stack();
	i = 0;
	while (i < files.size)
	{
		file = (t_file*)malloc(sizeof(t_file));
		if (file == NULL)
			ft_error(ALLOC_MSG, E_ALLOC);
		file->name = (char *)vector_get(&files, i);
		stat(file->name, &file->st);
		vector_push_back(&file_stats, file);
		++i;
	}
	// TODO: disabled by -f
	sort_files(file_stats, options);
//	if (*options & OP_L_LOWER)
//		print_files_long(stats, options, is_dir);
//	else
	print_files(file_stats, options, is_dir);
	vector_free_deep(&file_stats, free);
}
