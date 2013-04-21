/* Habe hier mal die Klausuraufgabe nachprogrammiert */
# include <stdio.h>

# define NELEM 1000
int stack[NELEM];
int sp = 0; /* zeigt immer auf die nächste freie Stelle */
int good = 0;

void
push(int v) {
    if (sp < NELEM-1) {
        stack[sp] = v;
        sp++;
        good = 1;
    } else {
        good = 0;
    }
}

int
pop(void) {
    int rc = -1;
    if (sp > 0) {
        sp--;
        rc = stack[sp];
    } else {
        good = 0;
    }
    return rc;
}

int
top(void) {
    if (sp > 0 && sp < NELEM) {
        good = 1;
        return stack[sp-1];
    } else {
        good = 0;
        return -1;
    }
}

int
is_valid(void) {
    return good;
}

int main() {
    printf("Number stack\n");
    printf("Push 5\n");
    push(5);
    printf("top of stack: %d\n", top());
    printf("is_valid: %d\n", is_valid());
    printf("pop stack: %d\n", pop());
    printf("is_valid: %s\n", (is_valid()?"yes":"nope!"));
    printf("pop_stack: %d\n", pop());
    printf("is_valid: %s\n", (is_valid()?"yes":"nope!"));
    return 0;
}
    


