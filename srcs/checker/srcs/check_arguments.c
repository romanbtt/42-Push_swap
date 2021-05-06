/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:11:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/06 12:26:10 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	lenght_array(char *array[])
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static bool	check_digits(char *seq[])
{
	int	i;
	int	j;

	i = 0;
	while (seq[i])
	{
		j = 0;
		while (seq[i][j])
		{
			if (seq[i][0] == '-')
				j++;
			if (!ft_isdigit(seq[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static bool	check_duplicate(long arr[], int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

bool	check_arguments(char *seq[])
{
	int		i;
	long	*arr;

	if (!check_digits(seq))
		return (0);
	i = 0;
	arr = malloc(sizeof(long) * lenght_array(seq));
	if (!arr)
		return (0);
	while (seq[i])
	{
		arr[i] = ft_atol(seq[i]);
		if (arr[i++] > 2147483647)
			return (0);
	}
	quicksort(arr, 0, i - 1);
	if (!check_duplicate(arr, i))
		return (0);
	return (1);
}


