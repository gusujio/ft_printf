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

#define PRC     "\x1b[31m"
#define PWC     "\x1b[107m"
#define PGC   "\x1b[32m"
#define PYC  "\x1b[33m"
#define PBC    "\x1b[34m"
#define PMC "\x1b[35m"
#define PCC    "\x1b[36m"
#define EPC   "\x1b[0m"

typedef struct  ilia
{
	char        type;
	char        *speth;
	char        *str;
	int         mines;
	int         plus;
	int         space;
	int         resh;
	int         zero;
	int         width;
	int         point;
	void        *v_i;
	long double   v_f;
}               il;

typedef union			types
{
	long double			f;
	unsigned long long	m;
	short int			e[5];
}						ilia;
char	*ft_degr5(int k);
char	*ft_degr2(int k);
char*	dop(int *k, char **k2, char *m[60]);
char	*del10(char *s, int k);
//void	ft_m2(const char *wer, const char *wer1, int *cc[99999], int r);
char	*revers_s(const int *s, long long int i);
char            *ft_strdup2(char *s);
char            *del10(char *s, int k);
char	*ft_degr(int k, int i);
char	*ft_multi(char *wer1,char *wer);
int             *ft_revers_ari(const int *ar, int size);
int             ft_printf(const char *restrict format, ...);
int             get_nb_size(unsigned long long int nb);
char            *ft_itoa_2(unsigned long long int nbr);
size_t          ft_strlen3(const char *s, const char *c);

char            *perevod(long long int x, char c);
void            obr_space(il *kok, char **v);
void            obr_resh(il *kok, char **v);
char            *obr_zv(const char *s0, va_list ar, int *len);
void            obr_struct(il **kok, char *s);
void            obr_sistem(char **v,char **buf, char c);
void            *flag_sign(il *kok, va_list ar);
void            *flag_unsign(il *kok, va_list ar);
char            *table(va_list ar, il *kok);
char            space_or_zero(il *kek);

void            table_m(il *kok, va_list ar);
char            *ft_bit(unsigned char c);

int             obr_width_f(il *kok, char **v, int i, char c);
void            obr_point_f(il *kok, char **v);
char            *mop_f(il *kok, char *v);
char            *table_f(il *kok, va_list ar);
char	*obr_f(ilia ili, char *man, int z, il *kok);
char	*inf(il *kok, ilia ili);
void	okrug(il *kok, char **s);
int		onlit(char *s, char c);
void	okr2(char **s, int l, int d);
char	*mop_f(il *kok, char *v);
void	obr_point_f(il *kok, char **v);

int             obr_width_i_d(il *kok, char **v,int param, char c);
void            obr_point_i_d(il *kok, char **v);
char            *mop_i_d(il *kok, char *v);
char            *table_i_d(il *kok, va_list ar);

int             obr_width_o(il *kok, char **v, int p, char c);
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

void		    obr_width_x(il *kok, char **v, int p, char c);
void            obr_point_x(il *kok, char **v);
char            *mop_x(il *kok, char *v);
char            *table_x(il *kok, va_list ar);

#endif
