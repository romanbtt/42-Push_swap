/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:44:19 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/06 11:25:56 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	rotate_both(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
