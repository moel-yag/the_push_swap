/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:56:02 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/13 12:02:14 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	is_valid_number(char *str)
{
  int i;

  i = 0;
  if (str[i] == '-' || str[i] == '+')
	i++;
  if (!str[i])
	return (0);
  while (str[i])
  {
	if (!ft_isdigit(str[i]))
	  return (0);
	i++;
  }
  return (1);
}

int	has_duplicates(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
