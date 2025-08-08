/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:21:39 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/07 18:24:19 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

int	is_sorted(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}
