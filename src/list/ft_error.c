/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:18:27 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/08 12:59:59 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static int	ft_check_range(char *str)
{
	int		sign;
	long	result;
	int		i;

	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (-2147483648);
	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
			ft_exit();
		i++;
	}
	return (sign * (int)result);
}

static int	ft_check_num(char **c_box)
{
	int	i;
	int	j;

	i = 0;
	while (c_box[i])
	{
		j = 0;
		if (c_box[i][j] == '-')
			j++;
		while (c_box[i][j])
		{
			if (ft_isdigit(c_box[i][j]) == 0)
				return (1);
			j++;
		}
		if (c_box[i][0] == '-' && c_box[i][1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	*ft_gen_num_array(char **c_box, int *len_p)
{
	int	*num_box;
	int	i;

	i = 0;
	while (c_box[i])
		i++;
	num_box = (int *)malloc(sizeof(int) * i);
	if (!num_box)
		ft_free_box_exit(&c_box);
	i = 0;
	while (c_box[i])
	{
		num_box[i] = ft_check_range(c_box[i]);
		i++;
	}
	*len_p = i;
	return (num_box);
}

static char	**ft_gen_c_box(int argc, char **argv)
{
	int		i;
	char	**c_box;

	i = 0;
	c_box = (char **)malloc(sizeof(char *) * argc);
	if (!c_box)
		ft_exit();
	while (i < argc)
		c_box[i++] = NULL;
	i = 0;
	while (i < argc - 1)
	{
		c_box[i] = ft_strdup(argv[i + 1]);
		if (c_box[i] == NULL)
			ft_free_box_exit(&c_box);
		i++;
	}
	return (c_box);
}

int	*ft_error(int argc, char **argv, int *len_p)
{
	char	**c_box;
	int		*array;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		c_box = ft_split(argv[1], ' ');
		if (!c_box)
			ft_exit();
	}
	else
		c_box = ft_gen_c_box(argc, argv);
	if (ft_check_num(c_box) == 1)
		ft_free_box_exit(&c_box);
	array = ft_gen_num_array(c_box, len_p);
	ft_free_box(&c_box);
	if (*len_p <= 1)
		exit(0);
	if (ft_dup_check(array, *len_p) == 1)
	{
		free(array);
		ft_exit();
	}
	return (array);
}
