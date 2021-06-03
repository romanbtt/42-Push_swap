/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:34:54 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/31 10:44:45 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

bool	create_node(t_list **list, int nb);
t_list	*last_node(t_list *node);
int		size_list(t_list *list);

void	exit_faillure(char *error);
void	free_list(t_list *a, t_list *b);

void	quicksort(long arr[], int low, int high);

bool	check_arguments(char *seq[]);

char	**get_arguments(int argc, char *argv[]);
bool	check_sort(t_list *a);

void	swap(t_list *lst);
void	swap_both(t_list *a, t_list *b);

void	push(t_list **from, t_list **to);

void	rotate(t_list **lst);
void	rotate_both(t_list **a, t_list **b);

void	reverse_rotate(t_list **lst);
void	reverse_rotate_both(t_list **a, t_list **b);

#endif