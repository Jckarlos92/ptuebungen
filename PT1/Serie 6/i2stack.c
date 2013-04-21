/* AP 26-sep-12	i2stack.c			*/
/*		ein Integer-Stack		*/
/*		Fehlercode in Stack-Struktur	*/

# include <stdlib.h>
# include <stdio.h>
# include "i2stack.h"

/* Alle Operationen setzen error Variable */
static enum errorT error;

typedef struct stackElem * stackElemPtr;
struct _stack {
	enum errorT error;
	stackElemPtr top;
} StackT;

struct stackElem {
    int isFloat;
	union {
        int i;
        double f;
    } val;
	stackElemPtr next;
	stackElemPtr prev;
} stackElemT;

void push_int( Stack s, int val ) {
	stackElemPtr pt;
	if (! s) {
		error = NOT_INITIALIZED;
		return;
	}
	pt = (stackElemPtr) malloc( sizeof( stackElemT ));
	if (! pt ) {
		s->error = NO_MEMORY;
		error = s->error;
		return;
	}
    pt->isFloat = 0;
	pt->val.i   = val;
	pt->prev    = NULL;
	pt->next    = s->top;
	s->top      = pt;
	s->error    = OK;
	error       = s->error;
}
	
void push_double( Stack s, double val ) {
	stackElemPtr pt;
	if (! s) {
		error = NOT_INITIALIZED;
		return;
	}
	pt = (stackElemPtr) malloc( sizeof( stackElemT ));
	if (! pt ) {
		s->error = NO_MEMORY;
		error = s->error;
		return;
	}
    pt->isFloat = 1;
	pt->val.f   = val;
	pt->prev    = NULL;
	pt->next    = s->top;
	s->top      = pt;
	s->error    = OK;
	error       = s->error;
}

/* gibt 0 zurück, wenn int auf dem stack lag,
 * sonst 1
 * Fehlercode: -1 
 * in der top Funktion ist vieles analog, deswegen beschreib ich
 * nur das hier en detail*/
char pop( Stack s, int *i, double *d ) {
    char rc;
	stackElemPtr pt;

    /* error handling hier */
	if (! s ) {
		error = NOT_INITIALIZED;
		return -1;
	}
	if(! s->top) {
		s->error = EMPTY;
		error = s->error;
		return -1;
	}

    /* entscheiden, welcher Wert in der Union benutzt werden soll,
     * bzw brauchbar ist */
    if (s->top->isFloat) {
        *d = s->top->val.f;
    } else {
        *i = s->top->val.i;
    }

    /* return code entsprechend setzen */
    rc = (s->top->isFloat)?1:0;

    /* und hier das "pop" ausführen */
	pt = s->top;
	s->top = s->top->next;
	if (s->top)
		s->top->prev = NULL;
	free( pt );
	s->error = OK;
	error = s->error;
	return rc;
}
	
/* gibt 0 zurück, wenn int auf dem stack liegt,
 * sonst 1
 * Fehlercode: -1 */
char top( Stack s, int *i, double *d ) {
	if (! s ) {
		error = NOT_INITIALIZED;
		return -1;
	}
	if(! s->top) {
		s->error = EMPTY;
		error = s->error;
		return -1;
	}
	s->error = OK;
	error = s->error;

    if (s->top->isFloat) {
        *d = s->top->val.f;
    } else {
        *i = s->top->val.i;
    }

	return ((s->top->isFloat)?1:0);
}

void swap( Stack s ) {
	stackElemPtr pt;
	if (! s ) {
		error = NOT_INITIALIZED;
		return;
	}
	if(! s->top) {
		s->error = EMPTY;
		error = s->error;
		return;
	}
	if (s && s->top && s->top->next) {
		pt = s->top;
		s->top = s->top->next;

		s->top->prev = pt->prev;
		pt->prev = s->top;
		pt->next = s->top->next;
		s->top->next = pt;
	}
	s->error = OK;
	error = s->error;
}
		
Stack allocStack() {
	Stack s = (Stack) malloc( sizeof( struct _stack ));
	if (! s) {
		error = NO_MEMORY;
		return (Stack) 0;
	}
	s->top = (stackElemPtr) 0;
	s->error = OK;
	error = s->error;
	return s;
}

void freeStack(Stack s) {
	stackElemPtr pt, p2;
	if (! s) {
		error = NOT_INITIALIZED;
		return;
	}
	pt = s->top;
	while (pt) {
		p2 = pt;
		pt = pt->next;
		free( p2 );
	}
	free( s );
	s->error = OK;
	error = s->error;
	return;
}

void print_error( Stack s ) {
	if (! s )
		printf("s == NULL; error = %d\n", error );
	else
		printf("error = %d\n", s->error );
}

enum errorT lastError( Stack s ) {
	if (! s) return error;
	return s->error;
}
