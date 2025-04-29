/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 00:23:35 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/29 05:18:07 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **a, t_list **b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *a;
	size = ft_lstsize(head_a);
	max_bits = find_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
        while (ft_lstsize(*b) != 0)
            pa(a, b);
		i++;
	}
}

// void print_stack_values(t_list *stack)
// {
//     while (stack) {
//         printf("%d(index:%d) ", stack->value, stack->index);
//         stack = stack->next;
//     }
//     printf("\n");
// }

// void radix_sort(t_list **a, t_list **b)
// {
//     t_list *head_a;
//     int i, j, size, max_bits;

//     printf("\n=== RADIX SORT START ===\n");
//     printf("Initial Stack A: ");
//     print_stack_values(*a);  // You'll need to implement this helper
    
//     max_bits = find_max_bits(a);
//     printf("Max bits needed: %d\n", max_bits);
    
//     for (i = 0; i < max_bits; i++) {
//         printf("\nProcessing bit %d:\n", i);
//         size = ft_lstsize(*a);
        
//         for (j = 0; j < size; j++) {
//             head_a = *a;
//             int current_index = head_a->index;
//             int bit_value = (current_index >> i) & 1;
            
//             printf("  Value: %d, Index: %d, Bit %d: %d -> ", 
//                   head_a->value, current_index, i, bit_value);
            
//             if (bit_value) {
//                 ra(a);
//                 printf("ra\n");
//             } else {
//                 pb(a, b);
//                 printf("pb\n");
//             }
            
//             // Print both stacks after each operation
//             printf("  A: ");
//             print_stack_values(*a);
//             printf("  B: ");
//             print_stack_values(*b);
//         }
        
//         printf("\nRebuilding stack A:\n");
//         while (*b) {
//             pa(a, b);
//             printf("  pa\n");
//             printf("  A: ");
//             print_stack_values(*a);
//             printf("  B: ");
//             print_stack_values(*b);
//         }
//     }
//     printf("\n=== RADIX SORT COMPLETE ===\n");
// }