/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:20:57 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/08 12:59:22 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_min(t_node **list_ab, char c, char *position, int size)
{
	t_node	*list;
	int		min;

	list = list_ab[c - 'a'];
	if (ft_strncmp(position, "top", 3) == 0)
		list = ft_first_node(list);
	else if (ft_strncmp(position, "bottom", 6) == 0)
		list = ft_last_node(list);
	if (size > ft_getsize(list))
	{
		ft_printf("Invalid input ft_get_min\n");
		return (0);
	}
	min = list -> data;
	while (size-- > 0)
	{
		if (list->data < min)
			min = list->data;
		if (ft_strncmp(position, "top", 3) == 0)
			list = list->next;
		else if (ft_strncmp(position, "bottom", 6) == 0)
			list = list->prev;
	}
	return (min);
}

void	ft_bottom_to_top(t_node **list_ab, char c, int size)
{
	int		i;
	t_node	*list;

	ft_choose_list(list_ab, c, &list, NULL);
	i = 0;
	if (ft_getsize(list) > size * 2)
	{
		while (i < size)
		{
			ft_reverse_rotate_write(list_ab, c);
			i++;
		}
	}
	else
	{
		while (i < ft_getsize(list) - size)
		{
			ft_rotate_write(list_ab, c);
			i++;
		}
	}
}
