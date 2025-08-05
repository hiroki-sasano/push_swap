/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:56:31 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/26 21:42:23 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	abst(int num, int dig)
{
	int	i;
	int	tmp;
	int	sign;
	int	digs;

	i = 1;
	sign = 1;
	digs = 0;
	if (num < 0)
		sign = -1;
	num *= sign;
	tmp = num;
	while (tmp > 0)
	{
		tmp /= 10;
		digs++;
	}
	if (digs < dig)
		return (0);
	while (i < dig)
	{
		num /= 10;
		i++;
	}
	return ((num % 10) * sign);
}

static int	is_min(t_node *head, int dig)
{
	int	min;
	int	num;

	min = INT_MAX;
	while (head)
	{
		num = abst(head->val, dig);
		if (min > num)
			min = num;
		head = head->next;
	}
	return (min);
}

static int	is_max(t_node *head, int dig)
{
	int	max;
	int	num;

	max = 0;
	while (head)
	{
		num = abst(head->val, dig);
		if (max < num)
			max = num;
		head = head->next;
	}
	return (max);
}

void	a_to_b(t_node **a, t_node **b, int dig, int size)
{
	t_node	**p;
	int		cur;
    int r_count;

	while (*a)
	{
		cur = is_min(*a, dig);
		p = a;
        r_count = 0;
		while (r_count < size)
		{
			if (abst((*p)->val, dig) == cur)
			{
				pb(p, b);
                size--;
			}
			else
			{
				ra(p);
                r_count++;
			}
		}
	}
	return ;
}

void	b_to_a(t_node **a, t_node **b, int dig, int size)
{
	t_node **p;
	int cur;
    int r_count;

	while (*b)
	{
		cur = is_max(*b, dig);
		p = b;
        r_count = 0;
		while (r_count < size)
		{
			if (abst((*p)->val, dig) == cur)
			{
				pa(a, p);
                size--;
			}
			else
            {
				rb(p);
                r_count++;
            }
		}
	}
	return ;
}
