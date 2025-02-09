/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:49:35 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:49:36 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_lstsize(*stack) > 1)
	{
		first = *stack;
		second = (*stack)->next;
		*stack = (*stack)->next->next;
		ft_lstadd_front(stack, first);
		ft_lstadd_front(stack, second);
		if (c == 'a')
			write(1, "sa", 3);
		else if (c == 'b')
			write(1, "sb", 3);
	}
}

void	swap_s(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		swap(stack_a, 'c');
		swap(stack_b, 'c');
		if (c == 's')
			write(1, "ss\n", 3);
	}
}
