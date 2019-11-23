/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tip_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:10:30 by gusujio           #+#    #+#             */
/*   Updated: 2019/10/28 17:10:32 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char * mop_u(il *kok, char *v)
{
	obr_point_i_d(kok, &v);
	obr_width_i_d(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}

char* table_u(il *kok, va_list ar)
{
	void *v;
	
	if ((v = flag_unsign(kok, ar)) == (void *)-2)
		v = (void *) va_arg(ar, unsigned int);
	return (mop_u(kok, ft_itoa2(v)));
}