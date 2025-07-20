/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:06:06 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/18 15:44:15 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ope_swap(t_node **stac)
{
	int	tmp;

	tmp = 0;
	if ((*stac)->next)
	{
		if ((*stac)->val < (*stac)->next->val)
		{
			tmp = (*stac)->val;
			(*stac)->val = (*stac)->next->val;
			(*stac)->next->val = tmp;
		}
	}
	return ;
}

void	ope_sa(t_node **stac_a)
{
	ope_swap(stac_a);
	write(1, "sa\n", 3);
	return ;
}

void	ope_sb(t_node **stac_b)
{
	ope_swap(stac_b);
	write(1, "sb\n", 3);
	return ;
}

void	ope_ss(t_node **stac_a, t_node **stac_b)
{
	if ((*stac_a)->next && (*stac_b)->next)
	{
		ope_swap(&*stac_a);
		ope_swap(&*stac_b);
	}
	write(1, "ss\n", 3);
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