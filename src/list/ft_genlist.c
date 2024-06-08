/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:35:36 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/08 13:00:19 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_node	*ft_new_list(int *array, int num)
{
	int		i;
	t_node	*now;
	t_node	*tmp;
	t_node	*result;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		ft_malloc_exit();
	tmp->data = -1;
	result = tmp;
	i = 0;
	while (i < num)
	{
		now = (t_node *)malloc(sizeof(t_node));
		if (!now)
			ft_malloc_exit();
		now->data = array[i];
		tmp->next = now;
		now->prev = tmp;
		tmp = now;
		i++;
	}
	tmp->next = result;
	result->prev = tmp;
	return (result);
}

static void	ft_sort_array(int *array, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*ft_gen_sort_array(int *array, int len)
{
	int	*sort_array;
	int	i;

	sort_array = (int *)malloc(sizeof(int) * len);
	if (!sort_array)
		ft_malloc_exit();
	i = 0;
	while (i < len)
	{
		sort_array[i] = array[i];
		i++;
	}
	ft_sort_array(sort_array, len);
	return (sort_array);
}

static int	*ft_gen_id_array(int *array, int len)
{
	int	*id_array;
	int	*sort_array;
	int	i;
	int	j;

	id_array = (int *)malloc(sizeof(int) * len);
	if (!id_array)
		ft_malloc_exit();
	sort_array = ft_gen_sort_array(array, len);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (array[i] == sort_array[j])
				id_array[i] = j;
			j++;
		}
		i++;
	}
	free(sort_array);
	return (id_array);
}

t_node	**ft_gen_list(int **array_p, int len)
{
	int		*id_array;
	t_node	*list_a;
	t_node	*list_b;
	t_node	**list_ab;

	id_array = ft_gen_id_array(*array_p, len);
	list_ab = (t_node **)malloc(sizeof(t_node *) * 2);
	free(*array_p);
	list_a = ft_new_list(id_array, len);
	free(id_array);
	list_b = ft_new_list(NULL, 0);
	list_ab[0] = list_a;
	list_ab[1] = list_b;
	return (list_ab);
}
