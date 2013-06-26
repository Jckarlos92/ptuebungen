import java.Math.*;

public class Bubblesort {

	public static void main (String[] args) {
		List liste = new List();
		for (int i=0; i<100; i++) {
			liste.next= new List(Math.random()*100);
		}
		
		List cursor = liste;

		for (int i=0; i<100; i++) {
			for (int j=0; j<99; j++) {
				if (cursor.getVal() < cursor.next.getVal()) {
					int temp = cursor.getVal();
					cursor.setVal(cursor.next.getVal);
					cursor.next.setVal(temp);
				}
				cursor=cursor.next;
			}
		}
	
		for (int i=0; i<100; i++) {
			System.out.println(liste.getVal());
			liste=liste.next;
		}
	}

}