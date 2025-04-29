/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:41:30 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 04:26:32 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	revrotate(t_list **stack)
{
	t_list	*top;
	t_list	*bottom;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	top = *stack;
	bottom = ft_lstlast(top);
	while (top)
	{
		if (top->next->next == NULL)
		{
			top->next = NULL;
			break ;
		}
		top = top->next;
	}
	bottom->next = *stack;
	*stack = bottom;
	return (0);
}

int	rra(t_list **a)
{
	if (revrotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **b)
{
	if (revrotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	revrotate(a);
	revrotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
