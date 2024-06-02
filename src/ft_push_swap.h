/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:41:59 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/06/02 20:30:58 by rkitao           ###   ########.fr       */
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



#endif
