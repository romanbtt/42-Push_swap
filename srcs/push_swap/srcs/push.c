/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:43:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 14:54:33 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function push the first element of a stack to the top of another stack.
** We save the list from where we want to push inside a tmp variable.
** We increment the head of the from list by one.
** We assign to the next node of tmp, the other list where we want to push.
** Finally we assign the tmp list to the to list.
*/

void	push(t_list **from, t_list **to, char *print)
{
	t_list	*tmp;

	if (!(*from))
		return ;
	else
	{
		tmp = *from;
		*from = (*from)->next;
		tmp->next = *to;
		*to = tmp;
	}
	ft_putstr_fd(print, 1);
}
