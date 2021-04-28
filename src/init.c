#include "ft_stdio.h"
#include "ft_vector.h"

#include "args.h"
#include "error.h"

void	init(t_args *args, unsigned *options)
{
	args->absent = vector_on_stack();
	args->files = vector_on_stack();
	args->dirs = vector_on_stack();
	*options = 0U;
	if (args->absent.capacity == VECTOR_BAD_CAPACITY || args->files.capacity == VECTOR_BAD_CAPACITY || args->dirs.capacity == VECTOR_BAD_CAPACITY)
		ft_error(ALLOC_MSG, E_ALLOC);
}
