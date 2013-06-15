import de.uni_potsdam.hpi.*;

public class DoubleLinkedList implements Deque {
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

    public void addFirst(Object e) throws DequeFull {
        if (elementCount+1 > capacity) {
            throw new DequeFull();
        }

        ListElement newFirstElement = new ListElement(e, this.first, null);
        
        if (first != null)
            this.first.prev = newFirstElement;

        this.first = newFirstElement;

        if (++elementCount == 1) {
            this.last = this.first;
        }
    }

    public void addLast(Object e) throws DequeFull {
        if (elementCount+1 > capacity) {
            throw new DequeFull();
        }

        ListElement newLastElement = new ListElement(e, null, this.last);
        
        if (last != null)
            this.last.next = newLastElement;

        this.last = newLastElement;
        
        if (++elementCount == 1) {
            this.first = this.last;
        }
    }

    public Object removeFirst() throws DequeEmpty {
        if (elementCount == 0) {
            throw new DequeEmpty();
        }
        
        Object retObj = this.first.obj;
        this.first = this.first.next;
        
        if (this.first != null) this.first.prev = null;
        
        if (--elementCount == 1) {
            this.last = this.first;
            this.last.prev = null;
            this.last.next = null;
        }

        return retObj;
    }

    public Object removeLast() throws DequeEmpty {
        if (elementCount == 0) {
            throw new DequeEmpty();
        }
        
        Object retObj = this.last.obj;
        this.last = this.last.prev;
        this.last.next = null;
        
        if (--elementCount == 1) {
            this.first = this.last;
            this.first.next = null;
            this.first.prev = null;
        }

        return retObj;
    }
}

class ListElement {
    public Object obj;
    public ListElement next;
    public ListElement prev;

    public ListElement(Object o, ListElement n, ListElement p) {
        this.obj = o;
        this.next = n;
        this.prev = p;
    }
}
