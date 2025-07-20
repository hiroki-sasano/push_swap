/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:55:10 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/20 13:52:10 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_list(t_node **stac)
{
	t_node	*head;
	int		count;

	head = *stac;
	count = 0;
	while (head)
	{
		if (count < head->index)
			count = head->index;
		head = head->next;
	}
	return (count);
}

void	sort_tree(t_node **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->index;
	b = (*head)->next->index;
	c = (*head)->next->next->index;
	if (a > b && b < c && a < c)
		ope_sa(head);
	else if (a > b && b > c)
	{
		ope_sa(head);
		ope_rra(head);
	}
	else if (a > b && b < c && a > c)
		ope_ra(head);
	else if (a < b && b > c && a < c)
	{
		ope_sa(head);
		ope_ra(head);
	}
	else if (a < b && b > c && a > c)
		ope_rra(head);
}

void	u_five_sort(t_node **stac_a, t_node **stac_b)
{
	t_node	*head;
	int		count;
	int		i;

	head = *stac_a;
	count = 0;
	i = 0;
	count = count_list(stac_a);
	while (i < count - 3)
	{
		while (head)
		{
			if (i == head->index)
				ope_pb(&head, stac_b);
			head = head->next;
		}
		head = *stac_a;
		i++;
	}
	sort_tree(stac_a);
	while (i--)
		ope_pa(stac_a, stac_b);
	return ;
}

void	small_sort(t_node **stac_a, t_node **stac_b, int size)
{
	if (size == 2)
	{
		if ((*stac_a)->index > (*stac_a)->next->index)
		{
			ope_sa(stac_a);
			return ;
		}
		else
			return ;
	}
	else if (size == 3)
		sort_tree(stac_a);
	else if (size <= 5)
		u_five_sort(stac_a, stac_b);
	// else
	//     u_ten_sort(&stac_a, &stac_b);
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