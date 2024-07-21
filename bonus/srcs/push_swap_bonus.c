/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 14:46:42 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_ptrs	ptrs;
	int		arg_count;

	if (argc < 2)
		return (FAIL);
	if (check_nul(argv) == FAIL)
		return (display_message(NULL, FAIL), FAIL);
	init_ptrs(&ptrs);
	arg_count = get_arg_count(argv, &ptrs);
	expand_argv(argv, arg_count, &ptrs);
	if (check_args(ptrs.exp_argv) == FAIL)
		return (display_message(NULL, FAIL), free_ptrs(&ptrs), FAIL);
	(init_stacks(&ptrs, arg_count), fill_stack_a(&ptrs, arg_count));
	if (check_dups_zith_0_before(&ptrs) == FAIL)
		return (display_message(NULL, FAIL), free_ptrs(&ptrs), FAIL);
	if (is_stack_a_ordered(&ptrs) == SUCCESS && !(*ptrs.stack_b)
		&& is_stack_a_complete(&ptrs, arg_count) == SUCCESS)
		return (write(1, "OK\n", 3), free_ptrs(&ptrs), SUCCESS);
	do_the_trick(&ptrs);
	if (is_stack_a_ordered(&ptrs) == SUCCESS && !(*ptrs.stack_b)
		&& is_stack_a_complete(&ptrs, arg_count) == SUCCESS)
		return (write(1, "OK\n", 3), free_ptrs(&ptrs), SUCCESS);
	else
		return (write(1, "KO\n", 3), free_ptrs(&ptrs), FAIL);
}
