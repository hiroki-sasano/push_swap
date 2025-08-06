/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:21:39 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/06 20:00:46 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error.h"

int is_sorted(t_node *a)
{
	int prev;
	
	prev = a->index;
	a = a->next;
	while(a)
	{
		if (prev >= a->val)
			return (1);
		prev = a->val;
		a = a->next;
	}
	
	return (0);
}