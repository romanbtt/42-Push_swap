/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:54:53 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/11 18:36:34 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long *insert_into_array(t_list *a, int size)
{
	long *arr;
	int i;

	i = 0;
	arr = malloc(sizeof(long) * size);
	if (!arr)
		exit_faillure("Error\n");
	while (a)
	{
		arr[i++] = a->content;
		a = a->next;
	}
	return (arr);
}

static void rotate_a(t_list **a, int nb)
{
	rotate(a);
	while (--nb > 0)
		rotate(a);
}

static void reverse_rotate_a(t_list **a, int nb)
{
	reverse_rotate(a);
	while (--nb >= 0)
		reverse_rotate(a);
}

int shortest_path(t_list **a, t_list **b, int mid, int size)
{
	int i;
	int top;
	int bottom;
	long *arr;

	i = 0;
	top = 0;
	bottom = 0;
	arr = insert_into_array(*a, size);
	while (arr[i++] >= mid)
		top++;
	while (arr[--size] >= mid)
		bottom++;
	if (top <= bottom)
		rotate_a(a, top);
	else
		reverse_rotate_a(a, bottom);
	free(arr);
	push(a, b);
}

int find_mid(t_list *a, int size)
{
	long *arr;
	int i;

	arr = insert_into_array(a, size);
	quicksort(arr, 0, size - 1);
	i = (int)arr[size / 2];
	free(arr);
	return (i);
	
}

void sort_stack(t_list **a, t_list **b)
{
	int	size_a;
	int	mid;
	int	size_chunk[32];
	int i;
	int	halh;
	
	i = 0;
	size_a = size_list(*a);
	while (size_a > 2)
	{
		size_chunk[i] = 0;
		mid = find_mid(*a, size_a);
		halh = size_a / 2;
		while (halh--)
		{
			if ((*a)->content < mid)
				push(a, b);
			else
				shortest_path(a, b, mid, size_a - size_chunk[i]);
			size_chunk[i]++;
		}
		size_a = size_list(*a);
		i++;
	}
	if ((*a)->content > (*a)->next->content)
		swap(a);
}