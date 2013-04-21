/* AP 30-Aug-2012 numbers.c					*/
/*		  Geruest zum Aufruf von Integer Funtionen	*/
/*		  Ruft je nach Namen verschiedene Funktionen auf*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# include "fib.h"
# include "fac.h"
# include "sqr.h"

int main( int argc, char * argv[] ) {
	char * progname = argv[0];
	char * func = NULL;
	int input, result = 0;

	if (argc < 2) {
		printf("usage: %s [func] <val>\n", progname);
		exit( 1 );
	}
	if (argc > 2) {
		func = argv[1];
		input = atoi( argv[2] );
	} else {
		func = progname;
		input = atoi( argv[1] );
	}

	if (func) {
		if (strcmp( func, FAC ) == 0)
			result = fac( input );
		else if (strcmp( func, FIB ) == 0)
			result = fib( input );
        else if (strcmp( func, SQR ) == 0)
            result = sqr( input );
	}
	printf("Resultat: %s( %d ) = %d\n", func, input, result );
	exit( 0 );
}
	
