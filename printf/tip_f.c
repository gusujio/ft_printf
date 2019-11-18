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
		*v = ft_strjoin(*v, buf);
	else
		*v = ft_strjoin(buf, *v);
	return (1);
}

void obr_point_f(il *kok, char **v)
{
	int len;
	int p;
	
	p = ft_strlen2(*v , '.');
	len = ft_strlen(*v + p) - 1;
	kok->point = kok->point == -1 ? 6 : kok->point;
	if (len < kok->point)//если меньше нормы, то дакидывем нулей
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
/*
typedef union
{
	float f;
	struct
	{
		unsigned int mantisa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	} parts;
} float_cast;
*/
typedef union types
{
	long double f;
	unsigned long long m;
	short int e[5];
} ilia;

void persey(unsigned char c)
{
	int k;
	int i;
	
	i = 0;
	k = 128;
	while (i < 8)
	{
		printf("%d", !!(c & k));
		k = k >> 1;
		i++;
	}
}

char* table_f(il *kok, va_list ar) //округление
{
	ilia ili;
	int z;
	 // m  = 1 , e = 3 16383
	ili.f =  -8.0L;
	z = ili.e[4] >> 15;
	ili.e[4] = ili.e[4] & 0x7fff;
	ili.e[4] -= 16383 + 63;
	

	printf("\n");
	return (mop_f(kok, "s"));
}