#include <stdio.h>
#include <stdlib.h>
#include <invert.h>

int main( int argc, char * argv[v] ) {
	if( argc == 1) {
		printf("Bitte Funktion mit Parametern aufrufen!");
		return 1;
	} 
	for( int i=1; i<argc; i++) {
		argv[i]=invert(argv[i]);
	}
	for( int i=argc; i>0; i--) {
		printf(%c; \n; argv[i]);
	}
	return 0;
}		
