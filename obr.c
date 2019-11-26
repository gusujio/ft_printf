/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:29:01 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/26 15:45:33 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	obr_str2(t_il **kok, char *s, int i)
{
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

void	obr_struct(t_il **kok, char *s)
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
	obr_str2(kok, s, i);
}

void	obr_zv2(char **s2, char **s, va_list ar, int i)
{
	*s2 = ft_itoa(va_arg(ar, int));
	if (ft_isdigit((*s)[i + 1]) || ((*s)[i - 1] == '.' && (*s2)[0] == '-'))
	{
		ft_strdel(s2);
		*s2 = ft_strdup("");
		(*s)[i - 1] == '.' ? (*s)[i - 1] = 0 : 0;
	}
	*s2 = ft_strjoin1(*s2, &((*s)[i + 1]));
	(*s)[i] = 0;
	*s2 = ft_strjoin2(*s, *s2);
	ft_strdel(s);
	*s = *s2;
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
			obr_zv2(&s2, &s, ar, i);
		i++;
	}
	return (s2);
}
