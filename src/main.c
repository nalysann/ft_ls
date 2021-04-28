#include "args.h"
#include "init.h"
#include "options.h"
#include "parse.h"
#include "process.h"

#include <stdlib.h>

int		main(int argc, char *argv[])
{
	t_args		args;
	unsigned	options;

	init(&args, &options);
	parse(argc, argv, &args, &options);
	process_absent(args.absent, &options);
	process_files(args.files, &options, 0);
//	process_dirs(args->dirs, *options, args->files.size, args->absent.size);

	if (options & OP_FAIL)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
