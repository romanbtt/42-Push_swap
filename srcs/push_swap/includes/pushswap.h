/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:32:12 by romanbtt          #+#    #+#             */
/*   Updated: 2021/05/27 09:53:52 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef struct s_helper_b
{
	int		size;
	int		shortest_largest;
	int		shortest_sd_largest;
	bool	reverse;
	bool	from_sd;
}				t_helper_b;

bool	check_sort(t_list *a);

char	**get_arguments(int argc, char *argv[]);

bool	check_arguments(char *seq[]);

bool	create_node(t_list **list, int nb);
int		size_list(t_list *lst);

void	free_list(t_list *lst);
void	exit_faillure(char *error);

void	first_step_sort(t_list **a, t_list **b);

void	rotate_few(t_list **lst, int nb, char *print);
void	reverse_rotate_few(t_list **lst, int nb, char *print);
int		find_mid(t_list *lst, int size);

void	second_step_sort(t_list **a, t_list **b);
int		select_largest(t_list **b, int nb, t_helper_b *h, bool is_sd_largest);
void	shortest_path_second_step(t_list **b, int largest, int size);

void	sort_three_number(t_list **a);
long	*insert_into_array(t_list *lst, int size);

void	rotate_few_b(t_list **b, int nb);
void	reverse_rotate_few_b(t_list **lst, int nb);
void	push_largest(t_list **a, t_list **b, int largest, t_helper_b *h);
void	push_second_largest(t_list **a, t_list **b, int largest, t_helper_b *h);

void	push_largest(t_list **a, t_list **b, int largest, t_helper_b *h);
void	push_second_largest(t_list **a, t_list **b, int largest, t_helper_b *h);

void	quicksort(long arr[], int low, int high);

void	push(t_list **from, t_list **to, char *print);

void	reverse_rotate(t_list **lst, char *print);
void	reverse_rotate_both(t_list **a, t_list **b);

void	rotate(t_list **lst, char *print);
void	rotate_both(t_list **a, t_list **b);

void	swap(t_list *lst, char *print);
void	swap_both(t_list *a, t_list *b);

#endif