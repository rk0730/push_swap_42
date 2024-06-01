/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:24:22 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/01 14:05:45 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//1周全てfreeする
void	ft_free_node(t_node *list)
{
	t_node	*tmp;
	t_node	*target;

	tmp = list;
	while (tmp->data != -1)
		tmp = tmp->next;
	tmp = tmp->next;
	while (tmp->data != -1)
	{
		target = tmp;
		tmp = tmp->next;
		free(target);
	}
	free(tmp);
}

void	ft_free_box(char ***box_p)
{
	int	i;

	i = 0;
	while ((*box_p)[i] != NULL)
	{
		free((*box_p)[i]);
		i++;
	}
	free(*box_p);
}

void	ft_free_box_exit(char ***box_p)
{
	ft_free_box(box_p);
	ft_printf("Error\n");
	exit(1);
}

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	ft_malloc_exit(void)
{
	ft_printf("malloc Error\n");
	exit(1);
}
