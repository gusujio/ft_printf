/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tip_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:11:04 by gusujio           #+#    #+#             */
/*   Updated: 2019/10/28 17:11:07 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

int    obr_width_f(il *kok, char **v, int p, char c)
{
	char *buf;
	int l;
	int param;
	
	param = p ? kok->width : kok->point;
	l = param - ft_strlen(*v) - (!p ? (((*v)[0] == '-') + ((*v)[0] == '+')) : 0);
	l = l > 0 ? l : 0;
	buf = (char *) malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	if ((!kok->plus || (ft_strlen(buf))))
	{
		if (ft_strlen(*v) <= param)
		{
			if (((*v)[0] == '-' || (*v)[0] == '+' || (*v)[0] == ' ') && c == '0')
			{
				buf[0] = (*v)[0];
				(*v)[0] = '0';
			}
		}
	}
	*v = ft_strjoin(buf, *v);
	return (1);
}

void obr_point_f(il *kok, char **v)
{
	int len;
	char *p;
	
	len = 6;
	if (kok->point > 0)
	{
		if (kok->point > 20)
			obr_width_f(kok, v, 0, '0');
		else
			(*v)[len + ft_strlen2(*v, '.') + 1] = 0;
	}
	else
	{
		(*v)[len + ft_strlen2(*v, '.') + 1] = 0;
		if (ft_strlen(ft_strchr(*v, '.') + 1) < 6)
			*v = ft_strjoin(*v, "00000");
	}
}

char *mop_f(il *kok, char *v)
{
	obr_mines(kok, &v);
	if (kok->plus && v[0] != '-')
		v = ft_strjoin("+", v);
	obr_point_f(kok, &v);
	obr_space(kok, &v);
	obr_width_f(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}

unsigned long long int ft_tail(long double v)
{
	long long int k;
	int z;
	unsigned long long int t;
	
	v = v - (long long int)v;
	t = 0;
	k = 0;
	while (k++ < 19)
	{
		t *= 10;
		t += ft_mod((v * 10));
		z = (v > 0 ? -1 : 1);
		v = (v + ((float)(t % 10) / 10) * z) * 10;
	}
	return (t);
}

long double okrug(long double v)
{
	long long int k;
	
	k = v;
	v = v - k;
	v = v * 1000000;
	v += k ? ft_mod(k) / k : 0;
	v = v / 1000000 + k;
	return (v);
}

char* table_f(il *kok, va_list ar) //округление
{
	long double v;
	char* tail;
	
	if (kok->speth)
	{
		if (kok->speth[0] == 'L')
			v = va_arg(ar, long double);
		if (kok->speth[0] == 'l')
			v = va_arg(ar, double);
	}
	else
		v = va_arg(ar, double);
	tail = ft_strjoin(".", ft_itoa_2(ft_tail(okrug(v))));
	return (mop_f(kok, ft_strjoin(ft_itoa(v), tail)));
}