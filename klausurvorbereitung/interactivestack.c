/* Habe hier mal die Klausuraufgabe nachprogrammiert */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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
    char buf[80];
    int stupid = 0;
    int val;

    printf("Welcome to the Integer Stack 3000 (c)!\n");
    printf("Please put in numbers that shall be pushed onto the stack\n");

    while (strcmp(buf, "q") != 0) {
        printf("[%s] command %s>", (is_valid()?"good":"invalid"), (stupid?"(again...) ":""));

        if (scanf("%s", buf)) {
            if (strcmp(buf, "push") == 0) {
                printf("\t push number >"); 
                if (scanf("%d",&val)) {
                    push(val);
                }

            } else if (strcmp(buf, "pop") == 0) {
                int good = is_valid();
                printf("popped %s value: %d\n", (good?"good":"bad"), pop());
            }
            stupid = 0;
        } else {
            stupid = 1;
        }
    }

    return 0;
}
    


