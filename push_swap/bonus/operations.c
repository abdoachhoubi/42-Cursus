/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:28 by aachhoub          #+#    #+#             */
/*   Updated: 2023/01/01 17:05:24 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	push(t_node **src, t_node **dest, char *str)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	if (str)
		ft_putstr(str);
}

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
	}
	if (str)
		ft_putstr(str);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
}

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

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
}
