#include "push_swap.h"

// Corrected del function to match ft_lstclear's expected signature
void	del(void *content)
{
	(void)content;
}

// Function to add a number to the stack
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

// Function to parse a single string of numbers
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

// Function to parse multiple arguments (including strings with multiple numbers)
static void parse_multiple_args(t_stack **stack, int argc, char **argv)
{
	int i;
	char **numbers;
	long num;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			ft_error("Error: Memory allocation failed");
		int j = 0;
		while (numbers[j])
		{
			if (!is_valid_number(numbers[j]))
				ft_error("Error: Invalid number");
			num = ft_atol(numbers[j]);
			if (num < INT_MIN || num > INT_MAX)
				ft_error("Error: Number out of range");
			if (has_duplicates(*stack, (int)num))
				ft_error("Error: Duplicate number");
			add_to_stack(stack, (int)num);
			j++;
		}
		ft_free_split(numbers);
		i++;
	}
}

// Main parsing function
void parse_input(t_stack **stack, int argc, char **argv)
{
	if (argc == 2)
		parse_single_string(stack, argv[1]); // Single string input
	else
		parse_multiple_args(stack, argc, argv); // Multiple arguments
}
