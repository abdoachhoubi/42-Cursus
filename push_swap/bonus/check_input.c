/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:29 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/31 18:17:44 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	ft_is_nbr(char *arg)
{
	int	i;

	i = 0;
	if (is_sign(arg[i]) && arg[i + 1] != '\0')
		i++;
	while (arg[i] && is_digit(arg[i]))
		i++;
	if (arg[i] && !is_digit(arg[i]))
		return (0);
	return (1);
}

static int	is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i])
		return (0);
	return (1);
}

int	is_empty(char *av)
{
	int	i;

	i = 0;
	if (!av[i])
		return (0);
	while (av[i])
	{
		if (av[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	is_duplicates(char **av)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		j = 0;
		while (av[++j])
			if (j != i && !nb_cmp(av[i], av[j]))
				return (1);
	}
	return (0);
}

int	valid_input(char **av)
{
	int	i;
	int	nb_zero;

	i = -1;
	nb_zero = 0;
	if (is_duplicates(av))
		return (0);
	while (av[++i])
	{
		if (!ft_is_nbr(av[i]))
			return (0);
		nb_zero += is_zero(av[i]);
	}
	if (nb_zero > 1)
		return (0);
	return (1);
}
