# 42_ft_printf

![Score](https://img.shields.io/badge/Score-100%2F100-success)
![Language](https://img.shields.io/badge/Language-C-blue)
![Norm](https://img.shields.io/badge/Norm-passing-brightgreen)

## 📋 Table of Contents
- [Description](#description)
- [Project Overview](#project-overview)
- [Supported Conversions](#supported-conversions)
- [Project Structure](#project-structure)
- [Implementation Details](#implementation-details)
- [Compilation](#compilation)
- [Usage](#usage)
- [Technical Challenges](#technical-challenges)
- [Testing](#testing)
- [Author](#author)

## 🔍 Description

**ft_printf** is the second project in the 42 School curriculum, where you recreate the behavior of the famous C standard library function `printf()`. This project deepens your understanding of variadic functions, string formatting, and efficient output management.

The goal is to implement a function that mimics the original `printf()` behavior with various format specifiers, handling different data types and returning the number of characters printed.

This implementation successfully passed all tests and earned **100/100** points.

## 🎯 Project Overview

The `ft_printf` function must handle multiple conversion specifiers and replicate the behavior of the standard `printf()` as closely as possible:

```c
int ft_printf(const char *format, ...);
```

### Key Features
- ✅ Variadic function implementation using `<stdarg.h>`
- ✅ Multiple format specifiers support
- ✅ Returns the number of characters printed
- ✅ Handles edge cases (NULL pointers, empty strings, INT_MIN/MAX)
- ✅ Memory-safe implementation

## 📝 Supported Conversions

The ft_printf function supports the following format specifiers:

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `ft_printf("%c", 'A')` → A |
| `%s` | String | `ft_printf("%s", "Hello")` → Hello |
| `%p` | Pointer address in hexadecimal | `ft_printf("%p", ptr)` → 0x7fff5fbff7e0 |
| `%d` | Signed decimal integer | `ft_printf("%d", -42)` → -42 |
| `%i` | Signed decimal integer | `ft_printf("%i", 42)` → 42 |
| `%u` | Unsigned decimal integer | `ft_printf("%u", 123)` → 123 |
| `%x` | Hexadecimal (lowercase) | `ft_printf("%x", 255)` → ff |
| `%X` | Hexadecimal (uppercase) | `ft_printf("%X", 255)` → FF |
| `%%` | Percent sign | `ft_printf("%%")` → % |

### Special Cases Handling

- **NULL strings**: `%s` with NULL prints `(null)`
- **NULL pointers**: `%p` with NULL prints `(nil)`
- **INT_MIN**: Correctly handles `-2147483648`
- **Empty strings**: Returns 0 characters printed

## 📁 Project Structure

```
42_printf/
├── Makefile              # Compilation rules
├── libftprintf.h         # Header file with function prototypes
├── ft_printf.c           # Main printf function and integer conversion
├── percent.c             # Format specifier handlers (hex, unsigned, ptr)
└── utilis.c              # Utility functions (putchar, strlen)
```

### File Breakdown

#### `ft_printf.c`
- Main `ft_printf()` function using variadic arguments
- `conversion()` - Router function for format specifiers
- `ft_putnbr()` - Handles signed integer printing

#### `percent.c`
- `ft_putstr()` - String printing with NULL handling
- `ft_put_hex()` - Hexadecimal conversion (lowercase/uppercase)
- `ft_put_hex_long()` - Hexadecimal for unsigned long (pointers)
- `ft_put_hex_ptr()` - Pointer address formatting
- `ft_putnbr_unsigned()` - Unsigned integer printing

#### `utilis.c`
- `ft_putchar()` - Character output
- `ft_strlen()` - String length calculation

## 🔧 Implementation Details

### Variadic Functions

The project uses `<stdarg.h>` macros to handle variable arguments:

```c
va_list ap;           // Declare argument pointer
va_start(ap, str);    // Initialize argument list
va_arg(ap, type);     // Retrieve next argument
va_end(ap);           // Clean up argument list
```

### Conversion Logic

```c
int conversion(char str, va_list ap)
{
    int count = 0;
    
    if (str == 's')
        count += ft_putstr(va_arg(ap, char *));
    else if (str == 'c')
        count += ft_putchar(va_arg(ap, int));
    else if (str == 'd' || str == 'i')
        count += ft_putnbr(va_arg(ap, int));
    // ... other conversions
    
    return count;
}
```

### Hexadecimal Conversion

Recursive approach for efficient hexadecimal conversion:

```c
int ft_put_hex(unsigned int n, char str)
{
    if (n < 16)
    {
        if (str == 'x')
            ft_putchar("0123456789abcdef"[n]);
        else
            ft_putchar("0123456789ABCDEF"[n]);
        return (1);
    }
    return (ft_put_hex(n / 16, str) + ft_put_hex(n % 16, str));
}
```

### Edge Cases

**INT_MIN Handling:**
```c
if (nb == -2147483648)
{
    write(1, "-2147483648", 11);
    return (11);
}
```

**NULL Pointer Handling:**
```c
if (!ptr)
    return (write(1, "(nil)", 5));
```

**NULL String Handling:**
```c
if (!str)
{
    write(1, "(null)", 6);
    return (6);
}
```

## 🔨 Compilation

### Using Makefile

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile from scratch
```

### Compilation Flags

The project uses strict compilation flags:
```makefile
CFLAGS = -Wall -Wextra -Werror -g
```

### Output

Creates `libftprintf.a` - a static library containing all ft_printf functions.

## 💻 Usage

### 1. Compile the Library

```bash
make
```

### 2. Include in Your Project

```c
#include "libftprintf.h"

int main(void)
{
    int ret;
    
    ret = ft_printf("Hello, %s!\n", "World");
    ft_printf("Characters printed: %d\n", ret);
    
    return (0);
}
```

### 3. Compile Your Program

```bash
cc your_program.c -L. -lftprintf -o your_program
```

### Example Code

```c
#include "libftprintf.h"

int main(void)
{
    int     num = 42;
    char    *str = "42 School";
    void    *ptr = &num;
    
    // Basic conversions
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", str);
    ft_printf("Decimal: %d\n", num);
    ft_printf("Integer: %i\n", -123);
    ft_printf("Unsigned: %u\n", 4294967295U);
    
    // Hexadecimal
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    
    // Pointer
    ft_printf("Pointer: %p\n", ptr);
    
    // Percent sign
    ft_printf("Percent: %%\n");
    
    // Mixed formats
    ft_printf("Mixed: %c %s %d %x %p\n", 'Z', "test", 1337, 255, ptr);
    
    return (0);
}
```

### Expected Output

```
Character: A
String: 42 School
Decimal: 42
Integer: -123
Unsigned: 4294967295
Hex (lower): ff
Hex (upper): FF
Pointer: 0x7ffeeb8b4a9c
Percent: %
Mixed: Z test 1337 ff 0x7ffeeb8b4a9c
```

## 🎯 Technical Challenges

### 1. **Variadic Functions**
Understanding and implementing `va_list`, `va_start`, `va_arg`, and `va_end` correctly.

### 2. **Return Value**
Tracking the exact number of characters printed across all conversions.

### 3. **Hexadecimal Conversion**
Implementing efficient recursive conversion for both lowercase and uppercase.

### 4. **Pointer Formatting**
Converting memory addresses to hexadecimal with `0x` prefix.

### 5. **Edge Cases**
- Handling INT_MIN without overflow
- NULL pointer and string management
- Unsigned integer overflow

### 6. **Type Casting**
Proper casting between different integer types (int, unsigned int, unsigned long).

## 🧪 Testing

### Comprehensive Test Suite

```c
#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ret1, ret2;
    
    // Test basic strings
    ret1 = printf("printf: %s\n", "Hello");
    ret2 = ft_printf("ft_printf: %s\n", "Hello");
    printf("Returns: %d vs %d\n\n", ret1, ret2);
    
    // Test integers
    ret1 = printf("printf: %d %i %u\n", 42, -42, UINT_MAX);
    ret2 = ft_printf("ft_printf: %d %i %u\n", 42, -42, UINT_MAX);
    printf("Returns: %d vs %d\n\n", ret1, ret2);
    
    // Test hexadecimal
    ret1 = printf("printf: %x %X\n", 255, 255);
    ret2 = ft_printf("ft_printf: %x %X\n", 255, 255);
    printf("Returns: %d vs %d\n\n", ret1, ret2);
    
    // Test pointers
    int n = 42;
    ret1 = printf("printf: %p\n", &n);
    ret2 = ft_printf("ft_printf: %p\n", &n);
    printf("Returns: %d vs %d\n\n", ret1, ret2);
    
    // Test edge cases
    ret1 = printf("printf: %d | %d | %u\n", INT_MAX, INT_MIN, UINT_MAX);
    ret2 = ft_printf("ft_printf: %d | %d | %u\n", INT_MAX, INT_MIN, UINT_MAX);
    printf("Returns: %d vs %d\n\n", ret1, ret2);
    
    // Test NULL cases
    ret1 = printf("printf: %s %p\n", (char *)NULL, NULL);
    ret2 = ft_printf("ft_printf: %s %p\n", (char *)NULL, NULL);
    printf("Returns: %d vs %d\n\n", ret1, ret2);
    
    return (0);
}
```

### Recommended Testers

- **[printfTester](https://github.com/Tripouille/printfTester)** by Tripouille
- **[ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)** by Paulo Santana
- Manual comparison with original `printf()`

## 📊 Performance

### Character Count Accuracy
- ✅ Returns exact number of printed characters
- ✅ Matches original `printf()` behavior
- ✅ Handles all edge cases correctly

### Memory Management
- ✅ No memory leaks
- ✅ No buffer overflows
- ✅ Safe NULL pointer handling

## 🎓 Learning Outcomes

This project teaches:
- **Variadic functions** - Using variable argument lists
- **Format parsing** - Interpreting format strings
- **Type conversions** - Converting between different representations
- **Recursion** - Efficient number-to-string conversion
- **Output management** - Tracking printed characters
- **Edge case handling** - Robust error management

## 👨‍💻 Author

**rydelepi (Vibes33)** - 42 Student

*This project was validated with a score of 100/100, successfully implementing all required format specifiers.*

---

## 📝 Notes

- This implementation follows the 42 Norm strictly
- Only allowed functions: `write`, `malloc`, `free`, `va_start`, `va_arg`, `va_copy`, `va_end`
- No use of the original `printf()` family functions in the implementation
- Designed to be used in future 42 projects (get_next_line, minitalk, etc.)

## 🚀 Future Improvements

While this implementation meets all project requirements, possible enhancements could include:
- Support for field width and precision modifiers
- Support for flags (`-`, `0`, `+`, `#`, ` `)
- Support for length modifiers (`l`, `ll`, `h`, `hh`)
- Additional format specifiers (`%f`, `%e`, `%g`, etc.)

---

*Part of the 42 School Common Core curriculum*
