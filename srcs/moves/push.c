/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:52:10 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 08:39:52 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_list **a, t_list **b)
{
	t_list	*first_b;

	if (!*b)
		return (-1);
	first_b = *b;
	*b = (*b)->next;
	first_b->next = *a;
	*a = first_b;
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
