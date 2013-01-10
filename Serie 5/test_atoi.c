# include <stdio.h>

/*#ifdef MY_ATOI */
# include "atoi.h"
/*#else
# include <stdlib.h>
#endif */

int main (int argc, char** argv) {
    if (argc == 1) {
        printf("Bitte mindestens einen Parameter übergeben!");
        return 1;
    }

    int i=1, result;
    for (; i<argc; ++i) {
        result = atoi(argv[i]);

        printf("%7s => %7d\n", argv[i], result);
    }

    return 0;
}
