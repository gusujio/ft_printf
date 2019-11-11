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

int             get_nb_size(unsigned long long int nb);
char            *ft_itoa_2(unsigned long long int nbr);
char            *perevod(long long int x, char c);
size_t          ft_strlen3(const char *s, const char *c);
int             obr_width(const char *s, char **v, int i, char c);
void            obr_mines(const char *s, char **v);
void            obr_resh(const char *s, char **v);
void            obr_space(const char *s, char **v);
void            *flag_sign(char *f, va_list ar);
void            *flag_unsign(char *f, va_list ar);
char            *table(char c, va_list ar, char *s);
char            *obrabotka_zv(char* s, va_list ar);
char            space_or_zero(char *s, int i);
char            *obr_char(char *s, va_list ar);

int             ft_printf(const char *restrict format, ...);
void            obr_point_f(const char *s, char **v, int f);
char            *mop_f(const char *s, char *v);
char            *table_f(char *s, va_list ar);
int             obr_width_f(const char *s, char **v, int i, char c);
void            obr_point_i_d(const char *s, char **v);
int             obr_width_i_d(const char *s, char **v, int i, char c);
char            *mop_i_d(const char *s, char *v);
char            *table_i_d(char *s, va_list ar);
void            obr_point_o(const char *s, char **v, int f);
char            *mop_o(const char *s, char *v);
char            *table_o(char *s, va_list ar , char c);
char            *table_p(char *s, va_list ar);
void            obr_point_p(const char *s, char **v);
char            *mop_p(const char *s, char *v);
void            obr_point_s_c(const char *s, char **v, int f);
char            *mop_s_c(const char *s, char *v);
char            *table_s_c(char *s, va_list ar);
int             obr_width_s_c(const char *s, char **v, int i, char c);
void            obr_point_u(const char *s, char **v, int f);
int             obr_width_u(const char *s, char **v, int i, char c);
char            *table_u(char *s, va_list ar);
char            *mop_u(const char *s, char *v);
char            *mop_s_c(const char *s, char *v);
char            *mop_u(const char *s, char *v);
void            obr_point_x_X(const char *s, char **v);
char            *mop_x_X(const char *s, char *v);
char            *table_x_X(char *s, va_list ar , char c);
int             obr_width_x_X(const char *s, char **v, int i, char c);

#endif
