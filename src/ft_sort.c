/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:23:59 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/02 20:24:23 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_choose_list(t_node **list_ab, char c, t_node **list_p, char *other)
{
	if (c == 'a')
	{
		if (list_p)
			*list_p = list_ab[0];
		if (other)
			*other = 'b';
	}
	else
	{
		if (list_p)
			*list_p = list_ab[1];
		if (other)
			*other = 'a';
	}
}

//listのindex個目のnodeを含むnum個のnodeが昇順になっているか確認する
int	ft_is_sorted(t_node **list_ab, char c, int index, int num)
{
	t_node	*list;

	// if (c == 'a')
	// 	list = list_ab[0];
	// else
	// 	list = list_ab[1];
	ft_choose_list(list_ab, c, &list, NULL);
	if (index + num > ft_getsize(list) || ft_getsize(list) == 0)
	{
		ft_printf("Invalid input ft_is_sorted\n");
		return (0);
	}
	if (ft_getsize(list) == 1)
		return (1);
	list = ft_first_node(list);
	while (index-- > 0)
		list = list->next;
	while (num-- - 1 > 0)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}

static void	ft_order_h(t_node *list, int num, char *str)
{
	t_node	*tmp;
	int		min;
	int		i;

	tmp = list;
	i = 0;
	min = list->data;
	while (i < num)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
		i++;
	}
	tmp = list;
	i = 0;
	while (i < num)
	{
		str[i] = '0' + (tmp->data - min);
		tmp = tmp->next;
		i++;
	}
	str[num] = '\0';
}

// index個目から見てnum個のnodeがどんな順番になっているか文字列で表示する
char	*ft_order(t_node *list, int index, int num)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (num + 1));
	if (str == NULL)
		ft_malloc_exit();
	list = ft_first_node(list);
	while (index-- > 0)
		list = list->next;
	ft_order_h(list, num, str);
	return (str);
}
