/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obr3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:31:47 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/26 15:45:39 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup2(char *s)
{
	char	*s2;

	s2 = ft_strdup(s);
	ft_strdel(&s);
	return (s2);
}

long long int flag_sign(t_il *kok, va_list ar)
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

unsigned long long int	flag_unsign(t_il *kok, va_list ar)
{
	if (kok->speth)
	{
		if (kok->speth[0] == 'h' && kok->speth[1] == 'h')
			return ((unsigned char)va_arg(ar, int));
		else if (kok->speth[0] == 'h')
			return ((unsigned short int)va_arg(ar, int));
		else if (kok->speth[0] == 'l' && kok->speth[1] == 'l')
			return (va_arg(ar, unsigned long long int));
		else if (kok->speth[0] == 'l')
			return (va_arg(ar, unsigned long int));
	}
	return (-2);
}

char	space_or_zero(t_il *kok)
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
