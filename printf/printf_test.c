/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishlepch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:56:14 by ishlepch          #+#    #+#             */
/*   Updated: 2026/10/23 15:56:22 by ishlepch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


void	int_to_hex(int n)
{
	char digits[] = "0123456789ABCDEF";

	
	if (n / 16 > 0)
		int_to_hex(n / 16);
	ft_putchar_fd(digits[n % 16], 1);
	//reverse the result I can make it to return string or smth 
}

void	test_char(char *format, int c)
{
	printf("REAL:    |");
	printf(format, c);
	printf("|\n");

	ft_printf("MY FUNC: |");
	ft_printf(format, c);
	ft_printf("|\n");

	printf("--------------------------------\n");
}

void	test_string(const char *format, char *str)
{
	printf("REAL:    |");
	printf(format, str);
	printf("|\n");

	ft_printf("MY FUNC: |");
	ft_printf(format, str);
	ft_printf("|\n");

	printf("------------------------------\n");
}

void	test_int(char *format, int n)
{
	printf("REAL:    |");
	printf(format, n);
	printf("|\n");

	ft_printf("MY FUNC: |");
	ft_printf(format, n);
	ft_printf("|\n");

	printf("--------------------------------\n");
}

void	test_unsigned(char *format, unsigned int n)
{
	printf("REAL:    |");
	printf(format, n);
	printf("|\n");

	ft_printf("MY FUNC: |");
	ft_printf(format, n);
	ft_printf("|\n");

	printf("--------------------------------\n");
}

void	test_hex(char *format, unsigned int n)
{
	printf("REAL:    |");
	printf(format, n);
	printf("|\n");

	ft_printf("MY FUNC: |");
	ft_printf(format, n);
	printf("|\n");
	printf("--------------------------------\n");
}

void	test_pointer(char *format, void *ptr)
{
	printf("REAL:    |");
	printf(format, ptr);
	printf("|\n");

	ft_printf("MY FUNC: |");
	ft_printf(format, ptr);
	ft_printf("|\n");

	printf("--------------------------------\n");
}

int	main(void)
{
	const char	*format;
	int			real;
	int			mine;

	/* TEST 1: %#X with 0 */
	printf("TEST 1: %#X with 0\n");

	real = printf("|%#X|\n", 0u);
	mine = ft_printf("|%#X|\n", 0u);

	printf("Return values: printf = %d, ft_printf = %d\n", real, mine);
	printf("--------------------------------------\n");

	/* TEST 55: %#X with LONG_MIN */
	real = printf("|%#X|\n", LONG_MIN);
	mine = ft_printf("|%#X|\n", LONG_MIN);

	printf("Return values: printf = %d, ft_printf = %d\n", real, mine);
	printf("--------------------------------------\n");


	/* TEST 1 */
	test_char("%c", '0');

	/* TEST 2 */
	test_char(" %c ", '0');

	/* TEST 3: Character value below the unsigned-char range */
	test_char(" %c", '0' - 256);

	/* TEST 4: Character value above the unsigned-char range */
	test_char("%c ", '0' + 256);

	/* TEST 5: Includes a null character in the middle */
	printf("TEST 5\n");
	printf("REAL:    |");
	printf(" %c %c %c ", '0', 0, '1');
	printf("|\n");
	ft_printf("MY FUNC: |");
	ft_printf(" %c %c %c ", '0', 0, '1');
	ft_printf("|\n");
	printf("--------------------------------\n");

	/* TEST 6 */
	test_char(" %c %c %c ", ' '); /* Don't use this for multiple %c */

	/* Correct TEST 6 */
	printf("TEST 6\n");
	printf("REAL:    |");
	printf(" %c %c %c ", ' ', ' ', ' ');
	printf("|\n");
	ft_printf("MY FUNC: |");
	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	ft_printf("|\n");
	printf("--------------------------------\n");

	/* TEST 7 */
	printf("TEST 7\n");
	printf("REAL:    |");
	printf(" %c %c %c ", '1', '2', '3');
	printf("|\n");
	ft_printf("MY FUNC: |");
	ft_printf(" %c %c %c ", '1', '2', '3');
	ft_printf("|\n");
	printf("--------------------------------\n");

	/* TEST 8: Null character at the end */
	printf("TEST 8\n");
	printf("REAL:    |");
	printf(" %c %c %c ", '2', '1', 0);
	printf("|\n");
	ft_printf("MY FUNC: |");
	ft_printf(" %c %c %c ", '2', '1', 0);
	ft_printf("|\n");
	printf("--------------------------------\n");

	/* TEST 9: Null character at the beginning */
	printf("TEST 9\n");
	printf("REAL:    |");
	printf(" %c %c %c ", 0, '1', '2');
	printf("|\n");
	ft_printf("MY FUNC: |");
	ft_printf(" %c %c %c ", 0, '1', '2');
	ft_printf("|\n");
	printf("--------------------------------\n");


	
	ft_printf("MY FUNC Char: %cI\n", 'A');
	ft_printf("MY FUNC Char: %+-0cI\n", 'B');
	ft_printf("MY FUNC Char: %-6cI\n", 'C');
	ft_printf("MY FUNC Char: %4cI\n", 'D');
	ft_printf("MY FUNC Char: %# 4cI\n", 'E');

	test_string("%s", "Hello");
	test_string("%10s", "Hello");
	test_string("%-10s", "Hello");
	test_string("%.3s", "Hello");
	test_string("%.0s", "Hello");
	test_string("%10.3s", "Hello");
	test_string("%-10.3s", "Hello");
	test_string("%3.8s", "Hello");
	test_string("%2.5s", "Hello");
	test_string("%5.2s", "Hello");
	test_string("%s", "");
	test_string("%5s", "");
	test_string("%.3s", "");
	test_string("%8.0s", "Hello");
	test_string("%12s", "Hi");



	// Basic integers
	test_int("%d", 42);
	test_int("%i", -42);
	test_int("%d", 0);
	test_int("%d", 2147483647);
	test_int("%d", -2147483648);

	// Width and alignment
	test_int("%10d", 42);
	test_int("%-10d", 42);
	test_int("%10d", -42);
	test_int("%-10d", -42);

	// Zero padding
	test_int("%010d", 42);
	test_int("%010d", -42);
	test_int("%-010d", 42);

	// Precision
	test_int("%.5d", 42);
	test_int("%.3d", 12345);
	test_int("%.0d", 0);
	test_int("%.0d", 42);

	// Width + precision
	test_int("%8.5d", 42);
	test_int("%-8.5d", 42);
	test_int("%8.5d", -42);
	test_int("%3.5d", 42);

	// Sign flags
	test_int("%+d", 42);
	test_int("%+d", -42);
	test_int("% d", 42);
	test_int("% d", -42);

	// Flags + width
	test_int("%+8d", 42);
	test_int("% 8d", 42);
	test_int("%+08d", 42);
	test_int("%+08d", -42);
	test_int("%-+8d", 42);

	// Flags + precision
	test_int("%+.5d", 42);
	test_int("% .5d", 42);
	test_int("%+8.5d", 42);
	test_int("% 8.5d", 42);

	// Edge cases
	test_int("%5d", 0);
	test_int("%05d", 0);
	test_int("%5.0d", 0);
	test_int("%-5.0d", 0);
	test_int("%08.5d", 42);
	test_int("%-08.5d", -42);



	// Basic unsigned integers
	test_unsigned("%u", 0);
	test_unsigned("%u", 42);
	test_unsigned("%u", 4294967295u);
	test_unsigned("%u", 2147483648u);

	// Width and alignment
	test_unsigned("%10u", 42);
	test_unsigned("%-10u", 42);
	test_unsigned("%10u", 123456);
	test_unsigned("%-10u", 123456);

	// Zero padding
	test_unsigned("%010u", 42);
	test_unsigned("%010u", 0);
	test_unsigned("%-010u", 42);

	// Precision
	test_unsigned("%.5u", 42);
	test_unsigned("%.3u", 12345);
	test_unsigned("%.0u", 0);
	test_unsigned("%.0u", 42);
	test_unsigned("%.1u", 0);

	// Width + precision
	test_unsigned("%8.5u", 42);
	test_unsigned("%-8.5u", 42);
	test_unsigned("%8.5u", 123456);
	test_unsigned("%3.5u", 42);

	// Zero flag + precision
	test_unsigned("%08.5u", 42);
	test_unsigned("%-08.5u", 42);
	test_unsigned("%05.0u", 0);

	// Flags that should be ignored for %u
	test_unsigned("%+u", 42);
	test_unsigned("% u", 42);
	test_unsigned("%+8u", 42);
	test_unsigned("% 8u", 42);
	test_unsigned("%+08u", 42);

	// Edge cases
	test_unsigned("%5u", 0);
	test_unsigned("%5.0u", 0);
	test_unsigned("%-5.0u", 0);
	test_unsigned("%12u", 4294967295u);
	test_unsigned("%.10u", 42);


	// Basic hexadecimal
	test_hex("%x", 0);
	test_hex("%x", 42);
	test_hex("%x", 255);
	test_hex("%X", 255);
	test_hex("%x", 4294967295u);
	test_hex("%X", 4294967295u);

	// Width and alignment
	test_hex("%10x", 42);
	test_hex("%-10x", 42);
	test_hex("%10X", 255);
	test_hex("%-10X", 255);

	// Zero padding
	test_hex("%010x", 42);
	test_hex("%010X", 255);
	test_hex("%-010x", 42);

	// Precision
	test_hex("%.5x", 42);
	test_hex("%.3x", 255);
	test_hex("%.0x", 0);
	test_hex("%.0X", 0);
	test_hex("%.5X", 0);

	// Width + precision
	test_hex("%8.5x", 42);
	test_hex("%-8.5x", 42);
	test_hex("%8.5X", 255);
	test_hex("%3.5x", 42);

	// Alternate form (#)
	test_hex("%#x", 42);
	test_hex("%#X", 255);
	test_hex("%#x", 0);
	test_hex("%#X", 0);
	test_hex("%#10x", 42);
	test_hex("%#-10x", 42);
	test_hex("%#010x", 42);

	// Alternate form + precision
	test_hex("%#.5x", 42);
	test_hex("%#8.5x", 42);
	test_hex("%#-8.5X", 255);
	test_hex("%#.0x", 0);

	// Edge cases
	test_hex("%5x", 0);
	test_hex("%5.0x", 0);
	test_hex("%-5.0x", 0);
	test_hex("%12x", 4294967295u);
	test_hex("%.10x", 42);


	int a = 42;
	int b = -42;
	int zero = 0;
	char c = 'A';
	char str[] = "Hello";

	/* Basic pointers */
	test_pointer("%p", &a);
	test_pointer("%p", &b);
	test_pointer("%p", &c);
	test_pointer("%p", str);

	/* NULL pointer */
	test_pointer("%p", NULL);

	/* Width */
	test_pointer("%20p", &a);
	test_pointer("%5p", &a);

	/* Left alignment */
	test_pointer("%-20p", &a);
	test_pointer("%-5p", &a);

	/* Zero flag: ignored for pointers */
	test_pointer("%020p", &a);

	/* NULL with width */
	test_pointer("%20p", NULL);
	test_pointer("%-20p", NULL);


	
	// ft_printf("MY FUNC Age: %i, Score: %d\n", 25, 45);
	// ft_printf("MY FUNC Age: %u, Score: %d\n", -25, 10);
	// ft_printf("MY FUNC Char: %c, Str: %s\n", 'a', "palmii parami na bereguuu");
	// ft_printf("MY FUNC Perc: %%\n", 1);
	// printf("Perc: %%\n");
	
	//ft_printf("MY FUNC Age: %u, Score: %d\n", -25, 10);
	//printf("unsigned decimal: %u\n", -25);
	//printf("unsigned decimal: %u\n", 10);
	// printf("Integer: %i\n", -25.5);
	// printf("Integer: %i\n", 5);
	// printf("Decimal: %d\n", 25.5);
	// printf("Hexadecimal: %x\n", -12);
	// printf("Hexadecimal: %x\n", 12);
	// printf("Hexadecimal: %X\n", 12);
	// printf("Hexadecimal: %X\n", -1);
	// printf("Age: %d, Score: %d\n", 25);
	// printf("Age: %d, Score: %d\n", 25, 45, 6);
	
	// printf("Hexadecimal: %X\n", -1);
	
	// printf("Pointer: %p\n", y);//basicaly same as hex
	char *null_str;
	printf("TEST 1: %#X with 0\n");

	real = printf("%.5s\n", null_str);
	mine = ft_printf("%.5s\n", null_str);

	printf("Return values: printf = %d, ft_printf = %d\n", real, mine);
	printf("--------------------------------------\n");

	printf("TEST 2: %#X with 0\n");

	
	real = printf("%.7s\n", null_str);
	mine = ft_printf("%.7s\n", null_str);

	printf("Return values: printf = %d, ft_printf = %d\n", real, mine);
	printf("--------------------------------------\n");

	printf("TEST 2: %#X with 0\n");

	
	real = printf("%.6s\n", null_str);
	mine = ft_printf("%.6s\n", null_str);

	printf("Return values: printf = %d, ft_printf = %d\n", real, mine);
	printf("--------------------------------------\n");


	printf("TEST 1: %#X with 0\n");

	real = printf("%8p is the address\n", (void *)0);
	mine = ft_printf("%8p is the address\n", (void *)0);

	printf("Return values: printf = %d, ft_printf = %d\n", real, mine);
	printf("--------------------------------------\n");

	
}
