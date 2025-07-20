/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:53:20 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/18 15:46:12 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ope_rotate(t_node **stac)
{
	t_node	*head;
	t_node	*cur;

	if (!stac || !*stac || !(*stac)->next)
		return ;
	head = *stac;
	*stac = head->next;
	cur = *stac;
	while (cur->next)
		cur = cur->next;
	cur->next = head;
	head->next = NULL;
	return ;
}

void	ope_ra(t_node **stac_a)
{
	ope_rotate(stac_a);
	write(1, "ra\n", 3);
	return ;
}

void	ope_rb(t_node **stac_b)
{
	ope_rotate(stac_b);
	write(1, "rb\n", 3);
	return ;
}

void	ope_rr(t_node **stac_a, t_node **stac_b)
{
	ope_rotate(stac_a);
	ope_rotate(stac_b);
	write(1, "rr\n", 3);
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
// 		// ope_ra(&stac_a);
// 		// ope_rb(&stac_b);
// 		ope_rr(&stac_a, &stac_b);
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

// ra, rb, rr