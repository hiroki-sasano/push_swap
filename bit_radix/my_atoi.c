/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:32:09 by hisasano          #+#    #+#             */
/*   Updated: 2025/07/30 15:44:25 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

static int	a_to_int(int sign, int i, const char *str)
{
	int	dig;
	int	res;

    res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		dig = str[i++] - '0';
		if (res > (LONG_MAX - dig) / 10)
			err_exit();
		res = res * 10 + dig;
	}
	if (str[i] != '\0')
		err_exit();
	res *= sign;
	if (res < INT_MIN || res > INT_MAX)
		err_exit();
	return (res);
}

void	err_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	my_atoi(const char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	return (a_to_int(sign, i, str));
}