#include <stdio.h>
#include <stdlib.h>

#define N 4

/* scmp: string compare of *p1 and *p2 */
int icmp(const void *p1, const void *p2)
{
	int v1, v2;

	v1 = *(int *) p1;
	v2 = *(int *) p2;
	if (v1 < v2) {
		return -1;	
	} else if (v1 == v2) {
		return 0;	
	} else {
		return 1;	
	}
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
