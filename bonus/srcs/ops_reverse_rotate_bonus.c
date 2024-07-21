/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 12:10:17 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	just_reverse_rotate_a(t_list **stack_a)
{
	t_list	*node;

	if (!*stack_a || !stack_a || !(*stack_a)->next)
		return ;
	node = *stack_a;
	while (node)
	{
		if (node->next->next == NULL)
		{
			ft_lstadd_front(stack_a, ft_lstnew((node->next->cont)));
			free(node->next);
			node->next = NULL;
		}
		node = node->next;
	}
}

void	reverse_rotate_a(t_list **stack_a)
{
	just_reverse_rotate_a(stack_a);
	write(1, "rra\n", 4);
}

void	just_reverse_rotate_b(t_list **stack_b)
{
	t_list	*node;

	if (!*stack_b || !stack_b || !(*stack_b)->next)
		return ;
	node = *stack_b;
	while (node)
	{
		if (node->next->next == NULL)
		{
			ft_lstadd_front(stack_b, ft_lstnew((node->next->cont)));
			free(node->next);
			node->next = NULL;
		}
		node = node->next;
	}
}

void	reverse_rotate_b(t_list **stack_b)
{
	just_reverse_rotate_b(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_r(t_list **stack_a, t_list **stack_b)
{
	just_reverse_rotate_a(stack_a);
	just_reverse_rotate_b(stack_b);
	write(1, "rrr\n", 4);
}
