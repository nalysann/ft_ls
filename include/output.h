/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:33:27 by bgilwood          #+#    #+#             */
/*   Updated: 2021/05/10 19:21:53 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_vector.h"

void	output_files(t_vector files, unsigned int options, int is_dir);

void	get_file_mode(t_file *file);
int		month_order(const char *month_name);
void	parse_time(t_file *file, time_t now);

typedef struct s_max_lengths
{
    nlink_t     num_links;
    off_t       size;
    size_t      num_links_len;
    size_t      user_len;
    size_t      group_len;
    size_t      size_len;
    blkcnt_t    total;
}               t_max_lengths;

void	long_output(t_file *file, t_max_lengths *lens);
