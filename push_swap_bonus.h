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

# include "push_swap.h"
# include "get_next_line/get_next_line.h"
# include <stdbool.h>
# include "libft/libft.h"

// Function prototypes
void	apply_moves(t_stack **stack_a, t_stack **stack_b, char *operation);
void	checker(t_stack **stack_a, t_stack **stack_b);
void	read_moves(t_stack **stack_a, t_stack **stack_b);
void	del(int content);

#endif
