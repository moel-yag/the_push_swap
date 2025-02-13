/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:44:44 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/13 11:44:46 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del(void *content)
{
	(void)content;
}

static void add_to_stack(t_stack **stack, int num)
{
	t_stack *new_node;

	new_node = ft_lstnew(num);
	if (!new_node)
	{
		ft_lstclear(stack, del);
		ft_error("Error: Memory allocation failed");
	}
	ft_lstadd_back(stack, new_node);
}

static void parse_single_string(t_stack **stack, char *str)
{
	char **numbers;
	int i;
	long num;

	numbers = ft_split(str, ' ');
	if (!numbers)
		ft_error("Error: Memory allocation failed");
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
			ft_error("Error: Invalid number");
		num = ft_atol(numbers[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error("Error: Number out of range");
		if (has_duplicates(*stack, (int)num))
			ft_error("Error: Duplicate number");
		add_to_stack(stack, (int)num);
		i++;
	}
	ft_free_split(numbers);
}

static void parse_multiple_args(t_stack **stack, int argc, char **argv)
{
	int i;
	long num;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			ft_error("Error: Invalid number");
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error("Error: Number out of range");
		if (has_duplicates(*stack, (int)num))
			ft_error("Error: Duplicate number");
		add_to_stack(stack, (int)num);
		i++;
	}
}

void parse_input(t_stack **stack, int argc, char **argv)
{
	if (argc == 2)
		parse_single_string(stack, argv[1]);
	else
		parse_multiple_args(stack, argc, argv);
}
