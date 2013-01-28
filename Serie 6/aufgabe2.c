#include <stdio.h>

int main (int argc, char * argv[]) {
    /* Die Zahlen 0-100 werden im Array zahlen gespeichert Dessen Typ ist char
     * (also ein Byte), weil wir nicht mehr als 255 Werte benötigen */
	unsigned char zahlen[100];
    /* Die Quadratzahlen werden im qzahlen Array abgelegt Dessen Typ ist short,
     * also zwei Bytes, da die Quadratzahlen bis zu 100*100=10000 groß werden */
	short qzahlen[100];
	int i;
	for (i=0; i<100; i++) {
		zahlen[i]=(unsigned char)(i+1);
		qzahlen[i]=(i+1)*(i+1);
	} 
	for (i=0; i<100; i++) {
		printf("%d, %d \n", zahlen[i], qzahlen[i]);
	}

	return 0;
}
