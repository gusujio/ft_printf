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

int    obr_width_i_d(const char *s, char **v, int i, char c)
{
	char *buf;
	int l;
	int k;
	
	if ((k = ft_atoi(s + i)) == 0)
		return (0);
	l = ft_atoi(s + i) - ft_strlen(*v);
	l = l > 0 ? l : 0;
	ft_strchr(*v, '-')  && ft_strchr(s, '.') && c != ' ' && l ? l++ : l; // если есть минус, то прибавим знак
	buf = (char *) malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	if (ft_strchr(s, '-'))
	{
		*v = ft_strjoin(*v, buf);
		return (1);
	}
	if ((!ft_strchr(s, '+') || (ft_strlen(buf))) && ft_strlen(*v) <= k)
	{
		if (((*v)[0] == '-' || (*v)[0] == '+' || (*v)[0] == ' ') && c == '0')
		{
			buf[0] = (*v)[0];
			(*v)[0] = '0';
		}
	}
	*v = ft_strjoin(buf, *v);
	return (1);
}
void obr_point_i_d(const char *s, char **v)
{
	if (!s)
		return;
	if (!ft_atoi(s + 1) && !ft_atoi(*v)) // ноль игнорируется
	{
		*v = "";
		return;
	}
	obr_width_i_d(s, v, 1, '0');
}
char * mop_i_d(const char *s, char *v)
{
	int i;
	char c;
	char *l;
	
	obr_mines(ft_strstr(s, "-"), &v);
	if (ft_strstr(s, "+"))
		if (v[0] != '-')
			v = ft_strjoin("+", v);
	i = 0;
	obr_point_i_d(ft_strstr(s, "."), &v);
	obr_space(ft_strstr(s, " "), &v);
	while (s[i])
	{
		if (s[i] > '0' && s[i] <= '9' && s[i-1] != '.')
		{
			if (obr_width_i_d(s, &v, i, space_or_zero(s, i)))
				break;
		}
		i++;
	}
	ft_putstr(v);
	return (v);
}

char* table_i_d(char *s, va_list ar)
{
	void *v;
	
	if (s[0] && ((v = flag_sign(s, ar)) == (void *)-2))
		v = (void *) va_arg(ar, int);
	return (mop_i_d(s, ft_itoa(v)));
}