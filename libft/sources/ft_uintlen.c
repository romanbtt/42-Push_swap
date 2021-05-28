/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:28:39 by romanbtt          #+#    #+#             */
/*   Updated: 2021/04/30 14:45:03 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uintlen(unsigned int nb, int base)
{
	size_t	len;

	len = 1;
	while ((nb / base) > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}
