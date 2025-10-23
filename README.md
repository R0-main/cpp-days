# cpp-days

## Overview
`cpp-days` collects my solutions to the 42 School C++ piscine modules (CPP00–CPP09). Each module is split into numbered exercises that build up from fundamental syntax and resource management to templates, STL algorithms, and custom containers.

## Repository layout
| Module | Highlights |
| ------ | ---------- |
| `CPP00` | Console utilities such as the interactive phone book that loops on user commands and validates input before displaying contacts. |
| `CPP01` | Memory management basics—dynamic allocation, references, and simple RAII wrappers such as the weapon/character pairing in `ex03`. |
| `CPP02` | Fixed-point arithmetic and geometric tests using immutable `Point` objects and a `bsp` helper to determine triangle membership. |
| `CPP03` | Canonical form and inheritance via the `ClapTrap` combat robot hierarchy. |
| `CPP04` | Abstract classes, deep copies, and polymorphic behavior with brain-owning animals. |
| `CPP05` | Bureaucracy simulator featuring `Bureaucrat` grade checks and executable forms. |
| `CPP06` | Casting exercises that generate random polymorphic types and identify them through RTTI. |
| `CPP07` | Function templates and iterators, exemplified by a generic `iter` utility that applies functors to arrays. |
| `CPP08` | STL containers and algorithms, including a `Span` class capable of range insertion and span computation. |
| `CPP09` | High-level algorithms such as a merge-insert sorter that times vector/deque specializations and a Bitcoin exchange parser. |

> 💡 Every exercise folder ships with its own `Makefile`, so you can build an example by changing into the directory you are interested in and running `make`.

## Prerequisites
- A C++98-compliant compiler (the projects default to `clang++ -std=c++98 -Wall -Wextra -Werror`).
- Make.

All exercises are self-contained; cloning the repository is enough to experiment with any module.

```bash
# build and run the first ClapTrap exercise
git clone https://github.com/<your-account>/cpp-days.git
cd cpp-days/CPP03/ex00
make
./ex00
```

Use `make clean` (or `make fclean`) to remove intermediate files before rebuilding.

## Code examples
Below are two representative snippets that illustrate how to explore the modules.

### ClapTrap duels (`CPP03/ex00`)
```cpp
#include "ClapTrap.hpp"

int main(void)
{
        ClapTrap robot("Wall-e");

        ClapTrap robot2 = robot;
        robot2.attack("Shreck");
        robot2.takeDamage(5);
        robot2.beRepaired(10);

        for (size_t i = 0; i < 9; i++)
        {
                robot.attack("Shreck");
        }
        robot.attack("Shreck");
        robot.beRepaired(10);
        robot.takeDamage(1005);
        return 0;
}
```
This scenario shows how copy construction and action point tracking are wired together: `robot2` is cloned from `robot`, attacks and heals, and the original instance eventually runs out of energy after repeated actions.

### Form bureaucracy (`CPP05/ex02`)
```cpp
const Bureaucrat emerik("Emerik", 1);
std::string str("fwqfqfqffq");
ShrubberyCreationForm form(str);
std::cout << emerik << "\n";
std::cout << form << "\n";

emerik.signForm(form);
emerik.executeForm(form);
```
Here a top-ranking bureaucrat signs and executes a shrubbery request, highlighting how grade thresholds gate the workflow. Lower-ranked runs in the same file demonstrate the exception paths when permissions are insufficient.

## Next steps
Pick a module that matches the concept you want to revise, build the corresponding exercise, and read through both the headers and the `main.cpp` driver. Most mains contain multiple scenarios that probe edge cases, making them great entry points for manual testing.
