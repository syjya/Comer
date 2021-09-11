import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class MaxRectangle_out {
public static void main(String[] args) throws Exception{
		
		if(args.length<=0)
			return;
		String temp= args[0];
		MaxRectangle m=new MaxRectangle();	
		
	        InputStreamReader read = new InputStreamReader(new FileInputStream(temp),"UTF-8");
	        BufferedReader bufferedReader = new BufferedReader(read);
	        String Txt="";
	        String lineTxt = "";
	        while((lineTxt = bufferedReader.readLine()) != null){
	             Txt+=lineTxt+" ";
	        }
	        String[] stringinput = Txt.split(" ");
	        
	        
	        int input[]=new int[stringinput.length];        
	        for(int i=0,j=0;i<stringinput.length&&j<stringinput.length;i++,j++)
	        {
	        	while(stringinput[j].equals("")||stringinput[j]==" "||stringinput[j]==null)
	        	{
	        		if(j+1<stringinput.length)
	        			j++;
	        		else
	        			break;
	        	}
	        	if(stringinput[j].equals("")||stringinput[j]==" "||stringinput[j]==null)
	        	{}
	        	else
	        	input[i]=Integer.valueOf(stringinput[j].trim()).intValue();
	        }
	        
	        Integer row=input[0];
	        int col=input[1];
	        int count=2;
	        
	        ArrayList<ArrayList<Integer>> a = new ArrayList<ArrayList<Integer>>();
	        for(int i=0;i<row;i++)
	        {
	        	ArrayList<Integer> tempr = new ArrayList<Integer>();
	        	for(int j=0;j<col;j++)
	        	{
	        		tempr.add(input[count++]);
	        	}
	        	a.add(new ArrayList<Integer>(tempr));
	            tempr.clear();
	        }
	        
		    int expect = m.maximalRectangle(a);

	        FileWriter fileWritter = new FileWriter(temp,true);
	        BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
	        bufferWritter.newLine();
	        bufferWritter.write(String.valueOf(expect));
	        bufferWritter.close();
	}
}
