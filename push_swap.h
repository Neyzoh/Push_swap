#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//#include "Libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
int	ft_strncmp(const char	*s1, const char	*s2, unsigned int n);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *str);
int is_numeric(char *str);
int is_int_limit(char *str);
int is_doublon(char **str);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void ft_free_tab(char **tab);
#endif