/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:30:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/11 15:12:43 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static bool	fill_stack_a(t_list **a, char *args[])
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!create_node(a, ft_atoi(args[i++])))
		{
			ft_free_array_string(args);
			return (0);
		}	
	}
	ft_free_array_string(args);
	return (1);
}

int main(int argc, char *argv[])
{
	char **seq;
	t_list *a;
	t_list *b;

	b = NULL;
	if (argc != 1)
	{
		seq = get_arguments(argc, argv);
		if (!check_arguments(seq) || !fill_stack_a(&a, seq))
			exit_faillure("Error\n");
	}
	sort_stack(&a, &b);
}