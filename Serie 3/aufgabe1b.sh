#!/bin/sh
# Lösung zu Aufgabe 1b aus Übung 3

## Variablen...
# Variable für maximale Wortanzahl
MAXWCOUNT=0
MAXFILE=""
SEARCHPATH=""
TMPFILE=tempfile.$RANDOM

## Die eigentlich Programmlogik
# Argumente verarbeiten
if [ $# -gt 1 ]; then
    echo "$(basename $0): Bitte das Skript mit einem oder gar keinem Argument aufrufen!"
    echo "$(basename $0): Als Argument bitte den Suchpfad angeben!"
    exit 1
elif [ $# -eq 1 ]; then
    if [ -d "$1" ]; then
        SEARCHPATH="$1"
    else
        echo "$(basename $0): Als Argument bitte den Suchpfad angeben!"
    fi
else
    SEARCHPATH="$HOME"
fi

# Die größte Datei finden
# das folgende ist ein Workaround für meine oder bash's Unfähigkeit
# das Verhalten für Dateinamen mit Leerstellen einzustellen
# Folgendes wurde ausprobiert:
# http://www.cybercity.biz/tips/handling-filenames-with-spaces-in-bash.html
# http://www.nucleardonkey.net/blog/2007/08/variable_scope_in_bash.html

find "$SEARCHPATH" -type f > $TMPFILE

while read FNAME; do
    WCOUNT=$(wc -w "$FNAME" | cut -d" " -f 1)

    if [ "$WCOUNT" -gt "$MAXWCOUNT" ]; then
        MAXWCOUNT=$WCOUNT
        MAXFILE="$FNAME"
    fi
done < $TMPFILE

rm $TMPFILE

echo "$MAXFILE ist mit $MAXWCOUNT Wörtern die größte Datei!"
