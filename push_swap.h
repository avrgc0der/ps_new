/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:08:46 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/25 02:08:56 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include "libft/libft.h"

# define EF EXIT_FAILURE
# define ES EXIT_SUCCESS
# define INT_MIN -2147483648
# define INT_MAX 2147483647


// * list struct
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_stack;


// ! -----------------------------------------`
// ! F U N C T I O N   D E F I N I T I O N S |
// ! ----------------------------------------`

// * init functions
void	init_stack(t_stack **stack, int ac, char **av);

// * parsing functions
void	args_check(int ac, char **av);
void	set_args(int ac, char **av, char **args, int i);

// * cleanup functions
void	ft_free(char **str);

// * movement functions

// * stack functions
void	stack_index(t_stack **stack);
t_stack	*stack_min(t_stack **stack);

// * utils
void	err_msg(char *msg);
int		isNum(char *nb);
int		isDup(int tmp, char **av, int i);



#endif