/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:04:54 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/14 20:53:33 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

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

void	err_exit(t_node **a, t_node **b, t_ps_err st)
{
	free_list(*a);
	*a = NULL;
	free_list(*b);
	*b = NULL;
	if (st != PS_OK)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
