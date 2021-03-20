/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:43:22 by bgilwood          #+#    #+#             */
/*   Updated: 2021/01/14 16:23:18 by nalysann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	process(&args, &options);

	if (options & OP_FAIL)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
