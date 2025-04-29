/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:08:46 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 04:39:42 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define ERROR "Error"

# define EF EXIT_FAILURE
# define ES EXIT_SUCCESS

// * list struct
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_parsing
{
	char		*joined; // * after strjoin
	char		**args; // * all of the args splitted
	int			counter; // * counter of the elements in the string
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
void	free_stack(t_list **stack);

// * sorting functions
void	sort_3(t_list **a);
void	sort_4(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
void	simple_sort(t_list **a, t_list **b);
void	radix_sort(t_list **a, t_list **b);

// * stack functions
void	stack_index(t_list **stack);
t_list	*stack_min(t_list **stack);
void	sort_stack(t_list **a, t_list **b);
int		stack_sorted(t_list **stack);

// * move functions
int		swap(t_list **stack);
int		rotate(t_list **stack);
int		revrotate(t_list **stack);
int		push(t_list **stack_from, t_list **stack_to);
int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);

// * utils
// void	err_msg(void);
void	err_msg(t_parsing *parsing);
int		is_dup(int tmp, char **av, int i);
int		distance_len(t_list **stack, int index);
int		find_max_bits(t_list **stack);
int		find_min(t_list **stack, int val);

// * libft utils
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
void	ft_putendl_fd(char *s, int fd);
long	ft_atoi(const char *str);
int		check(unsigned long nb, int mult);
char	**ft_split(char const *s, char c);
char	**ft_splitalloc(char **str, char *s, char c);
int		ft_wordlen(char *str, char c);
int		ft_countwords(char const *s, char dl);

#endif