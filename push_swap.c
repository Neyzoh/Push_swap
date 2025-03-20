#include "push_swap.h"

voidindex_stack(t_stack *stack)
{
    int index;
    t_node *current;
    t_node *cmp;

if (!stack || !stack->start)
return;

current = stack->start;
while (current)
{
    index = 0;
    cmp = stack->start;
    while (cmp)
    {
        if (current->value > cmp->value)
            index++;
        cmp = cmp->next;
    }
    current->index = index;
    current = current->next;
    }
}

intcount_bits(int size)
{
intmax_bits;

max_bits = 0;
while ((size >> max_bits) != 0)
max_bits++;
return (max_bits);
}

voidradix_sort(t_stack *stack_a, t_stack *stack_b)
{
inti;
intj;
intsize;
intmax_bits;

i = 0;
size = stack_a->size;
max_bits = count_bits((size - 1));

index_stack(stack_a);
while (i < max_bits)
{
j = 0;
while (j < size)
{
if (((stack_a->start->index >> i) & 1) == 1)
ra(stack_a);
else
pb(stack_a, stack_b);
j++;
}
while (stack_b->size > 0)
pa(stack_a, stack_b);
i++;
}
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

int main(int ac, char **av)
{
    
}