/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:43:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/06 11:23:59 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
