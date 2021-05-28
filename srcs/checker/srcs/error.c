/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:10:05 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 15:19:46 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
** Free_list simply iterate on the list and free each node.
*/

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
