/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 12:10:17 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	display_message(char *status_message, int exit_status)
{
	if (exit_status == FAIL)
	{
		ft_putstr_fd("Error\n", 2);
		if (status_message)
		{
			ft_putstr_fd(status_message, 2);
			ft_putchar_fd('\n', 2);
		}
	}
	else
	{
		ft_putstr_fd("Success\n", 1);
		if (status_message)
		{
			ft_putstr_fd(status_message, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	quit_prog(t_ptrs *ptrs, char *status_message, int exit_status)
{
	display_message(status_message, exit_status);
	free_ptrs(ptrs);
	exit(exit_status);
}
