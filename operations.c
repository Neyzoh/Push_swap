#include "push_swap.h"

void    sa(t_list **a)
{
    t_list *tmp = (*a)->next;
    (*a) = tmp->next;
    tmp->next = *a;
}
void    sb(t_list **b)
{
    t_list *tmp = (*b)->next;
    (*b) = tmp->next;
    tmp->next = *b;
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

void    pb(t_list **b, t_list **a)
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

    second_last = NULL;
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

    second_last = NULL;
    last->next = *b;
    *b = last;
}

void    rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}