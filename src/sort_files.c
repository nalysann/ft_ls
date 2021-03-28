/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:59:07 by bgilwood          #+#    #+#             */
/*   Updated: 2021/03/28 20:15:07 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "options.h"

// not tested

int		compare_files(void *file1_ptr, void *file2_ptr, int flags)
{
	int	tmp;
	t_file *file1;
	t_file *file2;

	file1 = (t_file*)file1_ptr;
	file2 = (t_file*)file2_ptr;
	if ((flags & OP_T_LOWER) && (flags & OP_R_LOWER))
	{
		tmp = file2->date - file1->date;
		if (tmp)
			return (tmp);
	}
	if ((flags & OP_T_LOWER))
	{
		tmp = file1->date - file2->date;
		if (tmp)
			return (tmp);
	}
	if (flags & OP_R_LOWER)
		return (ft_strcmp(file2->name, file1->name));
	return (ft_strcmp(file1->name, file2->name));
}




// void	switch_data(t_node *node1, t_node *node2)
// {
// 	void	*tmp;

// 	tmp = node1->data;
// 	node1->data = node2->data;
// 	node2->data = tmp;
// }

// void	sort_list(t_list *files, int flags)
// {
// 	t_node	*node;
// 	int		len;
// 	int		i;
// 	int		sorted;

// 	len = files->size;
// 	if (files->front == NULL || (files->front)->next == NULL)
// 		return;
// 	while (--len)
// 	{
// 		node = files->front;
// 		sorted = 1;
// 		i = 0;
// 		while (i++ < len)
// 		{
// 			if (compare_files(node->data, node->next->data, flags) > 0)
// 			{
// 				switch_data(node, node->next);
// 				sorted = 0;
// 			}
// 			node = node->next;
// 		}
// 		if (sorted)
// 			break;
// 	}
// }
