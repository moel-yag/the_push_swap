/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:50:03 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:50:04 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	stack_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	min = stack->content;
	if (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (min > tmp->content)
				min = tmp->content;
			tmp = tmp->next;
		}
	}
	return (min);
}

static int	stack_max(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	max = stack->content;
	if (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (max < tmp->content)
				max = tmp->content;
			tmp = tmp->next;
		}
	}
	return (max);
}

void	sort_three(t_stack **stack_a)
{
	int	min;
	int	max;

	min = stack_min(*stack_a);
	max = stack_max(*stack_a);
	if (ft_lstsize(*stack_a) < 3 && !is_sorted(*stack_a))
	{
		swap(stack_a, 'a');
		return ;
	}
	while (!is_sorted(*stack_a))
	{
		if (max == (*stack_a)->content)
			rotate(stack_a, 'a');
		if (min == (*stack_a)->next->content)
			swap(stack_a, 'a');
		if (max == (*stack_a)->next->content)
			rrotate(stack_a, 'a');
	}
}
