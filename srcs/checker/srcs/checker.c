/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:35:35 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/31 14:45:06 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** This function will insert into a stack (linked list) all the arguments.
** It iterate on the double array and each time create a node with the
** return of ft_atoi. If create_node failed, we freed the double array and
** return false to exit the program. Otherwise we freed the array and return
** true to continue with the sorting.
*/

static bool	fill_stack_a(t_list **a, char *args[])
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!create_node(a, ft_atoi(args[i++])))
			return (false);
	}
	return (true);
}

/*
** This function check if the input match an action.
** If yes, it will send to the right funtion. If not it will return false.
*/

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
		return (false);
	return (true);
}

/*
** This function wait for any inputs on the stdin.
** Get_next_line catch these inputs. And we send them through the
** process action function. If this function return false. It means that
** the inputs doesn't match an action.
*/

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
			return (false);
		}
		free(action);
	}
	return (true);
}

/*
** We check first if there is an argument, if not we can pass the verifications
** of the arguments and return. We put the arguments in a double array string.
** We send this array for checking, then we fill the stack A.
** If one of them failed to execute, we freed stack A, the double array and
** return an error.
** We call get_process_inputs to get the action to execute.
** Then we can verify is the stack is sorted and print the result.
*/

int	main(int argc, char *argv[])
{
	char	**seq;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	seq = get_arguments(argc, argv);
	if (!check_arguments(seq) || !fill_stack_a(&a, seq)
		|| !get_process_inputs(&a, &b))
	{
		free_list(a, b);
		ft_free_array_string(seq);
		exit_faillure("Error\n");
	}
	if (!b && a && check_sort(a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_list(a, b);
	ft_free_array_string(seq);
	return (0);
}
