/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_trick_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 12:10:17 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	get_cheapest_node_data(t_ptrs *ptrs, t_costs *costs)
{
	t_list	*node;

	(get_node_i(ptrs), node = (*ptrs->stack_b), init_costs(costs));
	while (node)
	{
		(get_init_tmp_costs(costs, ptrs, node), get_medians(costs, ptrs));
		if ((node->i < costs->med_b && node->targ->i < costs->med_a)
			|| (node->i >= costs->med_b && node->targ->i >= costs->med_a))
			update_tmp_costs(costs);
		else if (node->i == node->targ->i
			&& ((node->i < costs->med_b && node->targ->i >= costs->med_a)
				|| (node->i >= costs->med_b && node->targ->i < costs->med_a)))
		{
			if (node->i < costs->med_b && node->targ->i >= costs->med_a)
				costs->tmp_common_ops = costs->tmp_cost_b;
			else if (node->i >= costs->med_b && node->targ->i < costs->med_a)
				costs->tmp_common_ops = costs->tmp_cost_a;
			update_tmp_costs_if_same_i(costs);
		}
		else
			costs->tmp_common_ops = -1;
		if (costs->tot_cost == -1 || costs->tmp_tot_cost < costs->tot_cost)
			update_tot_cost_data(costs, node);
		node = node->next;
	}
}

void	get_node_i(t_ptrs *ptrs)
{
	get_node_i_stack(ptrs->stack_a);
	get_node_i_stack(ptrs->stack_b);
}

void	get_node_i_stack(t_list **stack)
{
	t_list	*node;
	int		i;

	node = (*stack);
	i = 0;
	while (node)
	{
		node->i = i++;
		node = node->next;
	}
}

void	init_costs(t_costs *costs)
{
	costs->tmp_cost_a = -1;
	costs->tmp_cost_b = -1;
	costs->tmp_tot_cost = -1;
	costs->tmp_common_ops = -1;
	costs->cost_a = -1;
	costs->cost_b = -1;
	costs->tot_cost = -1;
	costs->common_ops = -1;
	costs->side_a = "top";
	costs->side_b = "top";
}
