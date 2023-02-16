/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:19 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/29 14:29:38 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* rev_rotate_both:
*	Reverse rotate stacks A and B until they reach their correct position,
*	which is determined by the bottom half of each stack.
*	The cost of rotation increases until it reaches 0,
*	indicating that the top position is correct.
*/
static void	rev_rotate_both(t_node**a, t_node**b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

/* rotate_both:
*	Rotate stacks A and B until positioned.
*	Cost is positive, in top half of each stack.
*	Decreased as rotated, until cost reaches 0,
*	indicating correct top position.
*/
static void	rotate_both(t_node**a, t_node**b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

/* rotate_a:
*	Rotates stack A to position. If cost is negative,
*	reverse rotate; if positive, rotate.
*/
static void	rotate_a(t_node **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate(a, "ra");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrotate(a, "rra");
			(*cost)++;
		}
	}
}

/* rotate_b:
*	Rotates stack B to position. If cost is negative,
*	reverse rotate; if positive, rotate.
*/
static void	rotate_b(t_node **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate(b, "rb");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrotate(b, "rrb");
			(*cost)++;
		}
	}
}

/* move:
*	Select the move to place the B stack
*	element in the correct position in stack A.
*	If the cost of moving both stacks A and B is equal (positive or negative),
*	they will be rotated or reversed simultaneously. If not,
*	they may be rotated individually before
*	pushing the top B element to the top of stack A.
*/
void	move(t_node **a, t_node **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	push(b, a, "pa");
}
