/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:17:23 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/13 20:24:44 by kitaoryoma       ###   ########.fr       */
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
	free(array);
	return (0);
}
