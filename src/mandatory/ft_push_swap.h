/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:41:59 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/05 01:06:56 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../list/ft_list.h"

void	ft_choose_list(t_node **list_ab, char c, t_node **list_p, char *other);
int		ft_is_sorted(t_node **list_ab, char c, int index, int num);
char	*ft_order(t_node *list, int index, int num);
void	ft_sort_2(t_node **list_ab, char c);
void	ft_sort_3(t_node **list_ab, char c);
void	ft_sort3_h1(t_node *list, char c, char *str);
void	ft_sort3_h2(t_node *list, char c, char *str);
void	ft_sort3_h3(t_node *list, char c, char *str);
void	ft_sort3_h4(t_node *list, char c, char *str);

void	ft_sort_mini(t_node **list_ab, char c, int size);
void	ft_swap_write(t_node **list_ab, char c);
void	ft_push_write(t_node **list_ab, char c);
void	ft_rotate_write(t_node **list_ab, char c);
void	ft_reverse_rotate_write(t_node **list_ab, char c);


int		ft_get_min(t_node **list_ab, char c, char *str, int size);
void	ft_bottom_to_top(t_node **list_ab, char c, int size);

void	ft_top_a(t_node **list_ab, int size);
void	ft_bottom_a(t_node **list_ab, int size);
void	ft_top_b(t_node **list_ab, int size);
void	ft_bottom_b(t_node **list_ab, int size);

void	ft_print_list(t_node **list_ab);




#endif
