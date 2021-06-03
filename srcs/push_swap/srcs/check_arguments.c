/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:11:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/31 16:05:11 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function return the lenght of a double array of strings
** It iterate on array with a counter I. And we return the counter.
*/

static int	lenght_array(char *array[])
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/*
** This function iterate on each character to check if there are all digits.
** If one of them is not a digit, we return false.
** Otherwise we return true.
*/

static bool	check_digits(char *seq[])
{
	int		i;
	int		j;
	bool	neg;

	i = 0;
	neg = false;
	while (seq[i])
	{
		j = 0;
		while (seq[i][j])
		{
			if (seq[i][0] == '-' && !neg)
			{
				j++;
				neg = true;
			}	
			if (!ft_isdigit(seq[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
** Here, we take our array sorted, and check if the next value is equal
** to the current value. If it is the case, we return false.
** If there is no duplicate, we return true.
*/

static bool	check_duplicate(long arr[], int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
			return (false);
		i++;
	}
	return (true);
}

/*
** We first send the souble array to check_digits to verify if all
** all the arguments are numerical.
** Then we transfer and convert into numerical value the arguments to
** an array of longs. We sorted this array with a quicksort.
** Finally we check for duplicate value inside the array of long.
** If everything went correctly, we return true. Otherwise we return false.
*/

bool	check_arguments(char *seq[])
{
	int		i;
	long	*arr;

	if (!check_digits(seq))
		return (false);
	i = 0;
	arr = malloc(sizeof(long) * lenght_array(seq));
	if (!arr)
		return (false);
	while (seq[i])
	{
		arr[i] = ft_atol(seq[i]);
		if (arr[i] > 2147483647 || arr[i++] < -2147483648)
			return (false);
	}
	quicksort(arr, 0, i - 1);
	if (!check_duplicate(arr, i))
	{
		free(arr);
		return (false);
	}
	free(arr);
	return (true);
}
