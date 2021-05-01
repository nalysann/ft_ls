#include "ft_stdio.h"
#include "ft_vector.h"

#include "item.h"
#include "options.h"

void	print(t_vector *files, unsigned int *options)
{
	t_width	*width;
	size_t	lst_size;

	if (head == NULL)
		return ;
	lst_size = get_list_size(head);
	width = (flags->l) ? get_width(head) : NULL;
	if (flags->l)
		while (head != NULL)
		{
			print_with_flag_l(head, width, flags);
			print_name(head, flags);
			head = head->next;
		}
	else if (flags->one)
		print_flag_one(head, flags);
	else
		print_by_column(head, flags, lst_size);
	free(width);
}
