#include "args.h"
#include "options.h"
#include "process.h"
#include "sorting.h"
#include "output.h"

#include "ft_stdio.h"
#include "ft_vector.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>



//void	process_dir(char *dir_name, unsigned int options)
//{
//	DIR				*fd;
//	struct stat		st;
//	struct dirent	*file;
//	t_vector		file_stats;
//
//	fd = open_folder(dir_name);
//	if (!fd)
//		return ;
//	file_stats = vector_on_stack();
//	while (1)
//	{
//		file = readdir(fd);
//		if (!file)
//			break ;
//		if (!(options & OP_A_LOWER) && (!ft_strncmp(file->d_name, ".", 1)))
//			continue ;
//		stat(file->d_name, &st);
//		push_file_stat(&file_stats, &st, file->d_name, NULL);
//	}
//	sort_files(file_stats, options);
//	output_files(file_stats, options);
//	vector_free_deep(&file_stats, free);
//}
//
//static void	process_dirs(t_vector dirs, unsigned int options, int files,
//								int absent)
//{
//	size_t		i;
//	char		*dir_name;
//
//	if (options & (OP_R_LOWER | OP_T_LOWER))
//	{
//		dirs = get_sorted_dirs(dirs, options);
//	}
//	i = 0;
//	while (i < dirs.size)
//	{
//		dir_name = vector_get(&dirs, i);
//		if ((dirs.size > 1 && i > 0) || files)
//			ft_printf("\n%s:\n", dir_name);
//		else if (absent || dirs.size > 1)
//			ft_printf("%s:\n", dir_name);
//		if (options & OP_R_UPPER)
//			process_dir_recursive(dir_name, options);
//		else
//			process_dir(dir_name, options);
//		i++;
//	}
//}
