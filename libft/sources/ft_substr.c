/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:17:24 by romanbtt          #+#    #+#             */
/*   Updated: 2021/04/30 14:42:22 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_s;
	size_t	i;

	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (s == NULL || ptr == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	while (start < len_s && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
