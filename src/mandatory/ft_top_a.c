/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:20:40 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/04 23:09:00 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_divide_top_a(t_node **list_ab, int size, int border1, int border2)
{
	t_node	*list;

	list = ft_first_node(list_ab[0]);
	while (size-- > 0)
	{
		if (list->data < border1)
		{
			list = list->next;
			ft_push_write(list_ab, 'b');
			ft_rotate_write(list_ab, 'b');
		}
		else if (list->data < border2)
		{
			list = list->next;
			ft_push_write(list_ab, 'b');
		}
		else
		{
			list = list->next;
			ft_rotate_write(list_ab, 'a');
		}
	}
}

void	ft_top_a(t_node **list_ab, int size)
{
	int		border1;
	int		border2;

	// ft_printf("top_a start %d\n", size);
	
	if(ft_is_sorted(list_ab, 'a', 0, size))
	{
		// ft_printf("top_a end %d\n", size);
		// ft_print_list(list_ab);
		return ;
	}
	if (size <= 3)
	{
		ft_sort_mini(list_ab, 'a', size);
		// ft_printf("top_a end %d\n", size);
		// ft_print_list(list_ab);
		return ;
	}
	border1 = ft_get_min(list_ab, 'a', "top", size) + size / 3;
	border2 = border1 + size / 3;
	ft_divide_top_a(list_ab, size, border1, border2);
	ft_bottom_a(list_ab, size / 3 + size % 3);
	ft_top_b(list_ab, size / 3);
	ft_bottom_b(list_ab, size / 3);

	// ft_printf("top_a end %d\n", size);
	// ft_print_list(list_ab);
}
