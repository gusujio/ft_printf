/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tip_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:11:04 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/25 18:25:57 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		obr_width_f(il *kok, char **v, int p, char c)
{
	char	*buf;
	int		l;
	int		param;
	int		len;

	param = p ? kok->width : kok->point;
	len = ft_strlen(*v);
	l = param - len - (!p ? (((*v)[0] == '-') + ((*v)[0] == '+')) : 0);
	l = l > 0 ? l : 0;
	l = p == 2 ? kok->width : l;
	buf = (char *)malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	if ((!kok->plus || l) && p == 1 && len <= param)
		obr_sistem(v, &buf, c);
	if ((kok->mines && param != kok->point) ||
			(kok->point > 19 && !p) || p == 2)
	{
		if (!(*v)[len] && p == 2 && !ft_strchr(*v, '.'))
			buf[0] = '.';
		*v = ft_strjoin3(*v, buf);
	}
	else
		*v = ft_strjoin3(buf, *v);
	return (1);
}

void	obr_point_f(il *kok, char **v)
{
	int len;
	int p;

	p = ft_strlen2(*v, '.');
	len = (int)ft_strlen(*v + p) - 1;
	kok->point = kok->point == -1 ? 6 : kok->point;
	if (len < kok->point && kok->point != 0)
	{
		p = kok->width;
		kok->width = kok->point - len;
		kok->mines = 1;
		obr_width_f(kok, v, 2, '0');
		kok->width = p;
		kok->mines = 0;
	}
	else
	{
		if (kok->point != -1)
			(*v)[p + kok->point + (kok->point || kok->resh)] = 0;
		else
			(*v)[p + 7] = 0;
	}
}

char	*mop_f(il *kok, char *v)
{
	if (kok->plus && v[0] != '-')
		v = ft_strjoin("+", v);
	obr_point_f(kok, &v);
	obr_space(kok, &v);
	obr_width_f(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}

void	okr2(char **s, int l, int d)
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
		*s = ft_strjoin2("10", *s + 1);
	else if ((*s)[1] == ':' && d)
		*s = ft_strjoin2("-10", *s + 2);
}

int		onlit(char *s, char c)
{
	while (s)
	{
		if (*s != c)
			return (0);
		s++;
	}
	return (1);
}
