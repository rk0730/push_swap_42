/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:41:59 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/04 17:58:22 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "list/ft_list.h"

void	ft_choose_list(t_node **list_ab, char c, t_node **list_p, char *other);
int		ft_is_sorted(t_node **list_ab, char c, int index, int num);
char	*ft_order(t_node *list, int index, int num);
void	ft_sort_2(t_node **list_ab, char c);
void	ft_sort_3(t_node **list_ab, char c);
void	ft_sort_mini(t_node **list_ab, char c, int size);


int		ft_get_min(t_node **list_ab, char c, char *str, int size);
// int	ft_get_max(t_node **list_ab, char c, char *str, int size);

void	ft_top_a(t_node **list_ab, int size);
void	ft_bottom_a(t_node **list_ab, int size);
void	ft_top_b(t_node **list_ab, int size);
void	ft_bottom_b(t_node **list_ab, int size);

void	ft_print_list(t_node **list_ab);




#endif
