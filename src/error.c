#include "error.h"
#include "options.h"

#include "ft_stdio.h"

#include <stdlib.h>
#include <unistd.h>

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
