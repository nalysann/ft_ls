/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_extra_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:40:21 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/26 22:43:43 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

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
	return (time_diff);
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
	return (time_diff);
}
