/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:40:47 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/05 03:28:05 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "../../libft/libft.h"
# include "../../ft_printf/ft_printf.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// #include <fcntl.h>
#include <limits.h>

typedef	struct s_node {
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

void	ft_free_node(t_node *list);
void	ft_free_box_exit(char ***c_box_p);
void	ft_free_box(char ***box_p);
void	ft_exit(void);
void	ft_malloc_exit(void);
int		*ft_error(int argc, char **argv, int *len_p);
int		ft_dup_check(int *array, int num);
t_node	**ft_gen_list(int **array_p, int len);
void	ft_choose_list(t_node **list_ab, char c, t_node **list_p, char *other);
t_node	*ft_first_node(t_node *list);
t_node	*ft_last_node(t_node *list);
int		ft_getsize(t_node *list);
// void	ft_swap_a(t_node **list_ab);
// void	ft_swap_b(t_node **list_ab);
// void	ft_push_a(t_node **list_ab);
// void	ft_push_b(t_node **list_ab);
void	ft_swap(t_node **list_ab, char c);
void	ft_ss(t_node **list_ab);
void	ft_push(t_node **list_ab, char c);
void	ft_rotate(t_node **list_ab, char c);
// void	ft_rotate_b(t_node **list_ab);
void	ft_rr(t_node **list_ab);
void	ft_reverse_rotate(t_node **list_ab, char c);
// void	ft_reverse_rotate_b(t_node **list_ab);
void	ft_rrr(t_node **list_ab);





#endif
