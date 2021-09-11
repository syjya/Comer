import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;


public class Klp_run {
   public static void main(String[] args) throws Exception{
		
		klp1 m=new klp1();
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
	        
	     /*   for(int i=0;i<stringinput.length;i++)
            	System.out.print(stringinput[i]);
            System.out.println();*/
	        
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
	        	input[i]=Integer.parseInt(stringinput[j].trim());
	        }
	        
	      /*  for(int i=0;i<stringinput.length;i++)
            	System.out.print(stringinput[i]);
	        System.out.println();
	        for(int i=0;i<input.length;i++)
            	System.out.print(input[i]);
	        System.out.println();*/
	        int row=input[0];
	        int col=input[1]+1;
	        int mm[][]=new int[row][col];
	        int count=2;
	        for(int i=0;i<row;i++)
	        {
	        	for(int j=0;j<col;j++)
	        	{
	        		if(j==col-1)
	        			mm[i][j]=i+1;
	        		else
	        			mm[i][j]=input[count++];
	        	}
	        }
	        Integer[] result=m.klpp(mm, row, col);
	        int resultl=1;
	        for(int i=0;i<result.length;i++)
	        {
	        	if(result[i]==null)
	        	{
	        		resultl=i;
	        		break;
	        	}
	        	if(result[i]<1)
	        	{
	        		resultl=i;
	        		break;
	        	}
	        }
	        
            FileWriter fileWritter = new FileWriter(temp.getAbsoluteFile(),true);
            BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
            bufferWritter.newLine();
            for(int i=0;i<resultl;i++)
            {
            	bufferWritter.write(result[i].toString());
            	String kong=" ";
            	bufferWritter.write(kong);
            }
            
            bufferWritter.close();
            }
	    }
		
	}
}
