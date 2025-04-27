/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:41:30 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/28 01:22:35 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_list *stack)
{
	t_list *head;
	t_list *next;
	int tmp_val;
	int tmp_i;

	if (ft_lstsize(stack) < 2)
		return (-1);
	head = stack;
	next = head->next;
	if (!head || !next)
		err_msg();
	tmp_val = head->value;
	tmp_i = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_i;
	return (0);
}

int sa(t_list *a)
{
	if (swap(a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int sb(t_list *b)
{
	if (swap(b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int ss(t_list *a, t_list *b)
{
	if ((ft_lstsize(a) < 2) || (ft_lstsize(b) < 2))
		return (-1);
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
	return (0);
}


int rotate(t_list *stack)
{
	t_list *top;
	t_list *bottom;

	if (ft_lstsize(stack) < 2)
		return (-1);
	top = stack;
	bottom = ft_lstlast(top);
	stack = stack->next;
	top->next = NULL;
	bottom->next = top;
	return (0);
}

int ra(t_list *a)
{
	if (rotate(a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int rb(t_list *b)
{
	if (rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int rr(t_list *a, t_list *b)
{
	if ((ft_lstsize(a) < 2) || (ft_lstsize(b) < 2))
		return (-1);
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
	return (0);
}


int revrotate(t_list *stack)
{
	t_list *top;
	t_list *bottom;

	if (ft_lstsize(stack) < 2)
		return (-1);
	top = stack;
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
	bottom->next = stack;
	stack = bottom;
	return (0);
}

int rra(t_list *a)
{
	if (revrotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int rrb(t_list *b)
{
	if (revrotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int rrr(t_list *a, t_list *b)
{
	if ((ft_lstsize(a) < 2) || (ft_lstsize(b) < 2))
		return (-1);
	revrotate(a);
	revrotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}