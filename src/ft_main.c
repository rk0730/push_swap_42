/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:17:23 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/02 20:33:08 by rkitao           ###   ########.fr       */
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

#include <libc.h>

__attribute__((destructor))
static void destructor() {
	system("leaks -q push_swap");
}

void	ft_print_list(t_node **list_ab)
{
	int	size;
	size = ft_getsize(list_ab[0]);
	// ft_printf("--------------------\n");
	ft_printf("A size %d\t", size);
	if (size > 0)
	{
		list_ab[0] = ft_first_node(list_ab[0]);
		while (list_ab[0]->data != -1)
		{
			ft_printf("%d ", list_ab[0]->data);
			list_ab[0] = list_ab[0]->next;
		}
	}
	ft_printf("\n");
	size = ft_getsize(list_ab[1]);
	ft_printf("B size %d\t", size);
	if (size > 0)
	{
		list_ab[1] = ft_first_node(list_ab[1]);
		while (list_ab[1]->data != -1)
		{
			ft_printf("%d ", list_ab[1]->data);
			list_ab[1] = list_ab[1]->next;
		}
	}
	ft_printf("\n");
	// ft_printf("--------------------\n");
}

int	main(int argc, char **argv)
{
	// ft_printf("argc %d\n", argc);
	int len;
	int *array = ft_error(argc, argv, &len);
	
	// ft_printf("len %d\n", len);
	// int i = 0;
	// while (i < len)
	// {
	// 	ft_printf("%d\n", array[i]);
	// 	i++;
	// }
	
	t_node	**list_ab = ft_gen_list(&array, len);
	ft_print_list(list_ab);
	//デバッグ
	ft_sort_3(list_ab, 'a');
	ft_print_list(list_ab);
	//デバッグ
	ft_free_node(list_ab[0]);
	ft_free_node(list_ab[1]);
	free(list_ab);
	return (0);
}
