/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:07:20 by gusujio           #+#    #+#             */
/*   Updated: 2019/10/20 18:07:22 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>


#include <float.h>
#include <stdio.h>

typedef struct  ilia
{
	char        type;
	char        *speth;
	char*       str;
	int         mines;
	int         plus;
	int         space;
	int         resh;
	int         zero;
	int         width;
	int         point;
	void*         v_i;
	long double   v_f;
}               il;
char            *del10(char *s, int k);
char            *ft_degr5(int k);
char            *ft_degr2(int k);
char            *ft_multi(char *wer1, char* wer);
int             *ft_revers_ari(const int *ar, int size);
int             ft_printf(const char *restrict format, ...);
int             get_nb_size(unsigned long long int nb);
char            *ft_itoa_2(unsigned long long int nbr);
size_t          ft_strlen3(const char *s, const char *c);

char            *perevod(long long int x, char c);
void            obr_mines(il *kok, char **v);
void            obr_space(il *kok, char **v);
void            obr_resh(il *kok, char **v);
char            *obr_zv(char *s, va_list ar);
void            obr_struct(il **kok, const char *s);
void            *flag_sign(il *kok, va_list ar);
void            *flag_unsign(il *kok, va_list ar);
char            *table(va_list ar, il *kok);
char            space_or_zero(il *kek);

int             obr_width_f(il *kok, char **v, int i, char c);
void            obr_point_f(il *kok, char **v);
char            *mop_f(il *kok, char *v);
char            *table_f(il *kok, va_list ar);

int             obr_width_i_d(il *kok, char **v,int param, char c);
void            obr_point_i_d(il *kok, char **v);
char            *mop_i_d(il *kok, char *v);
char            *table_i_d(il *kok, va_list ar);

void            obr_point_o(il *kok, char **v);
char            *mop_o(il *kok, char *v);
char            *table_o(il *kok, va_list ar);

void            obr_point_p(il *kok, char **v);
char            *mop_p(il *kok, char *v);
char            *table_p(il *kok, va_list ar);

int             obr_width_s_c(il *kok, char **v, int i, char c);
void            obr_point_s_c(il *kok, char **v);
char            *mop_s_c(il *kok, char *v);
char            *table_s_c(il *kok, va_list ar);
char            *obr_char(il *kok, va_list ar);

int             obr_width_u(il *kok, char **v, int param, char c);
void            obr_point_u(il *kok, char **v);
char            *mop_u(il *kok, char *v);
char            *table_u(il *kok, va_list ar);

int             obr_width_x_X(il *kok, char **v, int param, char c);
void            obr_point_x_X(il *kok, char **v);
char            *mop_x_X(il *kok, char *v);
char            *table_x_X(il *kok, va_list ar);

#endif
