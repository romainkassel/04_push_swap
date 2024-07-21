/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_argv_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:31:46 by rkassel           #+#    #+#             */
/*   Updated: 2024/07/08 12:10:17 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	get_arg_count(char **argv, t_ptrs *ptrs)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		ptrs->tab_count = ft_split(argv[i], ' ');
		if (!ptrs->tab_count)
			quit_prog(ptrs, NULL, FAIL);
		j = 0;
		while (ptrs->tab_count[j++])
			count++;
		free_tab(ptrs->tab_count);
		i++;
	}
	ptrs->tab_count = NULL;
	return (count);
}

void	expand_argv(char **argv, int arg_count, t_ptrs *ptrs)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	ptrs->exp_argv = (char **)ft_calloc(sizeof(char *), (arg_count + 1));
	if (!ptrs->exp_argv)
		quit_prog(ptrs, NULL, FAIL);
	while (argv[i])
	{
		ptrs->tab = ft_split(argv[i++], ' ');
		if (!ptrs->tab)
			quit_prog(ptrs, NULL, FAIL);
		j = 0;
		while (ptrs->tab[j])
		{
			ptrs->exp_argv[k] = ft_strdup(ptrs->tab[j++]);
			if (!ptrs->exp_argv[k])
				quit_prog(ptrs, NULL, FAIL);
			k++;
		}
		free_tab(ptrs->tab);
		ptrs->tab = NULL;
	}
}
