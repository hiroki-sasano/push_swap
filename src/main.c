/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:31:10 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/06 20:07:36 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	push_swap(t_node **stac_a, t_node **stac_b, int list_size)
{
	int	range;

	range = (list_size / 10) - ((list_size / 100) * 3);
	if (list_size <= 10)
		small_sort(stac_a, stac_b, list_size);
	else if (list_size <= 100)
		chunk_sort(stac_a, stac_b, list_size, 18);
	else if (list_size <= 500)
		chunk_sort(stac_a, stac_b, list_size, 45);
	else if (list_size <= 1300)
		chunk_sort(stac_a, stac_b, list_size, range);
	else
		bit_radix(stac_a, stac_b, list_size);
	return ;
}

int	main(int argc, char **argv)
{
	t_node		*stac_a;
	t_node		*stac_b;
	int			size;
	t_ps_err	st;

	stac_a = NULL;
	stac_b = NULL;
	if (argc > 2)
	{
		st = make_list(argc - 1, argv, &stac_a);
		if (st != PS_OK)
			err_exit(&stac_a, &stac_b, st);
		stac_b = NULL;
		size = index_list(&stac_a);
		if (size <= 1)
			err_exit(&stac_a, &stac_b, st);
		if (is_sorted(stac_a) == 0)
			err_exit(&stac_a, &stac_b, st);
		push_swap(&stac_a, &stac_b, size);
	}
	err_exit(&stac_a, &stac_b, PS_OK);
	return (0);
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

// 600 , 45, 6622
// 1000 radix: 15070	chunk: 13715
// 1100 radix: 18781 chunk: 17202
// 1200 radix: 20481 chunk: 19293
// 1300 radix: 22121 chunk: 22056
// 1350 radix: 22956 chunk: 24222
// 1400 radix: 23757 chunk: 25675
// 1500 radix: 25337 chunk: 28241
// 2000 radix: 33137 chunk: 46213
// 4000 radix: 72273  chunk: 161973
// 5000 radix: 100197 chunk: 204301

// to_do
//

/*
	ccw main.c small_sort.c index_list.c make_list.c
	my_atoi.c ope_push.c ope_rev.c ope_rotate.c ope_swap.c
*/