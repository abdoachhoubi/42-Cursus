/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:28 by aachhoub          #+#    #+#             */
/*   Updated: 2023/01/05 14:42:03 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*	Prints the operation to the standard output.
*/
void	push(t_node **src, t_node **dest, char *str)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	ft_putstr(str);
}

/*	swap:
*	Swap the first 2 elements at the top of given stack. such a or b
*	Does nothing if there is only one or no elements.
*	Prints the operation to the standard output.
*/
void	swap(t_node **stack, char *str)
{
	int	tmp;

	if (ft_stack_size(*stack) > 1)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
		tmp = (*stack)->index;
		(*stack)->index = (*stack)->next->index;
		(*stack)->next->index = tmp;
		if (str)
			ft_putstr(str);
	}
}

/* ss:
*	Swaps the top 2 elements of stack a and the top 2 elements
*	of stack b.
*	Prints the operation "ss" to the standard output.
*/
void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_putstr("ss");
}

/* rotate:
*	Sends the top element of the stack to the bottom.
*	Do nothing if there is only one or no elements.
*	Prints the operation to the standard output.
*/
void	rotate(t_node **stack, char *str)
{
	t_node	*tmp;
	t_node	*last;

	if (ft_stack_size(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_stack_bottom(*stack);
	tmp->next = NULL;
	last->next = tmp;
	if (str)
		ft_putstr(str);
}

/* rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints the operation "rr" to the standard output.
*/
void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_putstr("rr");
}
