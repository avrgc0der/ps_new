/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:14:38 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/25 18:37:39 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_countwords(char const *s, char dl)
{
	int	words;
	int	x;

	words = 0;
	x = 0;
	while (*s)
	{
		if (*s != dl && x == 0)
		{
			x = 1;
			words++;
		}
		else if (*s == dl && x == 1)
			x = 0;
		s++;
	}
	return (words);
}

int	ft_wordlen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	**ft_splitalloc(char **str, char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = ft_wordlen(s, c);
			str[i] = (char *)malloc((len + 1) * sizeof(char));
			if (!str[i])
			{
				ft_freearray(str);
				return (NULL);
			}
			ft_strlcpy(str[i], s, len + 1);
			str[i][len] = '\0';
			i++;
			s += len;
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	return (ft_splitalloc(strs, (char *)s, c));
}

int	is_dup(int tmp, char **av, int i)
{
	i--;
	while (i >= 0)
	{
		if (ft_atoi(av[i], NULL) == tmp)
			return (1);
		i--;
	}
	return (0);
}
