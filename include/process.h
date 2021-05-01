#ifndef PROCESS_H
# define PROCESS_H

#include "ft_vector.h"

void	process_absent(t_vector absent, unsigned int *options);
void	process_present(t_vector present, unsigned int *options);
//static void	process_dirs(t_vector dirs, unsigned int options, int files,
//								int absent)

//int			compare_files(void *file1_ptr, void *file2_ptr, int flags);
//void		push_file_stat(t_vector *file_stats, struct stat *st, char *filename, char *parent);
//DIR			*open_folder(char *name);
//void		process_dir_recursive(char *dir_name, unsigned int options);
//t_vector	get_sorted_dirs(t_vector dirs, int options);
//void		del_item(void *data);

#endif
