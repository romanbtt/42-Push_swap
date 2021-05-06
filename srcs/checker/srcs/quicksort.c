/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:16:36 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/06 12:12:04 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_long(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(long arr[], int low, int high)
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
