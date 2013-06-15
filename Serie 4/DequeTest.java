import de.uni_potsdam.hpi.Deque;

class DequeTest {
    public static void main(String args[]) throws Exception {
        Deque ringBuffer = new Ringbuffer(1000);
        Deque doubleLinkedList = new DoubleLinkedList(1000);

        for (int i=0; i<500; ++i) {
            ringBuffer.addLast(new Object());
            doubleLinkedList.addLast(new Object());
        }

    }
}
