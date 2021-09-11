import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;



public class boyer_output {
public static void main(String[] args) throws Exception{
		
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
	        Boyer b = new Boyer(stringinput[0]);
	    	int where = b.indexOf(stringinput[1]);   
	    	
	        FileWriter fileWritter = new FileWriter(temp.getAbsoluteFile(),true);
	        BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
	        bufferWritter.newLine();
	        bufferWritter.write(String.valueOf(where));
	        bufferWritter.close();
	        }
	    }
	}
}
