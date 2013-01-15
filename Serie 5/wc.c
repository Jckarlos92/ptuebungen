# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

int main (/*@unused@*/int argc,/*@unused@*/char** argv) {
    /* CharacterCount, WordCount, LineCount */
    int workingChar; 
    int lastChar = (int)'\n';
    unsigned int cc=0, wc=0, lc=0; 

    while ((workingChar = getchar()) != EOF) {
        if ((char)workingChar == '\n') {
            ++lc;
        } else if  (((char)workingChar == ' ' && isgraph(lastChar)) ||
                   ((char)lastChar == '\n' && isgraph(workingChar))) {
            ++wc;
        } 

        ++cc;
        lastChar = workingChar;
    }

    printf("Zeichen: %u\n", cc);
    printf("Wörter : %u\n", wc);
    printf("Zeilen : %u\n", lc);

    return 0;
}
