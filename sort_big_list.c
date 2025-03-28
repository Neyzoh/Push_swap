/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:47:16 by adammour          #+#    #+#             */
/*   Updated: 2025/03/28 13:19:23 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_bits(t_list **a)
{
    int max;
    int max_bits;

    max = list_size(a) - 1;
    max_bits = 0;

    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void    radix_sort(t_list **a, t_list **b)
{
    //t_list *current;
    int maximum_bits;
    int sizeA;
    int sizeB;
    int i;
    int j;

    //current = *a;
    maximum_bits = max_bits(a);
    sizeA = list_size(a);
    sizeB = list_size(b);
    i = 0;
    while (i < maximum_bits)
    {
        j = 0;
        while (j < sizeA)
        {
            if (((*a)->node_idx >> i) & 1 == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        j = 0;
        while (j < sizeB)
        {
            if (((*b)->node_idx >> i) & 1 == 0)
            {    
                pa(a, b);
                sizeB--;
            }
            else
                rb(b);
            j++;
        }
        i++;
    }
    
}