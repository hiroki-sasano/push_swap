/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:12:21 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/14 20:14:33 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static t_ps_err	has_value(const t_node *head, int value, t_ps_err err)
{
	while (head)
	{
		if (head->val == value)
			return (err);
		head = head->next;
	}
	return (PS_OK);
}

static t_ps_err	free_partial(t_node *head, t_ps_err err)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	return (err);
}

static t_ps_err	create_node(const char *str, t_node **out)
{
	int			value;
	t_ps_err	st;

	st = my_atoi(str, &value);
	if (st != PS_OK)
		return (st);
	*out = malloc(sizeof(t_node));
	if (!*out)
		return (PS_ERR_MALLOC);
	(*out)->val = value;
	(*out)->index = 0;
	(*out)->next = NULL;
	return (PS_OK);
}

static t_ps_err	app_node(t_node **head, t_node **tail, t_node *node)
{
	if (has_value(*head, node->val, PS_ERR_DUP) != PS_OK)
	{
		free(node);
		return (PS_ERR_DUP);
	}
	if (!*head)
		*head = node;
	else
		(*tail)->next = node;
	*tail = node;
	return (PS_OK);
}

t_ps_err	make_list(int num, char **argv, t_node **a)
{
	t_node		*head;
	t_node		*tail;
	t_node		*node;
	t_ps_err	st;
	int			i;

	head = NULL;
	tail = NULL;
	i = 1;
	while (i <= num)
	{
		st = create_node(argv[i], &node);
		if (st != PS_OK)
			return (free_partial(head, st));
		st = app_node(&head, &tail, node);
		if (st != PS_OK)
			return (free_partial(head, st));
		i++;
	}
	*a = head;
	return (PS_OK);
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
