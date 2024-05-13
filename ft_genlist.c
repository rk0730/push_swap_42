/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:35:36 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/13 20:03:02 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
 * arrayに入ったint配列をt_nodeのリストに入れる
 * 次にdataをその数字が何番目に小さいかという値に置き換える
 * [詳細な説明や使用方法]
 * 問題なければt_nodeのポインタを返し、問題があればfreeして終了
 */

// //firstからnum個のt_nodeをfreeして終了する
// static void	ft_free_node(t_node *first, int num)
// {
// 	int		i;
// 	t_node	*tmp;

// 	i = 0;
// 	tmp = first;
// 	while (i < num - 1)
// 	{
// 		tmp = tmp->next;
// 		free(tmp->prev);
// 		i++;
// 	}
// 	free(tmp);
// }

// //num+1個のt_nodeを生成し、番兵ノードのポインタを返す　各t_nodeのdataにはarrayの値を入れる
// static t_node	*ft_new_list(int *array, int num)
// {
// 	int		i;
// 	t_node	*now;
// 	t_node	*tmp;
// 	t_node	*result;

// 	tmp = (t_node *)malloc(sizeof(t_node));
// 	if (!tmp)
// 		exit(1);
// 	tmp->data = array[0];
// 	result = tmp;
// 	i = 1;
// 	while (i < num)
// 	{
// 		now = (t_node *)malloc(sizeof(t_node));
// 		if (!now)
			
// 		now->data = array[i];
// 		tmp->next = now;
// 		now->prev = tmp;
// 		tmp = now;
// 		i++;
// 	}
// 	tmp->next = result;
// 	result->prev = tmp;
// 	return (result);
// }

// t_node	*ft_gen_list(int *array, int len)
// {
// 	t_node	*head;
	
// }
