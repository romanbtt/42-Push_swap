/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:34:16 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 15:18:43 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** This function return the last node of a list.
*/

t_list	*last_node(t_list *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

/*
** This function create a new node with the content nb and add it to the list.
** Return false, if it fail. And true if everything went well.
*/

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
