// This is a mutant program.
// Author : ysma

package org.apache.lucene.search;


import java.io.IOException;
import java.util.Vector;
import java.util.Iterator;
import org.apache.lucene.document.Document;


public final class Hits
{

    private org.apache.lucene.search.Weight weight;

    private org.apache.lucene.search.Searcher searcher;

    private org.apache.lucene.search.Filter filter = null;

    private org.apache.lucene.search.Sort sort = null;

    private int length;

    private java.util.Vector hitDocs = new java.util.Vector();

    private org.apache.lucene.search.HitDoc first;

    private org.apache.lucene.search.HitDoc last;

    private int numDocs = 0;

    private int maxDocs = 200;

    Hits( org.apache.lucene.search.Searcher s, org.apache.lucene.search.Query q, org.apache.lucene.search.Filter f )
        throws java.io.IOException
    {
        weight = q.weight( s );
        searcher = s;
        filter = f;
        getMoreDocs( 50 );
    }

    Hits( org.apache.lucene.search.Searcher s, org.apache.lucene.search.Query q, org.apache.lucene.search.Filter f, org.apache.lucene.search.Sort o )
        throws java.io.IOException
    {
        weight = q.weight( s );
        searcher = s;
        filter = f;
        sort = o;
        getMoreDocs( 50 );
    }

    private final  void getMoreDocs( int min )
        throws java.io.IOException
    {
        if (hitDocs.size() > min) {
            min = hitDocs.size();
        }
        int n = min * 2;
        org.apache.lucene.search.TopDocs topDocs = sort == null ? searcher.search( weight, filter, n ) : searcher.search( weight, filter, n, sort );
        length = topDocs.totalHits;
        org.apache.lucene.search.ScoreDoc[] scoreDocs = topDocs.scoreDocs;
        float scoreNorm = 1.0f;
        if (length > 0 && topDocs.getMaxScore() > 1.0f) {
            scoreNorm = 1.0f / topDocs.getMaxScore();
        }
        int end = scoreDocs.length < length ? scoreDocs.length : length;
        for (int i = hitDocs.size(); i < end; i++) {
            hitDocs.addElement( new org.apache.lucene.search.HitDoc( scoreDocs[i].score * scoreNorm, scoreDocs[i].doc ) );
        }
    }

    public final  int length()
    {
        return length;
    }

    public final  org.apache.lucene.document.Document doc( int n )
        throws java.io.IOException
    {
        org.apache.lucene.search.HitDoc hitDoc = hitDoc( n );
        remove( hitDoc );
        addToFront( hitDoc );
        if (numDocs > maxDocs) {
            org.apache.lucene.search.HitDoc oldLast = last;
            remove( last );
            oldLast.doc = null;
        }
        if (hitDoc.doc == null) {
            hitDoc.doc = searcher.doc( hitDoc.id );
        }
        return hitDoc.doc;
    }

    public final  float score( int n )
        throws java.io.IOException
    {
        return hitDoc( n ).score;
    }

    public final  int id( int n )
        throws java.io.IOException
    {
        return hitDoc( n ).id;
    }

    public  java.util.Iterator iterator()
    {
        return new org.apache.lucene.search.HitIterator( this );
    }

    private final  org.apache.lucene.search.HitDoc hitDoc( int n )
        throws java.io.IOException
    {
        if (n >= length) {
            throw new java.lang.IndexOutOfBoundsException( "Not a valid hit number: " + n );
        }
        if (n >= hitDocs.size()) {
            getMoreDocs( n );
        }
        return (org.apache.lucene.search.HitDoc) hitDocs.elementAt( n );
    }

    private final  void addToFront( org.apache.lucene.search.HitDoc hitDoc )
    {
        if (first == null) {
            last = hitDoc;
        } else {
            first.prev = hitDoc;
        }
        hitDoc.next = first;
        first = hitDoc;
        hitDoc.prev = null;
        numDocs++;
    }

    private final  void remove( org.apache.lucene.search.HitDoc hitDoc )
    {
        if (hitDoc.doc == null) {
            return;
        }
        if (hitDoc.next == null) {
            last = hitDoc.prev;
        } else {
            hitDoc.next.prev = hitDoc.prev;
        }
        if (hitDoc.prev == null) {
            first = hitDoc.next;
        } else {
            hitDoc.prev.next = hitDoc.next;
        }
        numDocs--;
    }

}

final class HitDoc
{

    float score;

    static int id;

    org.apache.lucene.document.Document doc = null;

    org.apache.lucene.search.HitDoc next;

    org.apache.lucene.search.HitDoc prev;

    HitDoc( float s, int i )
    {
        score = s;
        id = i;
    }

}
