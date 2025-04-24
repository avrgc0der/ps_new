/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:22:38 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/25 02:22:40 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void stack_index(t_stack **stack)
{
	t_stack *head;
	int i;
	
	i = 0;
	head = stack_min(stack);
	
	while (head)
	{
		head->index = i++;
		head = stack_min(stack);
	}
}

t_stack *stack_min(t_stack **stack)
{
	t_stack *head;
	t_stack *min;
	int flag;
	
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