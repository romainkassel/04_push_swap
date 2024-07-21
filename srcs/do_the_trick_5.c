/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_trick_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/07 17:05:07 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_tot_cost_data(t_costs *costs, t_list *node)
{
	costs->side_a = "top";
	costs->side_b = "top";
	costs->tot_cost = costs->tmp_tot_cost;
	costs->cost_a = costs->tmp_cost_a;
	costs->cost_b = costs->tmp_cost_b;
	costs->common_ops = costs->tmp_common_ops;
	if (node->i >= costs->med_b)
		costs->side_b = "down";
	if (node->targ->i >= costs->med_a)
		costs->side_a = "down";
}

void	put_nodes_to_top(t_list **stack_a, t_list **stack_b, t_costs *costs)
{
	if (costs->common_ops > 0)
		combine_ops(stack_a, stack_b, costs);
	if (ft_strcmp(costs->side_a, "top") == 0)
		while (costs->cost_a--)
			rotate_a(stack_a);
	else
		while (costs->cost_a--)
			reverse_rotate_a(stack_a);
	if (ft_strcmp(costs->side_b, "top") == 0)
		while (costs->cost_b--)
			rotate_b(stack_b);
	else
		while (costs->cost_b--)
			reverse_rotate_b(stack_b);
}

void	combine_ops(t_list **stack_a, t_list **stack_b, t_costs *costs)
{
	if (ft_strcmp(costs->side_a, "top") == 0
		&& ft_strcmp(costs->side_b, "top") == 0)
		while (costs->common_ops--)
			rotate_r(stack_a, stack_b);
	else if (ft_strcmp(costs->side_a, "down") == 0
		&& ft_strcmp(costs->side_b, "down") == 0)
		while (costs->common_ops--)
			reverse_rotate_r(stack_a, stack_b);
	else
		while (costs->common_ops--)
			rotate_r(stack_a, stack_b);
}
