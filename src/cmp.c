#include "ft_string.h"

int		cmp_lexicographical(const void *a, const void *b)
{
	return ft_strcmp(*(const char **)a, *(const char **)b);
}
