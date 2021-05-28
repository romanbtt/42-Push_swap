/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:45:03 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 15:07:33 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** We first assign to tmp and tmp2, the entire list.
** We iterate until the next of tmp is null to be able to catch the noce before
** the last one. And we store it inside tmp2. Tmp contain the last node.
** We assign to null the next node of tmp2.
** So the node before the last one is now the last.
** We now reassign the lst to the next node of tmp. So now, the last node is
** now the first and the next nodes are the nodes of the original list.
** Execpt for the last one.
** Finally we point back the lst to tmp.
*/

void	reverse_rotate(t_list **lst, char *print)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*lst) || !(*lst)->next)
		return ;
	else
	{
		tmp = *lst;
		tmp2 = *lst;
		while (tmp->next)
		{
			if (tmp->next->next)
				tmp2 = tmp2->next;
			tmp = tmp->next;
		}
		tmp2->next = NULL;
		tmp->next = *lst;
		*lst = tmp;
	}
	ft_putstr_fd(print, 1);
}

/*
** This function call two times the reverse rotate function.
** One time to reverse rotate stack a.
** Another time to reverse rotate stack b.
*/

void	reverse_rotate_both(t_list **a, t_list **b)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	ft_putstr_fd("rrr\n", 1);
}
