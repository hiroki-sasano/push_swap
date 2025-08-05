/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:30:23 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/30 18:30:55 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	fount_posi(t_node *stac, int max)
{
	int	pos;

	pos = 0;
	while (stac)
	{
		if (stac->index == max)
			break ;
		stac = stac->next;
		pos++;
	}
	return (pos);
}

static void	rotate_b(t_node **b, int max)
{
	int	posi;

	posi = fount_posi(*b, max);
	if (posi <= max / 2)
	{
		while ((*b)->index != max)
			rb(b);
	}
	else
	{
		while ((*b)->index != max)
			rrb(b);
	}
}

static void	b_to_a(t_node **a, t_node **b, int size)
{
	int	max;

	max = size - 1;
	while (*b)
	{
		if ((*b)->index == max)
		{
			pa(a, b);
			max--;
		}
		else if (((*b)->next && (*b)->next->index == max))
		{
			sb(b);
			pa(a, b);
			max--;
		}
		else
			rotate_b(b, max);
	}
}

void	chunk_sort(t_node **a, t_node **b, int list_size, int range)
{
	int	i;

	i = 0;
	if (!(*a && (*a)->next))
		return ;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
	b_to_a(a, b, list_size);
}

// void	put_node(t_node *head)
// {
// 	while (head)
// 	{
// 		printf("val: %d index: %d\n", head->val, head->index);
// 		head = head->next;
// 	}
// 	printf("\n");
// 	return ;
// }

// /******************************************************* */

// int	main(int argc, char **argv)
// {
// 	t_node	*stac_a;
// 	t_node	*stac_b;
//     t_node  *head;
//     int size;

// 	stac_a = NULL;
// 	if (argc > 2)
// 	{
// 		stac_a = make_list(argc - 1, argv);
// 		stac_b = NULL;
//         head = stac_a;
//         size = index_list(&stac_a);
// 		printf("index_test:\n");
// 		put_node(head);
//         if (size <= 1)
//             return (0);
//         printf("chack: %d\n", a_to_b(&stac_a, &stac_b, 1));
//         printf("%d\n", b_to_a(&stac_a, &stac_b, 1));

//         // radix_sort(&stac_a, &stac_b);
// 		put_node(stac_a);
// 	}

// 	return (0);
// }

/*
ccw index_list.c make_list.c my_atoi.c ope_push.c 
ope_rev.c ope_rotate.c ope_swap.c radix_sort.c
*/