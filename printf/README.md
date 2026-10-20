*This project has been created as part of the 42 curriculum by ishlepch.*

# Description
The goal of this project was to recode ft_printf function to learn about variadic functions (i.e. functions that recieve a variable number of arguments) and to gain deeper understanding of how one of the most used functions works.

Previously coded ¨libft" library was used.  <stdarg.h> lib was used for handeling the variable arguments:
 va_start,
 va_arg,
 va_copy,
 va_end
This function will be added to libft and will be used in future 42 curriculum projects.
All code in this repository follows the 42 Norm.

%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.

Flags:
- space padding 
0 zero padding
. precision & width
 # prefix specification
+ plus sign forcing
' ' space for positive number in place of sign 

**Requirements**
The library needs the gcc compiler, with <stdlib.h> and <unistd.h> standard libraries to run.

# Instructions
Compile the library:
make        # Compile the library -> generates libftprintf.a
make bonus  # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Rebuild everything


Using the Library:

To use the library simply include this header:
#include "libft.h"

# Resources
Linux manual pages (man)
Stack Overflow
W3Schools - https://www.w3schools.com/
Geeksforgeeks.org - https://www.geeksforgeeks.org/c/variadic-functions-in-c/
printfTester - library was tested using personal tests + https://github.com/paulo-santana/ft_printf_tester + https://github.com/Tripouille/printfTester
AI

**AI Usage**
AI was used as a learning tool during development. Specifically, it was used to clarify concepts and suggest possible improvements to efficiency, particularly during times at school when there were no peers available to ask for help.
