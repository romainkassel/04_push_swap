/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_trick_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/07 17:10:56 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_smallest_node_to_top(t_list **stack_a, t_costs	*costs)
{
	t_list	*smallest_node;

	smallest_node = get_smallest_node(stack_a);
	get_node_data(stack_a, smallest_node, costs);
	put_node_to_top(stack_a, costs);
}

t_list	*get_smallest_node(t_list **stack_a)
{
	t_list	*node;
	t_list	*smallest_node;

	node = *stack_a;
	smallest_node = node;
	while (node)
	{
		if (*(int *)node->cont < *(int *)smallest_node->cont)
		smallest_node = node;
		node = node->next;
	}
	return (smallest_node);
}

void	get_node_data(t_list **stack_a, t_list *smallest_node, t_costs *costs)
{
	get_node_i_stack(stack_a);
	init_costs(costs);
	costs->cost_a = get_node_cost(smallest_node, ft_lstsize(*stack_a));
	costs->med_a = get_median(ft_lstsize(*stack_a));
	if (smallest_node->i >= costs->med_a)
		costs->side_a = "down";
}

void	put_node_to_top(t_list **stack_a, t_costs *costs)
{
	if (ft_strcmp(costs->side_a, "top") == 0)
		while (costs->cost_a--)
			rotate_a(stack_a);
	else
		while (costs->cost_a--)
			reverse_rotate_a(stack_a);
}

int	is_stack_a_complete(t_ptrs *ptrs, int arg_count)
{
	int	len_stack_a;

	len_stack_a = ft_lstsize((*ptrs->stack_a));
	if (len_stack_a != arg_count)
		return (FAIL);
	else
		return (SUCCESS);
}
