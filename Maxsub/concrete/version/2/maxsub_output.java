import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;


public class maxsub_output {
    
	public static void main(String[] args) throws Exception{
		
		maxsub m=new maxsub();
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
	        
	        Integer result=m.maxsub(input,input.length);
            //System.out.println("结果");
            //System.out.println(result);
            
            String output=result.toString();
            //System.out.println(output);
            FileWriter fileWritter = new FileWriter(temp.getAbsoluteFile(),true);
            BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
            bufferWritter.newLine();
            bufferWritter.write(output);
            bufferWritter.close();
			//System.out.println(result);
            }
	    }
		
	}
}
