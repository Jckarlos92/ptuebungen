import java.Math.*;

public class Bubblesort {

	public static void main (String[] args) {
		DoubleLinkedList liste = new DoubleLinkedList(100)
		for (int i=0; i<100; i++) {
			liste.addLast (new Int(Math.random()*100));
		}
		liste.sort();
		for (int i=0; i<100; i++){
			System.out.println(liste.first.obj);
		} 
	}

}