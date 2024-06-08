/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:44:17 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/08 13:02:44 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_rotate(t_node **list_ab, char c)
{
	t_node	*first;
	t_node	*last;

	ft_choose_list(list_ab, c, &first, NULL);
	if (ft_getsize(first) <= 1)
		return ;
	first = ft_first_node(first);
	last = ft_last_node(first);
	first -> prev -> next = first -> next;
	first -> next -> prev = first -> prev;
	first -> prev -> prev = first;
	first -> next = first -> next -> prev;
	first -> prev = last;
	last -> next = first;
}

void	ft_rr(t_node **list_ab)
{
	ft_rotate(list_ab, 'a');
	ft_rotate(list_ab, 'b');
}
