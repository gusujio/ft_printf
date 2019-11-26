#include "ft_printf.h"

int main()
{
	printf(" =%d\n" , printf("%f", 1.5));
	printf(" =%d\n" , ft_printf("%f", 1.5));
	return (0);
}
