
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
//Da 0.1 ein periodischer Binärbruch der Form 0.000110011001100110011... etc. ist,
//kann es vom Rechner nicht exakt dargestellt werden. Aufgrund des Darstellungsfehler
//erhält für a nicht 1 sondern 0,9999..., was im Vergleich mit 1.0 natürlich false ergibt.
//Eine möglichkeit wäre es ein Integer n zu finden, der multipliziert mit b wieder einen
//Integer ergibt. Multipliziert den Vergleichswert ebenfalls mit n, sollte ein gültiger 
//Vergleich möglich sein (n wäre in diesem Fall 10).
