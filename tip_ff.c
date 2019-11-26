/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tip_ff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:18:17 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/25 18:27:33 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	okrug(il *kok, char **s)
{
	int p;

	if (!*s)
		*s = ft_strdup("0");
	kok->point = kok->point == -1 ? 6 : kok->point;
	p = (int)ft_strlen2(*s, '.') + kok->point + 1;
	if ((*s)[p] >= '6')
		okr2(s, p, 10 - (*s)[p]);
	else if ((*s)[p] == '5')
	{
		if (!onlit(*s, '0'))
			okr2(s, p, 5);
	}
}

char	*inf(il *kok, ilia ili)
{
	char	*man;

	man = NULL;
	if (ili.m == 9223372036854775808 && ili.e[4] == 32767)
		man = ft_strdup("inf");
	if (ili.m == 9223372036854775808 && ili.e[4] == -1)
		man = ft_strdup("-inf");
	if (ili.f != ili.f)
		man = ft_strdup("nan");
	if (man)
	{
		kok->resh = 1;
		man = mop_s_c(kok, man);
		ft_putstr(man);
	}
	return (man);
}

char	*obr_f(ilia ili, char *man, int z, il *kok)
{
	char	*tail;
	char	*s;

	if (man[0] == '-')
	{
		s = man;
		man = ft_strdup(man + 1);
		ft_strdel(&s);
	}
	if (ili.e[4] > 0)
	{
		s = ft_degr(ili.e[4], 2);
		tail = ft_multi(man, s);
	}
	else
	{
		s = ft_degr(ili.e[4] * -1, 5);
		tail = del10(ft_multi(man, s), ili.e[4] * -1);
	}
	okrug(kok, &tail);
	if (--man[0] == '-' || z == -1)
		tail = ft_strjoin("-", tail);
	ft_strdel(&man);
	ft_strdel(&s);
	return (mop_f(kok, tail));
}

char	*table_f(il *kok, va_list ar)
{
	ilia	ili;
	int		z;
	char	*man;

	if (kok->speth)
	{
		if (kok->speth[0] == 'L')
			ili.f = va_arg(ar, long double);
		if (kok->speth[0] == 'l')
			ili.f = va_arg(ar, double);
	}
	else
		ili.f = va_arg(ar, double);
	if ((man = inf(kok, ili)))
		return (man);
	z = ili.e[4] >> 15;
	ili.e[4] = ili.e[4] & 0x7fff;
	ili.e[4] -= 16383 + 63;
	man = ft_itoa2(ili.m);
	return (obr_f(ili, man, z, kok));
}
