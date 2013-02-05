# include <stdio.h>

# define SIZE 20

void reverse(int *field) {
    int i, j, buf;

    for (i=0; i<SIZE/2; ++i) {
        buf = field[i];
        field[i] = field[SIZE-1-i];
        field[SIZE-1-i] = buf;
    }
}


int main (int argc, char* argv[]) {
    int feld[SIZE] = {0,1,2,3,4};
    int i;

    printf("Normal order: ");
    for (i=0; i<SIZE; ++i) printf("%d ", feld[i]);
    printf("\nCalling reverse method on field...");
    reverse(feld);
    printf("done\n");
    printf("New order: ");
    for (i=0; i<SIZE; ++i) printf("%d ", feld[i]);
    printf("\n");
    return 0;
}
