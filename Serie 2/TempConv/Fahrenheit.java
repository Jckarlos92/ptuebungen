package TempConv;

public class Fahrenheit extends Conversion {
	
	public double convert (double val) {
		return ((val - 32)*5)/9;
	}
}
