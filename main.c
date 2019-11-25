#include "ft_printf.h"

int main()
{
	printf(" =%d\n" , printf("%.0f", DBL_MAX));
	printf(" =%d\n" , ft_printf("%.0f", DBL_MAX));
	return (0);
}
