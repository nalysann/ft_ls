#ifndef PROCESS_H
# define PROCESS_H

# include "args.h"
# include <sys/stat.h>
# include <dirent.h>
# include "ft_ls.h"

void		process(t_args *args, unsigned int *options);
void		output_files(t_vector files, unsigned int options);
int			compare_files(void *file1_ptr, void *file2_ptr, int flags);
void		push_file_stat(t_vector *file_stats, struct stat *st,
                char *filename, char *parent);
DIR			*open_folder(char *name);
void		process_dir_recursive(char *dir_name, unsigned int options);
t_vector	get_sorted_dirs(t_vector dirs, int options);

#endif
