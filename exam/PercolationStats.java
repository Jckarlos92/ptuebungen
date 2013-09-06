public class PercolationStats {
    public PercolationStats(int N, int T) {
        // perform T independent computational experiments on an N-by-N grid
    }
    public double mean() {
        // sample mean of percolation threshold
    }
    public double stddev() {
        // sample standard deviation of percolation threshold
    }
    public double confidenceLo() {
        // returns lower bound of the 95% confidence interval
    }
    public double confidenceHi() {
        // returns upper bound of the 95% confidence interval
    }
    public static void main(String[] args)   
        if (args.length != 2) {
            return;
        }

        int gridSize    = String.parseIntger(args[0]);
        int repetitions = String.parseIntger(args[1]);
    }
}
