#ifndef ERROR_H
# define ERROR_H

# define E_ALLOC 2
# define E_DEBUG 42

# define ALLOC_MSG "Memory allocation failed"
# define DEBUG_MSG "Unexpected error"

void	illegal_option(char option);
void	usage(void);

#endif
