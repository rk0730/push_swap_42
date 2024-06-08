/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:47:33 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/08 13:03:34 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static int	ft_help1(t_node **list_ab, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_swap(list_ab, 'a');
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_swap(list_ab, 'b');
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss(list_ab);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_push(list_ab, 'a');
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_push(list_ab, 'b');
	else
		return (0);
	return (1);
}

static int	ft_help2(t_node **list_ab, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_rotate(list_ab, 'a');
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rotate(list_ab, 'b');
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rr(list_ab);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		ft_reverse_rotate(list_ab, 'a');
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_reverse_rotate(list_ab, 'b');
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_rrr(list_ab);
	else
		return (0);
	return (1);
}

void	ft_sort_by_input(t_node **list_ab)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL || ft_strlen(line) == 0)
			break ;
		if (ft_help1(list_ab, line) == 0 && ft_help2(list_ab, line) == 0)
			ft_exit();
		free(line);
	}
}

int	ft_is_finished(t_node *list_a, int num)
{
	if (num != ft_getsize(list_a))
		return (0);
	list_a = ft_first_node(list_a);
	while (num-- - 1 > 0)
	{
		if (list_a->data > list_a->next->data)
			return (0);
		list_a = list_a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		len;
	int		*array;
	t_node	**list_ab;

	array = ft_error(argc, argv, &len);
	list_ab = ft_gen_list(&array, len);
	ft_sort_by_input(list_ab);
	if (ft_getsize(list_ab[1]) == 0 && ft_is_finished(list_ab[0], len))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_node(list_ab[0]);
	ft_free_node(list_ab[1]);
	free(list_ab);
	return (0);
}
