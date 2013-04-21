/* AP 10-sep-12 nimStrat.c				*/	
/*		Strategie fuers NIM-Spiel		*/

# include "nimStrat.h"
# include "nimData.h"
# include "nimIO.h"

int spiel_ende() {
	/* Das Spiel ist zu Ende wenn es keine Steine mehr gibt */
 	return reihe1+reihe2+reihe3 == 0;
}

void spielerwechsel() {
    if (n_spieler == 1) {
        spieler = (spieler) ? 0 : 1;
    } else {
        if (spieler == n_spieler) {
            spieler = 1;
        } else {
            spieler++;
        }
    }
}

static void ki_verlegenheitszug() {
	if (reihe3) reihe3--;
	else if (reihe2) reihe2--;
	else if (reihe1) reihe1--;
}

void ki_mache_zug() {
 	zugnummer += 1;
 	if (reihe1 > (reihe2 ^ reihe3)) 
      		reihe1 = reihe2 ^ reihe3; 
 	else if (reihe2 > (reihe1 ^ reihe3)) 
      		reihe2 = reihe1 ^ reihe3;
 	else if (reihe3 > (reihe1 ^ reihe2)) 
      		reihe3 = reihe1 ^ reihe2;
 	else 
      		ki_verlegenheitszug();
}

void mache_zug() {
    /* entscheiden, ob ki zieht oder ein reines Spiel unter Menschen */
    if (n_spieler == 1 && spieler == 0) {
        ki_mache_zug();
    } else {
        zugnummer += 1;

        struct PlayerMove move = frage_spielzug_ab(); 

        switch (move.reihe) {
            case 1: reihe1 -= move.steine;
                    break;

            case 2: reihe2 -= move.steine;
                    break;

            case 3: reihe3 -= move.steine;
                    break;
        }
    }
}
