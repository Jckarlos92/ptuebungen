# include "arena.h"
# include <stdio.h>

# define check( VAR ) \
do { if (! VAR ) fprintf(stderr, "Problem: " #VAR " is NULL\n" ); } while (0)

int main() {
	void *f, *g, *h;
	
	f = allocate(); check( f );
	g = allocate(); check( g );
	deallocate(g);
	h = allocate(); check( h );
	deallocate(f);
	deallocate(h);

    return 0;
}
