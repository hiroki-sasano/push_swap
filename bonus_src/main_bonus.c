/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:21:57 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/07 20:40:32 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

static int	my_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static size_t	my_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

static void test_sort(char *buf, t_node **a, t_node **b)
{
    if (my_strcmp(buf, "sa") == 0)
        b_sa(a);
    else if (my_strcmp(buf, "sb") == 0)
        b_sb(b);
    else if (my_strcmp(buf, "ss") == 0)
        b_ss(a, b);
    else if (my_strcmp(buf, "pa") == 0)
        b_pa(a, b);
    else if (my_strcmp(buf, "pb") == 0)
        b_pb(a, b);
    else if (my_strcmp(buf, "ra") == 0)
        b_ra(a);
    else if (my_strcmp(buf, "rb") == 0)
        b_rb(b);
    else if (my_strcmp(buf, "rr") == 0)
        b_rr(a, b);
    else if (my_strcmp(buf, "rra") == 0)
        b_rra(a);
    else if (my_strcmp(buf, "rrb") == 0)
        b_rrb(b);
    else if (my_strcmp(buf, "rrr") == 0)
        b_rrr(a, b);
    else
        err_exit(a, b, 1);
}

int	main(int argc, char **argv)
{
	t_node	*stac_a;
	t_node	*stac_b;
	char	buf[16];
	size_t	len;
	t_ps_err st;

	stac_a = NULL;
	stac_b = NULL;
	if (argc > 2)
	{
		st = make_list(argc - 1, argv, &stac_a);
		if (st != PS_OK)
			err_exit(&stac_a, &stac_b, st);
		while (fgets(buf, sizeof(buf), stdin) != NULL)
		{
			len = my_strlen(buf);
			if (len > 0 && buf[len - 1] == '\n')
				buf[len - 1] = '\0';
            test_sort(buf, &stac_a, &stac_b);
		}
		return (check_stac(stac_a, stac_b));
	}
	return (0);
}
