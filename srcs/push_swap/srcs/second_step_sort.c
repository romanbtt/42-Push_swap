/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:55:39 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 16:56:09 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function find the shortest way to move the largest number at the top.
** It will count from the top and from the bottom and compare
** these two values. If top is less than bottom, we call the rotate_few to put
** this number at the top.
** If bottom is less than top, we call reverse_rotate_few to put 
** this number at the top.
*/

void	shortest_path_second_step(t_list **b, int largest, int size)
{
	int		i;
	int		top;
	int		bottom;
	long	*arr;

	i = 0;
	top = 0;
	bottom = 1;
	arr = insert_into_array(*b, size);
	while (arr[i++] != largest)
		top++;
	while (arr[--size] != largest)
		bottom++;
	if (top <= bottom)
		rotate_few_b(b, top);
	else
		reverse_rotate_few_b(b, bottom);
	free(arr);
	arr = NULL;
}

/*
** This function return the shortest path to put the largest or second largest
** to the top of stack b.
** If the shortest path is from the bottom and we are looking for the second
** largest. We activate a reverse flag. THis flag will help to know if we have
** to process with a reverse rotate.
*/

int	select_largest(t_list **b, int nb, t_helper_b *h, bool is_sd_largest)
{
	int		i;
	int		top;
	int		bottom;
	int		tpm_size;
	long	*arr;

	i = 0;
	top = 0;
	bottom = 1;
	tpm_size = h->size;
	arr = insert_into_array(*b, h->size);
	while (arr[i++] != nb)
		top++;
	while (arr[--h->size] != nb)
		bottom++;
	h->size = tpm_size;
	free(arr);
	if (top <= bottom)
		return (top);
	else
	{
		if (is_sd_largest == true)
			h->reverse = true;
		return (bottom);
	}	
}
/*
** The actions of second_step_sort are executed until stack b is empty.
** We located the largest and the second largest of stack b.
** We calcul the shortest distance of the largest and second largest.
** If second largest has the shortest path to the top, we send it to stack a,
** then, we send the largest and we swap the first two element of stack a.
** Otherwise, we send the largest to stack a.
*/

void	second_step_sort(t_list **a, t_list **b)
{
	long		*arr;
	t_helper_b	h;

	while (*b)
	{
		ft_bzero(&h, sizeof(t_helper_b));
		h.size = size_list(*b);
		arr = insert_into_array(*b, h.size);
		quicksort(arr, 0, h.size - 1);
		h.shortest_largest = select_largest(b, arr[h.size - 1], &h, false);
		if (h.size != 1)
			h.shortest_sd_largest = select_largest(b, arr[h.size - 2],
					&h, true);
		if (h.shortest_sd_largest < h.shortest_largest)
			push_second_largest(a, b, arr[h.size - 1], &h);
		else
			push_largest(a, b, arr[h.size - 1], &h);
		free(arr);
	}
}
