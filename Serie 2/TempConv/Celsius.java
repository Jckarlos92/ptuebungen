package TempConv;

public class Celsius extends Conversion {

	public double convert (double val) {
		return ((9*val)/5) + 32;
	}
}
