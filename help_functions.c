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

char    **ft_split_args(int argc, char **argv)
{
    int     i;
    char    **result;

    result = malloc(sizeof(char *) * argc);
    if (!result)
        return (NULL);
    i = 1;
    while (i < argc)
    {
        result[i - 1] = strdup(argv[i]);
        if (!result[i - 1])
        {
            while (--i)
                free(result[i - 1]);
            free(result);
            return (NULL);
        }
        i++;
    }
    result[argc - 1] = NULL;
    return (result);
}
