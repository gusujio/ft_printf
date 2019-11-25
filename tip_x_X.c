/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_X.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:06:59 by gusujio           #+#    #+#             */
/*   Updated: 2019/10/28 17:07:01 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    obr_width_x_X(il *kok, char **v, int p, char c)
{
	char *buf;
	char *v2;
	int l;
	int k;
	int param;
	
	param = p ? kok->width : kok->point;
	if (param < 0 && kok->mines)
		return (0);
	k = ft_strlen(*v) - (!p ? (((*v)[0] == '-') + ((*v)[0] == '+')) : 0);
	l = param - k + !p * 2 * kok->resh ;
	l = l > 0 ? l : 0;
	buf = (char *) malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	obr_sistem(v,&buf,c);
	if (kok->resh && c != ' ' && l)
	{
		v2 = *v;
		*v = ft_strjoin1(buf, *v + 2);
		ft_strdel(&v2);
		obr_resh(kok, v);
	}
	else if (kok->mines && param != kok->point)
		*v = ft_strjoin3(*v, buf);
	else
		*v = ft_strjoin3(buf, *v);
	return (1);
}

char* table_x_X(il *kok, va_list ar)
{
	void *v1;
	char *v;
	
	if ((v1 = flag_unsign(kok, ar)) == (void *)-2)
		v1 = (void *) va_arg(ar, unsigned int);
	kok->v_i = v1;
	v = perevod(v1, kok->type);
	obr_resh(kok, &v);
	obr_point_i_d(kok, &v);
	obr_width_x_X(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}
