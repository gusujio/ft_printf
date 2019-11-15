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

int    obr_width_o(il *kok, char **v, int p, char c)
{
    char *buf;
    int l;
	int param;
	int k;
	
	param = p ? kok->width : kok->point;
	if (param < 0 && kok->mines)
		return (0);
	k = ft_strlen(*v) - (!p ? (((*v)[0] == '-') + ((*v)[0] == '+')) : 0);
	l = param - k;
	l = l > 0 ? l : 0;
	buf = (char *) malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
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
	if (kok->mines && param != kok->point)
		*v = ft_strjoin(*v, buf);
	else
		*v = ft_strjoin(buf, *v);
    return (1);
}

void obr_point_o(il *kok, char **v)
{
	if (!kok->point && !kok->v_i) // ноль игнорируется
	{
		if (kok->resh)
			(*v)[1] = 0;
		else
			*v = "";
		return;
	}
	obr_width_o(kok, v,0, '0');
}

char    *mop_o(il *kok, char *v)
{
	obr_resh(kok, &v);
	obr_point_o(kok, &v);
    obr_width_o(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
    return (v);
}

char* table_o(il *kok, va_list ar)
{
    void *v;
	
	if ((v = flag_unsign(kok, ar)) == (void *)-2)
        v = (void *) va_arg(ar, unsigned int);
	kok->v_i = v;
    return (mop_o(kok, perevod(v, kok->type)));
}