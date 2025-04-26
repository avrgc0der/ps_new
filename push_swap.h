/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:08:46 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/25 18:38:07 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

# define ERROR "Error"

# define EF EXIT_FAILURE
# define ES EXIT_SUCCESS

// included limits.h instead
// # define INT_MIN -2147483648
// # define INT_MAX 2147483647


// * list struct
typedef struct s_list
{
	int				value;
	int				index;
	// not needed
	// void			*content;
	struct s_list	*next;
}					t_list;


typedef struct s_parsing
{
	char	*joined;
	char	**args;
	int		counter;
}				t_parsing;


// ! -----------------------------------------`
// ! F U N C T I O N   D E F I N I T I O N S |
// ! ----------------------------------------`

// * init functions
void	init_stack(t_list **stack, int ac, char **av);

// * parsing functions
void	args_check(int ac, char **av, t_parsing *args);

// * cleanup functions
void	ft_freearray(char **str);

// * movement functions

// * stack functions
void	stack_index(t_list **stack);
t_list	*stack_min(t_list **stack);

// * utils
void	err_msg();
int		isNum(char *nb);
int		isDup(int tmp, char **av, int i);

// * added utils
size_t		ft_strlcpy(char *dst, const char *src, size_t len);
t_list		*ft_lstnew(int value);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_putendl_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
long		ft_atoi(const char *str);
int			check(unsigned int nb, int mult);
char		**ft_split(char const *s, char c);
char		**ft_splitalloc(char **str, char *s, char c);
int			ft_wordlen(char *str, char c);
int			ft_countwords(char const *s, char dl);

#endif