/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:07:20 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/26 17:00:42 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# define PRC "\x1b[31m"
# define PWC "\x1b[107m"
# define PGC "\x1b[32m"
# define PYC "\x1b[33m"
# define PBC "\x1b[34m"
# define PMC "\x1b[35m"
# define PCC "\x1b[36m"
# define EPC "\x1b[0m"

typedef struct			s_ilia
{
	char				type;
	char				*speth;
	char				*str;
	int					mines;
	int					plus;
	int					space;
	int					resh;
	int					zero;
	int					width;
	int					point;
	void				*v_i;
}						t_il;

typedef union			u_types
{
	long double			f;
	unsigned long long	m;
	short int			e[5];
}						t_ailia;

char					*del10(char *s, int k);
char					*revers_s(const int *s, long long int i);
char					*del10(char *s, int k);
char					*ft_degr(int k, int i);
char					*ft_multi(char *wer1, char *wer);
int						ft_printf(const char *restrict format, ...);
size_t					ft_strlen3(const char *s, const char *c);
char					*perevod(long long int x, char c);
void					obr_space(t_il *kok, char **v);
void					obr_resh(t_il *kok, char **v);
char					*obr_zv(const char *s0, va_list ar, int *len);
void					obr_struct(t_il **kok, char *s);
void					obr_sistem(char **v, char **buf, char c);
void					*flag_sign(t_il *kok, va_list ar);
void					*flag_unsign(t_il *kok, va_list ar);
char					*table(va_list ar, t_il *kok);
char					space_or_zero(t_il *kek);
void					table_m(t_il *kok, va_list ar);
char					*ft_bit(unsigned char c);
int						obr_width_f(t_il *kok, char **v, int i, char c);
void					obr_point_f(t_il *kok, char **v);
char					*mop_f(t_il *kok, char *v);
char					*table_f(t_il *kok, va_list ar);
char					*obr_f(t_ailia ili, char *man, int z, t_il *kok);
char					*inf(t_il *kok, t_ailia ili);
void					okrug(t_il *kok, char **s);
int						onlit(char *s, char c);
void					okr2(char **s, int l, int d);
char					*mop_f(t_il *kok, char *v);
void					obr_point_f(t_il *kok, char **v);
int						obr_width_i_d(t_il *kok, char **v, int param, char c);
void					obr_point_i_d(t_il *kok, char **v);
char					*table_i_d(t_il *kok, va_list ar);
int						obr_width_o(t_il *kok, char **v, int p, char c);
void					obr_point_o(t_il *kok, char **v);
char					*table_o(t_il *kok, va_list ar);
void					obr_point_p(t_il *kok, char **v);
char					*table_p(t_il *kok, va_list ar);
int						obr_width_s_c(t_il *kok, char **v, int i, char c);
char					*mop_s_c(t_il *kok, char *v);
char					*table_s_c(t_il *kok, va_list ar);
char					*obr_char(t_il *kok, va_list ar);
char					*mop_u(t_il *kok, char *v);
char					*table_u(t_il *kok, va_list ar);
void					obr_width_x(t_il *kok, char **v, int p, char c);
char					*table_x(t_il *kok, va_list ar);

#endif
