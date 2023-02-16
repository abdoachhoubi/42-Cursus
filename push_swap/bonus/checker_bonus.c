/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:16:12 by aachhoub          #+#    #+#             */
/*   Updated: 2023/01/05 14:13:31 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

static int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && r != -1 && c != '\n' && c != '\0')
	{
		buffer[i++] = c;
		r = read(0, &c, 1);
	}
	buffer[i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

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

static void	checker(t_node **a, t_node **b)
{
	char	*line;

	while (get_next_line(&line))
	{
		if (!line)
			break ;
		if (!str_ncmp(line, "sa", 3) || !str_ncmp(line, "sb", 3)
			|| !str_ncmp(line, "ss", 3) || !str_ncmp(line, "pa", 3)
			|| !str_ncmp(line, "pb", 3))
			do_oper_a(a, b, line);
		else if (!str_ncmp(line, "ra", 3) || !str_ncmp(line, "rb", 3)
			|| !str_ncmp(line, "rr", 3) || !str_ncmp(line, "rra", 4)
			|| !str_ncmp(line, "rrb", 4) || !str_ncmp(line, "rrr", 4))
			do_oper_b(a, b, line);
		else
			exit_error(a, b);
	}
}

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
	checker(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
