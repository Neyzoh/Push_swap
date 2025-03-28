/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:47:16 by adammour          #+#    #+#             */
/*   Updated: 2025/03/28 16:14:53 by adammour         ###   ########.fr       */
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
    int maximum_bits;
    int sizeA;
    int sizeB;
    int i;
    int j;

    maximum_bits = max_bits(a);
    sizeA = list_size(a);
    i = 0;
    while (i < maximum_bits)
    {
        j = 0;
        while (j < sizeA)
        {
            if ((((*a)->node_idx >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        j = 0;
        sizeB = list_size(b);
        while (j < sizeB)
        {
            pa(a, b);
            j++;
        }
        i++;
    }
}
void    ft_print_stack(t_list **a)
{
    t_list *cur;

    cur = *a;
    printf("========stack\n");
    while (cur)
    {
        printf("%d ->\n", cur->node_idx);
        cur = cur->next;
    }
    printf("NULL\n");
}
int main(int ac, char **av)
{
    t_list *a;
    t_list *b;

    a = parsing(ac, av);
    b = NULL;

    printf("Liste a avant le tri : ");
    ft_print_stack(&a);
    
    radix_sort(&a, &b);

    printf("Liste a après le tri : ");
    ft_print_stack(&a);
    ft_free_list(&a);
    return (0);
}