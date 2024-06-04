/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:12:32 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/05 03:30:21 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// void	ft_reverse_rotate_a(t_node **list_ab)
// {
// 	t_node	*first_a;
// 	t_node	*last_a;

// 	if (ft_getsize(list_ab[0]) <= 1)
// 		return ;
// 	first_a = ft_first_node(list_ab[0]);
// 	last_a = ft_last_node(list_ab[0]);
// 	last_a -> next -> prev = last_a -> prev;
// 	last_a -> prev -> next = last_a -> next;
// 	last_a -> next -> next = last_a;
// 	last_a -> prev = last_a -> prev -> next;
// 	last_a -> next = first_a;
// 	first_a -> prev = last_a;
// }

// void	ft_reverse_rotate_b(t_node **list_ab)
// {
// 	t_node	*first_b;
// 	t_node	*last_b;

// 	if (ft_getsize(list_ab[1]) <= 1)
// 		return ;
// 	first_b = ft_first_node(list_ab[1]);
// 	last_b = ft_last_node(list_ab[1]);
// 	last_b -> next -> prev = last_b -> prev;
// 	last_b -> prev -> next = last_b -> next;
// 	last_b -> next -> next = last_b;
// 	last_b -> prev = last_b -> prev -> next;
// 	last_b -> next = first_b;
// 	first_b -> prev = last_b;
// }

void	ft_reverse_rotate(t_node **list_ab, char c)
{
	t_node	*first;
	t_node	*last;

	// if (c == 'a')
	// 	first = ft_first_node(list_ab[0]);
	// else
	// 	first = ft_first_node(list_ab[1]);
	ft_choose_list(list_ab, c, &first, NULL);
	if (ft_getsize(first) <= 1)
		return ;
	first = ft_first_node(first);
	last = ft_last_node(first);
	last -> next -> prev = last -> prev;
	last -> prev -> next = last -> next;
	last -> next -> next = last;
	last -> prev = last -> prev -> next;
	last -> next = first;
	first -> prev = last;
}

void	ft_rrr(t_node **list_ab)
{
	ft_reverse_rotate(list_ab, 'a');
	ft_reverse_rotate(list_ab, 'b');
}

// void	ft_rotate_a(t_node **list_ab)
// {
// 	t_node	*first_a;
// 	t_node	*last_a;

// 	if (ft_getsize(list_ab[0]) <= 1)
// 		return ;
// 	first_a = ft_first_node(list_ab[0]);
// 	last_a = ft_last_node(list_ab[0]);
// 	first_a -> prev -> next = first_a -> next;
// 	first_a -> next -> prev = first_a -> prev;
// 	first_a -> prev -> prev = first_a;
// 	first_a -> next = first_a -> next -> prev;
// 	first_a -> prev = last_a;
// 	last_a -> next = first_a;
// }
