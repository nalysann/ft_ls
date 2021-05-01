#ifndef ERROR_H
# define ERROR_H

void	illegal_option(char option);
void	usage(void);
void	print_error(unsigned int *options, const char *msg, int error_code);

#endif
