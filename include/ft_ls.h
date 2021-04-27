/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:25:56 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/26 22:34:13 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include <dirent.h>
# include "ft_list.h"
# include <sys/types.h>
# include <sys/stat.h>

DIR						*open_folder(char *name);

// typedef struct			s_file
// {
// 	t_list				*sub_dirs;
// 	char				*name;
// 	long				date_modified;
// 	long				date_created;
// 	long				date_access;
// 	char				*type;
// 	uid_t				user_id;
// 	gid_t				group_id;
// 	off_t				size;
// 	blkcnt_t			blocks;
// 	struct s_file		*parent;
// }						t_file;

#endif