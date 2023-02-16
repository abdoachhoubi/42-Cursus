/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:10:55 by aachhoub          #+#    #+#             */
/*   Updated: 2023/01/05 14:39:57 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
/* sort tree*/
static int	highest_index(t_node *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* tiny_sort:
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
void	tiny_sort(t_node **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = highest_index(*stack);
	if ((*stack)->index == highest)
		rotate(stack, "ra");
	else if ((*stack)->next->index == highest)
		rrotate(stack, "rra");
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, "sa");
}

/* end */

/* push_all_save_three:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
void	push_and_save_three(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push(stack_a, stack_b, "pb");
			pushed++;
		}
		else
			rotate(stack_a, "ra");
		i++;
	}
	while (stack_size - pushed > 3)
	{
		push(stack_a, stack_b, "pb");
		pushed++;
	}
}

/* shift_stack:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
static void	shift_stack(t_node **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_stack_size(*stack_a);
	lowest_pos = lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rrotate(stack_a, "rra");
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate(stack_a, "ra");
			lowest_pos--;
		}
	}
}

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move.
*		Shift elements until stack A is in order.
*/
void	sort(t_node **stack_a, t_node **stack_b)
{
	push_and_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
