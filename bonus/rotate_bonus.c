/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:49:23 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:49:25 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_bonus(t_stack **stack, char c)
{
	t_stack	*top;
	t_stack	*last;

	(void)c;
	top = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		*stack = (*stack)->next;
		last = *stack;
		top->next = NULL;
		while (last->next)
			last = last->next;
		last->next = top;
	}
}

void	rotate_r_bonus(t_stack **stack_a, t_stack **stack_b, char c)
{
	(void)c;
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		rotate_bonus(stack_a, 'a');
		rotate_bonus(stack_b, 'b');
	}
}

void	rrotate_bonus(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*tmp;
	int		i;

	(void)c;
	if (ft_lstsize(*stack) > 1)
	{
		last = ft_lstlast(*stack);
		tmp = *stack;
		i = 1;
		while (i < ft_lstsize(*stack) - 1)
		{
			tmp = tmp->next;
			i++;
		}
		tmp->next = NULL;
		ft_lstadd_front(stack, last);
	}
}

void	rrotate_r_bonus(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		rrotate_bonus(stack_a, c);
		rrotate_bonus(stack_b, c);
	}
}
