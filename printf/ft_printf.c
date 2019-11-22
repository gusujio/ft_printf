#include "ft_printf.h"
#define ui_pos_1
int		get_nb_size(unsigned long long int nb)
{
	unsigned long long int size;
	
	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

char			*ft_itoa_2(unsigned long long int nbr)
{
	char *str;
	unsigned long long int nb;
	unsigned long long int index;
	unsigned long long int size;
	
	if (nbr < 0)
		nb = (nbr * -1);
	else
		nb = nbr;
	if (nbr == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	size = get_nb_size(nb);
	index = 0;
	if (!(str = (char *) malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && (str[index] = '-'))
		size++;
	index = size - 1;
	while (nb >= 10)
	{
		str[index--] = (char) (nb % 10 + 48);
		nb /= 10;
	}
	str[index] = (char) (nb % 10 + 48);
	str[size] = '\0';
	return (str);
}

char *perevod(long long int x, char c) // из деситичную в указанную
{
	unsigned long long int osn;
	unsigned long long int ost;
	unsigned long long int size;
	char *s;
	
	osn = c == 'o' ? 8 : c == 'x' || c == 'X' ? 16 : 2;
	ost = x;
	size = 1;
	while (ost >= osn)
	{
		ost /= osn;
		size++;
	}
	s = (char *) malloc(size + 1);
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

size_t	ft_strlen3(const char *s, const char *c)
{
	size_t i;
	size_t j;
	
	i = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (c[j])
		{
			if (c[j] == s[i])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void obr_resh(il *kok, char **v)
{
	if (!kok->resh)
		return;
	if (kok->type == 'p')
		*v = ft_strjoin("0x", *v);
	if ((*v)[0] == '0' && !kok->v_i && kok->point)
	{
		kok->resh = 0;
		return;
	}
	if (kok->type == 'x')
		*v = ft_strjoin("0x", *v);
	else if (kok->type == 'X')
		*v = ft_strjoin("0X", *v);
	else if (kok->type == 'o')
		*v = ft_strjoin("0", *v);
}

void obr_space(il *kok, char **v)
{
	if (!kok->space)
		return;
	if ((*v)[0] != '-' && (*v)[0] != '+' && ft_strcmp(*v, "nan"))
		*v = ft_strjoin(" ", *v);
}

char *ft_strup(const char *s)
{
	char *s2;
	int i;
	
	s2 = (char*)malloc((i =  ft_strlen(s)));
	s2[i] = 0;
	while (--i >= 0)
	{
		s2[i] = s[i];
		s2[i] = (char)ft_toupper(s2[i]);
	}
	return (s2);
}

char *ft_strdow(const char *s)
{
	char *s2;
	int i;
	
	s2 = (char*)malloc((i = ft_strlen(s)));
	s2[i] = 0;
	while (--i >= 0)
	{
		s2[i] = s[i];
		s2[i] = (char)ft_tolower(s2[i]);
	}
	return (s2);
}

void * flag_sign(il *kok, va_list ar)
{
	void *error;

	error = (void *)-2;
	if (kok->speth)
	{
		if (kok->speth[0] == 'h' && kok->speth[1] == 'h')
			return ((void *) va_arg(ar, signed char));
		else if (kok->speth[0] == 'h')
			return ((void *) va_arg(ar, short int));
		else if (kok->speth[0] == 'l' && kok->speth[1] == 'l')
			return ((void *) va_arg(ar, long long int));
		else if (kok->speth[0] == 'l')
			return ((void *) va_arg(ar, long int));
	}
	return (error);
}

void *flag_unsign(il *kok, va_list ar)
{
	void *error;

	error = (void *)-2;
	if (kok->speth)
	{
		if (kok->speth[0] == 'h' && kok->speth[1] == 'h')
			return ((void *) va_arg(ar, unsigned char));
		else if (kok->speth[0] == 'h')
			return ((void *) va_arg(ar, unsigned short int));
		else if (kok->speth[0] == 'l' && kok->speth[1] == 'l')
			return ((void *) va_arg(ar, unsigned long long int));
		else if (kok->speth[0] == 'l')
			return ((void *) va_arg(ar, unsigned long int));
	}
	return (error);
}

char space_or_zero(il *kok)
{
	if (kok->type == 'f' && !kok->mines && kok->zero && kok->str[0] != 1)
		return ('0');
	if (kok->point == -1 && !kok->mines && kok->zero && kok->str[0] != 1)
		return ('0');
	if (!kok->mines && kok->width < kok->point && kok->zero && kok->str[0] != 1)
		return ('0');
	return (' ');
}

char* table(va_list ar, il *kok)
{
	
	if (kok->type == 'c')
		return (obr_char(kok, ar));
	else if (kok->type == 's' || kok->type== '%')
		return (table_s_c(kok, ar));
	else if (kok->type == 'd' || kok->type == 'i')
		return (table_i_d(kok, ar));
	else if (kok->type == 'x' || kok->type == 'X')
		return (table_x_X(kok, ar));
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
		ft_bit(va_arg(ar, int));
}

void obr_struct(il **kok, const char *s)
{
	char *k;
	int i;
	
	i = 0;
	(*kok)->str = ft_strdup(s);
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
	if ((k = strchr(s, '.')))
		(*kok)->point = ft_atoi(k + 1);
	(*kok)->speth = (char *) malloc(3);
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

char* obr_zv(const char *s0, va_list ar, int *len)
{
	int i;
	char *s2;
	char *s;
	
	*len += (i = ft_strlen3(s0, "cspdioufxmX%")) + 1;
	s = ft_strdup(s0);
	if (s[i] == 'D' || s[i] == 'C' || s[i] == 'F' || s[i] == 'S' || s[i] == 'P')
		s[i] += 32;
	s[i + 1] = 0;
	s2 = ft_strdup(s);
	i = 0;
	while (s[i] && s[i] != ' ')
	{
		if (s[i] == '*')
		{
			s2 = ft_itoa(va_arg(ar, int));
			if (ft_isdigit(s[i + 1]) || (s[i - 1] == '.' && s2[0] == '-'))
			{
				s2 = "";
				s[i - 1] == '.' ? s[i - 1] = 0 : 0;
			}
			s2 = ft_strjoin(s2, &(s[i + 1]));
			s[i] = 0;
			s2 = ft_strjoin(s, s2);
			s = s2;
		}
		i++;
	}
	return (s2);
}

int ft_printf(const char *restrict format, ...)
{
	va_list ar;
	int i ;
	int len;
	char *s;
	
	il *kok = malloc(sizeof(il));
	ft_bzero(kok, sizeof(il));
	i = 0;
	len = 0;
	va_start(ar, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			obr_struct(&kok, obr_zv(format + i + 1, ar, &i));
			s = table(ar, kok);
			len += s == NULL ? 1 : (int)ft_strlen(s);
			ft_bzero(kok, sizeof(il));
		}
		else if (!(format[i] == '%' && !format[i + 1]))
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ar);
	return (len);
}

//2661
#include <float.h>
#include <stdio.h>
#include <math.h>
/*
int main()//("%.2000f", DBL_MIN) ("%.0f", DBL_MAX)
{
	char *str = "www";
	char *filename = "eee";
	ft_printf(PGC"%s"EPC, str);
	//ft_printf("%b", 23);
}
*/