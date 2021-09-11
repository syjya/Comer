import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;

import org.apache.lucene.document.Document;
import org.apache.lucene.index.Term;
import org.apache.lucene.search.BooleanQuery;
import org.apache.lucene.search.Hits;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.TermQuery;
import org.apache.lucene.search.BooleanClause.Occur;
import org.apache.lucene.store.FSDirectory;


public class TxtFile_output {
	
        public static void main(String[] args) throws Exception{
		
		if(args.length<=1)
			return;
		String str1=args[0];
		if(str1==null)
			return;
        	File indexDir = new File(str1); 
            FSDirectory directory = FSDirectory.getDirectory(indexDir,false); 
            IndexSearcher	searcher = new IndexSearcher(directory);
		
		String basePath=args[1];
		File dir=new File(basePath);
		File[] dirFiles = dir.listFiles();
		
		String encoding="UTF-8";
		if(dirFiles==null)
			return;
	    for(File temp : dirFiles){
	        if(temp.isFile() && temp.getAbsolutePath().endsWith(".txt") ){
	        InputStreamReader read = new InputStreamReader(new FileInputStream(temp),encoding);
	        BufferedReader bufferedReader = new BufferedReader(read);
	        String Txt="";
	        String lineTxt ="";
	        int line=0;
	        while((lineTxt = bufferedReader.readLine()) != null){
	             Txt+=lineTxt+" ";
	        }
	        String[] stringinput = Txt.split(" ");
	        
	        BooleanQuery query = new BooleanQuery();
           
	        if(stringinput.length==1)
	        {
	        	if(!(stringinput[0].equals("NOT")||stringinput[0].equals("OR")||stringinput[0].equals("AND")))
	        	{
	        		Query query1=new TermQuery(new Term("contents",stringinput[0]));
	        		query.add(query1, Occur.MUST);
	        	}
	        }

	        else if(stringinput.length==2)
	        {
	        	if((stringinput[1].equals("NOT")||stringinput[1].equals("OR")||stringinput[1].equals("AND")))
	        	{
	        		Query query1=new TermQuery(new Term("contents",stringinput[0]));
	        		query.add(query1, Occur.MUST);
	        	}
	        	else
	        	{
	        		String qu=stringinput[0]+stringinput[1];
		        	Query query1=new TermQuery(new Term("contents",qu));
	        		query.add(query1, Occur.MUST);
	        	}
	        	
	        }
	        
	        else if(stringinput.length==3)
	        {
	        	if(stringinput[1].equals("AND"))
	        	{
	        		
	        		Query query1=new TermQuery(new Term("contents",stringinput[0]));
	        		Query query2=new TermQuery(new Term("contents",stringinput[2]));
	        		query.add(query1, Occur.MUST);
	        		query.add(query2, Occur.MUST);
	        	}
	        	else if(stringinput[1].equals("OR"))
	        	{  
	        		Query query1=new TermQuery(new Term("contents",stringinput[0]));
	        		Query query2=new TermQuery(new Term("contents",stringinput[2]));
	        		query.add(query1, Occur.SHOULD);
	        		query.add(query2, Occur.SHOULD);
	        	}
	        	else if(stringinput[1].equals("NOT"))
	        	{
	        		Query query1=new TermQuery(new Term("contents",stringinput[0]));
	        		Query query2=new TermQuery(new Term("contents",stringinput[2]));
	        		query.add(query1, Occur.MUST);
	        		query.add(query2, Occur.MUST_NOT);
	        	}
	        }
	         
	        Hits hits = searcher.search(query); 
	        String temppath=args[2];
	        String[] allpath=temp.getAbsolutePath().split("/"); 
			temppath+="/";
			temppath+=allpath[allpath.length-1];

            FileWriter fileWritter = new FileWriter(temppath);
            BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
	        for(int i = 0; i < hits.length(); i++){ 
	              Document document = hits.doc(i); 
	              bufferWritter.write(document.get("path"));
	              bufferWritter.newLine();
	        } 
            bufferWritter.close();
            }
	    }
		
	}
}
