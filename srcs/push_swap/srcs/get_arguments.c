/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:03:35 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 09:51:14 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function simply use ft_split to get the arguments and store them into
** a double array of strings.
*/

static char	**one_line_arguments(char *argv[])
{
	char	**seq;

	seq = ft_split(argv[1], ' ');
	if (!seq)
		exit_faillure("Ft_split : Error\n");
	return (seq);
}

/*
** This function will iterate on each arguments and make a duplication of
** the arguments and store them inside a double array of strings.
** Then we terminate the array with NULL.
*/

static char	**separate_arguments(int argc, char *argv[])
{
	char	**seq;
	int		i;

	i = 0;
	seq = malloc(sizeof(char *) * argc);
	if (!seq)
		exit_faillure("Malloc : Error\n");
	while (argv[i + 1])
	{
		seq[i] = ft_strdup(argv[i + 1]);
		if (!seq[i])
		{
			ft_free_array_string(seq);
			exit_faillure("Ft_strdup : Error\n");
		}	
		i++;
	}
	seq[i] = NULL;
	return (seq);
}

/*
** This function will decide which method will be use to get the arguments
** depending of how the arguments has been send. In quotes or not.
** If the arguments arrive between quote, it will go to one_line_arguments.
** Otherwise it will go to separate_arguments.
*/

char	**get_arguments(int argc, char *argv[])
{
	char	**seq;

	if (argc == 2)
		seq = one_line_arguments(argv);
	else
		seq = separate_arguments(argc, argv);
	return (seq);
}
