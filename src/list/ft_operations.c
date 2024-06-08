/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:44:08 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/08 13:02:22 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_node **list_ab, char c)
{
	t_node	*first;
	t_node	*list;
	int		tmp;

	ft_choose_list(list_ab, c, &list, NULL);
	if (ft_getsize(list) <= 1)
		return ;
	first = ft_first_node(list);
	tmp = first -> data;
	first -> data = first -> next -> data;
	first -> next -> data = tmp;
}

void	ft_ss(t_node **list_ab)
{
	ft_swap(list_ab, 'a');
	ft_swap(list_ab, 'b');
}

static void	ft_push_h(t_node *dst, t_node *src)
{
	if (ft_getsize(dst) == 0)
	{
		dst -> next = src;
		dst -> prev = src;
		src -> prev = dst;
		src -> next = dst;
		return ;
	}
	else
	{
		dst = ft_first_node(dst);
		dst -> prev -> next = src;
		src -> prev = dst -> prev;
		dst -> prev = src;
		src -> next = dst;
	}
}

void	ft_push(t_node **list_ab, char c)
{
	t_node	*dst;
	t_node	*src;

	if (c == 'a')
	{
		dst = list_ab[0];
		src = list_ab[1];
	}
	else
	{
		dst = list_ab[1];
		src = list_ab[0];
	}
	if (ft_getsize(src) == 0)
		return ;
	src = ft_first_node(src);
	src -> prev -> next = src -> next;
	src -> next -> prev = src -> prev;
	ft_push_h(dst, src);
}
