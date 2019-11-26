/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:54:08 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/26 17:01:32 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*table(va_list ar, t_il *kok)
{
	if (kok->type == 'c')
		return (obr_char(kok, ar));
	else if (kok->type == 's' || kok->type == '%')
		return (table_s_c(kok, ar));
	else if (kok->type == 'd' || kok->type == 'i')
		return (table_i_d(kok, ar));
	else if (kok->type == 'x' || kok->type == 'X')
		return (table_x(kok, ar));
	else if (kok->type == 'o')
		return (table_o(kok, ar));
	else if (kok->type == 'u')
		return (table_u(kok, ar));
	else if (kok->type == 'p')
		return (table_p(kok, ar));
	else if (kok->type == 'f')
		return (table_f(kok, ar));
	else if (kok->type == 'm')
		table_m(kok, ar);
	else if (kok->type == 'b')
		return (ft_bit(va_arg(ar, int)));
	return (ft_strdup(""));
}

void	delst(t_il *kok, char *s, int *len)
{
	*len += s == NULL ? 1 : (int)ft_strlen(s);
	ft_strdel(&kok->speth);
	ft_strdel(&kok->str);
	ft_strdel(&s);
	ft_bzero(kok, sizeof(t_il));
}

int		decl(t_il **kok, int *i)
{
	ft_bzero(*kok = malloc(sizeof(t_il)), sizeof(t_il));
	*i = -1;
	return (0);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ar;
	int		i;
	int		len;
	char	*s;
	t_il	*kok;

	len = decl(&kok, &i);
	va_start(ar, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			obr_struct(&kok, obr_zv(format + i + 1, ar, &i));
			s = table(ar, kok);
			delst(kok, s, &len);
		}
		else if (!(format[i] == '%' && !format[i + 1]))
		{
			ft_putchar(format[i]);
			len++;
		}
	}
	free(kok);
	va_end(ar);
	return (len);
}
