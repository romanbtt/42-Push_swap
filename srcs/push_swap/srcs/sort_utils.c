/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:14:46 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 14:34:15 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function return the largest element found in a list.
** We first assign the min value possible to largest.
** Then we iterate on the list, if the element is greater than the current
** largest, then we assign the element to largest.
*/

static int	find_largest(t_list *lst)
{
	int	largest;

	largest = INT_MIN;
	while (lst != NULL)
	{
		if (largest < lst->content)
			largest = lst->content;
		lst = lst->next;
	}
	return (largest);
}

/*
** This function sort in the most efficient way three number or less.
** If the first element is equal to the largest element of these 3 numbers.
** We send it to the bottom with rotate.
** If the first element is greater than the second, we swap these two.
** Else we do a reverse rotate. This way, the maximum move to sort 3 numbers
** or less take no more than 2 moves.
*/

void	sort_three_number(t_list **a)
{
	while (check_sort(*a) == false)
	{
		if ((*a)->content == find_largest(*a))
			rotate(a, "ra\n");
		else if ((*a)->content > (*a)->next->content)
			swap(*a, "sa\n");
		else
			reverse_rotate(a, "rra\n");
	}
}

/*
** This function insert all the content of a list inside a array of long.
*/

long	*insert_into_array(t_list *lst, int size)
{
	long	*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(long) * size);
	if (!arr)
		exit_faillure("Error\n");
	while (lst)
	{
		arr[i++] = lst->content;
		lst = lst->next;
	}
	return (arr);
}
