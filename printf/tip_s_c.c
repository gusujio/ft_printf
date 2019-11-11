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

int    obr_width_s_c(const char *s, char **v, int i, char c)
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
	if (ft_strlen(*v) <= k)
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

void obr_point_s_c(const char *s, char **v, int f)
{
	int i;
	
	if (!s)
		return;
	i = ft_atoi(s + 1);
	if (ft_strlen(*v) >= i && ft_strstr(s, "s"))
		(*v)[i] = 0;
}

 char * mop_s_c(const char *s, char *v)
{
	int i;

	obr_mines(ft_strstr(s, "-"), &v);
	obr_point_s_c(ft_strstr(s, "."), &v, ft_atoi(s) && ft_strchr(s, '#'));
	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			break;
		if (s[i] > '0' && s[i] <= '9')
		{
			if (obr_width_s_c(s, &v, i, ' '))
				break;
		}
		i++;
	}
	return (v);
}

char *obr_char(char *s, va_list ar)
{
	int k;
	char *s2;
	int i;

	s2 = ft_memset(ft_strnew(2), va_arg(ar, int), 1);
	k = s2[0];
	s2 = mop_s_c(s, s2[0] ? s2 : "~");
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

char* table_s_c(char *s, va_list ar)
{
	char *v;
	if (ft_strchr(s, '%'))
		v = mop_s_c(s,"%");
	else
		v = mop_s_c(s ,ft_strdup(va_arg(ar, char*)));
	ft_putstr(v);
	return (v);
}