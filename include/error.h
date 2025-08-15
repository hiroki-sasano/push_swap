/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:43:06 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/14 00:07:37 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_ps_err
{
	PS_OK = 0,
	PS_ERR_BADINT = 1,
	PS_ERR_OVERFLOW = 2,
	PS_ERR_MALLOC = 3,
	PS_ERR_DUP = 4
}	t_ps_err;
#endif
