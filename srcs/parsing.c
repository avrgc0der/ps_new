/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:21:36 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 15:19:55 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

void	new_strjoin(char **av, t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	parsing->counter = 0;
	while (av[++i])
		parsing->counter += ft_strlen(av[i]) + 1;
	parsing->joined = malloc(parsing->counter + 1);
	i = 0;
	parsing->counter = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			parsing->joined[parsing->counter++] = av[i][j];
		parsing->joined[parsing->counter++] = ' ';
	}
	parsing->joined[--parsing->counter] = '\0';
}

void	check_digits(t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	while (parsing->args[i])
	{
		j = 0;
		if ((parsing->args[i][j] == '-') || (parsing->args[i][j] == '+'))
			j++;
		if (!parsing->args[i][j])
			err_msg(parsing);
		while (parsing->args[i][j])
		{
			if (!(parsing->args[i][j] >= '0' && parsing->args[i][j] <= '9'))
				err_msg(parsing);
			j++;
		}
		i++;
	}
}

static void	number_check(t_parsing *parsing)
{
	int	i;
	int	tmp;

	i = 0;
	while (parsing->args[i])
	{
		tmp = ft_atoi(parsing->args[i], parsing);
		if (tmp < INT_MIN || tmp > INT_MAX)
			err_msg(parsing);
		if (is_dup(tmp, parsing->args, i))
			err_msg(parsing);
		i++;
	}
}

void	args_check(int ac, char **av, t_parsing *parsing)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (check_spaces(av[i]) == 0)
			err_msg(parsing);
		i++;
	}
	new_strjoin(av, parsing);
	parsing->args = ft_split(parsing->joined, ' ');
	i = 0;
	check_digits(parsing);
	number_check(parsing);
	if (ac == 2)
	{
		ft_freearray(parsing->args);
		free(parsing->joined);
		parsing->args = NULL;
		parsing->joined = NULL;
	}
}
