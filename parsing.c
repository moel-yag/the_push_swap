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

void	del(int content)
{
	(void)content;
}

static void	add_to_stack(t_stack **stack, int num)
{
	t_stack	*new_node;

	new_node = ft_lstnew(num);
	if (!new_node)
	{
		ft_lstclear(stack, del);
		ft_error("Error", NULL);
	}
	ft_lstadd_back(stack, new_node);
}

static void	parse_single_string(t_stack **stack, char *str)
{
	char	**numbers;
	int		i;
	long	num;

	numbers = ft_split(str, ' ');
	if (!numbers)
		ft_error("Error", NULL);
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
			ft_exit(stack, numbers);
		num = ft_atol(numbers[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_exit(stack, numbers);
		if (has_duplicates(*stack, (int)num))
			ft_exit(stack, numbers);
		add_to_stack(stack, (int)num);
		i++;
	}
	ft_free_split(numbers);
}

static void	parse_multiple_args(t_stack **stack, int argc, char **argv, int i)
{
	int		j;
	char	**numbers;
	long	num;

	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			ft_error("Error", NULL);
		j = 0;
		while (numbers[j])
		{
			if (!is_valid_number(numbers[j]))
				ft_exit(stack, numbers);
			num = ft_atol(numbers[j]);
			if (num < INT_MIN || num > INT_MAX)
				ft_exit(stack, numbers);
			if (has_duplicates(*stack, (int)num))
				ft_exit(stack, numbers);
			add_to_stack(stack, (int)num);
			j++;
		}
		ft_free_split(numbers);
		i++;
	}
}

void	parse_input(t_stack **stack, int argc, char **argv)
{
	if (argc == 2)
		parse_single_string(stack, argv[1]);
	else
		parse_multiple_args(stack, argc, argv, 1);
}
