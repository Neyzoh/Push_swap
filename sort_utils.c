/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:51:38 by adammour          #+#    #+#             */
/*   Updated: 2025/03/28 11:20:03 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int list_size(t_list **a)
{
    t_list *current;
    int size;

    current = *a;
    size = 0;
    while (current)
    {
        current = current->next;
        size++;
    }
    return (size);
}

int is_sorted(t_list **a)
{
    t_list *current;
    
    current = *a;
    while (current->next)
    {
        if (current->node_val < current->next->node_val)
            return (0);
        current = current->next;
    }
    return (1);
}