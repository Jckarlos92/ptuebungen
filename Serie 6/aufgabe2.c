#include <stdio.h>

int main (int argc, char * argv[]) {
	unsigned char zahlen[100];
	short qzahlen[100];
	int i;
	for (i=0; i<100; i++) {
		zahlen[i]=(char)(i+1);
		qzahlen[i]=(i+1)*(i+1);
	} 
	for (i=0; i<100; i++) {
		printf("%d, %d \n", zahlen[i], qzahlen[i]);
	}

	return 0;
}
