/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tip_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:10:48 by gusujio           #+#    #+#             */
/*   Updated: 2019/10/28 17:10:51 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    obr_width_p(il *kok, char **v, int param, char c)
{
    char *buf;
    int l;

    if (param == 0)
        return (0);
    l = (int)(param - ft_strlen(*v));
    l = l > 0 ? l : 0;
    buf = (char *) malloc(l + 1);
    buf[l] = 0;
    ft_memset(buf, c, l);
	obr_sistem(v,&buf,c);
	if (kok->mines && param != kok->point)
		*v = ft_strjoin3(*v, buf);
	else
		*v = ft_strjoin3(buf, *v);
    return (1);
}

void obr_point_p(il *kok, char **v)
{
    if (!kok->point)
        (*v)[ft_strlen(*v) - 1] = 0;
    else if (!kok->point && !kok->v_i) // ноль игнорируется
    {
        *v = ft_strdup("");
        return;
    }
    obr_width_p(kok, v, kok->point, '0');
}

char* table_p(il *kok, va_list ar)
{
    void *v1;
	char *v;
	
	if ((v1 = flag_sign(kok, ar)) == (void *)-2)
        v1 = (void *) va_arg(ar, unsigned long int);
	kok->v_i = v1;
    v = perevod(v1, 'x');
	obr_resh(kok, &v);
	obr_point_p(kok, &v);
	v = ft_strjoin2("0x", v);
	obr_width_p(kok, &v, kok->width, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}
