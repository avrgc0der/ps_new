/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:12:28 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/28 00:04:38 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check(unsigned int nb, int mult)
{
	if (nb > 2147483647 && mult == 1)
		err_msg();
	else if (nb > 2147483648 && mult == -1)
		err_msg();
	nb *= mult;
	return (nb);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;
	int		temp;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if ((str[i] == '-' || str[i] == '+') && (str[i++] == '-'))
			sign = -1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			temp = res;	
			res = res * 10 + (str[i++] - '0');
			if (res < temp)
				err_msg();
		}
		return (check(res, sign));
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
