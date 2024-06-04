/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bottom_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:24:46 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/04 18:30:26 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_divide_bottom_a(t_node **list_ab, int size, int border1, int border2)
{
	t_node	*list;

	list = ft_last_node(list_ab[0]);
	while (size-- > 0)
	{
		if (list->data < border1)
		{
			list = list->prev;
			ft_reverse_rotate(list_ab, 'a');
			ft_printf("rra\n");
			ft_push(list_ab, 'b');
			ft_printf("pb\n");
			ft_rotate(list_ab, 'b');
			ft_printf("rb\n");
		}
		else if (list->data < border2)
		{
			list = list->prev;
			ft_reverse_rotate(list_ab, 'a');
			ft_printf("rra\n");
			ft_push(list_ab, 'b');
			ft_printf("pb\n");
		}
		else
		{
			list = list->prev;
			ft_reverse_rotate(list_ab, 'a');
			ft_printf("rra\n");
		}
	}
}

//bottomの要素をtopに移動させる
static void	ft_bottom_to_top(t_node **list_ab, int size)
{
	int	i;

	i = 0;
	if (ft_getsize(list_ab[0]) > size * 2)
	{
		while (i < size)
		{
			ft_reverse_rotate(list_ab, 'a');
			ft_printf("rra\n");
			i++;
		}
	}
	else
	{
		while (i < ft_getsize(list_ab[0]) - size)
		{
			ft_rotate(list_ab, 'a');
			ft_printf("ra\n");
			i++;
		}
	}
}

void	ft_bottom_a(t_node **list_ab, int size)
{
	int		border1;
	int		border2;

	// ft_printf("bottom_a start %d\n", size);
	if (size <= 3)
	{
		ft_bottom_to_top(list_ab, size);
		ft_sort_mini(list_ab, 'a', size);
		return ;
	}
	//bottomの要素が多く、topに回した方がいい
	if (2 * size / 3 > ft_getsize(list_ab[0]) - size)
	{
		ft_bottom_to_top(list_ab, size);
		ft_top_a(list_ab, size);
		return ;
	}
	border1 = ft_get_min(list_ab, 'a', "bottom", size) + size / 3;
	border2 = border1 + size / 3;
	ft_divide_bottom_a(list_ab, size, border1, border2);
	ft_top_a(list_ab, size / 3 + size % 3);
	ft_top_b(list_ab, size / 3);
	ft_bottom_b(list_ab, size / 3);

	// ft_printf("bottom_a end %d\n", size);
	// ft_print_list(list_ab);
}
