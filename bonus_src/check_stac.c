/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:00:10 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/03 22:14:57 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ko_exit(t_node *a, t_node *b)
{
    free_list(a);
    free_list(b);
	write(2, "KO\n", 3);
	exit(EXIT_FAILURE);
}

int check_stac(t_node *a, t_node *b)
{
    int prev;
    t_node *head_a;

    head_a = a;
    if (b)
        ko_exit(a, b);
    if (!a)
        ko_exit(a, b);
    prev = a->val;
    a = a->next;
    while(a)
    {
        if (prev >= a->val)
            ko_exit(a, b);
        prev = a->val;
        a = a->next;
    }
    free_list(head_a);
    write(1, "OK\n", 3);
    return (0);
}
