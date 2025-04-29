/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:23:35 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 05:27:47 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rsrr(t_list **a)
{
	ra(a);
	sa(a);
	rra(a);
}

void	sort_3(t_list **a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *a;
	min = find_min(a, -1);
	next_min = find_min(a, min);
	if (stack_sorted(a))
		return ;
	if (head->index == min && head->next->index != next_min)
		rsrr(a);
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(a);
		else
			rra(a);
	}
	else if (head->next->index == min)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	sort_4(t_list **a, t_list **b)
{
	int	distance;

	if (stack_sorted(a))
		return ;
	distance = distance_len(a, find_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (stack_sorted(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_list **a, t_list **b)
{
	int	distance;

	distance = distance_len(a, find_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	if (stack_sorted(a))
		return ;
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	simple_sort(t_list **a, t_list **b)
{
	int	i;

	if (stack_sorted(a) || ft_lstsize(*a) == 0
		|| ft_lstsize(*a) == 1)
		return ;
	i = ft_lstsize(*a);
	if (i == 2)
		sa(a);
	else if (i == 3)
		sort_3(a);
	else if (i == 4)
		sort_4(a, b);
	else if (i == 5)
		sort_5(a, b);
}
