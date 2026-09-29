# The Practice of Programming — chapter exercises

My solutions and small demonstrations inspired by *The Practice of Programming* by Brian W. Kernighan and Rob Pike. The repository currently contains Chapter 2 C and Java examples.

## Build and check

Install a C compiler, a Java Development Kit, Python 3, and Make, then run:

```sh
make
make check
```

The build writes new executables and Java classes to `Chapter-2/build/`. Existing executables and `.class` files at the chapter root are historical tracked files and are not used by these commands.

To run a demo directly, use `Chapter-2/build/quicksort` or `java -cp Chapter-2/build java_sort` after building. The checks verify the examples' output, including the sorted search and sorting demonstrations.
