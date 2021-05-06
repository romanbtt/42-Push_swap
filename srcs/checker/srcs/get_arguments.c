/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:03:35 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/06 11:23:02 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	**one_line_arguments(char *argv[])
{
	char	**seq;

	seq = ft_split(argv[1], ' ');
	if (!seq)
		exit_faillure("Ft_split : Error\n");
	return (seq);
}

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

char	**get_arguments(int argc, char *argv[])
{
	char	**seq;
	int		i;

	if (argc == 2)
		seq = one_line_arguments(argv);
	else
		seq = separate_arguments(argc, argv);
	return (seq);
}
