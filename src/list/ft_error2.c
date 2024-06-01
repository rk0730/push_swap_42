/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:18:52 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/13 20:20:48 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//arrayに同じ数字があったら1を返す
int	ft_dup_check(int *array, int num)
{
	int	i;
	int	j;

	i = 0;
	while (i < num)
	{
		j = i + 1;
		while (j < num)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
