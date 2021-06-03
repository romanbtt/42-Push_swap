/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:42:36 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 14:07:38 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** This function rotate until the number of move needed is reached.
*/

void	rotate_few_b(t_list **b, int nb)
{
	while (nb-- > 0)
		rotate(b, "rb\n");
}

/*
** This function reverse rotate until the number of move needed is reached.
*/

void	reverse_rotate_few_b(t_list **lst, int nb)
{
	while (nb-- > 0)
		reverse_rotate(lst, "rrb\n");
}

/*
** This function moves the largest number at the top with the help of
** the shortest_path_second_step function.
** Then we push the top number to stack a.
** If this function is called from push_second_largest. We swap the first two
** numbers of stack a. Since we first send the second largest, then the largest
*/

void	push_largest(t_list **a, t_list **b, int largest, t_helper_b *h)
{
	shortest_path_second_step(b, largest, size_list(*b));
	push(b, a, "pa\n");
	if (h->from_sd == true)
		swap(*a, "sa\n");
}

/*
** This function reverse rotate only if the flag reverse is activated.
** This flag in true only if the shortest path is from the bottom and
** we deal with the second largest element to send first.
** Otherwise we call rotate_few to rotate from the top.
** Then we push the top number (second largest) to stack a.
** We activated the flag (from second largest). and call the function to
** push the largest number.
*/

void	push_second_largest(t_list **a, t_list **b, int largest, t_helper_b *h)
{
	if (h->reverse == true)
		reverse_rotate_few_b(b, h->shortest_sd_largest);
	else
		rotate_few_b(b, h->shortest_sd_largest);
	push(b, a, "pa\n");
	h->from_sd = true;
	push_largest(a, b, largest, h);
}
