/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:54:35 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/08 12:06:11 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_c(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_convert_s(char *str)
{
	int	tmp;
	int	res;

	tmp = 0;
	res = 0;
	if (str == NULL)
	{
		if (write(STDOUT_FILENO, "(null)", 6) == -1)
			return (-1);
		else
			return (6);
	}
	while (tmp != -1 && *str)
	{
		tmp = write(STDOUT_FILENO, str, 1);
		if (tmp == -1)
			return (-1);
		else
			res += tmp;
		str++;
	}
	return (res);
}
