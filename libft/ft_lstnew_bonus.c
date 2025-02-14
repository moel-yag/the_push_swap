/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:58:19 by moel-yag          #+#    #+#             */
/*   Updated: 2025/02/08 11:01:42 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	// new_node = (t_stack *)malloc(sizeof(t_stack));
	// if (!new_node)
	// 	return (NULL);
	new_node = NULL;
	new_node->content = content;
	new_node->next = NULL;
	new_node->index = 0;
	return (new_node);
}
