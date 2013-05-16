import TempConv.Celsius;

public class C2F {
	public static void main (String[] args) {
		Celsius c = new Celsius();

        for (int i=0; i < args.length; ++i) {
            System.out.printf("%s °C => %.2f °F\n", args[i], c.convert(Double.parseDouble(args[i])));
        }
	}
}
