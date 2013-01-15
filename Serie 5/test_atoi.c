# include <stdio.h>

#ifdef MY_ATOI
# include "atoi.h"
#else
# include <stdlib.h>
#endif

int main (int argc, char** argv) {
    if (argc == 1) {
        printf("Bitte mindestens eine Zahl als Parameter übergeben!\n");
rintf("Zahlenformat:\n");
        printf("    - dezimal mit oder ohne Vorzeichen: [+/-]10\n");
        printf("    - hexadezimal mit oder ohne Vorzeichen: [+/-]0xDeaDBeeF\n");
        return 1;
    }

#ifdef MY_ATOI
        printf("test_atoi mit selbstgeschriebner atoi-Funktion\n");
#else
        printf("test_atoi mit atoi-Funktion aus Standardbibliothek\n");
#endif

    int i=1;
    long int result;
    for (; i<argc; ++i) {
        result = atoi(argv[i]);

        printf("%7s => %7ld\n", argv[i], result);
    }

    return 0;
}
