/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:30:07 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/16 18:30:09 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../push_swap.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdbool.h>
# include <signal.h>

int		apply_moves(t_stack **stack_a, t_stack **stack_b, char *operation);
void	checker(t_stack **stack_a, t_stack **stack_b);
void	read_moves(t_stack **stack_a, t_stack **stack_b);
void	del(int content);
void	push_bonus(t_stack **src, t_stack **dst);
void	rotate_bonus(t_stack **stack, char c);
void	rotate_r_bonus(t_stack **stack_a, t_stack **stack_b, char c);
void	rrotate_bonus(t_stack **stack, char c);
void	rrotate_r_bonus(t_stack **stack_a, t_stack **stack_b, char c);
void	swap_bonus(t_stack **stack);
void	swap_s_bonus(t_stack **stack_a, t_stack **stack_b);

#endif
