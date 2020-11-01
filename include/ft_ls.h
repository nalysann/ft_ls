/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:25:56 by bgilwood          #+#    #+#             */
/*   Updated: 2020/10/30 18:19:21 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include <dirent.h>

# define FLAG_A_LOWER 1
# define FLAG_L_LOWER 2
# define FLAG_R_LOWER 4
# define FLAG_R_UPPER 8
# define FLAG_T_LOWER 16

DIR						*open_folder(char *name);
t_user_input			*parse_input(int argc, char **argv);

typedef struct			s_user_input
{
	int					flags;
	int					num_directories;
	char				**directory_names;
}						t_user_input;

typedef struct			s_file
{
	t_file_list			*sub_dirs;
	char				*name;
	long				date;
	char				*type;
	struct s_file		*parent;
}						t_file;

typedef struct			s_file_list
{
	t_file				*content;
	struct s_file_list	*next;
}						t_file_list;

#endif