/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tip_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:10:30 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/25 17:37:18 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mop_u(t_il *kok, char *v)
{
	obr_point_i_d(kok, &v);
	obr_width_i_d(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}

char	*table_u(t_il *kok, va_list ar)
{
	unsigned long long int	v;

	if ((int)(v = flag_unsign(kok, ar)) == -2)
		v = va_arg(ar, unsigned int);
	return (mop_u(kok, ft_itoa2((unsigned long long int)v)));
}
