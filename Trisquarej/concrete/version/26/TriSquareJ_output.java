import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;


public class TriSquareJ_output {
     
public static void main(String[] args) throws Exception{
		
	    TriSquareJ m=new TriSquareJ();	
	    if(args.length<=0)
			return;
		String basePath=args[0];
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
	        
	       /*for(int i=0;i<stringinput.length;i++)
            	System.out.print(stringinput[i]);
	        System.out.println();
	        for(int i=0;i<input.length;i++)
            	System.out.print(input[i]);
	        System.out.println();*/
	        
	        String result=m.TriangleSquare(input[0], input[1], input[2]);
            //System.out.println(output);
            FileWriter fileWritter = new FileWriter(temp.getAbsoluteFile(),true);
            BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
            bufferWritter.newLine();
            bufferWritter.write(result);
            bufferWritter.close();
            }
	    }
		
	}
}
