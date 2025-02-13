/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:48:36 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:48:41 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "library/libft/libft.h"

void	push(t_stack **src, t_stack **dst, char c);
void	swap(t_stack **stack, char c);
void	swap_s(t_stack **stack_a, t_stack **stack_b, char c);
void	rotate(t_stack **stack, char c);
void	rotate_r(t_stack **stack_a, t_stack **stack_b, char c);
void	rrotate(t_stack **stack, char c);
void	rrotate_r(t_stack **stack_a, t_stack **stack_b, char c);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int flag);
void	ft_free(char **s);
void	parse_input(t_stack **stack, int argc, char **argv);
long	ft_atol(const char *str);
void	ft_error(char *msg);
void	ft_free_split(char **split);

#endif
