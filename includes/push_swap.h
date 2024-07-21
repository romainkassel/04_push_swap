/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:29:51 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 11:04:07 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// header includes

# include "../libft/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"

// return status

# define SUCCESS 0
# define FAIL 1

typedef struct s_ptrs
{
	char	**exp_argv;
	char	**tab;
	char	**tab_count;
	t_list	**stack_a;
	t_list	**stack_b;
	int		*argv_numbers;

}		t_ptrs;

typedef struct s_costs
{
	int		tmp_cost_a;
	int		tmp_cost_b;
	int		tmp_tot_cost;
	int		tmp_common_ops;
	int		cost_a;
	int		cost_b;
	int		tot_cost;
	int		common_ops;
	int		med_a;
	int		med_b;
	char	*side_a;
	char	*side_b;
}		t_costs;

// expand_argv 

int		get_arg_count(char **argv, t_ptrs *ptrs);
void	expand_argv(char **argv, int arg_count, t_ptrs *ptrs);

// check_args.c

int		check_args(char **argv);
int		check_nul(char **argv);
int		check_dups_zith_0_before(t_ptrs *ptrs);

// fill_stack.c

void	init_stacks(t_ptrs *ptrs, int arg_count);
void	fill_stack_a(t_ptrs *ptrs, int arg_count);

// ops

void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_s(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_r(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_r(t_list **stack_a, t_list **stack_b);

// clean and quiet

void	quit_prog(t_ptrs *ptrs, char *status_message, int exit_status);
void	init_ptrs(t_ptrs *ptrs);
void	free_ptrs(t_ptrs *ptrs);
void	free_tab(char **tab);
void	ft_lstfree(t_list **lst);
void	display_message(char *status_message, int exit_status);

// do_the_trick

void	do_the_trick(t_ptrs *ptrs);
void	sort_3_nodes(t_ptrs *ptrs);
int		is_stack_a_ordered(t_ptrs *ptrs);
void	init_targs(t_list **stack);
void	get_targs(t_ptrs *ptrs);

void	get_cheapest_node_data(t_ptrs *ptrs, t_costs *costs);
void	get_node_i(t_ptrs *ptrs);
void	get_node_i_stack(t_list **stack);
void	init_costs(t_costs *costs);

void	get_init_tmp_costs(t_costs *costs, t_ptrs *ptrs, t_list *node);
int		get_node_cost(t_list *stack_node, int stack_len);
void	get_medians(t_costs *costs, t_ptrs *ptrs);
int		get_median(int stack_len);

void	update_tmp_costs(t_costs *costs);
void	update_tmp_costs_if_a_bigger(t_costs *costs);
void	update_tmp_costs_if_b_bigger(t_costs *costs);
void	update_tmp_costs_if_a_b_equal(t_costs *costs);
void	update_tmp_costs_if_same_i(t_costs *costs);

void	update_tot_cost_data(t_costs *costs, t_list *node);
void	put_nodes_to_top(t_list **stack_a, t_list **stack_b, t_costs *costs);
void	combine_ops(t_list **stack_a, t_list **stack_b, t_costs *costs);

void	put_smallest_node_to_top(t_list **stack_a, t_costs	*costs);
t_list	*get_smallest_node(t_list **stack_a);
void	get_node_data(t_list **stack_a, t_list *smallest_node, t_costs *costs);
void	put_node_to_top(t_list **stack_a, t_costs *costs);
int		is_stack_a_complete(t_ptrs *ptrs, int arg_count);

#endif
