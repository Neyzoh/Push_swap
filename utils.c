/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:49:59 by adammour          #+#    #+#             */
/*   Updated: 2025/03/13 16:38:56 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int	i;
	int	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int is_numeric(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int is_int_limit(char *str)
{
    if (!(ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX))
        return (0);
    return (1);
}

int is_doublon(char **str)
{
    int i;
    int j;
    int len;

    i = 0;
    len = 0;
    while (str[i])
    {
        j = i + 1; 
        while (str[j])
        {
            if (ft_strlen(str[i]) > ft_strlen(str[j]))
                len = ft_strlen(str[i]);
            else
                len = ft_strlen(str[j]);
            if (!(ft_strncmp(str[i], str[j], len)))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
void ft_free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    ft_print_stack(t_list **a)
{
    t_list *cur;

    cur = *a;
    while (cur)
    {
        printf("node_val : %d\nnode_idx : %d\n\n", cur->node_val, cur->node_idx);
        cur = cur->next;
    }
}
// int main(int ac, char **av)
// {
//     (void)ac;
//     printf("%d", is_doublon(av));
// }