/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:21:36 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/25 18:44:14 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if (ft_atoi(av[i])  == tmp)
		return (1);
		i++;
	}
	return (0);
}

// function to check if args are empty
int	check_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0); // big broblem
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0); // big broblem
}

void new_strjoin(char **av, t_parsing *parsing)
{
	int	i;
	int	j;

	i = 1;
	j = 0;

	// counts characters in allllll args
	parsing->counter = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			parsing->counter++;
			j++;
		}
		// adds one for a space btwn args
		parsing->counter++;
		i++;
	}

	// allocates for the new string
	parsing->joined = malloc(parsing->counter + 1);
	i = 1;
	j = 0;
	parsing->counter = 0;

	// copies characters from all args to new string
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			parsing->joined[parsing->counter] = av[i][j];
			j++;
			parsing->counter++;
		}
		// adds one space btwn args
		parsing->joined[parsing->counter] = ' ';
		parsing->counter++;
		i++;
	}
	parsing->joined[parsing->counter] = '\0';
}

int check_sign(char character)
{
	if (character == '-' || character == '+')
		return (1);
	return (0);
}

void check_digits(t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	// goes over every argument
	while (parsing->args[i])
	{
		j = 0;
		// checks if the first character is a sign and skips it
		if (check_sign(parsing->args[i][j]))
			j++;
		// if there is nothing after sign
		if (!parsing->args[i][j])
			err_msg();	// big broblem
		// goes over rest of characters
		while (parsing->args[i][j])
		{
			// if character NOT a number (!)
			if (!(parsing->args[i][j] >= '0' && parsing->args[i][j] <= '9'))
				err_msg();	// big broblem
			j++;
		}
		i++;	// repeat for all
	}
}

void args_check(int ac, char **av, t_parsing *parsing)
{
	int	i;

	i = 1;

	// loop to check if args are empty or not
	while (i < ac)
	{
		// if empty
		if (check_spaces(av[i]) == 0)
			err_msg();	// big broblem
		i++;
	}

	// joins all args to one new arg
	new_strjoin(av, parsing);

	// new split args
	parsing->args = ft_split(parsing->joined, ' ');

	// prints dem for reference
	i = 0;
	while (parsing->args[i])
	{
		printf("%s\n", parsing->args[i]);
		i++;
	}

	// checks if args are all digits
	check_digits(parsing);
}

// void args_check(int ac, char **av)
// {
// 	int i;
// 	long tmp;
// 	char **args;
	
// 	i = 0;
// 	if (ac == 2)
// 		args = ft_split(av[1], ' ');
// 	else
// 	{
// 		i = 1;
// 		args = av + 1;
// 	}
// 	while (args[i])
// 	{
// 		tmp = ft_atoi(args[i]);
// 		if (!isNum(args[i]))
// 		err_msg();
// 		if (isDup(tmp, args, i))
// 		err_msg();
// 		if (tmp < INT_MIN || tmp > INT_MAX)
// 		err_msg();
// 		i++;
// 	}
// 	if (ac == 2)
// 	ft_freearray(args);
// }