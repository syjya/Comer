import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;

import flanagan.math.Matrix;

public class Determinant1_output {
	  public static void main(String[] args) throws Exception{
	
			//String basePath="G:\\MR\\model\\Determinant1\\src_input";
		    if(args.length<=0)
				return;
			String basePath= args[0];	
			File dir=new File(basePath);
			File[] dirFiles = dir.listFiles();
			if(dirFiles==null)
				return;
			String encoding="UTF-8";
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
		        
		        int row=input[0];
		        int col=input[1];
		        int count=2;
		        
		        Matrix aa = new Matrix(row,col,0);
		        for(int i=0;i<row;i++)
		        {
		        	for(int j=0;j<col;j++)
		        	{
		        		aa.setElement(i, j, input[count++]);
		        	}
		        }
			    double expect=aa.determinant();
		        FileWriter fileWritter = new FileWriter(temp.getAbsoluteFile(),true);
		        BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
				bufferWritter.newLine();
		        bufferWritter.write(String.format("%.8f", expect));
		        bufferWritter.close();
		        }
		    }
		    }
}
