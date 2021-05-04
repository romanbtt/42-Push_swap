/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 18:55:31 by romanbtt          #+#    #+#             */
/*   Updated: 2021/04/30 13:53:26 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delchar(char *str, char set)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != set)
			str[n++] = str[i];
		i++;
	}
	str[n] = '\0';
}
