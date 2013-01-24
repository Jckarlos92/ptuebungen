#include <stdio.h>
#include <stdlib.h>

//argv[0] rausnehmen!!!!

int main (int argc, char * argv[]) {
	int *zahlen = (int *) malloc (sizeof(int) * argc);
	int *qzahlen = (int *) malloc (sizeof(int) *argc);
	int i;
	for (i=0;i<argc;i++) {
		*(zahlen+i) = atoi(argv[i]);
	}
	for (i=0;i<argc;i++) {
		printf("%d \n", zahlen[i]);
	}
	return 0;
}
