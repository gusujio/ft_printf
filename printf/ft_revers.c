/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:17:35 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/17 13:17:38 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_revers_ari(const int *ar, int size)
{
	int *k;
	int i;
	
	i = 0;
	k = (int*)malloc(sizeof(int) * (size + 1));
	k[size] = size;
	while (--size >= 0)
	{
		k[i] = ar[size];
		i++;
	}
	return (k);
}
