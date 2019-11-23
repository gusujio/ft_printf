/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tip_i_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:11:31 by gusujio           #+#    #+#             */
/*   Updated: 2019/10/28 17:11:34 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    obr_width_i_d(il *kok, char **v,int p, char c)
{
	char *buf;
	int l;
	int k;
	int param;
	
	param = p ? kok->width : kok->point;
	if (param < 0 && kok->mines)
		return (0);
	k = (int)ft_strlen(*v) - (!p ? (((*v)[0] == '-') + ((*v)[0] == '+')) : 0);
	l = param - k;
	l = l > 0 ? l : 0;
	buf = (char *) malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	if (l && k <= param)
		obr_sistem(v,&buf,c);
	if (kok->mines && param != kok->point)
		*v = ft_strjoin(*v, buf);
	else
		*v = ft_strjoin(buf, *v);
	return (1);
}
void obr_point_i_d(il *kok, char **v)
{
	if (kok->point < 0)
		return;
	if (!kok->point && !kok->v_i)
		*v = "";
	else
	{
		if (kok->type == 'X' || kok->type == 'x')
			obr_width_x_X(kok, v, 0, '0');
		else
			obr_width_i_d(kok, v, 0, '0');
	}
}

char* table_i_d(il *kok, va_list ar)
{
	void *v1;
	char *v;
	
	if ((v1 = flag_sign(kok, ar)) == (void *)-2)
		v1 = (void *) va_arg(ar, int);
	kok->v_i = v1;
	v = ft_itoa(v1);
	obr_point_i_d(kok, &v);
	if (kok->plus && v[0] != '-')
		v = ft_strjoin("+", v);
	obr_space(kok, &v);
	obr_width_i_d(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}