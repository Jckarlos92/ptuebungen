import java.util.Random;

public class BubblesortTest {

	public static void main (String[] args) throws Exception {
		DoubleLinkedList<Integer> liste = new DoubleLinkedList<Integer>(10);
        Random rn = new Random();

		for (int i=0, j = rn.nextInt(); i<j; i++) {
			liste.addLast (new Integer(rn.nextInt()));
		}

        System.out.println("UNSORTIERT:");
        liste.print();
		liste.sort();
        System.out.println();
        System.out.println("SORTIERT:");
        liste.print();
	}

}
