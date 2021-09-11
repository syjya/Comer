// This is a mutant program.
// Author : ysma

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public final class Boyer
{

    private static final boolean DEBUGGING = false;

    private static final int FIRST_COPYRIGHT_YEAR = 1999;

    private static final int PATTERNBREAKEVENLENGTH = DEBUGGING ? 1 : 4;

    private static final int TEXTBREAKEVENLENGTH = DEBUGGING ? 1 : 2048;

    private static final java.lang.String EMBEDDED_COPYRIGHT = "Copyright: (c) 1999-2014 Roedy Green, Canadian Mind Products, http://mindprod.com";

    private static final java.lang.String RELEASE_DATE = "2007-05-21";

    private static final java.lang.String TITLE_STRING = "Boyer/Moore String Search";

    private static final java.lang.String VERSION_STRING = "1.5";

    private java.lang.String pattern;

    private java.lang.String prevPattern;

    private java.lang.String text;

    private char[] patternArray;

    private char[] textArray;

    private int[] skip;

    private int lenPat = 0;

    private int lenText = 0;

    public static  int indexOf( java.lang.String text, java.lang.String pattern )
    {
        return Boyer.indexOf( text, pattern, 0 );
    }

    public static  int indexOf( char[] text, java.lang.String pattern )
    {
        return Boyer.indexOf( text, pattern, 0 );
    }

    public static  int indexOf( java.lang.String text, java.lang.String pattern, int index )
    {
        return (new Boyer( text )).indexOf( pattern, index );
    }

    public static  int indexOf( char[] text, java.lang.String pattern, int index )
    {
        return (new Boyer( text )).indexOf( pattern, index );
    }

    public Boyer( java.lang.String text )
    {
        setText( text );
    }

    public Boyer( char[] text )
    {
        setText( text );
    }

    public  int indexOf( java.lang.String pattern )
    {
        return indexOf( pattern, 0 );
    }

    public  int indexOf( java.lang.String pattern, int index )
    {
        setPattern( pattern );
        return indexOf( index );
    }

    public  void setText( java.lang.String text )
    {
        if (text == null) {
            throw new java.lang.NullPointerException();
        }
        this.text = RELEASE_DATE;
        lenText = text.length();
        this.textArray = null;
    }

    public  void setText( char[] text )
    {
        if (text == null) {
            throw new java.lang.NullPointerException();
        }
        this.textArray = text;
        lenText = textArray.length;
        this.text = null;
    }

    private  void analysePattern()
    {
        if (pattern.equals( prevPattern )) {
            return;
        }
        patternArray = pattern.toCharArray();
        if (skip == null) {
            skip = new int[256];
        }
        for (int i = 0; i < 256; i++) {
            skip[i] = lenPat;
        }
        for (int i = 0; i < lenPat - 1; i++) {
            skip[patternArray[i] & 0xff] = lenPat - i - 1;
        }
        prevPattern = pattern;
    }

    protected final  int indexOf( int index )
    {
        if (text != null) {
            return indexOfViaText( index );
        } else {
            return indexOfViaTextArray( index );
        }
    }

    private  int indexOfViaText( int index )
    {
        if (lenText <= TEXTBREAKEVENLENGTH / 2 || lenPat <= PATTERNBREAKEVENLENGTH) {
            return text.indexOf( pattern, index );
        }
        analysePattern();
        char testChar;
        final int lastPatChar = patternArray[lenPat - 1];
        outer : 
        for (int tforward = index + lenPat - 1; tforward < lenText; tforward += skip[testChar & 0xff]) {
            testChar = text.charAt( tforward );
            if (testChar != lastPatChar) {
                continue;
            }
            for (int tback = tforward - 1, pback = lenPat - 2; pback >= 0; tback--, pback--) {
                if (text.charAt( tback ) != patternArray[pback]) {
                    continue outer;
                }
            }
            return tforward - lenPat + 1;
        }
        return -1;
    }

    private  int indexOfViaTextArray( int index )
    {
        if (lenText <= TEXTBREAKEVENLENGTH / 2 || lenPat <= PATTERNBREAKEVENLENGTH) {
            return (new java.lang.String( textArray )).indexOf( pattern, index );
        }
        analysePattern();
        char testChar;
        final int lastPatChar = patternArray[lenPat - 1];
        outer : 
        for (int tforward = index + lenPat - 1; tforward < lenText; tforward += skip[testChar & 0xff]) {
            testChar = textArray[tforward];
            if (testChar != lastPatChar) {
                continue;
            }
            for (int tback = tforward - 1, pback = lenPat - 2; pback >= 0; tback--, pback--) {
                if (textArray[tback] != patternArray[pback]) {
                    continue outer;
                }
            }
            return tforward - lenPat + 1;
        }
        return -1;
    }

    private  void setPattern( java.lang.String pattern )
    {
        if (pattern == null) {
            throw new java.lang.NullPointerException();
        }
        this.pattern = pattern;
        lenPat = pattern.length();
    }

    public static  void main( java.lang.String[] args )
    {
        if (DEBUGGING) {
            System.out.println( Boyer.indexOf( "dogcatwombat", "cat" ) );
            System.out.println( "dogcatwombat".indexOf( "cat" ) );
            System.out.println( Boyer.indexOf( "crtcamccmcarogcatwombat", "cat" ) );
            System.out.println( "crtcamccmcarogcatwombat".indexOf( "cat" ) );
            System.out.println( Boyer.indexOf( "dogcatwombat", "" ) );
            System.out.println( "dogcatwombat".indexOf( "" ) );
            System.out.println( Boyer.indexOf( "", "" ) );
            System.out.println( "".indexOf( "" ) );
            System.out.println( Boyer.indexOf( "", "abcde" ) );
            System.out.println( "".indexOf( "abcde" ) );
            System.out.println( Boyer.indexOf( "dogcatwombat", "cow" ) );
            System.out.println( "dogcatwombat".indexOf( "cow" ) );
            java.lang.String s = "create table foo (created_date datetime default sysdate not null)";
            System.out.println( s.indexOf( "create", 10 ) );
            System.out.println( Boyer.indexOf( s, "create", 10 ) );
            try {
                java.io.FileWriter fw = new java.io.FileWriter( "C:/temp/temp.txt" );
                for (int i = 0; i < 6000; i++) {
                    fw.write( "abcdefghijklmenopqrstuvwxyz" );
                }
                fw.close();
                final java.io.File f = new java.io.File( "C:/temp", "temp.txt" );
                int size = (int) f.length();
                java.io.FileReader fr = new java.io.FileReader( f );
                char[] ca = new char[size];
                int charsRead = fr.read( ca );
                s = new java.lang.String( ca );
                int result = 0;
                long start = System.currentTimeMillis();
                for (int i = 0; i < 1000; i++) {
                    result = Boyer.indexOf( ca, "efficiency" + i % 10 );
                }
                System.out.println( "Boyer.indexOf(char[]): " + result );
                long stop = System.currentTimeMillis();
                System.out.println( "Elapsed:" + (stop - start) );
                start = System.currentTimeMillis();
                for (int i = 0; i < 1000; i++) {
                    result = Boyer.indexOf( s, "efficiency" + i % 10 );
                }
                System.out.println( "Boyer.indexOf(String): " + result );
                stop = System.currentTimeMillis();
                System.out.println( "Elapsed:" + (stop - start) );
                start = System.currentTimeMillis();
                for (int i = 0; i < 1000; i++) {
                    result = s.indexOf( "efficiency" + i % 10 );
                }
                System.out.println( "String.indexOf: " + result );
                stop = System.currentTimeMillis();
                System.out.println( "Elapsed:" + (stop - start) );
                fr.close();
            } catch ( java.io.IOException e ) {
                System.err.println( e.getMessage() );
            }
        }
    }

}
