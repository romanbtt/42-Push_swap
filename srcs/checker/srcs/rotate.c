/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:44:19 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 15:17:20 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** We point tmp to the lst.
** We point tmp2 to the second node of the list.
** We iterate until the last node is reached.
** Then we point the next of the last node to tmp.
** Now the last element become the first, and we have all the orginal list
** that follow. We have just to set to NULL the last element.
** Then we point back the lst to the tmp list.
*/

void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*lst) || !(*lst)->next)
		return ;
	else
	{
		tmp = *lst;
		tmp2 = (*lst)->next;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = tmp;
		tmp->next = NULL;
		*lst = tmp2;
	}
}

/*
** This function call two times the rotate function.
** One time to rotate stack a.
** Another time to rotate stack b.
*/

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
