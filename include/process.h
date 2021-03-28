#ifndef PROCESS_H
# define PROCESS_H

#include "args.h"

void	process(t_args *args, unsigned *options);
void	output_files(t_vector files, unsigned *options);
int		compare_files(void *file1_ptr, void *file2_ptr, int flags);

#endif
