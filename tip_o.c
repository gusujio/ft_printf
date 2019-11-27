/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tip_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:08:22 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/27 15:11:01 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		obr_width_o(t_il *kok, char **v, int p, char c)
{
	char	*buf;
	int		l;
	int		param;
	int		k;

	param = p ? kok->width : kok->point;
	if (param < 0 && kok->mines)
		return (0);
	k = (int)ft_strlen(*v) - (!p ? (((*v)[0] == '-') + ((*v)[0] == '+')) : 0);
	l = param - k;
	l = l > 0 ? l : 0;
	buf = (char *)malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	obr_sistem(v, &buf, c);
	if (kok->mines && param != kok->point)
		*v = ft_strjoin3(*v, buf);
	else
		*v = ft_strjoin3(buf, *v);
	return (1);
}

void	obr_point_o(t_il *kok, char **v)
{
	if (!kok->point && !kok->v_i)
	{
		if (kok->resh)
			(*v)[1] = 0;
		else
			*v = ft_strdup("");
		return ;
	}
	obr_width_o(kok, v, 0, '0');
}

char	*table_o(t_il *kok, va_list ar)
{
	unsigned long long int	v1;
	char					*v;

	if ((int)(v1 = flag_unsign(kok, ar)) == -2)
		v1 = va_arg(ar, unsigned int);
	kok->v_i = v1;
	v = perevod2(v1, kok->type);
	obr_resh(kok, &v);
	obr_point_o(kok, &v);
	obr_width_o(kok, &v, 1, space_or_zero(kok));
	ft_putstr(v);
	return (v);
}
