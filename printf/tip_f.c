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
	int len ;
	
	param = p ? kok->width : kok->point;
	len = ft_strlen(*v);
	l = param - len - (!p ? (((*v)[0] == '-') + ((*v)[0] == '+')) : 0);
	l = l > 0 ? l : 0;
	if (p == 2)
		l = kok->width;
	buf = (char *) malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	if ((!kok->plus || (ft_strlen(buf))) && p)
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
	if ((kok->mines && param != kok->point) || (kok->point > 19 && !p) || p == 2)
	{
		if (!(*v)[len] && p == 2 && !ft_strchr(*v, '.'))
			buf[0] = '.';
		*v = ft_strjoin(*v, buf);
	}
	else
		*v = ft_strjoin(buf, *v);
	return (1);
}

void obr_point_f(il *kok, char **v)
{
	int len;
	int p;
	
	p = ft_strlen2(*v , '.');
	len = ft_strlen(*v + p) - 1 ;
	kok->point = kok->point == -1 ? 6 : kok->point;
	if (len < kok->point && kok->point != 0)//если меньше нормы, то дакидывем нулей
	{
		kok->width = kok->point - len;
		kok->mines = 1;
		obr_width_f(kok, v, 2, '0');
	}
	else
	{
		if (kok->point != -1)
			(*v)[p + kok->point + (kok->point || kok->resh)] = 0;
		else
			(*v)[p + 7] = 0;
	}
}

char *mop_f(il *kok, char *v)
{
	if (kok->plus && v[0] != '-')
		v = ft_strjoin("+", v);
	obr_point_f(kok, &v);
	obr_space(kok, &v);
	obr_width_f(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}

typedef union types
{
	long double f;
	unsigned long long m;
	short int e[5];
} ilia;

void okr2(char **s, int l, int d)
{
	d = 10 - (*s)[l] + 48;
	while ((*s)[l] != '.')
	{
		(*s)[l] += d;
		d = 0;
		if ((*s)[l] == ':')
		{
			(*s)[l] = '0';
			d = 1;
		}
		l--;
	}
	(*s)[l - 1] += d;
	if ((*s)[0] == ':' && d)
		*s = ft_strjoin("10", *s + 1 );
	else if ((*s)[1] == ':' && d)
		*s = ft_strjoin("-10", *s + 2 );
}

int onlit(char *s,  char c)
{
	while (s)
	{
		if (*s != c)
			return (0);
		s++;
	}
	return (1);
}

void okrug(il *kok, char **s)
{
	int p;
	
	kok->point = kok->point == -1 ? 6 : kok->point;
	p = ft_strlen2(*s, '.') + kok->point + 1;
	if ((*s)[p] >= '6')
		okr2(s, p, 10 - (*s)[p]);
	else if ((*s)[p] == '5')
	{
		if (!onlit(*s, '0'))
			okr2(s, p, 5);
	}
	
}

char* table_f(il *kok, va_list ar) //округление // m  = 1 , e = 3 16383
{
	ilia ili;
	int z;
	char *tail;
	char *man;
	
	if (kok->speth)
	{
		if (kok->speth[0] == 'L')
			ili.f = va_arg(ar, long double);
		if (kok->speth[0] == 'l')
			ili.f = va_arg(ar, double);
	}
	else
		ili.f = va_arg(ar, double);
	z = ili.e[4] >> 15;
	ili.e[4] = ili.e[4] & 0x7fff;
	ili.e[4] -= 16383 + 63;
	man = ft_itoa_2(ili.m);
	if (man[0] == '-')
		man++;
	if (ili.e[4] > 0)
		tail = ft_multi(man, ft_degr2(ili.e[4]));
	else
		tail = del10(ft_multi(man, ft_degr5(ili.e[4] * -1)), ili.e[4] * -1);
	if (--man[0] == '-' || z == -1)
		tail = ft_strjoin("-", tail);
	okrug(kok, &tail);
	return (mop_f(kok, tail));
}
