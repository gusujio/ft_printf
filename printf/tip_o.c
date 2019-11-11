/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tip_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:08:22 by gusujio           #+#    #+#             */
/*   Updated: 2019/10/28 17:08:24 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    obr_width_o(const char *s, char **v, int i, char c)
{
    char *buf;
    int l;
    int k;

    if ((k = ft_atoi(s + i)) == 0)
        return (0);
    l = ft_atoi(s + i) - ft_strlen(*v);
    l = l > 0 ? l : 0;
    buf = (char *) malloc(l + 1);
    buf[l] = 0;
    ft_memset(buf, c, l);
    if (ft_strchr(s, '-'))
    {
        *v = ft_strjoin(*v, buf);
        return (1);
    }
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
    *v = ft_strjoin(buf, *v);
    return (1);
}

void obr_point_o(const char *s, char **v, int f)
{
    if (!s)
        return;
    if (!(ft_strchr(s,'o') && f))
    {
        if (!ft_atoi(s + 1) && !ft_atoi(*v)) // ноль игнорируется
        {
            *v = "";
            return;
        }
    }
    obr_width_o(s, v, 1, '0');
}

char * mop_o(const char *s, char *v)
{
    int i;
    char c;
    int l;

    obr_mines(ft_strstr(s, "-"), &v);
    obr_resh(ft_strstr(s, "#"), &v);
    i = 0;
    obr_point_o(ft_strstr(s, "."), &v, !!ft_strstr(s, "#"));
    while (s[i])
    {
        if (s[i] > '0' && s[i] <= '9' && s[i-1] != '.')
        {
            if (obr_width_o(s, &v, i, space_or_zero(s, i)))
                break;
        }
        i++;
    }
	ft_putstr(v);
    return (v);
}

char* table_o(char *s, va_list ar , char c)
{
    void *v;

    if (s[0] && ((v = flag_unsign(s, ar)) == (void *)-2))
        v = (void *) va_arg(ar, unsigned int);
    return (mop_o(s, perevod(v, c)));
}