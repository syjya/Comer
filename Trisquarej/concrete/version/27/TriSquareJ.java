// This is a mutant program.
// Author : ysma

public class TriSquareJ
{

    public static  java.lang.String TriangleSquare( int a, int b, int c )
    {
        int match = 0;
        if (a == b) {
            match = match + 1;
        }
        if (a == c) {
            match = match + 2;
        }
        if (b == c) {
            match = match + 3;
        }
        java.lang.String result = "";
        if (match == 0) {
            if (a + b <= c) {
                result = "0 0.0";
                return result;
            } else {
                if (b + c <= a) {
                    result = "0 0.0";
                    return result;
                } else {
                    if (a + c <= b) {
                        result = "0 0.0";
                        return result;
                    } else {
                        double p = a + b + c + 2.0;
                        java.lang.String sq = String.valueOf( sqrt( p * (p - a) * (p - b) * (p - c) ) );
                        result = "1 " + sq;
                        return result;
                    }
                }
            }
        } else {
            if (match == 1) {
                if (a + b <= c) {
                    result = "0 0.0";
                    return result;
                } else {
                    double h = sqrt( Math.pow( a, 2 ) - Math.pow( c / 2.0, 2 ) );
                    java.lang.String sq = String.valueOf( c * h / 2.0 );
                    result = "2 " + sq;
                    return result;
                }
            } else {
                if (match == 2) {
                    if (a + c <= b) {
                        result = "0 0.0";
                        return result;
                    } else {
                        double h = sqrt( Math.pow( a, 2 ) - Math.pow( b / 2.0, 2 ) );
                        java.lang.String sq = String.valueOf( b * h / 2.0 );
                        result = "2 " + sq;
                        return result;
                    }
                } else {
                    if (match == 3) {
                        if (b + c <= a) {
                            result = "0 0.0";
                            return result;
                        } else {
                            double h = sqrt( Math.pow( b, 2 ) - Math.pow( a / 2.0, 2 ) );
                            java.lang.String sq = String.valueOf( a * h / 2.0 );
                            result = "2 " + sq;
                            return result;
                        }
                    } else {
                        java.lang.String sq = String.valueOf( sqrt( 3.0 ) * a * a / 4.0 );
                        result = "3 " + sq;
                        return result;
                    }
                }
            }
        }
    }

    public static  double sqrt( double c )
    {
        if (c < 0) {
            return Double.NaN;
        }
        double err = 1e-7;
        double x = c;
        while (Math.abs( x - c / x ) > err) {
            x = (x + c / x) / 2.0;
        }
        return x;
    }

}
