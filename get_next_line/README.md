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




get_next_line
Description

get_next_line is a C function that reads a file descriptor and returns its content one line at a time, each time it is called.

c
char *get_next_line(int fd);
It returns the next line, including the terminating \n if there is one.
It returns NULL when there is nothing left to read, or when an error occurs.
It works with files, standard input and any other readable file descriptor.
The size of the internal read buffer is set at compile time with -D BUFFER_SIZE=n.

The goal of the project is to learn about static variables, file descriptors, dynamic memory management and how to read data in chunks without losing what was read beyond the end of the current line.

Project structure
File	Content
get_next_line.c	get_next_line and its static helpers (get_buffer, extract_line, clean_stash, fail)
get_next_line_utils.c	stash_join, grow_stash, copy_till, check_line_end, ft_strlen
get_next_line.h	Prototypes and the BUFFER_SIZE default
get_next_line_bonus.c	Bonus: same function, handles several file descriptors at once
get_next_line_utils_bonus.c	Bonus helpers
get_next_line_bonus.h	Bonus header (defines t_stash and OPEN_MAX)
Instructions
Compilation

Compile the mandatory part together with your own main.c:

bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

Compile the bonus part:

bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus

If BUFFER_SIZE is not passed on the command line, the header defaults it to 42.

Execution
bash
./gnl
Minimal usage example
c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

The caller is responsible for freeing every returned line.

Testing

Try several values of BUFFER_SIZE (1, 42, 9999, 10000000) and several kinds of input: an empty file, a file with no trailing newline, a file with only \n, a very large single line, standard input, and invalid file descriptors. Running under valgrind or with -fsanitize=address is recommended to check for leaks.

For the bonus, alternate reads between several file descriptors (one line from A, one from B, back to A).

Algorithm
Overview

The difficulty of the project is that read() returns a fixed number of bytes (BUFFER_SIZE) that has no relation to line boundaries. A single read may contain half a line, exactly one line, or several lines. Whatever was read after the first \n must not be lost, so it has to be kept between calls.

Step by step
Persistent storage (the stash). A static char *stash keeps the data that was read but not yet returned. Because it is static, it survives between calls.
Check the stash first. If the stash already contains a \n (leftover from a previous read), no read is needed: the line is extracted directly.
Read loop. Otherwise, the function reads BUFFER_SIZE bytes into a temporary buffer, terminates it with '\0', appends it to the stash, and stops as soon as the new buffer contains a \n, or when read returns 0.
Extract the line. copy_till allocates and returns a copy of the stash up to and including the first \n. At end of file, with no trailing newline, it returns the remaining content without a \n.
Clean the stash. clean_stash shifts the bytes after the returned line to the start of the stash, so that the next call begins with the leftover data.
End of file / errors. When read returns 0 and the stash is empty, or when read or malloc fails, the stash is freed and set to NULL, and the function returns NULL. Nothing is leaked and the function is ready to be reused on another file.
Justification of the choices

A growing stash with a tracked length and capacity. The stash is a single buffer whose capacity doubles when it is full. Together with a stored length (len), this has two consequences:

Appending new data is amortized O(1) per byte: reallocations are rare, and each one copies the data only once.
The length never has to be recomputed with ft_strlen on the whole stash. A naive version that re-measures or re-joins the whole stash after every read is quadratic on a very long line (for example a multi-megabyte line read with BUFFER_SIZE=1) and times out. Keeping len avoids that.

Searching for \n only in the new buffer. Inside the read loop, check_line_end scans only the freshly read buffer (at most BUFFER_SIZE bytes), not the whole stash. The stash is scanned fully only once at the start of a call, to handle leftovers. This keeps the total work of a huge line linear.

Why not read the whole file at once? Reading the entire file would use memory proportional to the file size, would not work for standard input or pipes that are never closed, and would go against the purpose of the function. Here, only data up to the end of the current line (plus at most one extra buffer) is held in memory.

Memory and complexity. For a line of n bytes, the function performs about n / BUFFER_SIZE reads and O(n) copying work, with memory use of at most about twice the line length (because of capacity doubling) plus one buffer. One known trade-off: clean_stash moves the remaining data to the front of the stash after each returned line, which costs time proportional to the leftover size. This is small for normal BUFFER_SIZE values.

Bonus: multiple file descriptors

The bonus version must use only one static variable. All the per-file-descriptor state is grouped in a small struct:

c
typedef struct s_stash
{
	char	*str;
	size_t	cap;
	size_t	len;
}	t_stash;

and a single static array static t_stash st[OPEN_MAX]; is indexed by the file descriptor. Each fd therefore has its own stash, capacity and length, so reads on different file descriptors can be interleaved without mixing their data. The array is zero-initialized, so every fd starts with str = NULL and cap = len = 0, and its stash is allocated on first use. File descriptors outside 0 <= fd < OPEN_MAX are rejected.

Resources
References
man 2 read, man 3 malloc, man 3 free, man 2 open, man 2 close
The C Programming Language, Brian W. Kernighan and Dennis M. Ritchie
The Norm (42 coding standard)
Valgrind documentation
AddressSanitizer documentation
Static variables in C (GeeksforGeeks)
Amortized analysis of dynamic arrays (Wikipedia)
Use of AI

The design and the first working implementation of the project (the static stash, the read loop, the growing buffer) were written by me. AI (Claude, by Anthropic) was used for the following tasks:

Norm refactoring: splitting functions to respect the 25 lines and 5 variables per function limits and the 5 functions per file limit, while keeping the original structure and logic.