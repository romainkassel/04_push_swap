/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_trick_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/07 17:05:02 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_init_tmp_costs(t_costs *costs, t_ptrs *ptrs, t_list *node)
{
	costs->tmp_cost_b = get_node_cost(node, ft_lstsize((*ptrs->stack_b)));
	costs->tmp_cost_a = get_node_cost(node->targ, ft_lstsize((*ptrs->stack_a)));
	costs->tmp_tot_cost = costs->tmp_cost_a + costs->tmp_cost_b;
}

int	get_node_cost(t_list *stack_node, int stack_len)
{
	int		median;
	t_list	*node;
	int		node_cost;

	median = get_median(stack_len);
	node = stack_node;
	node_cost = -1;
	if (node->i < median)
		node_cost = node->i;
	else
		node_cost = stack_len - node->i;
	return (node_cost);
}

void	get_medians(t_costs *costs, t_ptrs *ptrs)
{
	costs->med_a = get_median(ft_lstsize((*ptrs->stack_a)));
	costs->med_b = get_median(ft_lstsize((*ptrs->stack_b)));
}

int	get_median(int stack_len)
{
	int	median;

	if (stack_len % 2 == 1)
		median = (stack_len - 1) / 2;
	else
		median = stack_len / 2;
	return (median + 1);
}
