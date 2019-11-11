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

int    obr_width_f(const char *s, char **v, int i, char c)
{
	char *buf;
	int l;
	int k;
	
	if ((k = ft_atoi(s + i)) == 0)
		return (0);
	l = ft_atoi(s + i) - ft_strlen(*v);
	l = l > 0 ? l : 0;
	ft_strchr(*v, '-') && ft_strchr(s, '.') && c != ' ' && l ? l++ : l;
	buf = (char *) malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	if (ft_strchr(s, '-'))
	{
		*v = ft_strjoin(*v, buf);
		return (1);
	}
	if ((!ft_strchr(s, '+') || (ft_strlen(buf))))
	{
		if (ft_strlen(*v) <= k)
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

void obr_point_f(const char *s, char **v, int f)
{
	int len;
	char *p;
	
	if (!s)
		return;
	len = 6;
	if ((p = ft_strchr(s, '.')))
	{
		if ((len = ft_atoi(p + 1)) > 20)
			obr_width_f(s, v, 1, '0');
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

char * mop_f(const char *s, char *v)
{
	int i;

	obr_mines(ft_strstr(s, "-"), &v);
	if (ft_strstr(s, "+"))
		if (v[0] != '-' )
			v = ft_strjoin("+", v);
	i = 0;
	obr_point_f(s, &v, ft_atoi(s) && ft_strchr(s, '#'));
	obr_space(ft_strstr(s, " "), &v);
	while (s[i])
	{
		if (s[i] > '0' && s[i] <= '9' && s[i-1] != '.')
		{
			if (obr_width_f(s, &v, i, space_or_zero(s, i)))
				break;
		}
		i++;
	}
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

char* table_f(char *s, va_list ar) //округление
{
	long double v;
	char* tail;
	
	if (ft_strchr(s, 'L'))
		v = va_arg(ar, long double);
	else
		v = va_arg(ar, double);
	tail = ft_strjoin(".", ft_itoa_2(ft_tail(okrug(v))));
	return (mop_f(s, ft_strjoin(ft_itoa(v), tail)));
}