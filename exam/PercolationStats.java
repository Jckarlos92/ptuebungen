import java.util.Random;
import java.lang.Math;

public class PercolationStats {

    /* ---- public methods ------------------- */
    public PercolationStats(int N, int T) throws java.lang.IllegalArgumentException {
        if (N <= 0 || T <= 1) {
            throw new java.lang.IllegalArgumentException("Illegal Argument dude!");
        }

        double fields  = N*N;

        repetitions = T;
        mean        = 0.0;
        stddev      = 0.0;

        double tmp;
        double[] estimateArray = new double[T];

        // perform T independent computational experiments on an N-by-N grid
        for (int rep = 0; rep < T; ++rep) {
            Percolation p = new Percolation(N);
            int openSites = 0;

            while (!p.percolates()) {
                int row = StdRandom.uniform(0,N) + 1 ;
                int col = StdRandom.uniform(0,N) + 1 ;

                if (!p.isOpen(row,col)) {
                    p.open(row,col);
                    ++openSites;
                }
            }

            tmp   = openSites/fields;
            estimateArray[rep] = tmp;
        }

        mean   = StdStats.mean(estimateArray);
        stddev = StdStats.stddev(estimateArray);
        sigma  = Math.sqrt(stddev);
        sqrtT  = Math.sqrt(T);
    }
    public double mean() {
        // sample mean of percolation threshold
        return this.mean;
    }
    public double stddev() {
        // sample standard deviation of percolation threshold
        return this.stddev;
    }
    public double confidenceLo() {
        // returns lower bound of the 95% confidence interval
        return mean - (1.96 * sigma)/sqrtT;
    }
    public double confidenceHi() {
        // returns upper bound of the 95% confidence interval
        return mean + (1.96 * sigma)/sqrtT;
    }
    public static void main(String[] args) {
        if (args.length != 2) {
            return;
        }

        PercolationStats ps = new PercolationStats(Integer.parseInt(args[0]), Integer.parseInt(args[1]));

        StdOut.println("mean                    = " + ps.mean());
        StdOut.println("stddev                  = " + ps.stddev());
        StdOut.println("95% confidence interval = " + ps.confidenceLo() + ", " + ps.confidenceHi());
    }

    /* ---- private attributes --------------- */
    private int repetitions;
    private double mean, stddev;
    private double sigma, sqrtT;
}
