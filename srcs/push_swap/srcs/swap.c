/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:43:00 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 14:51:09 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function swap the two first value at the top of a stack.
** We save the first value inside a tmp variable.
** We assign the value of the second element to the first.
** We assign the value of the tmp to the second element.
*/

void	swap(t_list *lst, char *print)
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
	ft_putstr_fd(print, 1);
}

/*
** This function call two times the swap function.
** One time to swap stack a.
** Another time to swap stack b.
*/

void	swap_both(t_list *a, t_list *b)
{
	swap(a, "");
	swap(b, "");
	ft_putstr_fd("ss\n", 1);
}
