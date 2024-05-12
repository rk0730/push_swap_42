/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:03:31 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/04 21:09:24 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_u_h(unsigned int num, int res)
{
	int	tmp;

	if (res == -1)
		return (-1);
	if (num >= 10)
	{
		tmp = ft_convert_u_h(num / 10, res);
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

int	ft_convert_u(unsigned int num)
{
	return (ft_convert_u_h(num, 0));
}
