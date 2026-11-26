*This project has been created as part of the 42 curriculum by ishlepch.*

# ft_printf

## Description

The goal of this project was to recode the printf() function to learn about variadic functions (functions that receive a variable number of arguments) and gain a better understanding of how one of the most commonly used C functions works.

I used functions from my previously implemented libft library. To handle variadic arguments, I used the <stdarg.h> header, which provides va_list and the macros va_start, va_arg, and va_end.

Ft_printf will be added to my libft library so I can use it in future projects within the 42 curriculum.

All code in this repository follows the 42 Norm.

### Supported Conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a signed decimal number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal number. |
| `%x` | Prints a number in lowercase hexadecimal format. |
| `%X` | Prints a number in uppercase hexadecimal format. |
| `%%` | Prints a percent sign. |

### Flags and Formatting

The implementation also supports the following formatting options:

| Flag / Option | Description |
|---|---|
| `-` | Left-aligns the output within the field width. |
| `0` | Pads numeric output with zeros. |
| `.` | Sets the precision. |
| Width | Sets the minimum field width. |
| `#` | Adds the `0x` or `0X` prefix for nonzero hexadecimal values. |
| `+` | Forces a sign (`+` or `-`) for signed decimal numbers. |
| Space (` `) | Prints a leading space for nonnegative signed decimal numbers when no sign is shown. |

## Requirements

- A C compiler, such as `cc`, GCC, or Clang.
The project uses standard headers such as `<stdarg.h>` and relies on functions from `libft`.

## Instructions

### Compile the library

Run the following commands from the root of the repository:

```bash
make        # Compile the library and generate libftprintf.a
make bonus  # Build using the bonus target
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Rebuild everything from scratch
```

### Usage

Include the header in your C file:

```c
#include "ft_printf.h"
```

For example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("%s, said Deep Thought, with infinite majesty and calm.", "Forty-two");
    return (0);
}
```

Compile the file with the ft_printf library and run the program:

```bash
cc filename.c libftprintf.a && ./a.out
```

## Resources

- Linux manual pages (`man`).
- [Stack Overflow](https://stackoverflow.com/).
- [W3Schools — C](https://www.w3schools.com/c/).
- [GeeksforGeeks — Variadic Functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/).
- [paulo-santana/ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester).
- [Tripouille/printfTester](https://github.com/Tripouille/printfTester).

The library was tested using personal tests and the testers listed above.

## AI Usage

AI was used as a learning tool during development. Specifically, it was used to clarify concepts and suggest possible improvements to code readability and efficiency, particularly during times at school when there were no peers available to ask for help.