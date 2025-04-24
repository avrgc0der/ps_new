/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:04:16 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/25 02:22:29 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void init_stack(t_stack **stack, int ac, char **av)
{
	char **args;
	t_stack *node;
	int i;

	i = 0;
	set_args(ac, av, args, i);
	while (args[i])
	{
		node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, node);
		i++;
	}
	stack_index(stack);
	if (ac == 2)
	ft_free(args);
}

int main(int ac, char **av)
{
	t_stack **a;
	t_stack **b;
	
	if (ac < 2)
	{
		err_msg("ERROR: try ./push_swap [input]");
		return (-1);
	}
		args_check(ac, av);
	a = (t_stack **)malloc(sizeof(t_stack));
	b = (t_stack **)malloc(sizeof(t_stack));
	*a = NULL;
	*b = NULL;
	init_stack(a, ac, av);
}