/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:48:57 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/09 16:48:59 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	give_index_to_node(t_stack **stack)
// {
// 	t_stack		*tmp;
// 	int			index;
// 	int			len;
// 	int			*tab;

// 	if (!*stack)
// 		return ;
// 	len = ft_lstsize(*stack);
// 	tab = (int *)malloc(sizeof(int) * len);
// 	if (!tab)
// 		return ;
// 	tmp = *stack;
// 	initialize_tab(tmp, len, tab);
// 	sort_tab(tab, len);
// 	index = 0;
// 	while (tmp)
// 	{
// 		while (index < len)
// 		{
// 			if (tmp->content == tab[index])
//             {
//                 tmp->index = index;
//                 break ;
//             }
//             index++;
// 		}
// 		tmp = tmp->next;
// 	}
// }
