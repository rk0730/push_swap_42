/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:17:23 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/08 13:08:56 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int		len;
	int		*array;
	t_node	**list_ab;

	array = ft_error(argc, argv, &len);
	list_ab = ft_gen_list(&array, len);
	ft_top_a(list_ab, len);
	ft_free_node(list_ab[0]);
	ft_free_node(list_ab[1]);
	free(list_ab);
	return (0);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q push_swap");
// }

// void	ft_print_list(t_node **list_ab)
// {
// 	int	size;
// 	size = ft_getsize(list_ab[0]);
// 	// ft_printf("--------------------\n");
// 	ft_printf("A size %d\t", size);
// 	if (size > 0)
// 	{
// 		list_ab[0] = ft_first_node(list_ab[0]);
// 		while (list_ab[0]->data != -1)
// 		{
// 			ft_printf("%d ", list_ab[0]->data);
// 			list_ab[0] = list_ab[0]->next;
// 		}
// 	}
// 	ft_printf("\n");
// 	size = ft_getsize(list_ab[1]);
// 	ft_printf("B size %d\t", size);
// 	if (size > 0)
// 	{
// 		list_ab[1] = ft_first_node(list_ab[1]);
// 		while (list_ab[1]->data != -1)
// 		{
// 			ft_printf("%d ", list_ab[1]->data);
// 			list_ab[1] = list_ab[1]->next;
// 		}
// 	}
// 	ft_printf("\n");
// 	// ft_printf("--------------------\n");
// }
