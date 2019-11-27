/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obr3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:31:47 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/27 15:09:30 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_strdup2(char *s)
{
	char	*s2;

	s2 = ft_strdup(s);
	ft_strdel(&s);
	return (s2);
}

long long int			flag_sign(t_il *kok, va_list ar)
{
	if (kok->speth)
	{
		if (kok->speth[0] == 'h' && kok->speth[1] == 'h')
			return ((signed char)va_arg(ar, int));
		else if (kok->speth[0] == 'h')
			return ((short int)va_arg(ar, int));
		else if (kok->speth[0] == 'l' && kok->speth[1] == 'l')
			return (va_arg(ar, long long int));
		else if (kok->speth[0] == 'l')
			return (va_arg(ar, long int));
	}
	return (-2);
}

unsigned long int		flag_unsign(t_il *kok, va_list ar)
{
	unsigned long long int e;

	if (kok->speth)
	{
		if (kok->speth[0] == 'h' && kok->speth[1] == 'h')
			return (e = (unsigned char)va_arg(ar, int));
		else if (kok->speth[0] == 'h')
			return (e = (unsigned short int)va_arg(ar, int));
		else if (kok->speth[0] == 'l' && kok->speth[1] == 'l')
			return (e = va_arg(ar, unsigned long long int));
		else if (kok->speth[0] == 'l')
			return (e = va_arg(ar, unsigned long int));
	}
	return ((unsigned int)-2);
}

char					space_or_zero(t_il *kok)
{
	int y;

	y = kok->type != 'f' ? 1 : kok->resh != 1;
	if (kok->type == 'f' && !kok->mines && kok->zero && y)
		return ('0');
	if (kok->point == -1 && !kok->mines && kok->zero && y)
		return ('0');
	if (!kok->mines && kok->width < kok->point && kok->zero && y)
		return ('0');
	return (' ');
}

char					*perevod2(unsigned long long int x, char c)
{
	unsigned long long int	osn;
	unsigned long long int	ost;
	unsigned long long int	size;
	char					*s;

	if (c == 'o')
		osn = 8;
	else
		osn = c == 'x' || c == 'X' ? 16 : 2;
	ost = x;
	size = sizes(osn, ost);
	s = (char *)malloc(size + 1);
	s[size] = 0;
	while (size-- > 0)
	{
		ost = (x - (osn * (x / osn))) + 48;
		if (ost > 57)
			ost = (c - 24) + (ost - 57);
		s[size] = (char)ost;
		x /= (long long int)osn;
	}
	return (s);
}
