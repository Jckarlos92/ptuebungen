import java.util.Random;

public class BubblesortTest {

	public static void main (String[] args) throws Exception {
		DoubleLinkedList<Integer> liste = new DoubleLinkedList<Integer>();
        Random rn = new Random();

		for (int i=0, j = rn.nextInt()%1000; i<10; i++) {
			liste.addLast (new Integer(rn.nextInt()));
		}

        System.out.println("UNSORTIERT:");
        liste.print();
		liste.bubblesort();
        System.out.println();
        System.out.println("SORTIERT:");
        liste.print();
	}

}
