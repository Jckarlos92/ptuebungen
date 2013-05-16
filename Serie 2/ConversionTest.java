
public class ConversionTest {

	public static void main (String[] args) {
		Fahrenheit f = new Fahrenheit();
		Celsius c = new Celsius();
		System.out.println(c.convert(20.0));
		System.out.println(f.convert(68.0));
	}
}
