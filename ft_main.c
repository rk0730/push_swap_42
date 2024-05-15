/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:17:23 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/15 16:50:54 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// #include <libc.h>
// #include <errno.h>

// int malloc_count = 10;

// //マロックを無理やり失敗させる
// void *malloc(size_t size)
// {
// 	static int i = 0;
// 	while (i++ < malloc_count)
// 		return (calloc(size, 1));
// 	return (NULL);
// }

int	main(int argc, char **argv)
{
	ft_printf("argc %d\n", argc);
	int len;
	int *array = ft_error(argc, argv, &len);
	ft_printf("len %d\n", len);
	int i = 0;
	while (i < len)
	{
		ft_printf("%d\n", array[i]);
		i++;
	}
	t_node	**list_ab = ft_gen_list(&array, len);
	//表示
	ft_printf("list_a\n");
	while (list_ab[0]->data != -1)
		list_ab[0] = list_ab[0]->next;
	list_ab[0] = list_ab[0]->next;
	while (list_ab[0]->data != -1)
	{
		ft_printf("%d\n", list_ab[0]->data);
		list_ab[0] = list_ab[0]->next;
	}
	ft_printf("%d\n", list_ab[0]->data);

	ft_printf("list_b\n");
	while (list_ab[1]->data != -1)
		list_ab[1] = list_ab[1]->next;
	list_ab[1] = list_ab[1]->next;
	while (list_ab[1]->data != -1)
	{
		printf("%d\n", list_ab[1]->data);
		list_ab[1] = list_ab[1]->next;
	}
	printf("%d\n", list_ab[1]->data);
	ft_free_node(list_ab[0]);
	ft_free_node(list_ab[1]);
	return (0);
}
