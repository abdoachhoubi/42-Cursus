/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:34 by aachhoub          #+#    #+#             */
/*   Updated: 2023/01/05 14:18:13 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* is_sorted:
*	Checks if a stack is sorted.
*	Returns 0 if the stack is not sorted, 1 if it is sorted.
*/
int	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	Chooses a sorting algo depending on the number
*	of nodes to be sorted.
*/
static void	push_swap(t_node **stack_a, t_node **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		swap(stack_a, "sa");
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* fill_stack:
*	Fills stack_a with the provided values.
*	If the values are out of int range, prints and error and exits the program.
*/
t_node	*fill_stack(int ac, char **av)
{
	t_node		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(NULL, NULL);
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			ft_stack_add_back(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/* assign_index:
*	Assigns an index to each value in stack a.
*	because indexes can be checked and compared instead of actual values,
*	which may or may not be adjacent to each other.
*		ex. values:		 -8	 19	 60	 27
*		indexes:		[1]	[2]	[4]	[3]
*	The indexes are assigned from highest (stack_size) to lowest (1).
*/
void	assign_index(t_node *stack_a, int size)
{
	t_node	*ptr;
	t_node	*highest;
	int		content;

	while (--size > 0)
	{
		ptr = stack_a;
		content = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->content == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->content > content && ptr->index == 0)
			{
				content = ptr->content;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
				highest->index = size;
	}
}

/* main:
*	Checks if the input is correct, in which case it initializes stacks a and b,
*	assigns each value indexes and sorts the stacks. When sorting is done, frees
*	the stacks and exits.
*/
int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	char	**tab;

	tab = fill_tab(av, &size, ac);
	if (!valid_input(tab))
		exit_error(NULL, NULL);
	stack_a = fill_stack(size, tab);
	stack_b = NULL;
	size = ft_stack_size(stack_a);
	assign_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
