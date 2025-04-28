/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:23:35 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/28 01:34:09 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_list *a)
{
	int top;
	int middle;
	int bottom;

	top = a->index;
	middle = a->next->index;
	bottom = a->next->next->index;
	if (stack_sorted(a))
		return;
	if (top > middle && middle < bottom && top < bottom)  // * 2 1 3    top bottom mid
		sa(a);
	else if (top > middle && middle < bottom && top > bottom) // * 3 1 2 top bottom mid
		ra(a);
	else if (top > middle && middle > bottom && top > bottom) // * 3 2 1
	{
		sa(a);
		rra(a);
	}
	else if (top < middle && middle > bottom && top < bottom) // * 1 3 2
	{
		sa(a);
		ra(a);
	}
	else if (top < middle && middle > bottom && top > bottom) // * 2 3 1
		rra(a);
}


void simple_sort(t_list *a, t_list *b)
{
	int i;

	if (stack_sorted(a) || ft_lstsize(a) <= 1)
		return ;
	i = ft_lstsize(a);
	if (i == 2)
		sa(a);
	else if (i == 3)
		sort_3(a);
}