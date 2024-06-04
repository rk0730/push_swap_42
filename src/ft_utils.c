/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:20:57 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/04 17:04:46 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//listのtopまたはbottomからsize個分のnodeを見てその最小値を求める
int	ft_get_min(t_node **list_ab, char c, char *str, int size)
{
	t_node	*list;
	int		min;

	list = list_ab[c - 'a'];
	if (ft_strncmp(str, "top", 3) == 0)
		list = ft_first_node(list);
	else if (ft_strncmp(str, "bottom", 6) == 0)
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
		if (ft_strncmp(str, "top", 3) == 0)
			list = list->next;
		else if (ft_strncmp(str, "bottom", 6) == 0)
			list = list->prev;
	}
	return (min);
}

// int	ft_get_max(t_node **list_ab, char c, char *str, int size)
// {
// 	t_node	*list;
// 	int		max;

// 	list = list_ab[c - 'a'];
// 	if (ft_strncmp(str, "top", 3) == 0)
// 		list = ft_first_node(list);
// 	else if (ft_strncmp(str, "bottom", 6) == 0)
// 		list = ft_last_node(list);
// 	if (size > ft_getsize(list))
// 	{
// 		ft_printf("Invalid input ft_get_max\n");
// 		return (0);
// 	}
// 	max = list -> data;
// 	while (size-- > 0)
// 	{
// 		if (list->data > max)
// 			max = list->data;
// 		if (ft_strncmp(str, "top", 3) == 0)
// 			list = list->next;
// 		else if (ft_strncmp(str, "bottom", 6) == 0)
// 			list = list->prev;
// 	}
// 	return (max);
// }
