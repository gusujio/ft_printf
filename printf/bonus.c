#include "ft_printf.h"

void print_m_c_z(char **c, int i, int j)
{
	int x;
	int y;
	
	x = 0;
	while (x < i && c[x])
	{
		y = 0;
		while (y < j && (*c)[y])
		{
			ft_putchar(c[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}
void print_m_c(char **c)
{
	int x;
	int y;
	
	x = 0;
	while (c[x])
	{
		y = 0;
		while ((*c)[y])
		{
			ft_putchar(c[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}
void print_m_i(int **c, int i, int j)
{
	int x;
	int y;
	
	x = 0;
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			ft_printf("%d ", c[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}
void table_m(il *kok, va_list ar)
{
	if (kok->mines && kok->point == -1)
		print_m_c(va_arg(ar, char**));
	else if (kok->mines && kok->point != -1)
		print_m_c_z(va_arg(ar, char**), kok->width, kok->point);
	else
		print_m_i(va_arg(ar, int**), kok->width, kok->point);
}

void ft_bit(unsigned char c)
{
	int k;
	int i;
	
	i = 0;
	k = 128;
	while (i < 8)
	{
		printf("%d", !!(c & k));
		k = k >> 1;
		i++;
	}
}