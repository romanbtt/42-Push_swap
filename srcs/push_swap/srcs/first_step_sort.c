/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:54:53 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 10:50:59 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** We push the number of the top of stack a to stack b.
** We check if this number (now on stack b) is less than the mid value
** of stack b. If it is the case, we know than we can rotate the first two 
** values of stack b because we want the low values at the bottom of stack b.
** We also check in this condition if we need to rotate the first two values
** of stack a. If it is the case we call rotate_both to rotate the first two
** values of the two stacks at the same time. 
*/

static void	push_reorder(t_list **a, t_list **b, int mid_a)
{
	int	size_b;

	push(a, b, "pb\n");
	size_b = size_list(*b);
	if ((*b)->content < find_mid(*b, size_b) && (*b)->next)
	{
		if ((*a)->content > mid_a)
			rotate_both(a, b);
		else
			rotate(b, "rb\n");
	}
}

/*
** This function find the shortest way to move the first number less than mid
** that we find. It will count from the top and from the bottom and compare
** these two values. If top is less than bottom, we call the rotate_few to put
** this number at the top.
** If bottom is less than top, we call reverse_rotate_few to put 
** this number at the top. Then we cann call push_reorder to push to stack b.
*/

static void	shortest_path_first_step(t_list **a, t_list **b, int mid, int size)
{
	int		i;
	int		top;
	int		bottom;
	long	*arr;

	i = 0;
	top = 0;
	bottom = 0;
	arr = insert_into_array(*a, size);
	while (arr[i++] >= mid)
		top++;
	while (arr[--size] >= mid)
		bottom++;
	if (top <= bottom)
		rotate_few(a, top, "ra\n");
	else
		reverse_rotate_few(a, bottom, "rra\n");
	free(arr);
	arr = NULL;
	push_reorder(a, b, mid);
}

/*
** The first step of sorting is to optimize the push to stack b.
** For this, we will find the mid value of the stack a. And send the numbers
** that are less than mid value to stack b. If value of stack a is less than
** mid value. We call push_reoder. If not, we call shortest_path_first_step to
** find the shortest way to move the first number less than mid to the top of
** stack a. Each time we are dividing the stack by 2. So we are creating chunks
** into stack b. Numbers inside chunks are not yet sorted, but the chunks are.
** The minimum value of the chunk of top of b, is always greater than the max
** value of previous chunk.
** We do that intil stack a contain 3 numbers. When it contains 3
** numbers, we call sort_three_number to sort these 3 numbers.
** Then we call the second step of sorting.
*/

void	first_step_sort(t_list **a, t_list **b)
{
	int	size_a;
	int	mid;
	int	size_chunk;
	int	half;

	size_a = size_list(*a);
	while (size_a > 3)
	{
		size_chunk = 0;
		mid = find_mid(*a, size_a);
		half = size_a / 2;
		while (half--)
		{
			if ((*a)->content < mid)
				push_reorder(a, b, mid);
			else
				shortest_path_first_step(a, b, mid, size_a - size_chunk);
			size_chunk++;
		}
		size_a = size_list(*a);
	}
	sort_three_number(a);
	second_step_sort(a, b);
}
