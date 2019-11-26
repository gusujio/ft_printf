/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obr2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:30:53 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/26 17:06:59 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int		sizes(unsigned long long int osn,
							unsigned long long int ost)
{
	unsigned long long int	size;

	size = 1;
	while (ost >= osn)
	{
		ost /= osn;
		size++;
	}
	return (size);
}

char						*perevod(long long int x, char c)
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
		s[size] = ost;
		x /= osn;
	}
	return (s);
}

void						obr_resh(t_il *kok, char **v)
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

void						obr_space(t_il *kok, char **v)
{
	if (!kok->space)
		return ;
	if ((*v)[0] != '-' && (*v)[0] != '+' && ft_strcmp(*v, "nan"))
		*v = ft_strjoin2(" ", *v);
}

void						obr_sistem(char **v, char **buf, char c)
{
	if (((*v)[0] == '-' || (*v)[0] == '+' || (*v)[0] == ' ') && c == '0')
	{
		(*buf)[0] = (*v)[0];
		(*v)[0] = '0';
	}
}
