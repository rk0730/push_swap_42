/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bottom_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:48:12 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/04 23:06:53 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_divide_bottom_b(t_node **list_ab, int size, int border1, int border2)
{
	t_node	*list;

	list = ft_last_node(list_ab[1]);
	while (size-- > 0)
	{
		if (list->data < border1)
		{
			list = list->prev;
			ft_reverse_rotate_write(list_ab, 'b');
		}
		else if (list->data < border2)
		{
			list = list->prev;
			ft_reverse_rotate_write(list_ab, 'b');
			ft_push_write(list_ab, 'a');
			ft_rotate_write(list_ab, 'a');
		}
		else
		{
			list = list->prev;
			ft_reverse_rotate_write(list_ab, 'b');
			ft_push_write(list_ab, 'a');
		}
	}
}

void	ft_bottom_b(t_node **list_ab, int size)
{
	int	i;
	int	border1;
	int	border2;

	// ft_printf("bottom_b start %d\n", size);
	i = 0;
	if (size <= 3)
	{
		ft_bottom_to_top(list_ab, 'b', size);
		while (i < size)
		{
			ft_push_write(list_ab, 'a');
			i++;
		}
		
		ft_sort_mini(list_ab, 'a', size);
		// ft_printf("bottom_a end %d\n", size);
		// ft_print_list(list_ab);
		return ;
	}
	// bottomの要素が多く、topに回した方がいい
	if (2 * size / 3 > ft_getsize(list_ab[1]) - size)
	{
		ft_bottom_to_top(list_ab, 'b', size);
		ft_top_b(list_ab, size);
		// ft_printf("bottom_a end %d\n", size);
		// ft_print_list(list_ab);
		return ;
	}
	border1 = ft_get_min(list_ab, 'b', "bottom", size) + size / 3 + size % 3;
	border2 = border1 + size / 3;
	ft_divide_bottom_b(list_ab, size, border1, border2);
	ft_top_a(list_ab, size / 3);
	ft_bottom_a(list_ab, size / 3);
	ft_top_b(list_ab, size / 3 + size % 3);

	// ft_printf("bottom_b end %d\n", size);
	// ft_print_list(list_ab);
}
