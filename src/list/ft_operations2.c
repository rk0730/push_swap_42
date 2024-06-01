/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:44:17 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/01 16:02:48 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate_a(t_node **list_ab)
{
	t_node	*first_a;
	t_node	*last_a;

	if (ft_getsize(list_ab[0]) <= 1)
		return ;
	first_a = ft_first_node(list_ab[0]);
	last_a = ft_last_node(list_ab[0]);
	first_a -> prev -> next = first_a -> next;
	first_a -> next -> prev = first_a -> prev;
	first_a -> prev -> prev = first_a;
	first_a -> next = first_a -> next -> prev;
	first_a -> prev = last_a;
	last_a -> next = first_a;
}

void	ft_rotate_b(t_node **list_ab)
{
	t_node	*first_b;
	t_node	*last_b;

	if (ft_getsize(list_ab[1]) <= 1)
		return ;
	first_b = ft_first_node(list_ab[1]);
	last_b = ft_last_node(list_ab[1]);
	first_b -> prev -> next = first_b -> next;
	first_b -> next -> prev = first_b -> prev;
	first_b -> prev -> prev = first_b;
	first_b -> next = first_b -> next -> prev;
	first_b -> prev = last_b;
	last_b -> next = first_b;
}

void	ft_rr(t_node **list_ab)
{
	ft_rotate_a(list_ab);
	ft_rotate_b(list_ab);
}
