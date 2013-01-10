#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main( int argc, char** argv ) {
	if( argc == 1) {
		printf("Bitte Funktion mit Parametern aufrufen!");
		return 1;
	} 

    int i, j;
    for (i=argc-1; i>=1; --i) {
        for (j=strlen(argv[i]); j >= 0; --j) {
            printf("%c", toupper(argv[i][j]));
        } 
        printf(" ");
    }
    printf("\n");

	return 0;
}		
