KeyValSto v1.0 by Boro Sitnikovski
==================================

This program is intended for demonstration purposes only.

It demonstrates a couple of things:

1. Basic (string) parsing (tokenization, scanf, basic loops on strings)
2. Representing data types (variables of dynamic types) with linked lists
3. Serializing and de-serializing data types

No external lib dependencies other than libc.

Example:
```
$ keyvalsto
KeyValSto v1.0 by Boro Sitnikovski.

Type "help" for more information.
Write "quit" at any time to quit.

> help
Available commands: list, save, load, quit, !var, @var

E.g. Define a variable, show its type, show its value, delete the variable:
test = 3
@test
test
!test
> hello = "Hello World!"
> list
hello
> hello
"Hello World!"
> double = 3.14
> double
3.140000
> number = 12345
> number
12345
> @number
int
> @double
double
> @hello
string
> list
hello double number
> save
Saved to keyvalsto.data.
> huh = "This won't be shown after load"
> huh
"This won't be shown after load"
> list
hello double number huh
> load
Loaded keyvalsto.data.
> list
hello double number
> huh
Undefined variable.
> !double
> double
Undefined variable.
> list
hello number
```

Linux users:
- Write "make" to build and "make clean" to clean.

Windows users:
- For Visual Studio, run the project file projects/keyvalsto.vcxproj.
- For Pelles C, run the project file projects/keyvalsto.ppj.
- For MinGW, write "make" in the console and "make clean" to clean.

Boro Sitnikovski

Licensed under GPL.  Read LICENSE for more information.

January, 2014