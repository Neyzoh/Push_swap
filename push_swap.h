#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//#include "Libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    int node_val;
    int node_idx;
 // int binary_val;
    struct s_list *next;
}               t_list;

// fonctions creation de la pile + parsing 
t_list *ft_create_node(int value);
t_list *ft_add_back(int value, t_list **head);
t_list *ft_create_stack(char **args);
void put_idx(char **tab, t_list **head);
t_list *ft_create_stack(char **args);
void    ft_print_stack(t_list **a);
int *sort_tab(int *tab);
int *copy_tab(char **tab);

// Libft
int	ft_strncmp(const char	*s1, const char	*s2, unsigned int n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
long	ft_atol(const char *str);

// Check
int is_numeric(char *str);
int is_int_limit(char *str);
int is_doublon(char **str);
void ft_free_tab(char **tab);

#endif