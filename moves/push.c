/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:49:12 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:49:13 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **src, t_stack **dst, char c)
{
	t_stack	*first;
	t_stack	*second;

	if (*src)
	{
		first = *src;
		second = (*src)->next;
		ft_lstadd_front(dst, first);
		*src = second;
		if (c == 'a')
			write(1, "pa\n", 3);
		else if (c == 'b')
			write(1, "pa\n", 3);
	}
}
