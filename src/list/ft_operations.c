/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:44:08 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/02 13:44:11 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

//list_aの先頭にあるノードと2番目のノードのデータを入れ替える
// void	ft_swap_a(t_node **list_ab)
// {
// 	t_node	*first;
// 	int		tmp;

// 	if (ft_getsize(list_ab[0]) <= 1)
// 		return ;
// 	first = ft_first_node(list_ab[0]);
// 	tmp = first -> data;
// 	first -> data = first -> next -> data;
// 	first -> next -> data = tmp;
// }

// void	ft_swap_b(t_node **list_ab)
// {
// 	t_node	*first;
// 	int		tmp;

// 	if (ft_getsize(list_ab[1]) <= 1)
// 		return ;
// 	first = ft_first_node(list_ab[1]);
// 	tmp = first -> data;
// 	first -> data = first -> next -> data;
// 	first -> next -> data = tmp;
// }

void	ft_swap(t_node **list_ab, char c)
{
	t_node	*first;
	t_node	*list;
	int		tmp;

	if (c == 'a')
		list = list_ab[0];
	else
		list = list_ab[1];
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

//list_bの先頭のノードをlist_aの先頭に移動する
// void	ft_push_a(t_node **list_ab)
// {
// 	t_node	*first_a;
// 	t_node	*first_b;

// 	if (ft_getsize(list_ab[1]) == 0)
// 		return ;
// 	first_b = ft_first_node(list_ab[1]);
// 	first_b -> prev -> next = first_b -> next;
// 	first_b -> next -> prev = first_b -> prev;
// 	if (ft_getsize(list_ab[0]) == 0)
// 	{
// 		list_ab[0] -> next = first_b;
// 		list_ab[0] -> prev = first_b;
// 		first_b -> prev = list_ab[0];
// 		first_b -> next = list_ab[0];
// 		return ;
// 	}
// 	else
// 	{
// 		first_a = ft_first_node(list_ab[0]);
// 		first_a -> prev -> next = first_b;
// 		first_b -> prev = first_a -> prev;
// 		first_a -> prev = first_b;
// 		first_b -> next = first_a;
// 	}
// }

// void	ft_push_b(t_node **list_ab)
// {
// 	t_node	*first_a;
// 	t_node	*first_b;

// 	if (ft_getsize(list_ab[0]) == 0)
// 		return ;
// 	first_a = ft_first_node(list_ab[0]);
// 	first_a -> prev -> next = first_a -> next;
// 	first_a -> next -> prev = first_a -> prev;
// 	if (ft_getsize(list_ab[1]) == 0)
// 	{
// 		list_ab[1] -> next = first_a;
// 		list_ab[1] -> prev = first_a;
// 		first_a -> prev = list_ab[1];
// 		first_a -> next = list_ab[1];
// 		return ;
// 	}
// 	else
// 	{
// 		first_b = ft_first_node(list_ab[1]);
// 		first_b -> prev -> next = first_a;
// 		first_a -> prev = first_b -> prev;
// 		first_b -> prev = first_a;
// 		first_a -> next = first_b;
// 	}
// }

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
	// if (ft_getsize(dst) == 0)
	// {
	// 	dst -> next = src;
	// 	dst -> prev = src;
	// 	src -> prev = dst;
	// 	src -> next = dst;
	// 	return ;
	// }
	// else
	// {
	// 	dst = ft_first_node(dst);
	// 	dst -> prev -> next = src;
	// 	src -> prev = dst -> prev;
	// 	dst -> prev = src;
	// 	src -> next = dst;
	// }
}
