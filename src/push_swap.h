/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:45:13 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/20 13:53:00 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void				ope_ss(t_node **stac_a, t_node **stac_b);
void				ope_sb(t_node **stac_b);
void				ope_sa(t_node **stac_a);
void				ope_swap(t_node **stac);

/* ope_push */
void				ope_pb(t_node **stac_a, t_node **stac_b);
void				ope_pa(t_node **stac_a, t_node **stac_b);
void				move_top(t_node **dst, t_node **src);

/* ope_rotate*/
void				ope_rotate(t_node **stac);
void				ope_ra(t_node **stac_a);
void				ope_rb(t_node **stac_b);
void				ope_rr(t_node **stac_a, t_node **stac_b);

/* ope_rev */
void				ope_rev(t_node **stac);
void				ope_rra(t_node **stac_a);
void				ope_rrb(t_node **stac_b);
void				ope_rrr(t_node **stac_a, t_node **stac_b);

/* index_list*/
int					found_next(t_node **head, int cur_n);
int					index_list(t_node **head);

/* small_sort*/
void				small_sort(t_node **stac_a, t_node **stac_b, int size);
void				u_five_sort(t_node **stac_a, t_node **stac_b);
void				sort_tree(t_node **head);
int					count_list(t_node **stac);

// void	put_node(t_node *head); /*   test_           */

#endif