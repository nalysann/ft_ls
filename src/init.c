#include "ft_vector.h"

#include "args.h"

void	init(t_args *args, unsigned int *options)
{
	args->absent = vector_on_stack();
	args->present = vector_on_stack();
	*options = 0U;
}
