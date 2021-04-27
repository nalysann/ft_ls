#include "ft_vector.h"

#include "args.h"

void	init(t_args *args, unsigned *options)
{
	args->absent = vector_on_stack();
	args->files = vector_on_stack();
	args->dirs = vector_on_stack();
	*options = 0U;
}
