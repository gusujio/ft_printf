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

void obr_point_u(il *kok, char **v)
{
	if (kok->point < 0)
		return;
	if (!kok->point && !ft_atoi(*v))
	{
		*v = "";
		return;
	}
	obr_width_i_d(kok, v, 0, '0');
}

char * mop_u(il *kok, char *v)
{
	obr_point_u(kok, &v);
	obr_space(kok, &v);
	obr_width_i_d(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}

char* table_u(il *kok, va_list ar)
{
	void *v;
	
	if ((v = flag_unsign(kok, ar)) == (void *)-2)
		v = (void *) va_arg(ar, unsigned int);
	return (mop_u(kok, ft_itoa_2(v)));
}