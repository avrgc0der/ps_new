/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:52:10 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/28 23:52:43 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list *stack_from, t_list *stack_to)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(stack_from) == 0)
		return (-1);
	head_to = stack_to;
	head_from = stack_from;
	tmp = head_from;
	head_from = head_from->next;
	stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
	}
}
