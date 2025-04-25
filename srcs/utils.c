/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:20:03 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/25 18:31:41 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	err_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EF);
}

void ft_freearray(char **str)
{
	int i;
	
	i = 0;
	while (str[i])
	i++;
	while (i >= 0)
	free(str[i--]);
}