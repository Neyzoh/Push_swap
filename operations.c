#include "push_swap.h"

// void    sa(t_list **a)
// {
//     t_list *tmp = (*a)->next;
//     tmp->next = *a;
//     tmp->next = *a;
// }

void    sa(t_list **a)
{
    if (*a == NULL || (*a)->next == NULL)
        return; 

    t_list *first_node = *a;
    t_list *second_node = (*a)->next;
    t_list *third_node = second_node->next;

    second_node->next = first_node;
    first_node->next = third_node;
    *a = second_node;
}

void    sb(t_list **b)
{
    if (*b == NULL || (*b)->next == NULL)
        return ;

    t_list *first_node = *b;
    t_list *second_node = (*b)->next;
    t_list *third_node = second_node->next;

    second_node->next = first_node;
    first_node->next = third_node;
    *b = second_node;
    
}

void    ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
}

void    pa(t_list **a, t_list **b)
{
    if (*b == NULL)
        return;

    t_list *tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
}

void    pb(t_list **a, t_list **b)
{
    if (*a == NULL)
        return;
    
    t_list *tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
}

void    ra(t_list **a)
{
    t_list *first = *a;
    *a = (*a)->next;
    t_list *last = *a;

    while(last->next != NULL)
        last = last->next;
    
    last->next = first;
    first->next = NULL; // Met à jour le pointeur 
}

void    rb(t_list **b)
{
    if (*b == NULL || (*b)->next == NULL)
        return ;
    
    t_list *first = *b;
    *b = (*b)->next;
    t_list *last = *b;

    while(last->next != NULL)
        last = last->next;

    last->next = first;
    first->next = NULL;
}

void    rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}

void    rra(t_list **a)
{
    t_list *last = *a;
    t_list *second_last = NULL;

    while(last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *a;
    *a = last;
}
void    rrb(t_list **b)
{
    if (*b == NULL || (*b)->next == NULL)
        return ;

    t_list *last = *b;
    t_list *second_last = NULL;

    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *b;
    *b = last;
}

void    rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}

// int main(int ac, char **av)
// {
//     t_list *a;
//     //t_list *b;

//     a = parsing(ac, av);
//     //b = NULL;

//     ft_print_stack(&a);
//     rra(&a);
//     ft_print_stack(&a);
//     return 0;
// }