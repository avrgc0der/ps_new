/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:04:16 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 01:06:56 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(t_list *stack, int ac, char **av)
{
	char	**args;
	t_list	*node;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, node);
		i++;
	}
	stack_index(stack);
	if (ac == 2)
		ft_freearray(args);
}

int	main(int ac, char **av)
{
	t_parsing	args;
	t_list		*a;
	t_list		*b;

	if (ac < 2)
		err_msg();
	args_check(ac, av, &args);
	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	a = NULL;
	b = NULL;
	init_stack(a, ac, av);
	if (stack_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
