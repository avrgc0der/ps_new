/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:22:38 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 05:02:24 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 5)
		simple_sort(a, b);
	else
		radix_sort(a, b);
}

int	stack_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	stack_index(t_list **stack)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_min(stack);
	while (head)
	{
		head->index = i++;
		head = stack_min(stack);
	}
}

t_list	*stack_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		flag;

	min = NULL;
	flag = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!flag || head->value < min->value))
			{
				min = head;
				flag = 1;
			}
			head = head->next;
		}
	}
	return (min);
}
