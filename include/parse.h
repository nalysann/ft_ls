#ifndef PARSE_H
# define PARSE_H

#include "ft_vector.h"

# include "args.h"

# define PATH_MAX 4096

void	parse(int argc, char *argv[], t_args *args, unsigned int *options);
void	add_item(t_vector *items, const char *name, const char *parent);

#endif
