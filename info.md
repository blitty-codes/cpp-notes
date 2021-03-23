# DAY 1 - 06/02/2021

## Compiling code
The compiler steps:
1. Checks if the code follows the C++ rules
  1.2 Any error, will tell u
2. Translates C++ to machine lannguaje file called **object file** (.o or .obj)
3. The **linker**
  3.1 takes all the _.o_ files and combine them into a single executable program
  3.2 Links library files too
3.3 It makes sure that all cross-file dependencies are resolved

## std::endl vs \n
- **_std::endl_** moves the cursor to the next line and "flushes" the output. (*)
- **_\n_** moves the cursor to the next line

(*) std::cout usually flushes the output

## literals
A literal is a vrable whose value is fixed and can't be changed
```cpp
int literal {120};
std::cout << "I am a literal";
```

## functions
We use functions to structure a program. Some benefits
- Organization
- Reusability (DRY - Don't Repear Yourslef)
- Testing
- Abstraction

## prepocessors
(translation)[https://en.cppreference.com/w/cpp/language/translation_phases] is the prior thing that happens before the compilation.

The preprocessor is a program that manipulates th text in each code file. When it runs, it searches for **preprocessor directives**, these are instructions that start with _#_ and end with a _newline_.

One example is the **_#include directive_**, this replaces the directive with the contents of the included file.

**Macro**, types:
  - Object-like
    - with substitution text, it is usually types in capital letters, using underscores to represent spaces.
    - without substitution text
  - Function-like, they act like functions, and serve a similar purpose. They are considered dangerous.
  - Conditional compilation, it allows you to specify whether or not compile a piece of code. There are different ones:
    - _#ifdef_ checks whether an identifier has been previously _#define_
    - _#ifndef_ reverse of _#ifndef_
    - _#endif_ ends the two other
    - _#if 0_ exclude code from being compiled

The **preprocessor** doesn't care about the scope, but it does care in which file it is placed.

# DAY 2 - 07/02/2021

## HEADER FILES
The extension of these files is _.h_ or _.hpp_, they has the functionality to propagate declarations to code files.
They don't have the body of the function, just functions and variable declarations. But when using constants, they can be inicializate.

The **Header Files** consist of two parts:
1. _header guard_
2. The content of the header file

When chars _<_ _>_ are used, we are telling the compiler that, that header was not written by us. When using _"_ _"_, means, we are telling the compiler that is a header made by us, so it will search first int the current directory and if it is not found, it will search in the "includes directory"

To specify another directory where a library of yours can be found from all the proyects, use the next command:
```
g++ -o main -I/source/includes main.cpp
```
The -I option specify an alternative _include directory_

**HEADER GUARDS** are conditional compilation directives that are like:
```cpp
#ifndef UNIQUE_NAME
#define UNIQUE_NAME
// declarations
#endif
```
when this header is _#include_, it cheecks if UNIQUE_NAME is alrady define, if so, the contents from the file will be ignored because they had been already included the contents. Otherwise, it defines the _object-like without substitution text_.

Another way is using ```cpp #pragma once``` this does the same, but it is not an official part of C++ and not all compilers support it.

(Design your first program)[https://www.learncpp.com/cpp-tutorial/how-to-design-your-first-programs/]

# DAY 3 - 12/02/2021

## Variables

| Category | Type | Size |
|:---------:|:------:|:--------------:|
| boolean	| bool | 1 byte	|
| character	| char | 1 byte (exactly)	|
| character | wchar_t	| 1 byte |
| character | char16_t | 2 bytes |
| character | char32_t | 4 bytes |
| integer	| short	| 2 bytes	|
| integer | int	| 2 bytes	|
| integer | long | 4 bytes |
| integer | long long	| 8 bytes	|
| floating point | float | 4 bytes |
| floating point | double | 8 bytes	|
| floating point | long double	| 8 bytes |

rather than consulting this table, you can use **sizeof(var_name)** to know the size of the object

## fixed width integer

| Name | Type | Range |
|:------------:|:-------:|:------------------------:|
| std::int8_t | 1 byte signed | -128 to 127 |
| std::uint8_t | 1 byte unsigned | 0 to 255 |
| std::int16_t |	2 byte signed |	-32,768 to 32,767	|
| std::uint16_t |	2 byte unsigned |	0 to 65,535	|
| std::int32_t |	4 byte signed |	-2,147,483,648 to 2,147,483,647	|
| std::uint32_t |	4 byte unsigned |	0 to 4,294,967,295 |
| std::int64_t |	8 byte signed |	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| std::uint64_t |	8 byte unsigned |	0 to 18,446,744,073,709,551,615 |

Using these types of variables makes your code less portable and may not compile in other systems

## least and fast
least and fast types of variables gives you the least or the fast bytes of a type.
See day3/main.cpp

they are useful when you need at least a certain number.

## Integer best practices
**int** should be used when the size of the integer doesn't matter.
**std::int_fast#_t** when you need a particular size and favor performance.
**std::int_least#_t** when you need a particular size and want memory conservation over performance.

_Avoid_ using 8-bit fixed width integer types and unsigned types unless you have a compiling reason.

### NOTE
It is better not to use ```cpp int8_t``` or ```cpp uint8_t``` neather **fast** and **least** 8 byte, because they can be treated as chars.
Try:
```cpp
int main() {
  std::int8_t i {65}; // 65 == 'A'
  std::cout << i << '\n';

  return 0;
}
```

## size_t
This type is typically used to represent the size or length of objects.
**std::size_t**

## Floating point numbers

| Type | Minimum size | typical size |
|:----:|:------------:|:------------:|
| float | 4 bytes | 4 bytes |
| double | 8 bytes | 8 bytes |
| long double | 8 bytes |	8, 12, or 16 bytes |

with suffix **f** means float, otherwise double.

## Escape sequences
| Name | Symbol | Meaning |
|:----:|:------:|:-------:|
| Alert | \a | Makes an alert, such as a beep |
Backspace | \b | Moves the cursor back one space |
| Formfeed | \f | Moves the cursor to next logical page |
| Newline | \n | Moves cursor to next line |
| Carriage return | \r | Moves cursor to beginning of line |
| Horizontal tab | \t | Prints a horizontal tab |
| Vertical tab | \v | Prints a vertical tab |
| Single quote | \’ | Prints a single quote |
| Double quote | \” | Prints a double quote |
| Backslash | \\\ | Prints a backslash. |
| Question mark | \? | Prints a question mark. No longer relevant. You can use question marks unescaped. |
| Octal number | \\(number) | Translates into char represented by octal |
| Hex number | \x(number) | Translates into char represented by hex number |

You won’t need to use char8_t, char16_t, or char32_t unless you’re planning on making your program Unicode compatible.

## Constants
C++ has 2 types of constants, **literal constants** and **symbolic constants**.

### Literal constants
They are values inserted in the code, like:
```cpp
return 5; // 5 is an integer literal
bool myNameIsAlex { true }; // true is a boolean literal
std::cout << 3.4; // 3.4 is a double literal
```

they cannot be change dynamicaly, this means that you need to change them and then recompile to take effect.

### Symbolic constants
Using the key **const** you can create a constant. It is recommended, for constant things, like gravity. Values that does not change, are the same always.
You cannot change its value and it has to be initialized.

Also they are used in parameters because in this way, it makes a "copy" where the value you are passing, cannot be change.

**constexpr** ensures that a constant must be a compile-time constant.

### constants vs object-like macros
You should not use object-like macros because of these reasons:
1. They are treated by the preprocessor, which replace the symbolic name with the defined value, #define. Symbolic constant doesn't show up in the debugger. Like so:
  ```
  without object-like, in the debugger would show as:
    int mass { 5 * 9.8 };
  and with it
    int mass {5 * GRAVITY };
  GRAVITY its value is not shown in the debugger.
  ```
2. Macros can conflict with normal code.
3. macros don’t follow normal scoping rules, which means in rare cases a macro defined in one part of a program can conflict with code written in another part of the program that it wasn’t supposed to interact with.

# DAY 4 - 20/02/2021

## Bitwise operators
| Operator | Description | Example |
|:----:|:------:|:-------:|
| ~ | Bitwise NOT | ~expression |
| << | Bitwise SHIFT LEFT | expression << expression |
| >> | Bitwise SHIFT RIGHT | expression >> expression |
| & | Bitwise AND | expresion & expresion |
| \| | Bitwise OR | expresion \| expresion |
| ^ | Bitwise XOR | expresion ^ expresion |

## Comma operator
```cpp
int z = (++x, ++y); // increment x, increment y and return the y
```
## bit flags
```cpp
#include <bitset>

std::bitset<8> mybitset {}; // 8 bits
```
Each number denotes a **bit position**
76543210 <- bit position
00001010 <- Bit sequence

### bit manipulation
**std::bitset** provides 4 key functions that are useful for doing bit manipulation
- test(position) allows us to query whether a bit is a 0 or 1
- set(position) turn a bit on
- reset(position) turn bit off
- flip(position) change the value from 0 to 1 or viceversa

bitwise operators does not know how to work with bit positions.
A **bitmask** is a predifined set of bits that is used to slect which specific bits will be modifie.

## blocks
```cpp
// global variable
const int g_no; // error constants must be initialized
const int g_yes { 9 };

int main {

  {
    // hello I am a block
    // well, an inner/nested block

    int x { 10 }; // it's not accesible outside this block
  }

  return 0;
}
```

#### TIP
When using global variables, use the **g** or **g_** prefix

# namespace
You should use namespaces to separate application-specific code that may be reusable later.
When you want to write a library or code to distribute to others, always place your code inside namespace, this evits conflicts.

Using the keyword **namespace** you can create your own declarations called **user-defined namespaces**. Namespace identifiers are typically non-capitalized.

In general, you don't need to use nested namespace.
