/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:23:35 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 00:04:26 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->index;
	middle = a->next->index;
	bottom = a->next->next->index;
	if (stack_sorted(a))
		return ;
	if (top > middle && middle < bottom && top < bottom)
		sa(a);
	else if (top > middle && middle < bottom && top > bottom)
		ra(a);
	else if (top > middle && middle > bottom && top > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(a);
}

void	sort_4(t_list *a, t_list *b)
{
	int	distance;

	if (stack_sorted(a))
		return ;
	distance = distance_len(a, min_index(a, -1));
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
}

void	sort_5(t_list *a, t_list *b);

void	simple_sort(t_list *a, t_list *b)
{
	int	i;

	if (stack_sorted(a) || ft_lstsize(a) <= 1)
		return ;
	i = ft_lstsize(a);
	if (i == 2)
		sa(a);
	else if (i == 3)
		sort_3(a);
	else if (i == 4)
		sort_4(a, b);
	else if (i == 5)
		sort_5(a, b);
}
