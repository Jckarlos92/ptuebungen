/* AP 30-Aug-2012 fac.c 			*/
/*		  Implementierung Fakultaet	*/

# include "fac.h"

int fac( int i ) {
	if (i <= 0) return 1;
	return i * fac( i-1 );
}
