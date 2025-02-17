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

void	push_bonus(t_stack **src, t_stack **dst)
{
	t_stack	*first;
	t_stack	*second;

	if (*src)
	{
		printf("here\n");
		first = *src;
		second = (*src)->next;
		ft_lstadd_front(dst, first);
		*src = second;
	}
}
