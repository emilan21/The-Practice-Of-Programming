#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(array) (sizeof(array) / sizeof(array[0]))

typedef struct Nameval Nameval;
struct Nameval {
	const char *name;
	int value;
};

/* nvcmp: compare two Nameval names */
int nvcmp(const void *va, const void *vb)
{
	const Nameval *a = va;
	const Nameval *b = vb;
	return strcmp(a->name, b->name);
}

/* lookup: use bsearch to find name in a sorted table; return index */
int lookup(const char *name, Nameval tab[], size_t ntab)
{
	Nameval key = {name, 0};
	Nameval *np = bsearch(&key, tab, ntab, sizeof(tab[0]), nvcmp);
	return np == NULL ? -1 : (int)(np - tab);
}

int main(void)
{
	Nameval htmlchars[] = {
		{"AElig", 0x00c6},
		{"Aacute", 0x00c1},
		{"Acirc", 0x00c2},
		{"zeta", 0x03b6},
	};

	printf("Index: %d\n", lookup("Acirc", htmlchars, NELEMS(htmlchars)));
	printf("Missing: %d\n", lookup("missing", htmlchars, NELEMS(htmlchars)));
	return 0;
}
