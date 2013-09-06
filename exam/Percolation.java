import QuickUnionUF;

public class Percolation {
    /* ---- public methods ------------------- */
    public Percolation(int N) {
        /* every entry in openArray marks a single site
         * the boolean value indicates wether this site is opened or not */
        boolean[] openArray = new boolean[N][];

        for (int i=0; i < N; ++i) {
            openArray[N] = new boolean[N];

            for (int j=0; j < N; ++j) openArray[j] = false;
        }

        /* create an N+2 sized array with QuickUnionUF
         * inside which the index 0 will mark the source
         * and index N+1 the drain */
        WeightedQuickUnionUF uf = new WeightedQuickUnionUF(N+2);
    }

    public void open(int i, int j) {
         // open site (row i, column j) if it is not already
    }

    public boolean isOpen(int i, int j) {
        // is site (row i, column j) open?
        return false;
    }

    public boolean isFull(int i, int j) {
        // is site (row i, column j) full?
        return false;
    }

    public boolean percolates() {
        // does the system percolate?
        return false;
    }

    /* ---- private methods ------------------ */
    /* ---- private attributes --------------- */
    int[][] openArray;
}

