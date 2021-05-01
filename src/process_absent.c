#include <errno.h>
#include <string.h>

#include "ft_vector.h"

#include "error.h"

void	process_absent(t_vector absent, unsigned int *options)
{
	size_t	i;

	i = 0;
	while (i < absent.size)
		print_error(options, absent.data[i++], ENOENT);
}
