/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:51:42 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/04 22:52:00 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_write(t_node **list_ab, char c)
{
	ft_swap(list_ab, c);
	ft_printf("s%c\n", c);
}

void	ft_push_write(t_node **list_ab, char c)
{
	ft_push(list_ab, c);
	ft_printf("p%c\n", c);
}

void	ft_rotate_write(t_node **list_ab, char c)
{
	ft_rotate(list_ab, c);
	ft_printf("r%c\n", c);
}

void	ft_reverse_rotate_write(t_node **list_ab, char c)
{
	ft_reverse_rotate(list_ab, c);
	ft_printf("rr%c\n", c);
}
