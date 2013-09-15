
public class Percolation {
    /* ---- public methods ------------------- */
    public Percolation(int N) {
        /* every entry in openArray marks a single site
         * the boolean value indicates wether this site is opened or not */
        fieldWidth = N;
        isOpenArray = new boolean[N*N];

        for (int i=0; i < isOpenArray.length; ++i) {
            isOpenArray[i] = false;
        }

        // we have n² fields
        // additionally, we have one source field, from which the liquid flows
        // and one drain field were we want the liquid to go
        uf = new WeightedQuickUnionUF(N*N + 2);
    }

    public void open(int i, int j) {
         // open site (row i, column j) if it is not already
        isOpenArray[calculateIndex(i,j)] = true;

        // we need to add one to obtain the index inside the WeightedUnion
        int ugIndex = calculateIndex(i,j)+1;

        // connect with source if neccessary
        if (i == 1) {
            uf.union(0, ugIndex);
        }

        // check environment of field
        // upside
        if (i > 1) {
            if (isOpenArray[calculateIndex(i-1,j)]) {
                uf.union(calculateIndex(i-1,j)+1, ugIndex);
            }
        }

        // right
        if (j < fieldWidth) {
            if (isOpenArray[calculateIndex(i,j+1)]) {
                uf.union(calculateIndex(i,j+1)+1, ugIndex);
            }
        }

        // downside
        if (i < fieldWidth) {
            if (isOpenArray[calculateIndex(i+1,j)]) {
                uf.union(calculateIndex(i+1,j)+1, ugIndex);
            }
        }

        // left
        if (j-1 >= 1) {
            if (isOpenArray[calculateIndex(i,j-1)]) {
                uf.union(calculateIndex(i,j-1)+1, ugIndex);
            }
        }

        // connect to drain
        // by doing it this way we avoid the backwash
        if (isFull(i,j)) {
            for (int c=1; c <= fieldWidth; ++c) {
                if (uf.connected(ugIndex, calculateIndex(fieldWidth, c)+1)) {
                    uf.union(calculateIndex(fieldWidth, c)+1, fieldWidth*fieldWidth + 1);
                    break;
                }
            }
        }
    }

    public boolean isOpen(int i, int j) {
        // is site (row i, column j) open?
        return isOpenArray[calculateIndex(i,j)];
    }

    public boolean isFull(int i, int j) {
        // is site (row i, column j) full?
        // assumption: check for connection with source (which lies at index 0)
        return uf.connected(0, calculateIndex(i,j)+1);
    }

    public boolean percolates() {
        // does the system percolate?
        //return false;
        return uf.connected(0, fieldWidth*fieldWidth+1);
    }

    /* ---- private methods ------------------ */
    private int calculateIndex(int i, int j) {
        return (i-1)*fieldWidth + (j-1);
    }
    /* ---- private attributes --------------- */
    private int       fieldWidth;
    private boolean[] isOpenArray;
    private WeightedQuickUnionUF uf;
}

