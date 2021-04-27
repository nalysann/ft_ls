#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>

#include "ft_vector.h"
#include "ft_stdio.h"
#include "ft_string.h"

#include "args.h"
#include "cmp.h"
#include "error.h"
#include "options.h"
#include "parse.h"


// TODO: excluding options, more options
static int	parse_options(int argc, char *argv[], unsigned *options)
{
	int		i;
	int		j;
	char	*pos;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || ft_strcmp(argv[i], "-") == 0)
			break ;
		if (ft_strcmp(argv[i], "--") == 0)
			return (i + 1);
		j = 1;
		while (argv[i][j] != '\0')
		{
			pos = ft_strchr(OPTIONS, argv[i][j]);
			if (pos == NULL)
				illegal_option(argv[i][j]);
			*options |= (1U << (pos - OPTIONS));
			++j;
		}
		++i;
	}
	return (i);
}

void		parse(int argc, char *argv[], t_args *args, unsigned *options)
{
	static char		*dot = ".";
	int				i;
	struct stat		st;

	i = parse_options(argc, argv, options);
	if (i == argc)
		vector_push_back(&args->dirs, dot);
	while (i < argc)
	{
		if (stat(argv[i], &st) != 0)
			if (errno == ENOENT)
				vector_push_back(&args->absent, argv[i]);
			else // TODO
				ft_error(DEBUG_MSG, E_DEBUG);
		else
			if (S_ISDIR(st.st_mode))
				vector_push_back(&args->dirs, argv[i]);
			else
				vector_push_back(&args->files, argv[i]);
		++i;
	}
	if (args->absent.size != 0 || args->files.size != 0)
		*options |= OP_DIR_NAME;
	// TODO: sort is disabled by -f
	vector_sort(&args->absent, cmp_lexicographical);
	vector_sort(&args->dirs, cmp_lexicographical);
	vector_sort(&args->files, cmp_lexicographical);
}
