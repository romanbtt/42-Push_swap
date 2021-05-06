/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:15:17 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/06 15:30:13 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_space(int nb_space)
{
	while (nb_space--)
		ft_putstr_fd(" ", 1);
}

int	size_list_debug(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	print_stacks(t_list *a, t_list *b)
{
	int		max_len;
	t_list	*a_print;
	t_list	*b_print;

	a_print = a;
	b_print = b;
	max_len = size_list_debug(a);
	if (size_list_debug(b) > max_len)
		max_len = size_list_debug(b);
	ft_putchar_fd('\n', 1);
	while (max_len-- > 0)
	{
		if (a_print && b_print)
		{
			ft_putnbr_fd(a_print->content, 1);
			print_space(11 - ft_intlen(a_print->content, 10));
			ft_putnbr_fd(b_print->content, 1);
			ft_putchar_fd('\n', 1);
			a_print = a_print->next;
			b_print = b_print->next;
			continue ;
		}
		if (a_print && !b_print)
		{
			ft_putnbr_fd(a_print->content, 1);
			print_space(11 - ft_intlen(a_print->content, 10));
			a_print = a_print->next;
		}
		if (!a_print && b_print)
		{
			print_space(11);
			ft_putnbr_fd(b_print->content, 1);
			ft_putchar_fd('\n', 1);
			b_print = b_print->next;
		}
		else
			ft_putchar_fd('\n', 1);
	}
	ft_putstr_fd("_          _\n", 1);
	ft_putstr_fd("a          b\n\n", 1);
}
