/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:43:54 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/05 01:07:15 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort3_h1(t_node *list, char c, char *str)
{
	if (ft_strncmp(str, "021", 3) == 0)
	{
		if (ft_getsize(list) == 3)
		{
			ft_swap_write(&list, c);
			ft_rotate_write(&list, c);
		}
		else
		{
			ft_rotate_write(&list, c);
			ft_swap_write(&list, c);
			ft_reverse_rotate_write(&list, c);
		}
	}
	if (ft_strncmp(str, "102", 3) == 0)
		ft_swap_write(&list, c);
}

void	ft_sort3_h2(t_node *list, char c, char *str)
{
	if (ft_strncmp(str, "120", 3) == 0)
	{
		if (ft_getsize(list) == 3)
			ft_reverse_rotate_write(&list, c);
		else
		{
			ft_rotate_write(&list, c);
			ft_swap_write(&list, c);
			ft_reverse_rotate_write(&list, c);
			ft_swap_write(&list, c);
		}
	}
}

void	ft_sort3_h3(t_node *list, char c, char *str)
{
	if (ft_strncmp(str, "201", 3) == 0)
	{
		if (ft_getsize(list) == 3)
		{
			ft_rotate_write(&list, c);
		}
		else
		{
			ft_swap_write(&list, c);
			ft_rotate_write(&list, c);
			ft_swap_write(&list, c);
			ft_reverse_rotate_write(&list, c);
		}
	}
}

void	ft_sort3_h4(t_node *list, char c, char *str)
{
	if (ft_strncmp(str, "210", 3) == 0)
	{
		if (ft_getsize(list) == 3)
		{
			ft_rotate_write(&list, c);
			ft_swap_write(&list, c);
		}
		else
		{
			ft_swap_write(&list, c);
			ft_rotate_write(&list, c);
			ft_swap_write(&list, c);
			ft_reverse_rotate_write(&list, c);
			ft_swap_write(&list, c);
		}
	}
}
