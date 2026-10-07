# My-Struct

A small C++ console project that demonstrates a singly linked list of films.

## Files

- `main.cpp` contains the program entry point and calls the list creation and display functions.
- `mon_fonction.h` defines the `Film` and `liste` structures and implements the list operations. Keep this header next to `main.cpp`; the program includes it directly.

## Build and run

The project uses `<conio.h>` and `getche()`, so it requires a C++ toolchain that provides this header and function (typically a Windows-oriented toolchain).

From the project directory, compile and run with a compatible compiler:

```sh
g++ main.cpp -o My-Struct.exe
./My-Struct.exe
```

The current entry point creates a list by prompting for film information, then displays the list. Enter `y` or `Y` when prompted to add another film.
