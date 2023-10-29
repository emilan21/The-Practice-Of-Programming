#include <stdio.h>
#include <stdlib.h>

#define N 4

/* nvcmp: compare two Nameval names */
int nvcmp(const void *va, const void *vb)
{
	const Nameval *a, *b;

	a = (Nameval *) va;
	b = (Nameval *) vb;
	return strcmp(a->name, b -> name);
}

/* lookup: use bsearch to find name in tab, return index */
int lookup(char *name, Nameval tab[], int ntab)
{
	Nameval key, *np;

	key.name = name;
	key.value = 0; 		/* unused; anything with do */
	np = (Nameval *) bsearch(&key, tab, ntab, sizeof(tab[0]), nvcmp);
	if (np == NULL)
		return -1;
	else
		return np-tab;
}

int main()
{
	int arr[N] = {5, 3, 10, 2};

	qsort(arr, N, sizeof(arr[0]), icmp);
	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);	
	}
	return 0;
}
