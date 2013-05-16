import TempConv.Fahrenheit;

public class F2C {
	public static void main (String[] args) {
		Fahrenheit f = new Fahrenheit();

        for (int i=0; i < args.length; ++i) {
            System.out.printf("%s °F => %.2f °C\n", args[i], f.convert(Double.parseDouble(args[i])));
        }
	}
}
