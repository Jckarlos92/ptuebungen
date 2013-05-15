import java.io.*;

class gleitkommaTest {
    public static void main(String args[]) {
        double a = 0.1;
        double b = 0;

        System.out.println("Aufsummieren von 0.1 auf 0...10 mal");
        for (int i = 0; i < 10; ++i) {
            b += a;
        }

        System.out.printf("Ergebnis des Vergleiches der Summe mit 1.0: %b", b == 1.0);
    }
}
