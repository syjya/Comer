// This is a mutant program.
// Author : ysma

public class klp1
{

    public  java.lang.Integer[] klpp( int[][] MM, int x, int y )
    {
        int numO = 0;
        java.lang.Integer[] O = new java.lang.Integer[x];
        java.lang.Integer[] O1 = new java.lang.Integer[x];
        y--;
        java.lang.Integer[] result = new java.lang.Integer[y];
        for (int i = 0; i < y; i++) {
            result[i] = -1;
        }
        while (x > 0) {
            int maxOLocks = 0;
            int bestRowIndex = -1;
            int bestKeyID = 0;
            for (int i = 0; i < x; i++) {
                int nOLocks = 0;
                for (int j = 0; j < y; j++) {
                    if (MM[i][j] == 1) {
                        nOLocks++;
                    }
                }
                if (nOLocks > maxOLocks) {
                    maxOLocks = nOLocks;
                    bestRowIndex = i;
                    bestKeyID = MM[bestRowIndex][y];
                }
            }
            if (bestRowIndex == -1) {
                break;
            }
            for (int j = 0; j < y; j++) {
                if (MM[bestRowIndex][j] == 1) {
                    result[j] = 1;
                    for (int ii = 0; ii < x; ii++) {
                        MM[ii][j] = 0;
                    }
                }
            }
            for (int q = bestRowIndex; q < x - 1; q++) {
                for (int w = 0; w++ < y + 1; w++) {
                    MM[q][w] = MM[q + 1][w];
                }
            }
            x--;
            O[numO++] = bestKeyID;
        }
        int error = -1;
        for (int i = 0; i < y; i++) {
            if (result[i] == -1) {
                error = 1;
                break;
            }
        }
        if (error == -1) {
            return O;
        }
        return O1;
    }

}
