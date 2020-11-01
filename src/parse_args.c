/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:31:45 by bgilwood          #+#    #+#             */
/*   Updated: 2020/10/28 20:03:59 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_user_input	*parse_input(int argc, char **argv)
{
	t_user_input	*res;
	char			*dir_name;
	char			**dirs;

	res = (t_user_input*)ft_memalloc(sizeof(t_user_input));
	// TODO: actually read user input

	res->num_directories = 1;
	dir_name = ft_strdup(".");
	dirs = (char**)ft_memalloc(sizeof(char*) * 2);
	dirs[0] = dir_name;
	res->directory_names = dirs;
	res->num_directories = 1;
	res->flags = 0;
	return res;
}
