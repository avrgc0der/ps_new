/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:04:16 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 08:43:50 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(t_list **stack, t_parsing *parsing)
{
	t_list	*node;
	int		i;

	i = 0;
	while (parsing->args[i])
	{
		node = ft_lstnew(ft_atoi(parsing->args[i], NULL));
		ft_lstadd_back(stack, node);
		i++;
	}
	stack_index(stack);
}

int	main(int ac, char **av)
{
	t_parsing	parsing;
	t_list		**a;
	t_list		**b;

	parsing.args = NULL;
	parsing.joined = NULL;
	if (ac < 2)
		return (0);
	args_check(ac, av, &parsing);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	*a = NULL;
	*b = NULL;
	init_stack(a, &parsing);
	if (ac > 2)
	{
		ft_freearray(parsing.args);
		free(parsing.joined);
	}
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
