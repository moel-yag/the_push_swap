/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:30:42 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/16 18:30:44 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	initialize_stack(t_stack **stack_a, int argc, char **argv)
{
	parse_input(stack_a, argc, argv);
	if (!*stack_a)
		ft_error("Error", NULL);
}

void	apply_moves(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		swap(stack_a, 'a');
	else if (!ft_strncmp(operation, "sb\n", 3))
		swap(stack_b, 'b');
	else if (!ft_strncmp(operation, "ss\n", 3))
		swap_s(stack_a, stack_b, 's');
	else if (!ft_strncmp(operation, "pa\n", 3))
		push(stack_a, stack_b, 'a');
	else if (!ft_strncmp(operation, "pb\n", 3))
		push(stack_b, stack_a, 'b');
	else if (!ft_strncmp(operation, "ra\n", 3))
		rotate(stack_a, 'a');
	else if (!ft_strncmp(operation, "rb\n", 3))
		rotate(stack_b, 'b');
	else if (!ft_strncmp(operation, "rr\n", 3))
		rotate_r(stack_a, stack_b, 'r');
	else if (!ft_strncmp(operation, "rra\n", 4))
		rrotate(stack_a, 'a');
	else if (!ft_strncmp(operation, "rrb\n", 4))
		rrotate(stack_b, 'b');
	else if (!ft_strncmp(operation, "rrr\n", 4))
		rrotate_r(stack_a, stack_b, 'r');
	else
		ft_error("Error\n", operation);
}

void	read_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line) // Corrected loop condition
	{
		apply_moves(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	read_moves(stack_a, stack_b);
	if (is_sorted(*stack_a) && !(*stack_b)) // Fixed condition
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
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
	checker(&stack_a, &stack_b);
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	return (0);
}
