/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:34:16 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/06 15:28:54 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*last_node(t_list *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

bool	create_node(t_list **list, int nb)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *list;
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	else
	{
		new->content = nb;
		new->next = NULL;
		if (*list)
		{
			tmp = last_node(tmp);
			tmp->next = new;
		}
		else
			*list = new;
	}
	return (1);
}
