/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:17:35 by rkitao            #+#    #+#             */
/*   Updated: 2024/05/13 20:21:24 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// #include <fcntl.h>
#include <limits.h>

// typedef	struct s_node {
// 	int		data;
// 	t_node	*next;
// 	t_node	*prev;
// } t_node;

void	ft_free_box_exit(char ***c_box_p);
void	ft_free_box(char ***box_p);
void	ft_exit(void);
int		*ft_error(int argc, char **argv, int *len_p);
int		ft_dup_check(int *array, int num);




#endif
