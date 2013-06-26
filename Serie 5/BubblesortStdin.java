import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BubblesortStdin {
    public static void main(String[] args) {
        DoubleLinkedList<String> dll = new DoubleLinkedList<String>();
        BufferedReader            br = new BufferedReader(new InputStreamReader(System.in));
        String input;

        try {
            while ((input = br.readLine()) != null) {
                dll.addLast(input);
            }

            System.out.println();
            System.out.println("=== Ende der Eingabe ========");
            System.out.println("=== Beginn der Sortierung ===");
            System.out.println();

            dll.bubblesort();
            dll.print();
        } catch (Exception e) {
            System.out.println("Etwas ist schiefgelaufen: " + e.getMessage());
        }
    }
}
