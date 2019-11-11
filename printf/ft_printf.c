#include "ft_printf.h"

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

void obr_mines(const char *s, char **v)
{
	int l;
	char *buf;
	char c;
	if (!s)
		return;
	l = ft_atoi(s) - ft_strlen(*v);
	if (l > 0)
	{
		buf = (char *) malloc(l);
		c = s[0] == '0' ? '0' : ' ';
		ft_memset(buf, c, l);
		*v = ft_strjoin(*v, buf);
	}
}

void obr_resh(const char *s, char **v)
{
	if (!s)
		return;
	if (ft_strstr(s, "p"))
		*v = ft_strjoin("0x", *v);
	if (!ft_atoi(*v))
		return;
	if (ft_strstr(s, "x"))
		*v = ft_strjoin("0x", *v);
	else if (ft_strstr(s, "X"))
		*v = ft_strjoin("0X", *v);
	else if (ft_strstr(s, "o"))
		*v = ft_strjoin("0", *v);
}

void obr_space(const char *s, char **v)
{
	if (!s || (!ft_strstr(s, "d") && !ft_strstr(s, "i")))
		return;
	if ((*v)[0] != '-' && (*v)[0] != '+')
		*v = ft_strjoin(" ", *v);
}

void * flag_sign(char *f, va_list ar)
{
	void *error;

	error = (void *)-2;
	if (ft_strstr(f, "hh"))
		return ((void*)va_arg(ar, signed char));
	else if (f[0] == 'h')
		return ((void*)va_arg(ar,short int));
	else if (ft_strstr(f, "ll"))
		return ((void*)va_arg(ar,long long int));
	else if (ft_strstr(f, "l"))
		return ((void*)va_arg(ar,long int));
	return (error);
}

void *flag_unsign(char *f, va_list ar)
{
	void *error;

	error = (void *)-2;
	if (ft_strstr(f, "hh"))
		return ((void*)va_arg(ar, unsigned char));
	else if (f[0] == 'h')
		return ((void*)va_arg(ar,unsigned short int));
	else if (ft_strstr(f, "ll"))
		return ((void*)va_arg(ar,unsigned long long int));
	else if (ft_strstr(f, "l"))
		return ((void *) va_arg(ar, unsigned long int));
	return (error);
}

char space_or_zero(char *s, int i)
{
	char *l;
	char *e;
	int k;
	
	l = ft_memchr(s, '0', i);
	k = 0;
	if ((e = ft_strchr(s, '.')) && !ft_strchr(s, '-'))
	{
		if ((k = ft_atoi(e + 1)) >= 0 && ft_atoi(s) < k)
			return ('0');
	}
	if (l && !ft_strchr(s, '-') && (ft_atoi(s) < k || k == 0))
		return ('0');
	else
		return (' ');
}

char* table(char c, va_list ar, char *s)
{
	if (c == 'c')
		return (obr_char(s, ar));
	else if (c == 's' || c == '%')
		return (table_s_c(s, ar));
	else if (c == 'd' || c == 'i')
		return (table_i_d(s, ar));
	else if (c == 'x' || c == 'X')
		return (table_x_X(s, ar, c));
	else if (c == 'o')
		return (table_o(s, ar, c));
	else if (c == 'u')
		return (table_u(s, ar));
	else if (c == 'p')
		return (table_p(s, ar));
	else if (c == 'f')
		return (table_f(s, ar));
}

char* obrabotka_zv(char *s, va_list ar)
{
	int i;
	char *s2;
	i = 0;
	
	s2 = s;
	while (s[i])
	{
		if (s[i] == '*')
		{
			s2 = ft_itoa(va_arg(ar,
			int));
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
	int i;
	int len;
	int j;
	char *s;
	char *s2;
	
	i = 0;
	len = 0;
	va_start(ar, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			s2 = ft_strsub(format, i, (j = ft_strlen3(format + i, "cspdiouxXf%")) + 1);
			s = table(format[i + j], ar, obrabotka_zv(s2, ar));
			i += j;
			len += s == NULL ? 1 : 0;
			len += (ft_mod(ft_atoi(s2)) < ft_strlen(s) ? ft_strlen(s) : ft_mod(ft_atoi(s2)));
		}
		else if (!(format[i] == '%' && !format[i + 1]))
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ar);
	return (len);//бонус - печать битов
}

int main()//
{
	printf(" = %d\n", printf("%.03s", NULL));
	printf(" = %d\n", ft_printf("%.03s", NULL));
}
