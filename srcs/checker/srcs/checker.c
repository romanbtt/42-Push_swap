/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:35:35 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/04 13:42:34 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_faillure(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

void	execute_actions(char *action)
{
	int len;

	len = ft_strlen(action) + 1;
	if (action[0] == 's')
		ft_putstr_fd("swap\n", 1);
	else if (action[0] == 'p')
		ft_putstr_fd("push\n", 1);
	else if (action[0] == 'r' && action[2])
		ft_putstr_fd("reverse rotate\n", 1);
	else
		ft_putstr_fd("rotate\n", 1);

}

void	check_input(char *action)
{
	int len;

	len = ft_strlen(action) + 1;
	if (!ft_strncmp(action, "sa", len) || !ft_strncmp(action, "sb", len)
		|| !ft_strncmp(action, "ss", len) || !ft_strncmp(action, "pa", len)
		|| !ft_strncmp(action, "pb", len) || !ft_strncmp(action, "ra", len)
		|| !ft_strncmp(action, "rb", len) || !ft_strncmp(action, "rr", len)
		|| !ft_strncmp(action, "rra", len) || !ft_strncmp(action, "rrb", len)
		|| !ft_strncmp(action, "rrr", len))
		return ;
	else
		exit_faillure("Error\n");
}
	

void	get_inputs()
{
	char *action;

	action = NULL;
	while (get_next_line(STDIN_FILENO, &action) > 0)
	{
		check_input(action);
		execute_actions(action);
		free(action);
	}
	free(action);
}

void check_sorting()
{
	get_inputs();
	check_sorting();
}



void	check_duplicate(long arr[], int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
			exit_faillure("Error\n");
		i++;
	}
}

int	count_check_digit(char *args[])
{
	int i;
	int j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][0] == '-')
				j++;
			if (!ft_isdigit(args[i][j]))
				exit_faillure("Error\n");
			j++;
		}
		i++;
	}
	return (i);
}

void	check_arguments(char *args[])
{
	int i;
	int j;
	int k;
	long *arr;
	
	i = count_check_digit(args);
	j = 0;
	k = i;
	arr = malloc(sizeof(long) * i);
	if (!arr)
		exit_faillure("Malloc : Error\n");
	while (i--)
	{
		arr[j] = ft_atol(args[j]);
		if (arr[j] > 2147483647)
			exit_faillure("Error\n");
		j++;
	}
	quicksort(arr, 0, k - 1);
	check_duplicate(arr, k);
	//debug_print_array(arr, k);
}

char	**get_arguments(int argc, char *argv[])
{
	char **args;
	int i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			exit_faillure("Ft_split : Error\n");
	}	
	else
	{
		i = 0;
		args = malloc(sizeof(char*) * (argc));
		if (!args)
			exit_faillure("Malloc : Error\n");
		while (--argc)
		{
			args[i] = ft_strdup(argv[i + 1]);
			if (!args[i])
				exit_faillure("Ft_strdup : Error\n");
			i++;
		}
		args[i] = NULL;
	}
	return (args);
}

int	main(int argc, char *argv[])
{
	char **args;
	
	if (argc != 1)
	{
		args = get_arguments(argc, argv);
		check_arguments(args);
		check_sorting();
	}	
	return (0);
}