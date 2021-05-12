/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:32:12 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/11 16:51:10 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

void	exit_faillure(char *error);
void 	free_checker(t_list *lst);

char	**get_arguments(int argc, char *argv[]);

bool	check_arguments(char *seq[]);

bool	create_node(t_list **list, int nb);

void	quicksort(long arr[], int low, int high);

void 	sort_stack(t_list **a, t_list **b);

void	push(t_list **from, t_list **to);

void	rotate(t_list **lst);
void	rotate_both(t_list **a, t_list **b);

void	reverse_rotate(t_list **lst);
void	reverse_rotate_both(t_list **a, t_list **b);

void	swap(t_list *lst);

#endif