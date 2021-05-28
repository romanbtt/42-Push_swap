/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:43:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 16:56:46 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** This function push the first element of a stack to the top of another stack.
** We save the list from where we want to push inside a tmp variable.
** We increment the head of the from list by one.
** We assign to the next node of tmp, the other list where we want to push.
** Finally we assign the tmp list to the to list.
*/

void	push(t_list **from, t_list **to)
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
}
