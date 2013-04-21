#define NELEM 1000
#include <stdio.h>

int stack[NELEM];
int sp=0;
int check=0;

void push (int val) {
	if (sp < NELEM-1) {
		stack[sp++] = val;
		check=1;
	} else if (sp = NELEM-1){
		stack[sp++] = val;
		printf("Stack ist voll!\n");
		check=1;
	} else {
		check=0;
	}
}

int pop(void) {
	if (sp > 0) {
		stack[--sp]=0;
		check=1;
	} else if (sp = 0) {
		printf("Kein Element auf dem Stack!\n");
		check=0;
	} 
	
}

int top() {
	if (sp > 0) {
		return stack[sp-1];
	} else if (sp = 0) {
		printf("Kein Element auf dem Stack!\n");
		return 0;	
	}
}

void swap() {
	if (sp > 1) {
		int temp = stack[sp-1];
		stack[sp-1] = stack[sp-2];
		stack[sp-2] = temp;
	} else {
		printf("Zu wenige Elemente auf dem Stack!\n");
	}
	
}

int is_valid(void) {
	if (check=1) {
		printf("Operation erfolgreich!\n");
	} else {
		printf("Operation fehlgeschlagen!\n");
	}
}

int main(void) {
	push(5);
	is_valid();
	printf("%d\n", top());
	push(25);
	printf("%d\n", top());
	swap();
	printf("%d\n", top());
	pop();
	printf("%d\n", top());
}
