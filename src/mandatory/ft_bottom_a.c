/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bottom_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:24:46 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/08 13:04:36 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_divide_bottom_a(t_node **list_ab, int size, int bo1, int bo2)
{
	t_node	*list;

	list = ft_last_node(list_ab[0]);
	while (size-- > 0)
	{
		if (list->data < bo1)
		{
			list = list->prev;
			ft_reverse_rotate_write(list_ab, 'a');
			ft_push_write(list_ab, 'b');
			ft_rotate_write(list_ab, 'b');
		}
		else if (list->data < bo2)
		{
			list = list->prev;
			ft_reverse_rotate_write(list_ab, 'a');
			ft_push_write(list_ab, 'b');
		}
		else
		{
			list = list->prev;
			ft_reverse_rotate_write(list_ab, 'a');
		}
	}
}

void	ft_bottom_a(t_node **list_ab, int size)
{
	int		border1;
	int		border2;

	if (size <= 3)
	{
		ft_bottom_to_top(list_ab, 'a', size);
		ft_sort_mini(list_ab, 'a', size);
		return ;
	}
	if (2 * size / 3 > ft_getsize(list_ab[0]) - size)
	{
		ft_bottom_to_top(list_ab, 'a', size);
		ft_top_a(list_ab, size);
		return ;
	}
	border1 = ft_get_min(list_ab, 'a', "bottom", size) + size / 3;
	border2 = border1 + size / 3;
	ft_divide_bottom_a(list_ab, size, border1, border2);
	ft_top_a(list_ab, size / 3 + size % 3);
	ft_top_b(list_ab, size / 3);
	ft_bottom_b(list_ab, size / 3);
}
