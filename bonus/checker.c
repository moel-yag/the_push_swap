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

int	apply_moves(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (!ft_strncmp(operation, "sa\n"))
		swap_bonus(stack_a);
	else if (!ft_strncmp(operation, "sb\n"))
		swap_bonus(stack_b);
	else if (!ft_strncmp(operation, "ss\n"))
		swap_s_bonus(stack_a, stack_b);
	else if (!ft_strncmp(operation, "pa\n"))
		push_bonus(stack_b, stack_a);
	else if (!ft_strncmp(operation, "pb\n"))
		push_bonus(stack_a, stack_b);
	else if (!ft_strncmp(operation, "ra\n"))
		rotate_bonus(stack_a, 'a');
	else if (!ft_strncmp(operation, "rb\n"))
		rotate_bonus(stack_b, 'b');
	else if (!ft_strncmp(operation, "rr\n"))
		rotate_r_bonus(stack_a, stack_b, 'r');
	else if (!ft_strncmp(operation, "rra\n"))
		rrotate_bonus(stack_a, 'a');
	else if (!ft_strncmp(operation, "rrb\n"))
		rrotate_bonus(stack_b, 'b');
	else if (!ft_strncmp(operation, "rrr\n"))
		rrotate_r_bonus(stack_a, stack_b, 'r');
	else
		return (0);
	return (1);
}

void	read_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	signal(SIGINT, SIG_IGN);
	line = get_next_line(0);
	while (line)
	{
		if (!apply_moves(stack_a, stack_b, line))
		{
			ft_lstclear(stack_a, del);
			ft_lstclear(stack_b, del);
			ft_error("Error", line);
		}
		free(line);
		line = get_next_line(0);
	}
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	read_moves(stack_a, stack_b);
	if (is_sorted(*stack_a) && !(*stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;
	int		i;

	if (argc < 2)
		return (0);
	str = NULL;
	i = 0;
	while (i < argc)
	{
		str = ft_strtrim(argv[i], " ");
		if (*argv[i] == '\0' || (str[0] == '\0'))
			ft_error("Error", str);
		free(str);
		i++;
	}
	stack_a = NULL;
	stack_b = NULL;
	initialize_stack(&stack_a, argc, argv);
	checker(&stack_a, &stack_b);
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	return (0);
}
