/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:47:22 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 10:56:02 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function rotate until the number of move needed is reached.
*/

void	rotate_few(t_list **lst, int nb, char *print)
{
	rotate(lst, print);
	while (--nb > 0)
		rotate(lst, print);
}

/*
** This function reverse rotate until the number of move needed is reached.
*/

void	reverse_rotate_few(t_list **lst, int nb, char *print)
{
	reverse_rotate(lst, print);
	while (--nb >= 0)
		reverse_rotate(lst, print);
}

/*
** This function will find the mid value of a stack.
** To do that, we first sorted the stack with a quicksort.
** Then we take the value at the middle of the sorted array.
*/

int	find_mid(t_list *lst, int size)
{
	long	*arr;
	int		i;

	arr = insert_into_array(lst, size);
	quicksort(arr, 0, size - 1);
	i = (int)arr[size / 2];
	free(arr);
	arr = NULL;
	return (i);
}
