import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;

import org.joda.time.DateTime;
import org.junit.Assert;


public class jodatime_output {
	
	public static void main(String[] args) throws Exception{
		
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
				DateTime dateTime = new DateTime(
	  			  input[0],
	  			  input[1],    // month
	  			  input[2],    // day
	  			  input[3],    // hour (midnight is zero)
	  			  input[4],    // minute
	  			  input[5],    // second
	  			  input[6]     // milliseconds
	  			);
				DateTime then = dateTime.plusWeeks(input[7]).plusDays(input[8]).plusSeconds(input[9]);
	  	int year=then.getYear();
		int mon=then.getMonthOfYear();
		int day=then.getDayOfMonth();
		int hour=then.getHourOfDay();
		int minu=then.getMinuteOfHour();
		int semin=then.getSecondOfMinute();
		int mill=then.getMillisOfSecond();
	        
	  	
	  	


	        FileWriter fileWritter = new FileWriter(temp.getAbsoluteFile(),true);
	        BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
	        bufferWritter.newLine();
	        bufferWritter.write(year+" "+mon+" "+day+" "+hour+" "+minu+" "+semin+" "+mill);
	        bufferWritter.close();
	        }
	    }
	}
}
