/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:13:07 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/25 22:39:32 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*del10(char *s, int k)
{
	int		len;
	char	*s2;
	int		i;

	if (k >= (len = ft_strlen(s)))
	{
		k = k - len + 2;
		s2 = ft_memset(ft_strnew(k), '0', k);
		s2[1] = '.';
		return (ft_strjoin3(s2, s));
	}
	s2 = ft_strnew(len + 1);
	k = len - k - 1;
	i = 1;
	while (--len >= 0)
	{
		if (len == k)
		{
			s2[len + i] = '.';
			i = 0;
		}
		s2[len + i] = s[len];
	}
	ft_strdel(&s);
	return (s2);
}
