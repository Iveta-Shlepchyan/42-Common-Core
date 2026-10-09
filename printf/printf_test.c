#include <stdio.h>
#include "ft_printf.h"

void	int_to_hex(int n)
{
	char digits[] = "0123456789ABCDEF";

	
	if (n / 16 > 0)
	{
		ft_putchar_fd(digits[n % 16], 1);
		n /= 16;
	}
	ft_putchar_fd(digits[n % 16], 1);
	//reverse the result I can make it to return string or smth 
}

int	main(void)
{
	int a = 42;
	int *y = &a;
	
	int_to_hex(108);
	ft_printf("\n");
	
	ft_printf("MY FUNC Age: %i, Score: %d\n", 25, 45);
	ft_printf("MY FUNC Age: %u, Score: %d\n", -25, 10);
	ft_printf("MY FUNC Char: %c, Str: %s\n", 'a', "palmii parami na bereguuu");
	ft_printf("MY FUNC Perc: %%\n", 1);
	printf("Perc: %%\n");
	
	printf("unsigned decimal: %u\n", -25);
	printf("unsigned decimal: %u\n", 10);
	printf("Integer: %i\n", -25.5);
	printf("Integer: %i\n", 5);
	printf("Decimal: %d\n", 25.5);
	printf("Hexadecimal: %x\n", -12);
	printf("Hexadecimal: %x\n", 12);
	printf("Hexadecimal: %X\n", 12);
	printf("Hexadecimal: %X\n", -1);
	printf("Age: %d, Score: %d\n", 25);
	printf("Age: %d, Score: %d\n", 25, 45, 6);
	
	printf("Hexadecimal: %X\n", -1);
	
	printf("Pointer: %p\n", y);//basicaly same as hex
	
}


