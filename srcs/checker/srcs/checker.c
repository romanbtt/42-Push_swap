/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:35:35 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/06 12:34:23 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static bool	process_actions(char *action, t_list **a, t_list **b)
{
	if (!ft_strncmp(action, "sa", 3))
		swap(*a);
	else if (!ft_strncmp(action, "sb", 3))
		swap(*b);
	else if (!ft_strncmp(action, "ss", 3))
		swap_both(*a, *b);
	else if (!ft_strncmp(action, "pa", 3))
		push(b, a);
	else if (!ft_strncmp(action, "pb", 3))
		push(a, b);
	else if (!ft_strncmp(action, "ra", 3))
		rotate(a);
	else if (!ft_strncmp(action, "rb", 3))
		rotate(b);
	else if (!ft_strncmp(action, "rr", 3))
		rotate_both(a, b);
	else if (!ft_strncmp(action, "rra", 4))
		reverse_rotate(a);
	else if (!ft_strncmp(action, "rrb", 4))
		reverse_rotate(b);
	else if (!ft_strncmp(action, "rrr", 4))
		reverse_rotate_both(a, b);
	else
		return (0);
	return (1);
}

static bool	get_process_inputs(t_list **a, t_list **b)
{
	char	*action;
	int		ret;

	action = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &action);
		if ((!process_actions(action, a, b) || ret == -1) && ret != 0)
		{
			free(action);
			return (0);
		}
		free(action);
		print_stacks(*a, *b);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char	**seq;
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc != 1)
	{
		seq = get_arguments(argc, argv);
		if (!check_arguments(seq) || !fill_stack_a(&a, seq))
			exit_faillure("Error\n");
		if (!get_process_inputs(&a, &b))
		{
			free_checker(a);
			exit_faillure("Error\n");
		}	
	}
	if (!b && a && check_sort(a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_checker(a);
	return (0);
}
