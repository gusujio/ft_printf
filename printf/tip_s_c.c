/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:05:21 by gusujio           #+#    #+#             */
/*   Updated: 2019/10/28 17:05:24 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    obr_width_s_c(il *kok, char **v, int param, char c)
{
	char *buf;
	int l;
	
	l = param - ft_strlen(*v);
	l = l > 0 ? l : 0;
	ft_strchr(*v, '-') && kok->point && c != ' ' && l ? l++ : l;
	buf = (char *) malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	if (kok->mines)
	{
		*v = ft_strjoin(*v, buf);
		return (1);
	}
	if (ft_strlen(*v) <= param)
	{
		if (((*v)[0] == '-' || (*v)[0] == '+' || (*v)[0] == ' ') && c == '0')
		{
			buf[0] = (*v)[0];
			(*v)[0] = '0';
		}
		if ((*v)[1] == 'x' && buf[0] != ' ')
		{
			buf[1] = 'x';
			(*v)[1] = '0';
		}
	}
	*v = ft_strjoin(buf, *v);
	return (1);
}

void obr_point_s_c(il *kok, char **v)
{
	if (ft_strlen(*v) >= kok->point && kok->type == 's')
		(*v)[kok->point] = 0;
}

char * mop_s_c(il *kok, char *v)
{
	obr_mines(kok, &v);
	obr_point_s_c(kok, &v);
	obr_width_s_c(kok, &v, kok->width, v[0] ? space_or_zero(kok) : ' ');
	return (v);
}

char *obr_char(il *kok, va_list ar)
{
	int k;
	char *s2;
	int i;

	s2 = ft_memset(ft_strnew(2), va_arg(ar, int), 1);
	k = s2[0];
	s2 = mop_s_c(kok, s2[0] ? s2 : "~");
	i = 0;
	while (s2[i] != 0)
	{
		if (s2[i] == '~' && !k)
			write(1, &k, 1);
		else
			write(1, &(s2[i]), 1);
		i++;
	}
	return (s2);
}

char* table_s_c(il *kok, va_list ar)
{
	char *v;
	if (kok->type == '%')
		v = mop_s_c(kok, "%");
	else if ((v = va_arg(ar, char*)) || !v)
		v = mop_s_c(kok, ft_strdup(v ? v : "(null)"));
	ft_putstr(v);
	return (v);
}