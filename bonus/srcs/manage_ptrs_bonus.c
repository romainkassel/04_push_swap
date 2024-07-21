/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ptrs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 12:10:17 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	init_ptrs(t_ptrs *ptrs)
{
	ptrs->exp_argv = NULL;
	ptrs->tab = NULL;
	ptrs->tab_count = NULL;
	ptrs->stack_a = NULL;
	ptrs->stack_b = NULL;
	ptrs->argv_numbers = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(stack);
}

void	free_ptrs(t_ptrs *ptrs)
{
	if (ptrs->exp_argv)
		free_tab(ptrs->exp_argv);
	if (ptrs->tab)
		free_tab(ptrs->tab);
	if (ptrs->tab_count)
		free_tab(ptrs->tab_count);
	if (ptrs->stack_a)
		free_stack(ptrs->stack_a);
	if (ptrs->stack_b)
		free_stack(ptrs->stack_b);
	if (ptrs->argv_numbers)
		free(ptrs->argv_numbers);
}
