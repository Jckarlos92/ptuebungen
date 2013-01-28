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

double pop( Stack s, int *isf ) {
	double rc;
	stackElemPtr pt;
	if (! s ) {
		error = NOT_INITIALIZED;
		return 0;
	}
	if(! s->top) {
		s->error = EMPTY;
		error = s->error;
		return 0;
	}
	rc = ((s->top->isFloat)?s->top->val.f:(double)s->top->val.i);
    *isf = (s->top->isFloat)?1:0;
	pt = s->top;
	s->top = s->top->next;
	if (s->top)
		s->top->prev = NULL;
	free( pt );
	s->error = OK;
	error = s->error;
	return rc;
}
	
double top( Stack s, int *isf ) {
	if (! s ) {
		error = NOT_INITIALIZED;
		return 0;
	}
	if(! s->top) {
		s->error = EMPTY;
		error = s->error;
		return 0;
	}
	s->error = OK;
	error = s->error;
    *isf = (s->top->isFloat)?1:0;
	return ((s->top->isFloat)?s->top->val.f:(double)s->top->val.i);
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
