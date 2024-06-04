/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:44:08 by rkitao            #+#    #+#             */
/*   Updated: 2024/06/05 03:27:47 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_choose_list(t_node **list_ab, char c, t_node **list_p, char *other)
{
	if (c == 'a')
	{
		if (list_p)
			*list_p = list_ab[0];
		if (other)
			*other = 'b';
	}
	else
	{
		if (list_p)
			*list_p = list_ab[1];
		if (other)
			*other = 'a';
	}
}

t_node	*ft_first_node(t_node *list)
{
	while (list->data != -1)
		list = list->next;
	if (list->next->data == -1)
		return (NULL);
	else
		return (list->next);
}

t_node	*ft_last_node(t_node *list)
{
	while (list->data != -1)
		list = list->next;
	if (list->prev->data == -1)
		return (NULL);
	else
		return (list->prev);
}

int	ft_getsize(t_node *list)
{
	t_node	*tmp;
	int		size;

	size = 0;
	tmp = ft_first_node(list);
	if (tmp == NULL)
		return (0);
	while (tmp->data != -1)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
