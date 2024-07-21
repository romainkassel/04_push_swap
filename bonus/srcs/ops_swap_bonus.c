/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 12:10:17 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	just_swap_a(t_list **stack_a)
{
	void	*tmp;

	if (!stack_a || !*stack_a || ft_lstsize_circular(*stack_a) == 1)
		return ;
	tmp = (*stack_a)->next->cont;
	(*stack_a)->next->cont = (*stack_a)->cont;
	(*stack_a)->cont = tmp;
}

void	swap_a(t_list **stack_a)
{
	just_swap_a(stack_a);
	write(1, "sa\n", 3);
}

void	just_swap_b(t_list **stack_b)
{
	void	*tmp;

	if (!stack_b || !*stack_b || ft_lstsize_circular(*stack_b) == 1)
		return ;
	tmp = (*stack_b)->next->cont;
	(*stack_b)->next->cont = (*stack_b)->cont;
	(*stack_b)->cont = tmp;
}

void	swap_b(t_list **stack_b)
{
	just_swap_b(stack_b);
	write(1, "sb\n", 3);
}

void	swap_s(t_list **stack_a, t_list **stack_b)
{
	just_swap_a(stack_a);
	just_swap_b(stack_b);
	write(1, "ss\n", 3);
}
