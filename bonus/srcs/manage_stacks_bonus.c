/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 14:41:59 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	init_stacks(t_ptrs *ptrs, int arg_count)
{
	ptrs->stack_a = (t_list **)ft_calloc(sizeof(t_list *), arg_count);
	if (!ptrs->stack_a)
		quit_prog(ptrs, NULL, FAIL);
	ptrs->stack_b = (t_list **)ft_calloc(sizeof(t_list *), arg_count);
	if (!ptrs->stack_b)
		quit_prog(ptrs, NULL, FAIL);
}

void	fill_stack_a(t_ptrs *ptrs, int arg_count)
{
	t_list	*node;
	t_list	*new_node;
	int		i;

	i = 0;
	ptrs->argv_numbers = (int *)ft_calloc(sizeof(int), arg_count);
	if (!ptrs->argv_numbers)
		quit_prog(ptrs, NULL, FAIL);
	(*ptrs->argv_numbers) = ft_atoi(ptrs->exp_argv[i++]);
	(*ptrs->stack_a) = ft_lstnew(ptrs->argv_numbers);
	if (!(*ptrs->stack_a))
		quit_prog(ptrs, NULL, FAIL);
	node = (*ptrs->stack_a);
	while (ptrs->exp_argv[i])
	{
		ptrs->argv_numbers++;
		(*ptrs->argv_numbers) = ft_atoi(ptrs->exp_argv[i++]);
		new_node = ft_lstnew(ptrs->argv_numbers);
		if (!new_node)
			quit_prog(ptrs, NULL, FAIL);
		ft_lstadd_back(ptrs->stack_a, new_node);
		node = node->next;
	}
	ptrs->argv_numbers -= (arg_count - 1);
	(free_tab(ptrs->exp_argv), ptrs->exp_argv = NULL);
}

int	check_dups_zith_0_before(t_ptrs *ptrs)
{
	t_list	*node1;
	t_list	*node2;
	int		i;
	int		j;

	node1 = (*ptrs->stack_a);
	i = 0;
	while (node1)
	{
		node2 = (*ptrs->stack_a);
		j = 0;
		while (node2)
		{
			if (*(int *)node1->cont == *(int *)node2->cont && i != j)
				return (FAIL);
			node2 = node2->next;
			j++;
		}
		node1 = node1->next;
		i++;
	}
	return (SUCCESS);
}

int	check_final_stack(t_ptrs *ptrs, int arg_count)
{
	if (is_stack_a_ordered(ptrs) == SUCCESS && !(*ptrs->stack_b)
		&& is_stack_a_complete(ptrs, arg_count) == SUCCESS)
		return (write(1, "OK\n", 3), free_ptrs(ptrs), SUCCESS);
	else
		return (write(1, "KO\n", 3), free_ptrs(ptrs), FAIL);
}
