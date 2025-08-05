/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_push_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:59:42 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/03 22:17:30 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	b_move_top(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	b_pa(t_node **stac_a, t_node **stac_b)
{
	b_move_top(stac_a, stac_b);
	return ;
}

void	b_pb(t_node **stac_a, t_node **stac_b)
{
	b_move_top(stac_b, stac_a);
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
// 	char	*tes_b[] = {"tes_b", "10", "20"};

// 	if (!(argc < 3))
// 	{
// 		stac_a = make_list(argc - 1, argv);
// 		stac_b = make_list(2, tes_b);
// 		printf("before a:\n");
// 		put_node(stac_a);
// 		printf("before b:\n");
// 		put_node(stac_b);

// 		// ope_pa(&stac_a, &stac_b);
// 		ope_pb(&stac_a, &stac_b);

// 		printf("after a:\n");
// 		put_node(stac_a);
// 		printf("after b:\n");
// 		put_node(stac_b);
// 	}
// 	return (0);
// }

// typedef struct s_node
// {
// 	int             val;
// 	struct s_node  *next;
// }	t_node;
// pa, pb
