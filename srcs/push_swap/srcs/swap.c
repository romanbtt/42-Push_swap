/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:43:00 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/11 16:51:32 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_list *lst)
{
	int	tmp;

	if (!lst || !lst->next)
		return ;
	else
	{
		tmp = lst->content;
		lst->content = lst->next->content;
		lst->next->content = tmp;
	}
}

void	swap_both(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
}
