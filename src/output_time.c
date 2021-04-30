/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 23:48:54 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/30 23:51:37 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>
#include "libft.h"

int month_order(const char *month_name)
{
	if (!ft_strncmp(month_name, "Jan", 3))
		return 0;
	if (!ft_strncmp(month_name, "Feb", 3))
		return 1;
	if (!ft_strncmp(month_name, "Mar", 3))
		return 2;
	if (!ft_strncmp(month_name, "Apr", 3))
		return 3;
	if (!ft_strncmp(month_name, "May", 3))
		return 4;
	if (!ft_strncmp(month_name, "Jun", 3))
		return 5;
	if (!ft_strncmp(month_name, "Jul", 3))
		return 6;
	if (!ft_strncmp(month_name, "Aug", 3))
		return 7;
	if (!ft_strncmp(month_name, "Sep", 3))
		return 8;
	if (!ft_strncmp(month_name, "Oct", 3))
		return 9;
	if (!ft_strncmp(month_name, "Nov", 3))
		return 10;
	if (!ft_strncmp(month_name, "Dec", 3))
		return 11;
	return 424242; // wtf scenario, hopefully large num will help debug
}

void	parse_time(t_file *file, time_t now)
{
	char	*now_str;
	char	*file_str;
	int		now_tmp;
	int		file_tmp;

	now_str = ctime(&now);
	file_str = ctime(&(file->st.st_mtimespec.tv_sec));
	file->month_and_day = ft_strsub(file_str, 4, 6);
	now_tmp = ft_atoi(now_str + 20);
	file_tmp = ft_atoi(file_str + 20);
	if ((ft_abs(now_tmp - file_tmp) > 1)
		|| (now_tmp - file_tmp == 0 && 
			ft_abs((month_order(now_str) - month_order(file_str)) > 6))) // other cases of month diff + day time diff
		file->time_or_year = ft_strsub(file_str, 20, 4);
	else
		file->time_or_year = ft_strsub(file_str, 11, 5);
}
