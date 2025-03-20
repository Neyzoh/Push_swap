/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:58:07 by adammour          #+#    #+#             */
/*   Updated: 2025/03/13 14:45:46 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			break ;
		i++;
	}
	if (str[i] == (char) c)
		return ((char *) str + i);
	return (NULL);
}
char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
int	ft_strncmp(const char	*s1, const char	*s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (c1[i] && c2[i] && c1[i] == c2[i] && i < n - 1)
		i++;
	return (c1[i] - c2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}
static int	count_lettre(char const *s, int c)
{
	int	len_lettre;

	if (!ft_strchr(s, c))
		len_lettre = ft_strlen(s);
	else
		len_lettre = ft_strchr(s, c) - s;
	return (len_lettre);
}
void	**ft_free(char **split, int j)
{
	while (j > 0)
	{
		free(split[--j]);
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	size_t	nb_lettre;
	char	**split;

	i = ((j = 0));
	split = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			nb_lettre = count_lettre(&s[i], c);
			split[j] = ft_substr(s, i, nb_lettre);
			if (!split[j])
				return ((char **)ft_free(split, j));
			i = i + nb_lettre;
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}
