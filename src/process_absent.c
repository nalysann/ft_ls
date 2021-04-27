#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "ft_stdio.h"
#include "ft_vector.h"

#include "options.h"

void	process_absent(t_vector absent, unsigned *options)
{
	size_t	i;

	i = 0;
	while (i < absent.size)
		ft_dprintf(STDERR_FILENO, "ft_ls: %s: %s\n", absent.data[i++], strerror(ENOENT));
	if (absent.size > 0)
		*options |= OP_FAIL;
}
