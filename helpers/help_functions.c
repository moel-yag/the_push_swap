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

#include "../push_swap.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		s[i++] = NULL;
	}
	free(s);
	s = NULL;
}

void	check_dup(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	if (numbers[i])
	{
		while (numbers[i])
		{
			j = i + 1;
			while (numbers[j])
			{
				if (ft_atoi(numbers[j]) == ft_atoi(numbers[i]))
				{
					write(2, "Error\n", 6);
					ft_free(numbers[j]);
					exit(1);
				}
				j++;
			}
			i++;
		}
	}
}

static char	remove_tab(char *str)
{
	char    *temp;
    int        i;

    i = 0;
    while (str[i] && str[i]!= '\t')
        i++;
    temp = ft_substr(str, i, ft_strlen(str) - i);
    free(str);
    return (*temp);
}

