import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;


public class superstring_output {

	
public static void main(String[] args) throws Exception{
		
	    superstring m=new superstring();
	    if(args.length<=0)
			return;
		String basePath= args[0];
		File dir=new File(basePath);
		File[] dirFiles = dir.listFiles();
		
		String encoding="UTF-8";
		if(dirFiles==null)
			return;
	    for(File temp : dirFiles){
	        if(temp.isFile() && temp.getAbsolutePath().endsWith(".txt") ){
	        InputStreamReader read = new InputStreamReader(new FileInputStream(temp),encoding);
	        BufferedReader bufferedReader = new BufferedReader(read);
	        String Txt[] = new String[1000];
	        String lineTxt = "";
	        int Txti=0;
	        while((lineTxt = bufferedReader.readLine()) != null){
				  String[] tempstring = lineTxt.trim().split(" ");
				  for(int i=0;i<tempstring.length;i++)
				  {
					  Txt[Txti++]=tempstring[i];				 
					  }
	             
	        }
	        String str[]=new String[Txti];
	        for(int i=0;i<Txti;i++)
	        	str[i]=Txt[i];
	       // System.out.println(Txti+" "+str.length);
	        String result=m.shortestSuperstring(str);

            FileWriter fileWritter = new FileWriter(temp.getAbsoluteFile(),true);
            BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
            bufferWritter.newLine();
            bufferWritter.write(result);
            bufferWritter.close();
            }
	    }
		
	}

}
