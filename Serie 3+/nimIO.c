/* AP 10-sep-12	nimIO.c					*/
/*		UI fuer das NIM-Spiel  			*/
# include <stdio.h>
# include "nimIO.h"
# include "nimData.h"

void zeige_spiel() { 
 	/* Ausgabe des Spielfelds auf die Standardausgabe */ 
	int i;
	printf("Spieler %d, Zug %d: ", spieler, zugnummer );
	printf("\t");
	for (i = 0; i < reihe1; i++) printf("*"); 
	printf("\t");
	for (i = 0; i < reihe2; i++) printf("*"); 
	printf("\t");
	for (i = 0; i < reihe3; i++) printf("*"); 
	printf("\n");
}

void gratuliere_dem_sieger() { 
	/* gewonnen hat, wer den letzten Zug gemacht hat; */
	/* dieser Wert ist noch in Variable spieler gespeichert */
	printf("Gewonnen hat Spieler %d - \t", spieler );
	printf("Herzlichen Glückwunsch\n" );
}

void lege_anzahl_spieler_fest(void) {
    char n_char;
   
    printf("Bitte die Anzahl der teilnehmenden Spieler eingeben: ");
    n_char = getchar();
    getchar(); /* zeilenumbruch entfernen */

    while (n_char < '0' || '9' < n_char) {
        printf("Bitte die Anzahl der teilnehmenden Spieler erneut eingeben: ");
        n_char = getchar();
        getchar(); /* zeilenumbruch entfernen */
    } 
    n_spieler = n_char - '0';
}

struct PlayerMove frage_spielzug_ab(void) {
    char ch_reihe;
    char ch_steine;
    int *reihe = NULL;

    printf("SPIELER %i > Reihe auswählen: ", spieler);
    ch_reihe = getchar();
    getchar(); /* zeilenumbruch entfernen */

    while (ch_reihe < '1' || '3' < ch_reihe) {
        printf("Bitte die ausgewählte Reihe erneut eingeben: ");
        ch_reihe = getchar();
        getchar(); /* zeilenumbruch entfernen */
    }

    printf("SPIELER %i > Anzahl der zu entfernenden Steine eingeben: ", spieler);
    ch_steine = getchar();
    getchar();

    /* gewählte Reihe herausfinden */
    switch (ch_reihe - '0') {
        case 1: reihe = &reihe1; break;
        case 2: reihe = &reihe2; break;
        case 3: reihe = &reihe3; break;
    }
    
    /* keine zu große Anzahl an Steinen zulassen */
    if (ch_steine > ('0' + *reihe)) {
        ch_steine = '0';
    }

    while (ch_steine < '1' || '9' < ch_steine) {
        printf("Bitte die Anzahl erneut eingeben: ");
        ch_steine = getchar();
        getchar(); /* zeilenumbruch entfernen */

        /* keine zu große Anzahl an Steinen zulassen */
        if (ch_steine > ('0' + *reihe)) {
            ch_steine = '0';
        }
    }

    struct PlayerMove pm;
    pm.reihe = ch_reihe - '0';
    pm.steine = ch_steine - '0';


    return pm;
}
