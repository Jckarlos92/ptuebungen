public class DoubleLinkedList  {
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

    public sort () {
        boolean swapped = false;

        for (ListElement i = this.first; i != last && swapped; i = i.next) {
            for (ListElement j = this.last; j != i.next; j = j.prev) {
                if (j.obj < j.prev.obj) {
                    Object temp = j.obj;
                    j.obj = j.prev.obj;
                    j.prev.obj = temp;
                    swapped = true;
                }
            }
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

    public void addFirst(Object e) throws Exception  {
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

    public void addLast(Object e) throws Exception  {
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

    public Object removeFirst() throws Exception  {
        if (elementCount == 0) {
            throw new Exception("Liste ist leer!");
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

    public Object removeLast() throws Exception {
        if (elementCount == 0) {
            throw new Exception("Liste ist leer!");
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
