/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:10:05 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/10 16:36:05 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exit_faillure(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

void free_checker(t_list *lst)
{
	t_list *tmp;
	
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
