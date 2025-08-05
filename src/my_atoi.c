/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:32:09 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/03 21:22:28 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

static int	will_overflow(long res, int dig, int sign)
{
	if (sign > 0)
		return (res > (LONG_MAX - dig) / 10);
	else
		return (-res < (LONG_MIN + dig) / 10);
}

static t_ps_err	a_to_long(const char *s, int sign, long *out)
{
	int		dig;
	long	res;

	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		dig = *s++ - '0';
		if (will_overflow(res, dig, sign))
			return (PS_ERR_OVERFLOW);
		res = res * 10 + dig;
	}
	if (*s != '\0')
		return (PS_ERR_BADINT);
	*out = res * sign;
	return (PS_OK);
}

t_ps_err	my_atoi(const char *str, int *out)
{
	int			sign;
	long		val;
	t_ps_err	st;

	sign = 1;
	if (!str || !*str)
		return (PS_ERR_BADINT);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		if (!*(++str))
			return (PS_ERR_BADINT);
	}
	st = a_to_long(str, sign, &val);
	if (st != PS_OK)
		return (st);
	if (val < INT_MIN || val > INT_MAX)
		return (PS_ERR_OVERFLOW);
	*out = (int)val;
	return (PS_OK);
}
