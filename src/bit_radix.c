/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:23:16 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/30 18:25:23 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	count_bits(int max_val)
{
	int	bits;

	bits = 0;
	if (max_val == 0)
		return (1);
	while (max_val > 0)
	{
		max_val >>= 1;
		bits++;
	}
	return (bits);
}

static void	a_to_b(t_node **stac_a, t_node **stac_b, int bit)
{
	int	count;
	int	n;

	count = 0;
	n = list_count(*stac_a);
	while (count < n)
	{
		if ((((*stac_a)->index >> bit) & 1) == 0)
			pb(stac_a, stac_b);
		else
			ra(stac_a);
		count++;
	}
	while (*stac_b)
		pa(stac_a, stac_b);
}

void	bit_radix(t_node **stac_a, t_node **stac_b, int list_size)
{
	int	bit;
	int	max_bits;

	bit = 0;
	max_bits = count_bits(list_size);
	if (!(*stac_a && (*stac_a)->next))
		return ;
	while (bit < max_bits)
	{
		a_to_b(stac_a, stac_b, bit);
		bit++;
	}
	while (*stac_b)
		pa(stac_a, stac_b);
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

/* ccw index_list.c make_list.c my_atoi.c 
ope_push.c ope_rev.c ope_rotate.c ope_swap.c radix_sort.c
 */
