#include <stdio.h>
#include <string.h>

/* lookup: sequentail search for word in array */
int lookup(char *word, char *array[])
{
	int i;
	for (i = 0; array[i] != NULL; i++) {
		if (strcmp(word, array[i]) == 0)	
			return i;
	}	
	return -1;
}

int main()
{
	
	char *word = "none";
	char *flab[] = {
		"actually",
		"just",
		"quite",
		"really",
		NULL
	};

	printf("Index of %s: %d\n", word, lookup(word, flab));

	return 0;
}
