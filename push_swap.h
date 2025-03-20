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

int	ft_strncmp(const char	*s1, const char	*s2, unsigned int n);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *str);
int is_numeric(char *str);
int is_int_limit(char *str);
int is_doublon(char **str);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void ft_free_tab(char **tab);
t_list *ft_create_stack(char **args);
void    ft_print_stack(t_list **a);
void put_idx(char **tab, t_list **head);
int *sort_tab(int *tab);
int *copy_tab(char **tab);

#endif