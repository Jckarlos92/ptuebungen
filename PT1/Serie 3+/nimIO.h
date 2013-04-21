/* AP 10-sep-12	nimIO.h					*/
/*		UI-Deklarationen fuer das NIM-Spiel	*/

struct PlayerMove{
    int reihe;
    int steine;
} ;

void zeige_spiel(); 
void gratuliere_dem_sieger();
void lege_anzahl_spieler_fest(void);
struct PlayerMove frage_spielzug_ab(void);
