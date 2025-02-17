/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:50:34 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:50:35 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_index(t_stack *stack_a, int value)
{
	int	index;

	index = 0;
	while (stack_a)
	{
		if (stack_a->content == value)
			return (index);
		index++;
		stack_a = stack_a->next;
	}
	return (-1);
}

static int	get_index_value(t_stack *stack_b, int index)
{
	int	val;

	val = 0;
	while (stack_b)
	{
		if (stack_b->index == index)
		{
			val = stack_b->content;
			break ;
		}
		stack_b = stack_b->next;
	}
	return (val);
}

static void	send_to_b(t_stack **stack_a, t_stack **stack_b, int flag)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b', 1);
			i++;
		}
		else if ((*stack_a)->index <= (i + flag))
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a', 1);
	}
}

static void	back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	stack_index;
	int	value;

	max_index = ft_lstsize(*stack_b) - 1;
	while (*stack_b)
	{
		value = get_index_value(*stack_b, max_index);
		stack_index = find_index(*stack_b, value);
		while ((*stack_b)->content != value)
		{
			if (stack_index <= ft_lstsize(*stack_b) / 2)
				rotate(stack_b, 'b', 1);
			else
				rrotate(stack_b, 'b', 1);
		}
		if ((*stack_b)->content == value)
		{
			push(stack_b, stack_a, 'a');
			max_index--;
		}
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int flag)
{
	send_to_b(stack_a, stack_b, flag);
	back_to_a(stack_a, stack_b);
}
