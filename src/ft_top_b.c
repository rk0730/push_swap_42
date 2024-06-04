/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:41:19 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/04 18:30:15 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_divide_top_b(t_node **list_ab, int size, int border1, int border2)
{
	t_node	*list;

	list = ft_first_node(list_ab[1]);
	while (size-- > 0)
	{
		if (list->data < border1)
		{
			list = list->next;
			ft_rotate(list_ab, 'b');
			ft_printf("rb\n");
		}
		else if (list->data < border2)
		{
			list = list->next;
			ft_push(list_ab, 'a');
			ft_printf("pa\n");
			ft_rotate(list_ab, 'a');
			ft_printf("ra\n");
		}
		else
		{
			list = list->next;
			ft_push(list_ab, 'a');
			ft_printf("pa\n");
		}
	}
}

void	ft_top_b(t_node **list_ab, int size)
{
	int	i;
	int	border1;
	int	border2;

	// ft_printf("top_b start %d\n", size);
	i = 0;
	if (size <= 3)
	{
		while (i < size)
		{
			ft_push(list_ab, 'a');
			ft_printf("pa\n");
			i++;
		}
		ft_top_a(list_ab, size);
		return ;
	}

	border1 = ft_get_min(list_ab, 'b', "bottom", size) + size / 3;
	border2 = border1 + size / 3;
	ft_divide_top_b(list_ab, size, border1, border2);
	ft_top_a(list_ab, size / 3 + size % 3);
	ft_bottom_a(list_ab, size / 3);
	ft_bottom_b(list_ab, size / 3);

	// ft_printf("top_b end %d\n", size);
	// ft_print_list(list_ab);
}
