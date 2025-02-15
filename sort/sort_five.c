/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:50:23 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:50:24 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	stack_min(t_stack *stack)
{
	t_stack	*tmp;
	int			i;
	int			index;
	int			min;

	if (stack)
	{
		min = stack->content;
		tmp = stack->next;
		index = 0;
		i = 1;
		while (tmp)
		{
			if (min > tmp->content)
			{
				index = i;
				min = tmp->content;
			}
			i++;
			tmp = tmp->next;
		}
		return (index);
	}
	return (4);
}

static int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int			min;

	tmp = *stack_a;
	min = stack_min(tmp);
	if (!is_sorted(*stack_a))
	{
		if (min == 1)
			swap(stack_a, 'a');
		else if (min == 2)
		{
			rotate(stack_a, 'a');
			rotate(stack_a, 'a');
		}
		else if (min == 3)
		{
			rrotate(stack_a, 'a');
			rrotate(stack_a, 'a');
		}
		else if (min == 4)
			rrotate(stack_a, 'a');
		push(stack_a, stack_b, 'a');
		sort_four(stack_a, stack_b);
		push(stack_b, stack_a, 'b');
	}
}
