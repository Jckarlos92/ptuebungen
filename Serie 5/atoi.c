# include "atoi.h"

# include <string.h>
# include <stdio.h>

long int atoi (const char* s) {
	int      i = 0;
    long int n = 0;
    int   sign = 1;

    if (s[i] == '-') {
        sign = -1;
        ++i;
    } else if (s[i] == '+') {
        ++i;
    }

    /* Hexadezimal umwandeln */
    if (s[i] == '0' && s[i+1] == 'x') {
        for (i+=2; isValid(s[i]); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                n = 16*n + (s[i]-'0');
            } else if (s[i] >= 'A' && s[i] <= 'F') {
                n = 16*n + (s[i]-'A' +10);
            } else {
                n = 16*n + (s[i]-'a' +10);
            }
        }
    } else {
        /* hier dezimal umwandeln */
        for (;s[i] >= '0'&& s[i] <= '9'; i++) {
            n = 10*n + (s[i]-'0');
        }
    }
        
    if (i != strlen(s)) {
            n = 0;
    }

	return n * sign;
}
