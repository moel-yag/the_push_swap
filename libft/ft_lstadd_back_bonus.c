/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:22:21 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/08 11:04:04 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!lst || !new)
		return ;
	new->index = 0;
	current = *lst;
	if (!current)
		*lst = new;
	else
	{
		while (current->next)
		{
			if (new->content > current->content)
				new->index++;
			else
				current->index++;
			current = current->next;
		}
		current->next = new;
		if (new->content > current->content)
			new->index++;
		else
			current->index++;
	}
}
