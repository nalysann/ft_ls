/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:25:56 by bgilwood          #+#    #+#             */
/*   Updated: 2020/11/05 23:21:14 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include <dirent.h>
# include "ft_list.h"



DIR						*open_folder(char *name);
t_user_input			*parse_input(int argc, char **argv);

typedef struct			s_file
{
	t_list				*sub_dirs;
	char				*name;
	long				date;
	char				*type;
	struct s_file		*parent;
}						t_file;

#endif