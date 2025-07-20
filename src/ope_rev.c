/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:09:57 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/20 19:38:24 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ope_rev(t_node **stac)
{
	t_node	*prev;
	t_node	*tail;

	if (!stac || !*stac || !(*stac)->next)
		return ;
	prev = NULL;
	tail = *stac;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	tail->next = *stac;
	*stac = tail;
}

void	rra(t_node **stac_a)
{
	if (!stac_a || !*stac_a || !(*stac_a)->next)
		return ;
	ope_rev(stac_a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_node **stac_b)
{
	if (!stac_b || !*stac_b || !(*stac_b)->next)
		return ;
	ope_rev(stac_b);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_node **stac_a, t_node **stac_b)
{
	if (!stac_a || !*stac_a || !(*stac_a)->next || !stac_b || !*stac_b
		|| !(*stac_b)->next)
		return ;
	ope_rev(stac_a);
	ope_rev(stac_b);
	write(1, "rrr\n", 4);
	return ;
}

// #include <stdio.h>

// void	put_node(t_node *head)
// {
// 	t_node	*cur;

// 	cur = head;
// 	while (cur)
// 	{
// 		printf("%d\n", cur->val);
// 		cur = cur->next;
// 	}
// 	printf("\n");
// 	return ;
// }

// int	main(int argc, char **argv)
// {
// 	t_node	*stac_a;
// 	t_node	*stac_b;

// 	if (!(argc < 3))
// 	{
// 		stac_a = make_list(argc - 1, argv);
// 		stac_b = make_list(argc - 1, argv);
// 		printf("before a:\n");
// 		put_node(stac_a);
// 		printf("before b:\n");
// 		put_node(stac_b);
// 		ope_rra(&stac_a);
// 		ope_rrb(&stac_b);
// 		// ope_rrr(&stac_a, &stac_b);
// 		printf("after a:\n");
// 		put_node(stac_a);
// 		printf("after b:\n");
// 		put_node(stac_b);
// 	}
// 	return (0);
// }

// rra：スタックaを1つ下に回転（末尾が先頭へ）
// ope_reverse
// rrb：スタックbを1つ下に回転
// ope_reverse
// rrr：rraとrrbを同時に実行
// ope_reverse
// rra, rrb, rrr