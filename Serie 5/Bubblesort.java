import java.util.Random;

public class Bubblesort {

	public static void main (String[] args) throws Exception {
		DoubleLinkedList liste = new DoubleLinkedList(10);
        Random rn = new Random();

		for (int i=0, j = rn.nextInt(); i<10; i++) {
			liste.addLast (rn.nextInt() % 1000);
		}

        System.out.println("UNSORTIERT:");
        liste.print();
		liste.sort();
        System.out.println("SORTIERT:");
        liste.print();
	}

}
