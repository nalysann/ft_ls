/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:43:39 by bgilwood          #+#    #+#             */
/*   Updated: 2021/04/26 22:43:40 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

void	sort_files(t_vector file_stats, unsigned options);
int		compare_by_time_accessed_rev(const void *obj1, const void *obj2);
int		compare_by_time_accessed(const void *obj1, const void *obj2);

