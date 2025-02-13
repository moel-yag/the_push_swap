/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:48:16 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:48:19 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to initialize Stack A with parsed input
static void	initialize_stack(t_stack **stack_a, int argc, char **argv)
{
	parse_input(stack_a, argc, argv);
	if (!*stack_a)
		ft_error("Error: Stack initialization failed");
}

static void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap(stack_a, 'a');
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		sort_stack(stack_a, stack_b, size / 2);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	initialize_stack(&stack_a, argc, argv);
	if (check_sort(stack_a))
		sort_list(&stack_a, &stack_b);
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	return (0);
}
