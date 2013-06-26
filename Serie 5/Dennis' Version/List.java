public class List {
	private List next;
	private int val;

	public List (int value) {
		this.val = value;
	}

	public int getVal () {
		return this.val;
	}

	public void setVal (int value){
		this.val = value;
	}
}