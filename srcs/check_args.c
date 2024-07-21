/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 10:16:35 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-') && (argv[i][j + 1] == '0')
				&& ((argv[i][j + 2] < '1') || (argv[i][j + 2] > '9')))
				return (FAIL);
			else if ((ft_isdigit(argv[i][j]) == SUCCESS)
				|| ((argv[i][j] == '-')
				&& (ft_isdigit(argv[i][j + 1]) == SUCCESS)
				&& (((j < 0) && (argv[i][j - 1] == ' ')) || (j == 0))))
				j++;
			else
				return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0 && i != j)
				return (FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_int(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	check_nul(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "") == 0)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	check_args(char **argv)
{
	if (check_int(argv) == FAIL
		|| check_dup(argv) == FAIL
		|| check_digit(argv) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
