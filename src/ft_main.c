/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:17:23 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/01 16:27:44 by rkitao           ###   ########.fr       */
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
	ft_printf("--------------------\n");
	ft_printf("list_a size %d\n", size);
	if (size > 0)
	{
		list_ab[0] = ft_first_node(list_ab[0]);
		while (list_ab[0]->data != -1)
		{
			ft_printf("%d\n", list_ab[0]->data);
			list_ab[0] = list_ab[0]->next;
		}
	}
	size = ft_getsize(list_ab[1]);
	ft_printf("list_b size %d\n", size);
	if (size > 0)
	{
		list_ab[1] = ft_first_node(list_ab[1]);
		while (list_ab[1]->data != -1)
		{
			ft_printf("%d\n", list_ab[1]->data);
			list_ab[1] = list_ab[1]->next;
		}
	}
	ft_printf("--------------------\n");
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
	ft_reverse_rotate_a(list_ab);ft_printf("rra\n");
	ft_print_list(list_ab);
	ft_swap_b(list_ab);ft_printf("sb\n");
	ft_print_list(list_ab);
	ft_push_a(list_ab);ft_printf("pa\n");
	ft_print_list(list_ab);
	ft_push_b(list_ab);ft_printf("pb\n");
	ft_print_list(list_ab);
	ft_push_b(list_ab);ft_printf("pb\n");
	ft_print_list(list_ab);
	ft_reverse_rotate_b(list_ab);ft_printf("rrb\n");
	ft_print_list(list_ab);
	ft_rrr(list_ab);ft_printf("rrr\n");
	ft_print_list(list_ab);
	ft_push_a(list_ab);ft_printf("pa\n");
	ft_print_list(list_ab);
	//デバッグ
	ft_free_node(list_ab[0]);
	ft_free_node(list_ab[1]);
	free(list_ab);
	return (0);
}
