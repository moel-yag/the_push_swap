/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:50:12 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:50:13 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	t_min(t_stack *stack)
{
	t_stack	*tmp;
	int			min;
	int			i;
	int			index;

	if (stack)
	{
		min = stack->content;
		tmp = stack->next;
		index = 0;
		i = 1;
		while (tmp)
		{
			if (tmp->content < min)
			{
				index = i;
				min = tmp->content;
			}
			i++;
			tmp = tmp->next;
		}
		return (index);
	}
	return (-1);
}

static int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
	}
	return (1);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int			min;

	if (!is_sorted(stack_a))
	{
		tmp = *stack_a;
		min = t_min(tmp);
		if (min == 1)
			swap(stack_a, 'a');
		else if (min == 2)
		{
			rrotate(stack_a, 'a');
			rrotate(stack_a, 'a');
		}
		else if (min == 3)
			rrotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
		sort_three(stack_a);
		push(stack_b, stack_a, 'a');
	}
}
