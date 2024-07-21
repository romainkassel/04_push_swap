/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_trick_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/07 18:10:12 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_the_trick(t_ptrs *ptrs)
{
	t_costs	costs;

	while (ft_lstsize(*ptrs->stack_a) > 3)
		push_b(ptrs->stack_a, ptrs->stack_b);
	if (ft_lstsize(*ptrs->stack_a) == 3)
		sort_3_nodes(ptrs);
	while ((*ptrs->stack_b))
	{
		init_targs(ptrs->stack_b);
		get_targs(ptrs);
		get_cheapest_node_data(ptrs, &costs);
		put_nodes_to_top(ptrs->stack_a, ptrs->stack_b, &costs);
		push_a(ptrs->stack_b, ptrs->stack_a);
	}
	put_smallest_node_to_top(ptrs->stack_a, &costs);
}

void	sort_3_nodes(t_ptrs *ptrs)
{
	int		nb1;
	int		nb2;
	int		nb3;
	t_list	*node;

	node = (*ptrs->stack_a);
	nb1 = *(int *)node->cont;
	nb2 = *(int *)node->next->cont;
	nb3 = *(int *)node->next->next->cont;
	if (nb2 > nb1 && nb2 > nb3 && nb1 < nb3)
		(swap_a(ptrs->stack_a), rotate_a(ptrs->stack_a));
	else if (nb2 > nb1 && nb2 > nb3 && nb1 > nb3)
		reverse_rotate_a(ptrs->stack_a);
	else if (nb2 < nb1 && nb2 < nb3 && nb1 < nb3)
		swap_a(ptrs->stack_a);
	else if (nb2 < nb1 && nb2 < nb3 && nb1 > nb3)
		rotate_a(ptrs->stack_a);
	else if (nb1 > nb2 && nb2 > nb3)
		(rotate_a(ptrs->stack_a), swap_a(ptrs->stack_a));
	else
		return ;
}

int	is_stack_a_ordered(t_ptrs *ptrs)
{
	t_list	*node;

	node = (*ptrs->stack_a);
	while (node->next)
	{
		if (*(int *)node->cont < *(int *)node->next->cont)
			node = node->next;
		else
			return (FAIL);
	}
	return (SUCCESS);
}

void	init_targs(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node)
	{
		node->targ = NULL;
		node = node->next;
	}
}

void	get_targs(t_ptrs *ptrs)
{
	t_list	*a;
	t_list	*b;
	int		d;

	b = (*ptrs->stack_b);
	while (b)
	{
		a = (*ptrs->stack_a);
		d = *(int *)a->cont - *(int *)b->cont;
		b->targ = a;
		while (a)
		{
			if (((d < 0) && (*(int *)a->cont - *(int *)b->cont >= 0))
				|| ((*(int *)a->cont - *(int *)b->cont < d)
					&& (((d >= 0) && (*(int *)a->cont - *(int *)b->cont >= 0))
						|| ((d < 0)
							&& (*(int *)a->cont - *(int *)b->cont < 0)))))
			{
				d = *(int *)a->cont - *(int *)b->cont;
				b->targ = a;
			}
			a = a->next;
		}
		b = b->next;
	}
}
