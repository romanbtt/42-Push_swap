/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:33:10 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 17:24:53 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Check_sort iterate on each node and check if the content of the next node is
** less than the content of the current node. If it is the case, we know that
** our stack is not sorted. We return false. Otherwise everything is sorted, we
** return true.
*/

bool	check_sort(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}
