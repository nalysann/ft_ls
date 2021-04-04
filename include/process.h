#ifndef PROCESS_H
# define PROCESS_H

#include "args.h"
#include <sys/stat.h>

void	process(t_args *args, unsigned *options);
void	output_files(t_vector files, unsigned *options);
int		compare_files(void *file1_ptr, void *file2_ptr, int flags);
void	push_file_stat(t_vector *file_stats, struct stat *st, char *filename);


#endif
