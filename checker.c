#include "push_swap_bonus.h"

// Function to apply a single operation
void	apply_operations(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (!ft_strcmp(operation, "sa"))
		swap(stack_a, 'a');
	else if (!ft_strcmp(operation, "sb"))
		swap(stack_b, 'b');
	else if (!ft_strcmp(operation, "ss"))
		swap_s(stack_a, stack_b, 's');
	else if (!ft_strcmp(operation, "pa"))
		push_stack(stack_a, stack_b, 'a');
	else if (!ft_strcmp(operation, "pb"))
		push_stack(stack_b, stack_a, 'b');
	else if (!ft_strcmp(operation, "ra"))
		rotate(stack_a, 'a');
	else if (!ft_strcmp(operation, "rb"))
		rotate(stack_b, 'b');
	else if (!ft_strcmp(operation, "rr"))
		rotate_r(stack_a, stack_b, 'r');
	else if (!ft_strcmp(operation, "rra"))
		r_rotate(stack_a, 'a');
	else if (!ft_strcmp(operation, "rrb"))
		r_rotate(stack_b, 'b');
	else if (!ft_strcmp(operation, "rrr"))
		r_rotate_r(stack_a, stack_b, 'r');
	else
		ft_error("Error: Invalid operation");
}

// Function to read and apply operations from standard input
void	read_operations(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		apply_operations(stack_a, stack_b, line);
		free(line);
	}
	free(line);
}

// Main checker function
void	checker(t_stack **stack_a, t_stack **stack_b)
{
	read_operations(stack_a, stack_b);
	if (check_sort(*stack_a) && !*stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

// Main function for the bonus part
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0); // No input provided
	stack_a = NULL;
	stack_b = NULL;
	initialize_stack(&stack_a, argc, argv);
	checker(&stack_a, &stack_b);
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	return (0);
}