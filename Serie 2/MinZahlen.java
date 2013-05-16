
public class MinZahlen {

	public static void main (String[] args) {
		int temp;
		int min;

		System.out.println("Zahl eingeben:");
		In.init();
		temp = In.getInt();
		min = temp;

		while (temp >= 0) {
			if (temp < min) {
				min = temp;
			}
			System.out.println("Zahl eingeben:");
			temp = In.getInt();
		}
		if (min < 0) {
			System.out.println("Keine gültige Eingabe erfolgt.");
		} else {
			System.out.println("Die kleinste Zahl ist "+min);
		}
	}
}
