/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:20:03 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 05:18:56 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	err_msg(void)
// {
// 	ft_putendl_fd(ERROR, 2);
// 	exit(EF);
// }

void err_msg(t_parsing *parsing)
{
    if (parsing)
	{
        if (parsing->args)
            ft_freearray(parsing->args);
        if (parsing->joined)
            free(parsing->joined);
    }
    ft_putendl_fd("Error", 2);
    exit(1);
}

void ft_freearray(char **str)
{
    int i = 0;
    
    if (!str)
        return;
        
    while (str[i])
        free(str[i++]);
    free(str);
}

int	distance_len(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

int	find_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}
