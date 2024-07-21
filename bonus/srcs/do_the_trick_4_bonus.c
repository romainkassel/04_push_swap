/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_trick_4_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 12:10:17 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	update_tmp_costs(t_costs *costs)
{
	if (costs->tmp_cost_a > costs->tmp_cost_b)
		update_tmp_costs_if_a_bigger(costs);
	else if (costs->tmp_cost_a < costs->tmp_cost_b)
		update_tmp_costs_if_b_bigger(costs);
	else
		update_tmp_costs_if_a_b_equal(costs);
}

void	update_tmp_costs_if_a_bigger(t_costs *costs)
{
	costs->tmp_common_ops = costs->tmp_cost_b;
	costs->tmp_cost_b = 0;
	costs->tmp_cost_a -= costs->tmp_common_ops;
	costs->tmp_tot_cost -= costs->tmp_common_ops;
}

void	update_tmp_costs_if_b_bigger(t_costs *costs)
{
	costs->tmp_common_ops = costs->tmp_cost_a;
	costs->tmp_cost_a = 0;
	costs->tmp_cost_b -= costs->tmp_common_ops;
	costs->tmp_tot_cost -= costs->tmp_common_ops;
}

void	update_tmp_costs_if_a_b_equal(t_costs *costs)
{
	costs->tmp_tot_cost /= 2;
	costs->tmp_common_ops = costs->tmp_tot_cost;
	costs->tmp_cost_a = 0;
	costs->tmp_cost_b = 0;
}

void	update_tmp_costs_if_same_i(t_costs *costs)
{
	costs->tmp_tot_cost = costs->tmp_common_ops;
	costs->tmp_cost_a = 0;
	costs->tmp_cost_b = 0;
}
