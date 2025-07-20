/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:12:21 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/20 13:55:38 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_node	*create_node(char *str)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = my_atoi(str);
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	free_list(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}

t_node	*make_list(int num, char **argv)
{
	t_node	*head;
	t_node	*new_node;
	t_node	*cur;
	int		i;

	head = NULL;
	i = 1;
	while (i <= num)
	{
		new_node = create_node(argv[i]);
		if (!new_node)
			return (free_list(head), NULL);
		if (!head)
		{
			head = new_node;
			cur = head;
		}
		else
		{
			cur->next = new_node;
			cur = cur->next;
		}
		i++;
	}
	return (head);
}

// #include <stdio.h>

// void	put_node(t_node *head)
// {
// 	t_node	*cur;

// 	cur = head;
// 	while (cur)
// 	{
// 		printf("val: %d index: %d\n", cur->val, cur->index);
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
//         // index_list(&stac_a);
//         // index_list(&stac_b);

//         printf("before a:\n");
// 		put_node(stac_a);
// 		printf("before b:\n");
// 		put_node(stac_b);

// 		printf("after a:\n");
// 		put_node(stac_a);
// 		printf("after b:\n");
// 		put_node(stac_b);
// 	}
// 	return (0);
// }
