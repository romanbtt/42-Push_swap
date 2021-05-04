/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:15:17 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/03 23:07:04 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void debug_print_array(long arr[], int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%ld ", arr[i]);
		i++;
	}
	printf("\n");
}