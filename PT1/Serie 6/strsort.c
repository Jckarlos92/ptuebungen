/* AP 16-sep-12	strsort.c					 */
/*		Sortiern von Zeilen mit verschiedenen Funktionen */

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/* resultat < 0 wenn s1 kuerzer als s2     */
/* resultat > 0 wenn s1 laenger als s2     */
/* resultat == 0 wenn s1 und s2 gleichlang */
int comp_len( char * s1, char * s2 ) {
	return (strlen(s1) - strlen(s2));
}

/* resultat < 0 wenn s1 lexikographisch vor s2   */
/* resultat > 0 wenn s1 lexikographisch nach s2  */
/* resultat == 0 wenn s1 und s2 gleich           */
int comp_lexi( char * s1, char * s2) {
	return strcmp(s1, s2);
}

/* resultat < 0 wenn s1 numerisch größer s2   */
/* resultat > 0 wenn s1 numerisch kleiner s2  */
int comp_num( char * s1, char * s2) {
    unsigned int sum_s1, sum_s2, i,l;
    sum_s1 = sum_s2 = 0;

    /* die einzelnen char-Werte von s1 aufsummieren */
    l = strlen(s1);
    for (i=0; i<l; ++i) {
        sum_s1 += s1[i];
    }

    /* analog für s2 */
    l = strlen(s2);
    for (i=0; i<l; ++i) {
        sum_s2 += s2[i];
    }

    return (sum_s1 > sum_s2) ? 1 : -1;
}

/* Vertausche zwei Strings in Abhaengigkeit von compare() */
int swap( char * s[], int i, int j, int (*compare)(char *, char *)) {
	char * t;
	if ((*compare)(s[i], s[j]) > 0) {
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		return 1;
	}
	return 0;
}

void usage(char * prog) {
	printf("usage: %s [-lexi | -len | -num] <string> <string>+\n", prog);
	exit(1);
}

int main( int argc, char *argv[] ){
	char *prog = argv[0];
	int i, j, first;

	/* Deklaration unserer Vergleichsfunktion 		  */
	/* Bei Aufruf ohne Argumente soll comp_len gerufen werden */
	int (* compare_function)(char *, char *) = comp_len;

	if (argc < 3) usage( prog );
	first = 1;
	if (argv[1][0] == '-') {
		if (argc < 4) usage( prog ); 
		if (strcmp( &argv[1][1], "len") == 0) {
			/* Der Laenge nach sortieren */
			compare_function = comp_len;
        } else if (strcmp( &argv[1][1], "lexi") == 0) {
			/* Lexikographisch sortieren */
			compare_function = comp_lexi;
        } else if (strcmp (&argv[1][1], "num") == 0) {
			/* Numerisch sortieren */
            compare_function = comp_num;
        }
		first = 2;
	}
	/* Sortieren durch paarweisen Vergleich */
	for ( i = first; i < argc-1; i++)
		for (j = i+1; j < argc; j++) 	
			swap( argv, i, j, compare_function);

	if (compare_function == comp_len)
		printf("Der Laenge nach aufsteigend sortiert:\n");
    else if (compare_function == comp_lexi)
		printf("Lexikographisch aufsteigend sortiert:\n");
    else if (compare_function == comp_num)
		printf("Numerisch aufsteigend sortiert:\n");
	
    for ( i = first; i < argc; i++ )
		printf("%s\n", argv[i]);

    return 0;
}
