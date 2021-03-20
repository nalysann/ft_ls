#include "error.h"
#include "options.h"

#include "ft_stdio.h"

#include <stdlib.h>

void	illegal_option(char option)
{
	ft_printf("ft_ls: illegal option -- %c\n", option);
	usage();
}

void	usage(void)
{
	ft_printf("usage: ft_ls [-%s] [file ...]\n", OPTIONS);
	exit(EXIT_FAILURE);
}
