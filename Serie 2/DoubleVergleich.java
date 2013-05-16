
public class DoubleVergleich {

	public static void main (String[] args) {
		double a = 0.0;
		double b = 0.1;

		for (int i=0; i<10; i++) {
			a = a + b;
		}
		System.out.println(a == 1.0);
		System.out.println(a);
	}
}
/* Zu Frage 1:
 * Da 0.1 ein periodischer Binärbruch der Form 0.000110011001100110011... etc.
 * ist, kann es vom Rechner nicht exakt dargestellt werden. Aufgrund des
 * Darstellungsfehler erhält für a nicht 1 sondern 0,9999..., was im Vergleich
 * mit 1.0 natürlich false ergibt.
 *
 * Zu Frage 2:
 * Die beste Möglichkeit wäre, eine Toleranzgrenze für solche Fehler zu finden.
 * So könnte man die Differenz aus dem Rechenergebnis und dem erwarteten
 * Ergebnis bilden und mit dieser Toleranzgrenze vergleichen.  Ist der Fehler
 * im Toleranzbereich, so kann das Ergebnis als gleich betrachtet werden,
 * andernfalls eben nicht.
 * */
