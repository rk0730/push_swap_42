/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:01:02 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/08 12:58:55 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_2(t_node **list_ab, char c)
{
	t_node	*list;

	ft_choose_list(list_ab, c, &list, NULL);
	if (ft_getsize(list) <= 1)
	{
		ft_printf("Invalid input ft_sort_2\n");
		return ;
	}
	list = ft_first_node(list);
	if (ft_is_sorted(list_ab, c, 0, 2) == 1)
		return ;
	ft_swap(&list, c);
	ft_printf("s%c\n", c);
}

void	ft_sort_3(t_node **list_ab, char c)
{
	t_node	*list;
	char	*str;

	ft_choose_list(list_ab, c, &list, NULL);
	if (ft_getsize(list) <= 2)
	{
		ft_printf("Invalid input ft_sort_3\n");
		return ;
	}
	list = ft_first_node(list);
	str = ft_order(list, 0, 3);
	ft_sort3_h1(list, c, str);
	ft_sort3_h2(list, c, str);
	ft_sort3_h3(list, c, str);
	ft_sort3_h4(list, c, str);
	free(str);
}

void	ft_sort_mini(t_node **list_ab, char c, int size)
{
	if (size > 3 || size < 1)
	{
		ft_printf("Invalid input ft_sort_mini\n");
		return ;
	}
	if (size == 2)
		ft_sort_2(list_ab, c);
	else if (size == 3)
		ft_sort_3(list_ab, c);
}
