# My-Struct

My-Struct is a small C++ console project for learning how a singly linked list works. Each node stores a film name, title, year, duration, and a pointer to the next film.

## Project layout

| File | Purpose |
| --- | --- |
| `main.cpp` | Program entry point and examples of the available list operations. |
| `mon_fonction.h` | `Film` and `liste` structures, plus their function declarations and implementations. |

Keep both files in the same directory because `main.cpp` includes `mon_fonction.h` directly.

## Requirements

- A C++ compiler with `<conio.h>` and `getche()` support, such as MinGW on Windows.
- A terminal for the interactive prompts.

> [!NOTE]
> Most Linux and macOS toolchains do not provide `<conio.h>`. The project will need a small input-handling adaptation before it can be compiled on those platforms.

## Build and run

From the project directory, compile the program with a compatible compiler:

```sh
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o my-struct.exe
```

Then run it:

```sh
./my-struct.exe
```

On Windows Command Prompt, use:

```bat
my-struct.exe
```

## Current program flow

The active code in `main.cpp`:

1. Creates a list and asks for the first film.
2. Prompts for the film name, title, year, and duration.
3. Adds another film when you enter `y` or `Y`.
4. Displays every film in the list.

The additional examples in `main.cpp` are commented out. Uncomment only the operation you want to try, then rebuild the program.

## Available operations

| Function | Description |
| --- | --- |
| `creation_film` | Allocates a film and reads its fields interactively. |
| `afich_film` | Displays one film. |
| `creation_liste` | Creates an interactive list of films. |
| `liste_est_vid` | Checks whether a list is empty. |
| `afich_liste` | Displays every film in a list. |
| `inverse_ordre` | Reverses the order of the linked nodes. |
| `ajout_tete` | Adds a film at the beginning. |
| `ajout_fin` | Adds a film at the end. |
| `ajout_Milio` | Inserts a film at a selected position. |
| `nombre_des_eliment` | Counts films by traversing the list. |
| `afich_elemient_position` | Displays the film at a selected position. |
| `suppr_position` | Removes the film at a selected position. |

## Input constraints

The current implementation reads names and titles with `scanf("%s", ...)` into 10-character arrays. For predictable input:

- enter a single word for each name and title;
- use no more than 9 characters per value;
- enter whole numbers for the year and duration.

These constraints reflect the current code and help avoid invalid or oversized input.
