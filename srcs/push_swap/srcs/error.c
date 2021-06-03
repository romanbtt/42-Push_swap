/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:10:05 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/31 10:45:47 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function print the error message in paramenter on the STDERR.
** Then exit the program.
*/

void	exit_faillure(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

/*
** Free_list simply iterate on the lists and free each node.
*/

void	free_list(t_list *a, t_list *b)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
}
