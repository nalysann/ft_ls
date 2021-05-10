/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_output_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:21:15 by bgilwood          #+#    #+#             */
/*   Updated: 2021/05/10 19:22:22 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "output.h"
#include "libft.h"
#include "stdlib.h"

static void print_links_user(t_file *file, t_max_lengths *lens)
{
	char	*s1;
	char	*s2;
	char	*s3;
	
    s1 = ft_itoa((int) lens->num_links_len + 1);
	s2 = ft_strjoin("%", s1);
	free(s1);
	s1 = ft_strjoin(s2, "hu");
	free(s2);
	s2 = ft_strjoin(s1, "%");
	free(s1);
	s1 = ft_itoa((int) lens->user_len + 1);
	s3 = ft_strjoin(s2, s1);
	free(s1);
	free(s2);
	s1 = ft_strjoin(s3, "s");
	free(s3);
    ft_printf(s1, file->st.st_nlink, file->user_name);
    free(s1);
}

static void print_group_size(t_file *file, t_max_lengths *lens)
{
    char	*s1;
	char	*s2;
	char	*s3;

	s2 = ft_itoa((int) lens->group_len + 2);
	s1 = ft_strjoin("%", s2);
	free(s2);
	s2 = ft_strjoin(s1, "s");
	free(s1);
	s1 = ft_itoa((int) lens->size_len +2);
	s3 = ft_strjoin(s2, "%");
	free(s2);
	s2 = ft_strjoin(s3, s1);
	free(s1);
	free(s3);
	s1 = ft_strjoin(s2, "i");
	free(s2);
    ft_printf(s1, file->group_name, file->st.st_size);
    free(s1);
}

void	long_output(t_file *file, t_max_lengths *lens)
{
	ft_printf("%-11s", file->mode);
	print_links_user(file, lens);
    print_group_size(file, lens);
	ft_printf(" %s %s %s\n", file->month_and_day,
		file->time_or_year, file->name);
		(void)lens;
}