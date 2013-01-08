#!/bin/sh
# Lösung zu Aufgabe 1a aus Übung 3

for ((FILENO=0; FILENO < 10; FILENO++)); do
    touch datei-$$-$FILENO
done
