import java.io.*;

public class findMinimum {

    public static void main(String args[]) {
        int minimum = Integer.MAX_VALUE;
        int tmp = minimum;

        System.out.println("Guuude");

        do {
            if (tmp < minimum) minimum = tmp;
            
            System.out.print("Gib eine Zahl ein: ");
            
            tmp = In.getInt();

        } while (tmp > 0);

        System.out.printf("Das gefundene Minimum ist: %d\n", minimum);
    }
}
