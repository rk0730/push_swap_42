/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:18:27 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/12 20:27:39 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * プログラムに与えられた引数のエラーを処理する関数
 * [詳細な説明や使用方法]
 * 問題なければint配列を返し、問題があればfreeしてexitする
 */

#include "ft_push_swap.h"

//c_boxをatoiした時にintの範囲を超えないかどうか確認する　大丈夫であればintを返し、範囲外であればexit
static int	*ft_check_range(char *str)
{
	int		sign;
	long	result;

	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	sign = 1;
	result = 0;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str)
	{
		result += *str - '0';
		if (result > INT_MAX)
			ft_exit();
		str++;
	}
	return (sign * (int)result);
}

//c_boxに数字以外の文字がないかどうかを確認する　エラーがあれば1を返す、なければ0を返す
static int	ft_check_num(char **c_box)
{
	while (*c_box)
	{
		if (**c_box == '-')
			*c_box++;
		while (**c_box)
		{
			if (ft_isdigit(**c_box) == 0)
				return (1);
			*c_box++;
		}
		c_box++;
	}
}

//c_boxからnum_boxを生成する
static int	**ft_gen_num_box(char **c_box)
{
	int	**num_box;
	int	i;
	int	len;

	len = 0;
	while (c_box[len])
		len++;
	num_box = (int **)malloc(sizeof(int) * (len + 1));
	if (!num_box)
		ft_free_box_exit(&c_box);
	i = 0;
	while (c_box[i])
	{
		num_box[i] = ft_check_range(c_box[i]);
		i++;
	}
	num_box[i] = NULL;
	return (num_box);
}

static char	**ft_gen_c_box(int argc, char **argv)
{
	int		i;
	char	**c_box;

	i = 0;
	c_box = (char **)malloc(sizeof(char *) * argc);
	if (!c_box)
		ft_free_box_exit(&c_box);
	while (i < argc - 1)
	{
		c_box[i] = argv[i + 1];
		i++;
	}
	c_box[argc - 1] = NULL;
	return (c_box);
}

int	*ft_error(int argc, char **argv)
{
	char	**c_box;
	char	**num_box;

	if (argc == 1)
		return (NULL);
	if (argc == 2)
	{
		c_box = ft_split(argv[1], ' ');
		if (!c_box)
			ft_free_box_exit(&c_box);
	}
	else
		c_box = ft_gen_c_box(argc, argv);
	num_box = ft_gen_num_box(c_box);
}
