/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:45:13 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/03 22:04:30 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

int		check_stac(t_node *a, t_node *b);
void	ko_exit(t_node *a, t_node *b);

void	b_ss(t_node **stac_a, t_node **stac_b);
void	b_sb(t_node **stac_b);
void	b_sa(t_node **stac_a);
void	b_pb(t_node **stac_a, t_node **stac_b);
void	b_pa(t_node **stac_a, t_node **stac_b);
void	b_ra(t_node **stac_a);
void	b_rb(t_node **stac_b);
void	b_rr(t_node **stac_a, t_node **stac_b);
void	b_rra(t_node **stac_a);
void	b_rrb(t_node **stac_b);
void	b_rrr(t_node **stac_a, t_node **stac_b);

#endif
