#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ft_stdio.h"

#include "error.h"
#include "options.h"

void	illegal_option(char option)
{
	ft_dprintf(STDERR_FILENO, "ft_ls: illegal option -- %c\n", option);
	usage();
}

void	usage(void)
{
	ft_dprintf(STDERR_FILENO, "usage: ft_ls [-%s] [file ...]\n", OPTIONS);
	exit(EXIT_FAILURE);
}

void	print_error(unsigned int *options, const char *msg, int error_code)
{
	ft_dprintf(STDERR_FILENO, "ft_ls: %s: %s\n", msg, strerror(error_code));
	*options |= OP_FAIL;
}
