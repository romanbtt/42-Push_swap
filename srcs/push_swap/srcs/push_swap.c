/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:30:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/31 10:46:11 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** Check_sort iterate on each node and check if the content of the next node is
** less than the content of the current node. If it is the case, we know that
** our stack is not sorted. We return false. Otherwise everything is sorted, we
** return true.
*/

bool	check_sort(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}

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
		{
			ft_free_array_string(args);
			return (false);
		}	
	}
	ft_free_array_string(args);
	return (true);
}

/*
** We check first if there is an argument, if not we can pass the verifications
** of the arguments and return. We put the arguments in a double array string.
** We send this array for checking, then we fill the stack A.
** If one of them failed to execute, we freed stack A, the double array and
** return an error.
** We check if stack A is already sorted before we start the sorting.
** Then we stack a and b to sorting. We it return from first_step_sort, we
** freed stack a to avoid memory leaks.
*/

int	main(int argc, char *argv[])
{	
	char	**seq;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc != 1)
	{
		seq = get_arguments(argc, argv);
		if (!check_arguments(seq) || !fill_stack_a(&a, seq))
		{
			free_list(a, b);
			ft_free_array_string(seq);
			exit_faillure("Error\n");
		}	
	}
	else
		return (0);
	if (check_sort(a) == true)
	{
		free_list(a, b);
		return (1);
	}	
	first_step_sort(&a, &b);
	free_list(a, b);
}
