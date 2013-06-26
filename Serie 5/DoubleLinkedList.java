import java.lang.Math.*;

/* Begründung für die Wahl einer doppelt verketteten Liste:
 * ========================================================
 *
 * Ich habe Bubblesort so kennengelernt, dass man die Liste von
 * hinten nach vorne abarbeitet. Weiterhin konnten wir dadurch
 * größtenteils die Implementierung unserer Liste aus der vergangen
 * Aufgabe verwenden. Natürlich ganz im Sinne von Refactoring ;-)
 */

public class DoubleLinkedList<T extends Comparable<T>>  {
    /* ListElement-Klasse hier einnisten */
    class ListElement {
        public T val;
        public ListElement next;
        public ListElement prev;

        public ListElement(T o, ListElement n, ListElement p) {
            this.val = o;
            this.next = n;
            this.prev = p;
        }
    }

    private int capacity;
    private int elementCount;
    private ListElement first;
    private ListElement last;

    public DoubleLinkedList(int maxCapacity) {
        this.capacity = maxCapacity;
        this.elementCount = 0;
        this.first = null;
        this.last = null;
    }

    public void bubblesort() {
        boolean swapped = true;

        for (ListElement i = this.first; i != last && swapped; i = i.next) {
            swapped = false;
            for (ListElement j = this.last; j != i; j = j.prev) {
                if (j.val.compareTo(j.prev.val) == -1) {
                    T temp = j.val;
                    j.val = j.prev.val;
                    j.prev.val = temp;
                    swapped = true;
                }
            }

            if (!swapped) break;
        }

    }

    public void print() {
        for (ListElement i = this.first; i != this.last; i = i.next) {
            System.out.println(i.val);
        }
    }

    public int capacity() {
        return this.capacity;
    }

    public int size() {
        return this.elementCount;
    }

    public void clear() {
        this.first = null;
        this.last = null;
    }

    public void addFirst(T e) throws Exception  {
        if (elementCount+1 > capacity) {
            throw new Exception("Liste ist voll!");
        }

        ListElement newFirstElement = new ListElement(e, this.first, null);
        
        if (first != null)
            this.first.prev = newFirstElement;

        this.first = newFirstElement;

        if (++elementCount == 1) {
            this.last = this.first;
        }
    }

    public void addLast(T e) throws Exception  {
        if (elementCount+1 > capacity) {
            throw new Exception("Liste ist leer!");
        }

        ListElement newLastElement = new ListElement(e, null, this.last);
        
        if (last != null)
            this.last.next = newLastElement;

        this.last = newLastElement;
        
        if (++elementCount == 1) {
            this.first = this.last;
        }
    }

    public T removeFirst() throws Exception  {
        if (elementCount == 0) {
            throw new Exception("Liste ist leer!");
        }
        
        T ret = this.first.val;
        this.first = this.first.next;
        
        if (this.first != null) this.first.prev = null;
        
        if (--elementCount == 1) {
            this.last = this.first;
            this.last.prev = null;
            this.last.next = null;
        }

        return ret;
    }

    public T removeLast() throws Exception {
        if (elementCount == 0) {
            throw new Exception("Liste ist leer!");
        }
        
        T ret = this.last.val;
        this.last = this.last.prev;
        this.last.next = null;
        
        if (--elementCount == 1) {
            this.first = this.last;
            this.first.next = null;
            this.first.prev = null;
        }

        return ret;
    }
}

