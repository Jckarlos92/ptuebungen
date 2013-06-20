import de.uni_potsdam.hpi.Deque;

class DequeTest {
    public static void main(String args[]) throws Exception {
        Deque ringBuffer = new Ringbuffer(1000);
        Deque doubleLinkedList = new DoubleLinkedList(1000);

        /* benchmark Ringbuffer */
        long startTick = java.lang.System.nanoTime();
        
        for (int i=0; i<500; ++i) {
            ringBuffer.addLast(new Object());
        }

        long middleTick = java.lang.System.nanoTime(); 
        
        for (int i=0; i<500; ++i) {
            ringBuffer.removeLast();
            ringBuffer.addLast("");
        }

        long endTick = java.lang.System.nanoTime();
    
        /* benchmark DoubleLinkedList */
        long startTick2 = java.lang.System.nanoTime();
        
        for (int i=0; i<500; ++i) {
            doubleLinkedList.addLast(new Object());
        }
        
        long middleTick2 = java.lang.System.nanoTime(); 
        
        for (int i=0; i<500; ++i) {
            doubleLinkedList.removeLast();
            doubleLinkedList.addLast("");
        }

        long endTick2 = java.lang.System.nanoTime();

        System.out.println("Total runtime of benchmark for RingBuffer: " + (endTick - startTick) + "ns");
        System.out.println("\tInserting 500 elements: " + (middleTick - startTick) + "ns");
        System.out.println("\tDeleting and inserting 500 times: " + (endTick - middleTick) + "ns");
        System.out.println("\tAverage time for inserting and deleting one element: " + (endTick - middleTick)/500 + "ns");
        System.out.println("Total runtime of benchmark for DoubleLinkedList: " + (endTick2 - startTick2) + "ns");
        System.out.println("\tInserting 500 elements: " + (middleTick2 - startTick2) + "ns");
        System.out.println("\tDeleting and inserting 500 times: " + (endTick2 - middleTick2) + "ns");
        System.out.println("\tAverage time for inserting and deleting one element: " + (endTick2 - middleTick2)/500 + "ns");
    }
}
