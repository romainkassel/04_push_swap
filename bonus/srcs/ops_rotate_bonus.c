/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 12:10:17 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	just_rotate_a(t_list **stack_a)
{
	t_list	*tmp;

	if (!*stack_a || !stack_a)
		return ;
	ft_lstadd_back(stack_a, ft_lstnew((*stack_a)->cont));
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(tmp);
}

void	rotate_a(t_list **stack_a)
{
	just_rotate_a(stack_a);
	write(1, "ra\n", 3);
}

void	just_rotate_b(t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b || !stack_b)
		return ;
	ft_lstadd_back(stack_b, ft_lstnew((*stack_b)->cont));
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(tmp);
}

void	rotate_b(t_list **stack_b)
{
	just_rotate_b(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	just_rotate_a(stack_a);
	just_rotate_b(stack_b);
	write(1, "rr\n", 3);
}
