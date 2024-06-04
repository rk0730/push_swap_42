/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:20:40 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/04 19:42:38 by kitaoryoma       ###   ########.fr       */
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
			// ft_printf("small\n");
			ft_push(list_ab, 'b');
			ft_printf("pb\n");
			ft_rotate(list_ab, 'b');
			ft_printf("rb\n");
		}
		else if (list->data < border2)
		{
			list = list->next;
			// ft_printf("medium\n");
			ft_push(list_ab, 'b');
			ft_printf("pb\n");
		}
		else
		{
			list = list->next;
			// ft_printf("large\n");
			ft_rotate(list_ab, 'a');
			ft_printf("ra\n");
		}
	}
}

void	ft_top_a(t_node **list_ab, int size)
{
	int		border1;
	int		border2;

	ft_printf("top_a start %d\n", size);
	
	if(ft_is_sorted(list_ab, 'a', 0, size))
	{
		ft_printf("top_a end %d\n", size);
		ft_print_list(list_ab);
		return ;
	}
	if (size <= 3)
	{
		ft_sort_mini(list_ab, 'a', size);
		ft_printf("top_a end %d\n", size);
		ft_print_list(list_ab);
		return ;
	}
	border1 = ft_get_min(list_ab, 'a', "top", size) + size / 3;
	border2 = border1 + size / 3;
	ft_divide_top_a(list_ab, size, border1, border2);
	ft_bottom_a(list_ab, size / 3 + size % 3);
	ft_top_b(list_ab, size / 3);
	ft_bottom_b(list_ab, size / 3);

	ft_printf("top_a end %d\n", size);
	ft_print_list(list_ab);
	// ft_print_list(list_ab);
}
