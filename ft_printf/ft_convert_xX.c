/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1652952399 <1652952399@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:16:27 by 1652952399        #+#    #+#             */
/*   Updated: 2024/05/08 18:41:11 by 1652952399       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_x_h(unsigned int num, int res, int flag)
{
	int		tmp;
	char	*str;

	if (flag)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (res == -1)
		return (-1);
	if (num >= 16)
	{
		tmp = ft_convert_x_h(num / 16, res, flag);
		if (tmp == -1)
			return (-1);
		else
			res += tmp;
	}
	tmp = ft_convert_c(str[num % 16]);
	if (tmp == -1)
		return (-1);
	else
		return (res + tmp);
}

int	ft_convert_x(unsigned int num)
{
	return (ft_convert_x_h(num, 0, 1));
}

int	ft_convert_x2(unsigned int num)
{
	return (ft_convert_x_h(num, 0, 0));
}
