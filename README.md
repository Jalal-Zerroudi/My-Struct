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

## Position conventions and limitations

Positions used by `afich_elemient_position(l, p)` and `suppr_position(l, p)` start at **1**: position 1 refers to the head. Display rejects positions outside the current traversed length; deletion instead checks the stored `l->nb` counter. When deletion removes the tail, `fin` is moved to the preceding node; removing the only node resets both `tete` and `fin` to `NULL`.

Despite its name, `ajout_Milio(l, n)` links a new node **after** the nth existing node, not before it. For example, inserting after position 2 in `A → B → C` is intended to produce `A → B → new → C`.

The insertion examples are experimental and should not be enabled without reviewing their implementation:

- `ajout_tete`, `ajout_fin`, and `ajout_Milio` ignore the pointer returned by `creation_film`, which allocates a separate node; this can leave the linked node's fields uninitialized and leak memory.
- These insertions do not update `l->nb`, so later deletion checks can disagree with the actual list length.

Use the default creation-and-display flow as the starting example. The extra operations are learning exercises, not a validated general-purpose list library.

## Non-interactive regression check

With the compatible compiler described above, save the following as
`list_check.cpp` beside `mon_fonction.h`. It checks that counting preserves the
tail, reversing three nodes updates both endpoints, and reversing twice restores
the original links. It also checks the single-node case.

```cpp
#include <cassert>
#include "mon_fonction.h"

int main() {
    Film a = {}, b = {}, c = {};
    a.FS = &b;
    b.FS = &c;
    liste l = {&a, &c, 3};

    assert(nombre_des_eliment(&l) == 3);
    assert(l.fin == &c && c.FS == NULL);
    inverse_ordre(&l);
    assert(l.tete == &c && c.FS == &b && b.FS == &a);
    assert(l.fin == &a && a.FS == NULL && l.nb == 3);
    assert(nombre_des_eliment(&l) == 3);
    inverse_ordre(&l);
    assert(l.tete == &a && a.FS == &b && b.FS == &c);
    assert(l.fin == &c && c.FS == NULL && l.nb == 3);

    liste single = {&c, &c, 1};
    inverse_ordre(&single);
    assert(single.tete == &c && single.fin == &c && c.FS == NULL);
}
```

Compile and run it without disabling assertions (do not add `-DNDEBUG`):

```sh
g++ -std=c++11 -Wall -Wextra -pedantic list_check.cpp -o list-check.exe
./list-check.exe
```

A successful run exits with code 0; the single-node case prints an informational
message. An assertion failure indicates a regression. The nodes in this example
are stack-allocated: do not pass this fixture to `suppr_position`, which calls
`free`. This check does not validate interactive input or the experimental
insertion/deletion operations.

## Input constraints

The current implementation reads names and titles with `scanf("%s", ...)` into 10-character arrays. For predictable input:

- enter a single word for each name and title;
- use no more than 9 characters per value;
- enter whole numbers for the year and duration.

These constraints reflect the current code and help avoid invalid or oversized input.
