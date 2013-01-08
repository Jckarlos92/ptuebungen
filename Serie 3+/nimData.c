/* AP 10-sep-12	nimData.c				*/
/*		Datendefinitionen für das NIM-Spiel	*/

# include "nimData.h"

int reihe1 = 0, reihe2 = 0, reihe3 = 0;  
int zugnummer = 0;
int spieler = 1;
int n_spieler = 2;

void init() { 
 	reihe1 = 7; reihe2 = 5; reihe3 = 7;
	zugnummer = 0;
	spieler = 1;
    n_spieler = 2;
}
