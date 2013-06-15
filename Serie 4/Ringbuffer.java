import de.uni_potsdam.hpi.*;

public class Ringbuffer implements Deque {
    private int capacity;
    private int first;
    private int last;
    private Object[] oblist;

    public Ringbuffer(int capacity) {
        this.capacity = capacity;
        this.first = this.last = 0;
        oblist = new Object[capacity];
    }

    public int capacity() {
        return capacity;
    }

    public int size() {
        return last-first;
    }

    public void clear() {
        oblist = new Object[capacity];
    }

    public void addFirst(Object e) throws DequeFull {
        if (isFull()) {
            throw new DequeFull();
        }

        if (first-1 < 0) {
            // Den Ring simulieren, und wieder zum Anfang springen
            first = Math.abs(--first) % capacity;
        }
        
        oblist[first] = e;
    }

    public void addLast(Object e) throws DequeFull {
        if (isFull()) {
            throw new DequeFull();
        }

        if (last+1 > capacity-1) {
            // Den Ring simulieren, und wieder zum Anfang springen
            last = (++last) % capacity;
        }
        
        oblist[last] = e;
    }

    public Object removeFirst() throws DequeEmpty {
        if (isEmpty())
            throw new DequeEmpty();

        Object retObject = oblist[first];
        oblist[first] = null;

        if (first+1 > capacity-1) {
            first = (++first)%capacity;
        }

        return retObject;
    }

    public Object removeLast() throws DequeEmpty {
        if (isEmpty())
            throw new DequeEmpty();

        Object retObject = oblist[last];
        oblist[last] = null;

        if (last-1 < 0) {
            last = Math.abs(--last)%capacity;
        }

        return retObject;
    }

    private boolean isFull() {
        return (Math.abs(last-first)+1 == capacity);
    }

    private boolean isEmpty() {
        return !isFull();
    }
}

