/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:19:56 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/31 18:17:07 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_node
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

/* push_swap */
int			is_sorted(t_node *stack);
void		tiny_sort(t_node **stack);
void		push_and_save_three(t_node **stack_a, t_node **stack_b);
void		sort(t_node **stack_a, t_node **stack_b);
void		get_cost(t_node **stack_a, t_node **stack_b);
void		cheapest_move(t_node **stack_a, t_node **stack_b);
int			lowest_index_position(t_node **stack);
void		target_position(t_node **a, t_node **b);
void		move(t_node **a, t_node **b, int cost_a, int cost_b);

/* initialization */

t_node		*fill_stack(int ac, char **av);
void		assign_index(t_node *stack_a, int stack_size);

/* checker_bonus */

// int			get_next_line(char **line);

/* stcak */

t_node		*ft_stack_bottom(t_node *stack);
t_node		*ft_stack_before_bottom(t_node *stack);
t_node		*stack_new(int content);
int			ft_stack_size(t_node	*stack);
void		ft_stack_add_back(t_node **stack, t_node *new);

/* string utils */

void		ft_putstr(char *str);
long int	ft_atoi(const char *str);
char		**ft_split(char *str, char sep, int *size);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
int			str_ncmp(char *str1, char *str2, int n);

/* ultils */

void		free_stack(t_node **stack);
void		exit_error(t_node **stack_a, t_node **stack_b);
long int	ft_atoi(const char *str);
int			nb_abs(int nb);
char		**fill_tab(char **av, int *size, int ac);

/* Operations */

void		swap(t_node **stack, char *str);
void		ss(t_node **stack_a, t_node **stack_b);
void		push(t_node **src, t_node **dest, char *str);
void		rotate(t_node **stack, char *str);
void		rr(t_node **stack_a, t_node **stack_b);
void		rrotate(t_node **stack, char *str);
void		rrr(t_node **stack_a, t_node **stack_b);

/* input check */

int			valid_input(char **av);
int			is_empty(char *av);
int			is_digit(char c);
int			is_sign(char c);
int			nb_cmp(const char *s1, const char *s2);

#endif
