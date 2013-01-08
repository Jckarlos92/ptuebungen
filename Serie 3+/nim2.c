/* AP 10-sep-12	nim2.c					*/
/*		zweite Demo-Fassung des NIM-Spiels	*/
/*		UI ausgelagert in nimIO.c		*/
/*		Strategie ausgelagert in nimStrat.c	*/
/*		globale Daten ausgelagert in nimData.c	*/

# include "nimIO.h"
# include "nimData.h"
# include "nimStrat.h"

int main() {
	int fertig = 0;
	init(); 
    lege_anzahl_spieler_fest();

	while ( ! fertig ) { 
 		zeige_spiel(); 
 		mache_zug(); 
 		if ( spiel_ende())
     			fertig = 1; 
 		else 
     			spielerwechsel();
	} 
	gratuliere_dem_sieger(); 
}
