libft
<p align="center">
  <img src="https://github.com/mazen-tech/42-banner/blob/main/libft1710117289.jpeg">
</p>
<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square"/>
	<a href='https://www.linkedin.com/in/mazen-tarek-2b2275296/' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
        <a href='https://profile.intra.42.fr/' target="_blank"><img alt='42' src='https://img.shields.io/badge/Warsaw-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000'/></a>

## ABOUT
The first project at 42, libft, involves learning how the standard functions of C programming work by writing them from scratch and creating a personal library. This project is vital as the library will be used in future assignments at 42.

If you're a 42 student, it's highly recommended that you go through the process of writing your code and testing it yourself rather than copying and pasting code that you only partially understand. If you've completed your piscine, there's no reason why you couldn't tackle this project on your own! Be patient and thorough.
- [Subject](https://cdn.intra.42.fr/pdf/pdf/124419/en.subject.pdf) `PDF`

## HOW TO USE
#### 1º - Clone the repository
```bash
git clone https://github.com/mazen-tech/libft-llibrary.c.git
## HOW TO USE
#### 1º - Clone the repository
```bash
git clone https://github.com/mazen-tech/libft-llibrary.c.git
```
#### 2º - Enter the project folder and run `make`
```bash
cd libft/libft
make
```
#### 3º - To use in your code, include the header
```c
#include "libft.h"
```
#### MAKEFILE RULES
`make` - Compile libft **mandatory** files.
`make bonus` - Compile libft **bonus** files.
`make all` - Compile **mandatory** + **bonus** files.
`make clean` - Delete all .o (object files) files.
`make fclean` - Delete all .o (object file) and .a (executable) files.
`make re` - Use rules `fclean` + `all`.
## MANDATORY
> The mandatory functions in libft include both functions from the standard C library and other functions that are useful for character, string, and memory manipulation. These **34 mandatory functions** are essential to achieving a **grade of 100**.
#### Check and manipulate characters:
| Function | Description |
| :- | :- |
| `ft_isalpha` | Alphabetic character test. |
| `ft_isdigit` | Decimal-digit character test. |
| `ft_isalnum` | Alphanumeric character test. |
| `ft_isascii` | Test for ASCII character. |
| `ft_toupper` | Lower case to upper case letter conversion. |
| `ft_tolower` | Upper case to lower case letter conversion. |
#### Manipulate strings:
| Function | Description |
| :- | :- |
| `ft_strlen`   | Find length of string. |
| `ft_strlen`   | Find the length of the string. |
| `ft_strlcpy`  | Size-bounded string copying. |
| `ft_strlcat`  | Size-bounded string concatenation. |
| `ft_strchr`   | Locate character in string (first occurrence). |
| `ft_strrchr`  | Locate character in string (last occurence). |
| `ft_strchr`   | Locate the character in the string (first occurrence). |
| `ft_strrchr`  | Locate the character in the string (last occurrence). |
| `ft_strncmp`  | Compare strings (size-bounded). |
| `ft_strnstr`  | Locate a substring in a string (size-bounded) |
| `ft_substr`   | Extract substring from string. |
| `ft_substr`   | Extract substring from a string. |
| `ft_strjoin`  | Concatenate two strings into a new string (with malloc). |
| `ft_strtrim`  | Trim beginning and end of string with the specified characters. |
| `ft_strtrim`  | Trim the beginning and end of the string with the specified characters. |
| `ft_split`    | Split string, with specified character as delimiter, into an array of strings. |
| `ft_strmapi`  | Create new string from modifying string with specified function. |
| `ft_strmapi`  | Create a new string by modifying the string with a specified function. |
| `ft_striteri` | Iterates through a string, enabling character and index manipulation. |

#### Manipulate memory:
@@ -105,31 +105,31 @@ make
#### Manipulate numbers:
| Function | Description |
| :- | :- |
| `ft_atoi` | Convert ASCII string to integer. |
| `ft_atoi` | Convert the ASCII string to an integer. |
| `ft_itoa` | Convert integer to ASCII string. |

#### Write to a file descriptor:
| Function | Description |
| :- | :- |
| `ft_putchar_fd` | Output a character to given file. |
| `ft_putstr_fd`  | Output string to given file. |
| `ft_putchar_fd` | Output a character to the given file. |
| `ft_putstr_fd`  | Output string to the given file. |
| `ft_putendl_fd` | Output string to given file with newline. |
| `ft_putnbr_fd`  | Output integer to given file. |
| `ft_putnbr_fd`  | Output integer to the given file. |

## BONUS
The bonus part in not included in my repo 

## NORMINETTE
> At 42 School, it is expected that almost every project is written following the Norm, which is the coding standard of the school.

