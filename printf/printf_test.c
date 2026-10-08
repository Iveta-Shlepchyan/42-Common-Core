#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	ft_printf("MY FUNC Age: %d, Score: %d\n", 25, 45);
	
	printf("Age: %d, Score: %d\n", 25);
	printf("Age: %d, Score: %d\n", 25, 45, 6);
}
