/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:01:02 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/04 16:47:14 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//先頭の2つのnodeを昇順にする
void	ft_sort_2(t_node **list_ab, char c)
{
	t_node	*list;

	// if (c == 'a')
	// 	list = list_ab[0];
	// else
	// 	list = list_ab[1];
	ft_choose_list(list_ab, c, &list, NULL);
	if (ft_getsize(list) <= 1)
	{
		ft_printf("Invalid input ft_sort_2\n");
		return ;
	}
	list = ft_first_node(list);
	if (ft_is_sorted(list_ab, c, 0, 2) == 1)
		return ;
	// while (index-- > 0)
	// 	list = list->next;
	ft_swap(&list, c);
	ft_printf("s%c\n", c);
}

static void	ft_sort3_h1(t_node *list, char c)
{
	char	*str;

	str = ft_order(list, 0, 3);
	if (ft_strncmp(str, "021", 3) == 0)
	{
		ft_swap(&list, c);
		ft_printf("s%c\n", c);
		ft_rotate(&list, c);
		ft_printf("r%c\n", c);
	}
	if (ft_strncmp(str, "102", 3) == 0)
	{
		ft_swap(&list, c);
		ft_printf("s%c\n", c);
	}
	if (ft_strncmp(str, "120", 3) == 0)
	{
		ft_reverse_rotate(&list, c);
		ft_printf("rr%c\n", c);
	}
	free(str);
}

static void	ft_sort3_h2(t_node *list, char c)
{
	char	*str;

	str = ft_order(list, 0, 3);
	if (ft_strncmp(str, "201", 3) == 0)
	{
		ft_rotate(&list, c);
		ft_printf("r%c\n", c);
	}
	if (ft_strncmp(str, "210", 3) == 0)
	{
		ft_rotate(&list, c);
		ft_printf("r%c\n", c);
		ft_swap(&list, c);
		ft_printf("s%c\n", c);
	}
	free(str);
}

//先頭の3つのnodeを昇順にする
void	ft_sort_3(t_node **list_ab, char c)
{
	t_node	*list;

	// char	other;
	// ft_choose_list(list_ab, c, list, &other);
	ft_choose_list(list_ab, c, &list, NULL);
	if (ft_getsize(list) <= 2)
	{
		ft_printf("Invalid input ft_sort_2\n");
		return ;
	}
	// if (ft_is_sorted(list_ab, c, 0, 3) == 1)
	// 	return ;
	list = ft_first_node(list);
	ft_sort3_h1(list, c);
	ft_sort3_h2(list, c);
}

//sizeが3以下の場合はソートする
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
