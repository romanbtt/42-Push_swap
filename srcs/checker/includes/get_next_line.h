/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:01:04 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/04 09:47:32 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# define OPEN_MAX 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int	get_next_line(int fd, char **line);

#endif
