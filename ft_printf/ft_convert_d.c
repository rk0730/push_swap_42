/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:23:44 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/08 12:12:19 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_d_h(int num, int res)
{
	int	tmp;

	if (res == -1)
		return (-1);
	if (num >= 10)
	{
		tmp = ft_convert_d_h(num / 10, res);
		if (tmp == -1)
			return (-1);
		else
			res += tmp;
	}
	tmp = ft_convert_c('0' + num % 10);
	if (tmp == -1)
		return (-1);
	else
		return (res + tmp);
}

int	ft_convert_d(int num)
{
	int	res;

	res = 0;
	if (num == -2147483648)
	{
		if (write(STDOUT_FILENO, "-2147483648", 11) == -1)
			return (-1);
		else
			return (11);
	}
	if (num < 0)
	{
		if (write(STDOUT_FILENO, "-", 1) == -1)
			return (-1);
		else
			res += 1;
		num *= -1;
	}
	res += ft_convert_d_h(num, 0);
	return (res);
}
