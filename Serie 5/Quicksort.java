import java.util.Random;

/* Empirische Messsung:
 * ====================
 * Um eine unsortierte Menge von 150000 zufälligen
 * Elementen zu sortieren, benötigt der Algorithmus 36271805ns = 36,2718ms.
 * Die Laufzeit im schlimmsten Falle (also auf einer schon sortierten Menge)
 * ließ sich erst ermitteln, nachdem die Stack-Größe angehoben wurde. Sonst
 * kam es zum Stack-Overflow. Damit dauerte das Sortieren auf einer schon sortierten
 * Menge 8194970143ns = 8194,96ms = 8,195s */

class Quicksort {	
    public static void main(String[] args) {
        System.out.println("Empirischer Vergleich von Quicksort-Laufzeiten");
        System.out.println("    auf sortierten und unsortierten Mengen");
        System.out.println("==============================================");

        int n      = 150000;
        int iArr[] = new int[n];
        Random randomGen = new Random();

        /* erzeuge Normalfall */
        for (int i = 0; i < n; i++)
            iArr[i] = randomGen.nextInt();

        long averageCasebegin = java.lang.System.nanoTime();
        quicksort(iArr, 0, n-1);
        long averageCasetime = java.lang.System.nanoTime() - averageCasebegin;
        
        /* erzeuge worst-case Szenario */
        for (int i = 0; i < n; ++i)
            iArr [i] = i;

        long worstCasebegin = java.lang.System.nanoTime();
        quicksort(iArr, 0, n-1);
        long worstCasetime = java.lang.System.nanoTime() - worstCasebegin;


        System.out.println("Laufzeit auf unsortierter Menge: " + averageCasetime + "ns" );
        System.out.println("Laufzeit auf   sortierter Menge: " + worstCasetime + "ns" );
    }

    static void quicksort(int[] array, int left, int right) { 
        if (right <= left)
            return;

        int pivotIndex = partition(array, left, right);

        quicksort(array, left, pivotIndex-1);
        quicksort(array, pivotIndex+1, right);
    }

    static int partition(int a[], int left, int right) {
        int i = left-1;
        int j = right;
        int tmp;

        while(true) { 
            for (++i; a[i] < a[right]; ++i);

            for (--j; a[right] < a[j]; --j) {
                if (j == left)
                    break;
            }

            if (i >= j) break;

            tmp = a[i];
            a[i]    = a[j];
            a[j]    = tmp;
        }
            
       tmp      = a[i];
       a[i]     = a[right];
       a[right] = tmp;
       
       return i;
    }
}
