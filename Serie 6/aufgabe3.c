#include <stdio.h>
#include <stdlib.h>

//argv[0] rausnehmen!!!!

int main (int argc, char * argv[]) {
	int *zahlen = (int *) malloc (sizeof(int) * argc);
	int *qzahlen = (int *) malloc (sizeof(int) *argc);
	int i;
	for (i=0;i<argc-1;i++) {
		*(zahlen+i) = atoi(argv[i+1]);
		*(qzahlen+i) = zahlen[i]*zahlen[i];
	}
	for (i=0;i<argc-1;i++) {
		printf("%d, %d \n", zahlen[i], qzahlen[i]);
	}
	return 0;
}
