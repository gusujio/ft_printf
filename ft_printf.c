/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:54:08 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/25 18:04:15 by gusujio          ###   ########.fr       */
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

char	*perevod(long long int x, char c)
{
	unsigned long long int	osn;
	unsigned long long int	ost;
	unsigned long long int	size;
	char					*s;

	osn = c == 'o' ? 8 : c == 'x' || c == 'X' ? 16 : 2;
	ost = x;
	size = 1;
	while (ost >= osn)
	{
		ost /= osn;
		size++;
	}
	s = (char *)malloc(size + 1);
	s[size] = 0;
	while (size-- > 0)
	{
		ost = (x - (osn * (x / osn))) + 48;
		if (ost > 57)
			ost = (c - 24) + (ost - 57);
		s[size] = ost;
		x /= osn;
	}
	return (s);
}

void	obr_resh(il *kok, char **v)
{
	if (!kok->resh)
		return ;
	if (kok->type == 'p')
		*v = ft_strjoin2("0x", *v);
	if ((*v)[0] == '0' && !kok->v_i && kok->point)
	{
		kok->resh = 0;
		return ;
	}
	if (kok->type == 'x')
		*v = ft_strjoin2("0x", *v);
	else if (kok->type == 'X')
		*v = ft_strjoin2("0X", *v);
	else if (kok->type == 'o')
		*v = ft_strjoin2("0", *v);
}

void	obr_space(il *kok, char **v)
{
	if (!kok->space)
		return ;
	if ((*v)[0] != '-' && (*v)[0] != '+' && ft_strcmp(*v, "nan"))
		*v = ft_strjoin2(" ", *v);
}

void	obr_sistem(char **v, char **buf, char c)
{
	if (((*v)[0] == '-' || (*v)[0] == '+' || (*v)[0] == ' ') && c == '0')
	{
		(*buf)[0] = (*v)[0];
		(*v)[0] = '0';
	}
}

void	*flag_sign(il *kok, va_list ar)
{
	void *error;

	error = (void *)-2;
	if (kok->speth)
	{
		if (kok->speth[0] == 'h' && kok->speth[1] == 'h')
			return ((void *)va_arg(ar, signed char));
		else if (kok->speth[0] == 'h')
			return ((void *)va_arg(ar, short int));
		else if (kok->speth[0] == 'l' && kok->speth[1] == 'l')
			return ((void *)va_arg(ar, long long int));
		else if (kok->speth[0] == 'l')
			return ((void *)va_arg(ar, long int));
	}
	return (error);
}

void	*flag_unsign(il *kok, va_list ar)
{
	void	*error;

	error = (void *)-2;
	if (kok->speth)
	{
		if (kok->speth[0] == 'h' && kok->speth[1] == 'h')
			return ((void *)va_arg(ar, unsigned char));
		else if (kok->speth[0] == 'h')
			return ((void *)va_arg(ar, unsigned short int));
		else if (kok->speth[0] == 'l' && kok->speth[1] == 'l')
			return ((void *)va_arg(ar, unsigned long long int));
		else if (kok->speth[0] == 'l')
			return ((void *)va_arg(ar, unsigned long int));
	}
	return (error);
}

char	space_or_zero(il *kok)
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

char	*table(va_list ar, il *kok)
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
	else
		return (ft_strdup(""));
}

void	obr_struct(il **kok, char *s)
{
	char	*k;
	int		i;

	i = 0;
	(*kok)->str = s;
	while (s[i] && s[i] < '1' && s[i] != '.')
	{
		(*kok)->mines += s[i] == '-';
		(*kok)->plus += s[i] == '+';
		(*kok)->space += s[i] == ' ';
		(*kok)->resh += s[i] == '#';
		(*kok)->zero += s[i] == '0' && s[i - 1] != '-';
		i++;
	}
	(*kok)->width = ft_atoi(s + i);
	(*kok)->point = -1;
	if ((k = ft_strchr(s, '.')))
		(*kok)->point = ft_atoi(k + 1);
	(*kok)->speth = NULL;
	while (s[i] && !(*kok)->speth)
	{
		if (s[i] == 'l' && s[i + 1] != 'l')
			(*kok)->speth = ft_strdup("l");
		else if (s[i] == 'l')
			(*kok)->speth = ft_strdup("ll");
		else if (s[i] == 'h' && s[i + 1] != 'h')
			(*kok)->speth = ft_strdup("h");
		else if (s[i] == 'h')
			(*kok)->speth = ft_strdup("hh");
		else if (s[i] == 'L')
			(*kok)->speth = ft_strdup("L");
		i++;
	}
	(*kok)->type = s[ft_strlen(s) - 1];
}

char	*obr_zv(const char *s0, va_list ar, int *len)
{
	int		i;
	char	*s2;
	char	*s;

	*len += (i = ft_strlen3(s0, "cspdioufxmX%")) + 1;
	s = ft_strdup(s0);
	if (s[i] == 'D' || s[i] == 'C' || s[i] == 'F' || s[i] == 'S' || s[i] == 'P')
		s[i] += 32;
	s[i + 1] = 0;
	i = 0;
	s2 = s;
	while (s[i] && s[i] != ' ')
	{
		if (s[i] == '*')
		{
			s2 = ft_itoa(va_arg(ar, int));
			if (ft_isdigit(s[i + 1]) || (s[i - 1] == '.' && s2[0] == '-'))
			{
				ft_strdel(&s2);
				s2 = ft_strdup("");
				s[i - 1] == '.' ? s[i - 1] = 0 : 0;
			}
			s2 = ft_strjoin1(s2, &(s[i + 1]));
			s[i] = 0;
			s2 = ft_strjoin2(s, s2);
			ft_strdel(&s);
			s = s2;
		}
		i++;
	}
	return (s2);
}

void	delst(il *kok, char *s)
{
	ft_strdel(&kok->speth);
	ft_strdel(&kok->str);
	ft_strdel(&s);
	ft_bzero(kok, sizeof(il));
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ar;
	int		i;
	int		len;
	char	*s;
	il		*kok;

	kok = malloc(sizeof(il));
	ft_bzero(kok, sizeof(il));
	i = -1;
	len = 0;
	va_start(ar, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			obr_struct(&kok, obr_zv(format + i + 1, ar, &i));
			s = table(ar, kok);
			len += s == NULL ? 1 : (int)ft_strlen(s);
			delst(kok, s);
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