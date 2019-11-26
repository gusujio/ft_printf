/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_X.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:06:59 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/25 18:52:05 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	obr_width_x(t_il *kok, char **v, int p, char c)
{
	char	*buf;
	char	*v2;
	int		l;
	int		k;
	int		n;

	if ((n = p ? kok->width : kok->point) < 0 && kok->mines)
		return ;
	k = (int)ft_strlen(*v) - (!p ? (((*v)[0] == '-') + ((*v)[0] == '+')) : 0);
	l = n - k + !p * 2 * kok->resh;
	l = l > 0 ? l : 0;
	buf = (char *)malloc((l) + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	obr_sistem(v, &buf, c);
	if (kok->resh && c != ' ' && l)
	{
		v2 = *v;
		*v = ft_strjoin1(buf, *v + 2);
		ft_strdel(&v2);
		obr_resh(kok, v);
		return ;
	}
	*v = kok->mines && n != kok->point ?
	ft_strjoin3(*v, buf) : ft_strjoin3(buf, *v);
}

char	*table_x(t_il *kok, va_list ar)
{
	unsigned long long int	v1;
	char	*v;

	if ((int)(v1 = flag_unsign(kok, ar)) == -2)
		v1 = va_arg(ar, unsigned int);
	kok->v_i = (void*)v1;
	v = perevod((long long int)v1, kok->type);
	obr_resh(kok, &v);
	obr_point_i_d(kok, &v);
	obr_width_x(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}
