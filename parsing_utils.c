#include "push_swap.h"

t_list *ft_create_node(int value)
{
    t_list *node;
    //allouer de la memoire pour 1 noeud
    node = malloc(sizeof(t_list));
    if(!node)
        return(NULL);
    node->node_val = value;
    node->node_idx = 0;
    node->next = NULL;
    return (node);
}
t_list *ft_add_back(int value, t_list **head)
{
    t_list *current;
    t_list *last_node;

    current = *head;
    last_node = ft_create_node(value);
    if (*head)
    {
        while (current->next)
            current = current->next;
        current->next = last_node;
    }
    else
        *head = last_node;
    return (*head);
}
t_list *ft_create_stack(char **args)
{
    t_list *head;
    int i;

    i = 0;
    head = NULL;
    while (args[i])
    {
        head = ft_add_back(ft_atol(args[i]), &head);
        i++;
    }
    put_idx(args, &head);
    return(head);
}
void put_idx(char **tab, t_list **head)
{
    int i;
    int len;
    int *tab_int;
    t_list *current;

    current = *head;
    tab_int = copy_tab(tab);
    tab_int = sort_tab(tab_int);
    len = 0;
    while (tab[len])
        len++;
    while (current)
    {
        i = 0;
        while (i < len)
        {
            if (current->node_val == tab_int[i])
                current->node_idx = i;
            i++;
        }
        current = current->next;
    }
    free(tab_int);
}
int *copy_tab(char **tab)
{
    int i;
    int len;
    int *tab_int;

    i = 0;
    len = 0;
    while (tab[len])
        len++;
    tab_int = malloc(sizeof(int) * len);
    if(!tab_int)
        return (NULL);
    while (i < len)
    {
        tab_int[i] = ft_atol(tab[i]);
        i++;
    }
    return(tab_int);
}
int *sort_tab(int *tab)
{
    int i;
    // int j;
    int tmp;
    i = 0;
    while (tab[i + 1])
    {
        if (tab[i] > tab[i + 1])
        {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
    return(tab);
}

// int main(int ac, char **av)
// {
//     t_list *a;
//     // int i = 0;
//     // int *a;
//     // a = copy_tab(av + 1);
//     // a = sort_tab(a);
//     (void)ac;
//     a = ft_create_stack(av + 1);
//     ft_print_stack(&a);
//     // while (i < 6)
//     // {
//     //     printf("%d ", a[i]);
//     //     i++;
//     // }
// }
