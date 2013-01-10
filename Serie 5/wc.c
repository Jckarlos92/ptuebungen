# include <stdio.h>

int main (int, char**) {
    /* CharacterCount, WordCount, LineCount */
    int workingChar;
    unsigned int cc=0, wc=0, lc=0; 

    while ((workingChar = getchar()) != EOF) {
        if ((char)workingChar == '\n') {
            if (wc == 0) {
                /* wenn ein Zeilenumbruch gefunden wurde, dann existieren schon zwei Zeilen!*/
                ++wc;
            }
            ++lc;
        } else if ((char)workingChar == ' ') {
            if (wc == 0) {
                /* wenn eine Leerstelle gefunden wurde, dann existieren schon zwei Wörter!*/
                ++wc;
            }
            ++wc;
        } else {
            ++cc;
        }
    }

    printf("Zeichen: %ud\n", cc);
    printf("Wörter : %ud\n", wc);
    printf("Zeilen : %ud\n", lc);

    return 0;
}
