#include <stdio.h>
#include <stdlib.h>

#define N 4

/* scmp: string compare of *p1 and *p2 */
int scmp(const void *p1, const void *p2)
{
	char *v1, *v2;

	v1 = *(char **) p1;
	v2 = *(char **) p2;
	return strcmp(v1, v2);
}

int main()
{
	char *str[N] = {"d", "a", "c", "b"};

	qsort(str, N, sizeof(str[0]), scmp);
	for (int i = 0; i < N; i++) {
		printf("%s\n", str[i]);	
	}
	return 0;
}
