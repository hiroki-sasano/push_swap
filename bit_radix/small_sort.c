/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:55:10 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/26 21:32:08 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tree(t_node **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->index;
	b = (*head)->next->index;
	c = (*head)->next->next->index;
	if (a > b && b < c && a < c)
		sa(head);
	else if (a > b && b > c)
	{
		sa(head);
		rra(head);
	}
	else if (a > b && b < c && a > c)
		ra(head);
	else if (a < b && b > c && a < c)
	{
		sa(head);
		ra(head);
	}
	else if (a < b && b > c && a > c)
		rra(head);
}

void	under_ten_sort(t_node **a, t_node **b, int size)
{
	int	to_push;
	int	pushed;

	to_push = size - 3;
	pushed = 0;
	while (pushed < to_push)
	{
		if ((*a)->index < to_push)
		{
			pb(a, b);
			pushed++;
			if (pushed > 1 && (*b)->index < (*b)->next->index)
				sb(b);
		}
		else
			ra(a);
	}
	sort_tree(a);
	while (pushed--)
		pa(a, b);
}

void	small_sort(t_node **stac_a, t_node **stac_b, int size)
{
	index_list(stac_a);
	if (size == 2)
	{
		if ((*stac_a)->index > (*stac_a)->next->index)
		{
			sa(stac_a);
			return ;
		}
		else
			return ;
	}
	else if (size == 3)
		sort_tree(stac_a);
	else if (size <= 10)
		under_ten_sort(stac_a, stac_b, size);

	return ;
}

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