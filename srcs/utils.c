/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:20:03 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 01:04:27 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	err_msg(void)
{
	ft_putendl_fd(ERROR, 2);
	exit(EF);
}

void	ft_freearray(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

int	distance_len(t_list *stack, int index)
{
	t_list	*head;
	int		distance;

	head = stack;
	distance = 0;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	min_index(t_list *stack, int val)
{
	t_list	*head;
	int		min;

	head = stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	free_stack(t_list *stack)
{
	t_list	*head;
	t_list	*tmp;

	head = stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
