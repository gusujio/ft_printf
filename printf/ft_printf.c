#include "ft_printf.h"

static char *perevod(long long int x, char c) // из деситичную в указанную
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
	s = (char*)malloc(size + 1);
	s[size] = 0;
	while (size-- > 0)
	{
		ost = (x - (osn * (x / osn))) + 48;
		if (ost > 57)
			ost = (c - 24) + (ost - 57);
		s[size] = ost ;
		x /= osn;
	}
	return (s);
}

static  size_t	ft_strlen3(const char *s, const char *c)
{
	size_t	i;
	size_t	j;

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


int    obr_width(const char *s, char **v, int i, char c)
{
	char *buf;
	int l;

	if (ft_atoi(s + i) == 0)
		return (0);
	l = ft_atoi(s + i) - ft_strlen(*v);
	l = l > 0 ? l : 0;
	buf = (char *) malloc(l + 1);
	buf[l] = 0;
	ft_memset(buf, c, l);
	if (ft_strchr(s, '-'))
	{
		*v = ft_strjoin(*v, buf);
		return (1);
	}
	if (((*v)[0] == '-' || (*v)[0] == '+') && c == '0')
	{
		buf[0] = (*v)[0];
		(*v)[0] = '0';
	}
	if ((*v)[1] == 'x' && buf[0] != ' ')
	{
		buf[1] = 'x';
		(*v)[1] = '0';
	}
	*v = ft_strjoin(buf, *v);
	return (1);
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
	if (!s || ft_atoi(*v) == 0)
		return;
	if (ft_strstr(s, "x"))
		*v = ft_strjoin("0x", *v);
	else if (ft_strstr(s, "X"))
		*v = ft_strjoin("0X", *v);
	else if (ft_strstr(s, "o"))
		*v = ft_strjoin("0", *v);
}
void obr_point(const char *s, char **v)
{
	int i;

	if (!s)
		return;
	i = ft_atoi(s + 1);
	if (ft_strlen(*v) >= i && ft_strstr(s, "s"))
		(*v)[i] = 0;
	else if (!ft_strstr(s, "c") && !ft_strstr(s, "s"))
	{
		if (!(ft_strstr(s, "#") && ft_strstr(s, "o")))
		{
			if (i == 0 && (*v)[0] == '0')
				*v = "";
			else if (i == 0 && (*v)[ft_strlen(*v) - 1] == '0')
				(*v)[ft_strlen(*v) - 1] = ' ';
			else
				obr_width(s, v, 1, '0');
		}
	}
}
void obr_space(const char *s, char **v)
{
	if (!s || !ft_strstr(s, "d"))
		return;
	if ((*v)[0] != '-' && (*v)[0] != '+')
		*v = ft_strjoin(" ", *v);
}
static char * mop(const char *s, char *v)
{
	int i;

	obr_mines(ft_strstr(s, "-"), &v);
	if (ft_strstr(s, "+"))
		if (v[0] != '-')
			v = ft_strjoin("+", v);
	obr_space(ft_strstr(s, " "), &v);
	obr_resh(ft_strstr(s, "#"), &v);
	i = 0;
	if (!(ft_strstr(s, "#") && ft_strstr(s, "o")))
		obr_point(ft_strstr(s, "."), &v);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9' && s[i-1] != '.')
		{
			if (obr_width(s, &v, i, ft_strnstr(s,"0", i + 1) && !ft_strchr(s, '-') ? '0' : ' '))
				break;
		}
		i++;
	}
	return (v);
}
static  void * flag_sign(char *f, va_list ar)
{
	if (ft_strstr(f, "hh"))
		return ((void*)va_arg(ar, signed char));
	else if (f[0] == 'h')
		return (va_arg(ar,short int));
	else if (ft_strstr(f, "ll"))
		return (va_arg(ar,long long int));
	else if (f[0] == 'l')
		return (va_arg(ar,long int));
	else
		return (NULL);
}
static  void * flag_unsign(char *f, va_list ar)
{
	if (ft_strstr(f, "hh"))
		return ((void*)va_arg(ar, unsigned char));
	else if (f[0] == 'h')
		return (va_arg(ar,unsigned short int));
	else if (ft_strstr(f, "ll"))
		return (va_arg(ar,unsigned long long int));
	else if (f[0] == 'l')
		return (va_arg(ar,unsigned long int));
	else
		return (NULL);
}
static char* table(char c, va_list ar, char *s)
{
	void *v;
	double vd;
	char *s2;

	if (c == 'c')
	{
		s2 = ft_memset(ft_strnew(2), va_arg(ar, int), 1); // ??
		return (s2[0] ? s2 : "^@");
	}
	else if(c == 's')
		return (ft_strdup(va_arg(ar, char*)));
	else if (c == '%')
		return ("%");
	else if ( c == 'd' || c == 'i')
	{
		if (s[0] && !(v = flag_sign(s, ar)))
			v = (void *)va_arg(ar, int);
		return (ft_itoa(v));
	}
	else if (c == 'x' || c == 'X' || c == 'o' || c == 'u')
	{
		if (s[0] && !(v = flag_unsign(s, ar)))
			v = (void *) va_arg(ar, int);
		if (c == 'u')
			return (ft_itoa(v));
		return (perevod(v, c));
	}
	else if (c == 'p')
	{
		if (s[0] && !(v = flag_sign(s, ar)))
			vd = va_arg(ar, double);
		return (ft_strjoin("0x", perevod(vd, 'x')));
	}
	else if (c == 'f')
	{
		if (s[0] && !(v = flag_sign(s, ar)))
			vd = va_arg(ar, double);
		return (ft_itoa(vd));
	}
}
char* obrabotka_zv(char* s, va_list ar)
{
	int i;
	int i2;
	int d;
	char *s2;
	char *s3;

	i = 0;
	s2 = s;
	while (s[i])
	{
		if (s[i] == '*')
		{
			s3 = ft_itoa(va_arg(ar, int));
			d = ft_strlen(s3) + ft_strlen(s);
			s2 = (char*)malloc(d);
			s2[d] = 0;
			i2 = 0;
			d = 0;
			while (s[i2])
			{
				s2[d] = s[i2];
				if (s[i2] == '*')
				{
					s2[d] = *s3;
					d++;
					s3++;
				}
				i2++;
				d++;
			}
		}
		i++;
	}
	return (s2);
}
int ft_printf(const char *restrict format, ...) // обработка флагов, обработка флага и значения
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
		if (format[i] == '%')
		{
			i++;
			s2 = ft_strsub(format, i,  (j = ft_strlen3(format + i, "cspdiouxXf%")) + 1);
			s = table(format[i + j], ar, s2);
			s2 = obrabotka_zv(s2, ar);
			s = mop(s2, s);
 			ft_putstr(s);
			i += j;
			len -= !!ft_strstr(s, "^@");
			len += (ft_mod(ft_atoi(s2)) < ft_strlen(s) ? ft_strlen(s) : ft_mod(ft_atoi(s2)));
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ar);
	return (len);//37
} //27

int main()
{
	printf(" = %d\n", printf("%hx", 4294967296));
	printf(" = %d\n", ft_printf("%hx", 4294967296));
}
