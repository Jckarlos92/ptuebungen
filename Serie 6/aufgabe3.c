#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
	unsigned char *zahlen = (unsigned char *) malloc (sizeof(unsigned char) * argc);
	unsigned short *qzahlen = (unsigned short *) malloc (sizeof(unsigned short) *argc);
	int i;
	for (i=0;i<argc-1;i++) {
		*(zahlen+i) = atoi(argv[i+1]);
		*(qzahlen+i) =(short) zahlen[i]*zahlen[i];
	}
	for (i=0;i<argc-1;i++) {
		printf("%d, %d \n", zahlen[i], qzahlen[i]);
	}
	return 0;
}
