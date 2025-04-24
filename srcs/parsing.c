/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:21:36 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/25 02:21:55 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void set_args(int ac, char **av, char **args, int i)
{
	i = 0;
	if (ac == 2)
	args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
}

int isNum(char *nb)
{
	int i;
	
	i = 0;
	if (nb[0] == '-')
	i++;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
		return (0);
		i++;
	}
	return (1);
}


int isDup(int tmp, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i] == tmp))
		return (1);
		i++;
	}
	return (0);
}

void args_check(int ac, char **av)
{
	int i;
	long tmp;
	char **args;
	
	i = 0;
	set_args(ac, av, args, i);
	while (args[i])
	{
		tmp = ft_atoi(args[i]); 
		if (!isNum(args[i]))
		err_msg("ERROR: arguments must be numerical.");
		if (isDup(tmp, args, i))
		err_msg("ERROR: arguments must not include duplicates");
		if (tmp < INT_MIN || tmp > INT_MAX)
		err_msg("ERROR: invalid integer range.");
		i++;
	}
}