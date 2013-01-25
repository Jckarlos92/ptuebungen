#include <stdio.h>
#include <stdlib.h>

/* Da wir in Aufgabe 2 mit unsigned char und short gearbeitet haben, haben wir dies auch
in diesem Programm übernommen, um eine gewisse Speichereffizienz beizubehalten. Allerdings
haben wir unsigned short statt short verwendet, um alle Zahlen (0-255), die unsigned char 
fasst, auch als positive Quadratzahlen darstellen zu können. */

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
	free(zahlen);
	free(qzahlen);
	return 0;
}
