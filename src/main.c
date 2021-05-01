#include "args.h"
#include "init.h"
#include "options.h"
#include "parse.h"
#include "process.h"

#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_args			args;
	unsigned int	options;

	init(&args, &options);
	parse(argc, argv, &args, &options);
	process_absent(args.absent, &options);
	process_present(args.present, &options);

	if (options & OP_FAIL)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
