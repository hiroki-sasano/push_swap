/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:45:13 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/20 20:30:57 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> /*       *****************************************************************************************/

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
}					t_node;

/* make_list.c*/
t_node				*make_list(int num, char **argv);
void				free_list(t_node *node);
t_node				*create_node(char *str);

/* my_atoi*/
int					my_atoi(const char *str);
void				err_exit(void);

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
int					found_next(t_node **head, int cur_n);
int					index_list(t_node **head);

/* small_sort*/
void				small_sort(t_node **stac_a, t_node **stac_b, int size);
void				under_ten_sort(t_node **stac_a, t_node **stac_b, int size);
void				sort_tree(t_node **head);

void	put_node(t_node *head); /*   test*************************************************/

#endif

// sa：スタックaの先頭2つの要素を交換

// sb：スタックbの先頭2つの要素を交換

// ss：saとsbを同時に実行

// pa：スタックbの先頭をスタックaの先頭に移動

// pb：スタックaの先頭をスタックbの先頭に移動

// ra：スタックaを1つ上に回転（先頭が末尾へ）

// rb：スタックbを1つ上に回転

// rr：raとrbを同時に実行

// rra：スタックaを1つ下に回転（末尾が先頭へ）

// rrb：スタックbを1つ下に回転

// rrr：rraとrrbを同時に実行