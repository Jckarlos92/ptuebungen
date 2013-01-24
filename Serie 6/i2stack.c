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
	int val;
	stackElemPtr next;
	stackElemPtr prev;
} stackElemT;

void push( Stack s, int val ) {
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
	pt->val = val;
	pt->prev = NULL;
	pt->next = s->top;
	s->top = pt;
	s->error = OK;
	error = s->error;
}
	
int pop( Stack s ) {
	int rc;
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
	rc = s->top->val;
	pt = s->top;
	s->top = s->top->next;
	if (s->top)
		s->top->prev = NULL;
	free( pt );
	s->error = OK;
	error = s->error;
	return rc;
}
	
int top( Stack s ) {
	if (! s ) {
		error = NOT_INITIALIZED;
		return;
	}
	if(! s->top) {
		s->error = EMPTY;
		error = s->error;
		return 0;
	}
	s->error = OK;
	error = s->error;
	return s->top->val;
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
