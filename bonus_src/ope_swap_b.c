/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_swap_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:06:06 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/03 22:18:24 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	b_ope_swap(t_node **stac)
{
	t_node	*first;
	t_node	*second;

	if (!stac || !*stac || !(*stac)->next)
		return ;
	first = *stac;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stac = second;
}

void	b_sa(t_node **stac_a)
{
	b_ope_swap(stac_a);
	return ;
}

void	b_sb(t_node **stac_b)
{
	b_ope_swap(stac_b);
	return ;
}

void	b_ss(t_node **stac_a, t_node **stac_b)
{
	if ((*stac_a)->next && (*stac_b)->next)
	{
		b_ope_swap(stac_a);
		b_ope_swap(stac_b);
	}
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
// 		ope_sa(&stac_a);
// 		ope_sb(&stac_b);
// 		// ope_ss(&stac_a, &stac_b);
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

// sa, sb, ss