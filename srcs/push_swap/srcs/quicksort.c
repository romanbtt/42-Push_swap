/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:16:36 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 11:18:15 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function swap two pointer of long.
*/

static void	swap_long(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** We choose the last element of the array as pivot.
** Then we swap to put all the element less than pivot at the left of
** the pivot.
*/

static int	partition(long arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
			swap_long(&arr[++i], &arr[j]);
		j++;
	}
	swap_long(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/*
** Quicksort recurse until the low is not smaller than the high.
** The pivot choose in the partition function. The swap is done as well in
** the partition function. Then we recurse.
*/

void	quicksort(long arr[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}
