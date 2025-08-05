/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:32:47 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/27 16:39:39 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

static int	is_even(int cur, int src);
static int	found_min(t_node *head);
int			found_next(t_node *head, int cur_n);
void		index_list(t_node **head);
int			list_count(t_node *head);

static int	found_min(t_node *head)
{
	int	min;

	if (!head)
		return (INT_MAX);
	min = head->val;
	for (t_node *cur = head; cur; cur = cur->next)
		if (cur->val < min)
			min = cur->val;
	return (min);
}

int	list_count(t_node *head)
{
	t_node	*cur;
	int		count;

	cur = head;
	count = 0;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return (count);
}

int	found_next(t_node *head, int cur_n)
{
	t_node	*cur;
	int		next;

	cur = head;
	next = INT_MAX;
	while (cur)
	{
		if (cur->val > cur_n && cur->val < next)
			next = cur->val;
		cur = cur->next;
	}
	return (next);
}

static int	is_even(int cur, int src)
{
	return (cur == src);
}

void	index_list(t_node **head)
{
	t_node	*cur;
	int		index;
	int		cur_no;
	int		lim;

	cur = *head;
	index = 0;
	cur_no = found_min(*head);
	lim = list_count(*head);
	while (index < lim)
	{
		while (cur)
		{
			if (is_even(cur->val, cur_no))
			{
				cur->index = index;
				index++;
			}
			cur = cur->next;
		}
		cur_no = found_next(*head, cur_no);
		cur = *head;
	}
	return ;
}

// typedef struct s_node
// {
// 	int				val;
// 	int				index;
// 	struct s_node	*next;
// }					t_node;
