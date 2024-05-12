/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:24:22 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/12 20:17:58 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

static void	ft_free_box_exit(char ***c_box_p)
{
	int	i;

	i = 0;
	while ((*c_box_p)[i] != NULL)
		free((*c_box_p)[i++]);
	free(*c_box_p);
	ft_printf("Error\n");
	exit(1);
}

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}
