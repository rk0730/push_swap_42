/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:12:32 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/08 13:02:59 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_reverse_rotate(t_node **list_ab, char c)
{
	t_node	*first;
	t_node	*last;

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
