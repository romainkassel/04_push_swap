/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 12:10:17 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->cont));
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(tmp);
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->cont));
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(tmp);
	write(1, "pb\n", 3);
}
