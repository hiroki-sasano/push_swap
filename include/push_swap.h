/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:45:13 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/14 20:17:46 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "error.h"

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
}					t_node;

/* make_list.c*/
t_ps_err			my_atoi(const char *str, int *out);
t_ps_err			make_list(int argc, char **argv, t_node **a);
void				free_list(t_node *head);
void				err_exit(t_node **a, t_node **b, t_ps_err st);

/* ope_swap */
void				ss(t_node **stac_a, t_node **stac_b);
void				sb(t_node **stac_b);
void				sa(t_node **stac_a);
void				ope_swap(t_node **stac);

/* ope_push */
void				pb(t_node **stac_a, t_node **stac_b);
void				pa(t_node **stac_a, t_node **stac_b);
void				move_top(t_node **dst, t_node **src);

/* ope_rotate*/
void				ope_rotate(t_node **stac);
void				ra(t_node **stac_a);
void				rb(t_node **stac_b);
void				rr(t_node **stac_a, t_node **stac_b);

/* ope_rev */
void				ope_rev(t_node **stac);
void				rra(t_node **stac_a);
void				rrb(t_node **stac_b);
void				rrr(t_node **stac_a, t_node **stac_b);

/* index_list*/
int					found_next(t_node *head, int cur_n);
int					index_list(t_node **head);
int					list_count(t_node *head);

/* small_sort*/
void				small_sort(t_node **stac_a, t_node **stac_b, int size);
void				under_ten_sort(t_node **stac_a, t_node **stac_b, int size);
void				sort_tree(t_node **head);

/* chunk*/
void				chunk_sort(t_node **a, t_node **b, int list_size,
						int range);

/* radix*/
void				bit_radix(t_node **stac_a, t_node **stac_b, int list_size);

/* is_sorted*/
int					is_sorted(t_node *a);

#endif

/* ccw main.c small_sort.c index_list.
c make_list.c my_atoi.c ope_push.c ope_rev.c ope_rotate.c ope_swap.c chunk.c
	-o push_swap */
