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

void	rotate(t_stack **stack, char c, int flag)
{
	t_stack	*top;
	t_stack	*last;

	top = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		*stack = (*stack)->next;
		last = *stack;
		top->next = NULL;
		while (last->next)
			last = last->next;
		last->next = top;
		if (c == 'a' && flag == 1)
			write(1, "ra\n", 3);
		else if (c == 'b' && flag == 1)
			write(1, "rb\n", 3);
	}
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		rotate(stack_a, 'a', 0);
		rotate(stack_b, 'b', 0);
		if (c == 'r')
			write(1, "rr\n", 3);
	}
}

void	rrotate(t_stack **stack, char c, int flag)
{
	t_stack	*last;
	t_stack	*tmp;
	int		i;

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
		if (c == 'a' && flag == 1)
			write(1, "rra\n", 4);
		else if (c == 'b' && flag == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrotate_r(t_stack **stack_a, t_stack **stack_b, char c)
{
	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		rrotate(stack_a, c, 0);
		rrotate(stack_b, c, 0);
	}
	if (c == 'r')
		write(1, "rrr\n", 4);
}
