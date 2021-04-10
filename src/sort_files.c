/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:59:07 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/10 20:55:53 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "options.h"

int	compare_by_time_accessed(const void *obj1, const void *obj2)
{
	t_file	*file1;
	t_file	*file2;
	int		time_diff;

	if (obj1 == NULL || obj2 == NULL)
		return (0);
	file1 = *(t_file **)obj1;
	file2 = *(t_file **)obj2;
	time_diff = file2->st.st_atimespec.tv_sec - file1->st.st_atimespec.tv_sec;
	if (time_diff == 0)
		return (ft_strcmp(file1->name, file2->name));
	return (file2->st.st_atimespec.tv_sec - file1->st.st_atimespec.tv_sec);
}

int	compare_by_time_accessed_rev(const void *obj1, const void *obj2)
{
	t_file	*file1;
	t_file	*file2;
	int		time_diff;

	if (obj1 == NULL || obj2 == NULL)
		return (0);
	file1 = *(t_file **)obj1;
	file2 = *(t_file **)obj2;
	time_diff = file1->st.st_atimespec.tv_sec - file2->st.st_atimespec.tv_sec;
	if (time_diff == 0)
		return (ft_strcmp(file2->name, file1->name));
	return (file1->st.st_atimespec.tv_sec - file2->st.st_atimespec.tv_sec);
}

int	compare_by_name_rev(const void *obj1, const void *obj2)
{
	t_file	*file1;
	t_file	*file2;

	if (obj1 == NULL || obj2 == NULL)
		return (0);
	file1 = *(t_file **)obj1;
	file2 = *(t_file **)obj2;
	return (ft_strcmp(file2->name, file1->name));
}

int	compare_by_name(const void *obj1, const void *obj2)
{
	t_file	*file1;
	t_file	*file2;

	if (obj1 == NULL || obj2 == NULL)
		return (0);
	file1 = *(t_file **)obj1;
	file2 = *(t_file **)obj2;
	return (ft_strcmp(file1->name, file2->name));
}

void	sort_files(t_vector file_stats, unsigned int options)
{
	if (options & OP_R_LOWER)
	{
		if (options & OP_T_LOWER)
			vector_sort(&file_stats, compare_by_time_accessed_rev);
		else
			vector_sort(&file_stats, compare_by_name_rev);
	}
	else
	{
		if (options & OP_T_LOWER)
			vector_sort(&file_stats, compare_by_time_accessed);
		else
			vector_sort(&file_stats, compare_by_name);
	}
}
