/* AP 26-sep-12 test2stack.c			*/
/*		testdriver for Integer stack 	*/
/*		improved error handling		*/

# include <stdio.h>
# include <stdlib.h>
# include "i2stack.h"

# define LEN 80

/* gibt 0 zurück wenn eine ganze Zahl eingegeben wurde,
 * andernfalls (also bei Fließkommazahl) eine 1 */
int get_input( char * command[], int * val, double * dval) {
    /* Befehlssyntax: COMMAND VALUE */
	static char buf[LEN];	
	int i;

	*val = 0;
	fgets( buf, LEN, stdin );
	buf[LEN] = '\0';

    /* Kommando überschreiben */
	for (i = 0; i < LEN; i++ ) 
		if (isspace( buf[i] )) {
			buf[i] = '\0';
			break;
		}
    
    /* Beginn der Zahl finden */
	for ( i++; i < LEN; i++ )
		if (!isspace( buf[i] ))  
			break;

    /* Komma finden */
    for (*val=i; *val < LEN; ++(*val)) {
        if (buf[*val] == '.') {
            val = NULL;
            break;
        }
    }

    /* entscheiden ob Zahl in double oder int umzuwandeln ist */
    if (i < LEN) {
        *command = buf;
        
        if (val) {
            *val  = atoi( &buf[i] );
            return 0;
        } else {
            *dval = atof( &buf[i] );
            return 1;
        }
    } else {
        return 0;
    }
}

int main(int argc, char * argv[]) {
    /* generelle Idee:
     * union für int und double innerhalb des StackElem
     * dann innerhalb von StackElem flag setzen für isFloat
     */
	char* prog = argv[0];
	int cont = 1;
	char * command;
    char isFloat;
	int val;
    double dval;
	Stack s = NULL;

	printf("%s: Integer- und Kommazahlen-Stack mit Fehlercode in Stack-Struktur\n", prog);

	while( cont ) {
		printf("{init | push | pop | swap |"
			" top | free | quit} <int/float>\n");
		isFloat = get_input( &command, &val, &dval);

		if (strcmp( command, "init" ) == 0) {
			if (s) 
				printf("already initialized\n");
			else 	
				s = allocStack();
			print_error( s );
		} else if (strcmp( command, "push" ) == 0) {
            if (isFloat) {
			    push_double( s, dval );
            } else {
                push_int( s, val );
            }

			print_error( s );
		} else if (strcmp( command, "pop" ) == 0) {
			dval = pop( s );
			printf("pop: value = %f\n", dval );
			print_error( s );
		} else if (strcmp( command, "swap" ) == 0) {
			swap( s );
			print_error( s );
		} else if (strcmp( command, "top" ) == 0) {
			dval = top( s );
			printf("top: value = %f\n", dval );
			print_error( s );
		} else if (strcmp(command, "free") == 0) {
			freeStack( s );
			s = (Stack) 0;
			print_error( s );				
		} else if (strcmp(command, "quit") == 0) {
			cont = 0;
		} else {
			printf("wie bitte?\n");
			print_error( s );
		}
	}
}
