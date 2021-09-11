#include <iostream>
#include <fstream> 
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int src_input;
int arg[20000][12];
int bi;

int flag[20000];
 
string number;

std::string result_line[20000][5000];
int result_linei[20000];
void MR2_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
	
	std::string line[1000];
	std::string begin;
	std::string end;
	line[0] = "b";
	int linei = 1;

	
	switch (arg[a1][1])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][0])
		{
		case 0:
			begin = "and ";	
			break;
		case 1:
			begin = "or ";
			break;
		case 2:
			begin = "if ";
			break;
		case 3:
			begin = "xor ";
			break;
		case 4:
			begin = "lambda ";
			break;
		case 5:
			begin = "=> ";
			break;
		case 6:
			begin = "( ";
			break;
		case 7:
			begin = ") ";
			break;
		case 8:
			begin = "[ ";
			break;
		case 9:
			begin = "] ";
			break;
		case 10:
			begin = "' ";
			break;		
		case 11:
			begin = "` ";
			break;
		case 12:
			begin = ", ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][0])
		{
		case 0:
			line[linei++]= "and ";	
			break;
		case 1:
			line[linei++]= "or ";
			break;
		case 2:
			line[linei++]= "if ";
			break;
		case 3:
			line[linei++]= "xor ";
			break;
		case 4:
		line[linei++]= "lambda ";
			break;
		case 5:
			line[linei++]= "=> ";
			break;
		case 6:
			line[linei++]= "( ";
			break;
		case 7:
			line[linei++]= ") ";
			break;
		case 8:
			line[linei++]= "[ ";
			break;
		case 9:
			line[linei++]= "] ";
			break;
		case 10:
			line[linei++]= "' ";
			break;		
		case 11:
			line[linei++]= "` ";
			break;
		case 12:
			line[linei++]= ", ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][0])
		{
		case 0:
			end = "and ";	
			break;
		case 1:
			end = "or ";
			break;
		case 2:
			end = "if ";
			break;
		case 3:
			end = "xor ";
			break;
		case 4:
			end = "lambda ";
			break;
		case 5:
			end = "=> ";
			break;
		case 6:
			end = "( ";
			break;
		case 7:
			end = ") ";
			break;
		case 8:
			end = "[ ";
			break;
		case 9:
			end = "] ";
			break;
		case 10:
			end = "' ";
			break;		
		case 11:
			end = "` ";
			break;
		case 12:
			end = ", ";
			break;
		}
		break;
	}



	switch (arg[a1][3])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][2])
		{
		case 0:
			begin = "test ";	
			break;
		case 1:
			begin = "test15 ";
			break;
		case 2:
			begin = "AND ";
			break;
		case 3:
			begin = "IF3 ";
			break;
		case 4:
			begin = "lambda7 ";
			break;
		case 5:
			begin = "X15or ";
			break;
		case 6:
			begin = "test	 ";
			break;
		case 7:
			begin = "te?st ";
			break;
		case 8:
			begin = "test. ";
			break;
		case 9:
			begin = "15or ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][2])
		{
		case 0:
			line[linei++]= "test ";	
			break;
		case 1:
			line[linei++]= "test15 ";
			break;
		case 2:
			line[linei++]= "AND ";
			break;
		case 3:
			line[linei++]= "IF3 ";
			break;
		case 4:
			line[linei++]= "lambda7 ";
			break;
		case 5:
			line[linei++]= "X15or ";
			break;
		case 6:
			line[linei++]= "test	 ";
			break;
		case 7:
			line[linei++]= "te?st ";
			break;
		case 8:
			line[linei++]= "test. ";
			break;
		case 9:
			line[linei++]= "15or ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][2])
		{
		case 0:
			end = "test ";	
			break;
		case 1:
			end = "test15 ";
			break;
		case 2:
			end = "AND ";
			break;
		case 3:
			end = "IF3 ";
			break;
		case 4:
			end = "lambda7 ";
			break;
		case 5:
			end = "X15or ";
			break;
		case 6:
			end = "test	 ";
			break;
		case 7:
			end = "te?st ";
			break;
		case 8:
			end = "test. ";
			break;
		case 9:
			end = "15or ";
			break;
		}
		break;
	}



	switch (arg[a1][5])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][4])
		{
		case 0:
			begin = "0 ";	
			break;
		case 1:
			begin = "7 ";
			break;
		case 2:
			begin = "770 ";
			break;
		case 3:
			begin = "777 ";
			break;
		case 4:
			begin = "077 ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][4])
		{
		case 0:
			line[linei++]= "0 ";	
			break;
		case 1:
			line[linei++]= "7 ";
			break;
		case 2:
			line[linei++]= "770 ";
			break;
		case 3:
			line[linei++]= "777 ";
			break;
		case 4:
			line[linei++]= "077 ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][4])
		{
		case 0:
			end = "0 ";	
			break;
		case 1:
			end = "7 ";
			break;
		case 2:
			end = "770 ";
			break;
		case 3:
			end = "777 ";
			break;
		case 4:
			end = "077 ";
			break;
		}
		break;
	}



	std::string special = "";
	switch (arg[a1][7])
		{
		case 0:
			special = " ";
			break;
		case 1:
			special = "te #st";
			break;
		case 2:
			special = "te ;st";
			break;
		case 3:
			special = "te \"st";
			break;	
		case 4:
			special = "te#st";
			break;	
		case 5:
			special = "te;st";
			break;	
		case 6:
			special = "te\"st";
			break;	
		case 7:
			special = "and";
			break;	
		case 8:
			special = "test";
			break;
		case 9:
			special = "te?st";
			break;	
		case 10:
			special = "770";
			break;	
		case 11:
			special = "test	test";
			break;	
		case 12:
			special = "test (";
			break;	
	}

	switch (arg[a1][6])
		{
		case 0:
			special = ";"+special;
			break;
		case 1:
			special = "#"+special;
			break;
		case 2:
			special = "\""+special+"\"";
			break;
		}
	
	
	
	
	
	switch (arg[a1][8])
	{
	case 0:
		break;
	case 1:
		begin = special;	
		break;
	case 2:
		line[linei++]= special;
		break;
	case 3:
		end = special;
		break;
	}
		
	if(arg[a1][10]==1)
	{
		for(int stri=0;stri<begin.length();stri++)
		{
			if(begin[stri]>='a'&&begin[stri]<='z')
			begin[stri]=begin[stri]+'A'-'a';
		}
        for(int stri=0;stri<linei;stri++)
		{
			for(int strj=0;strj<line[stri].length();strj++)
			{
				if(line[stri][strj]>='a'&&line[stri][strj]<='z')
				line[stri][strj]=line[stri][strj]+'A'-'a';
			}
		}
		for(int stri=0;stri<end.length();stri++)
		{
			if(end[stri]>='a'&&end[stri]<='z')
			end[stri]=end[stri]+'A'-'a';
		}
	}	
	int resulta1=0;
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         if(begin!="")
         {
         	examplefile<<begin<<"\n";
         	result_line[a1][resulta1++]=begin;
         }
         
         for(int stri=0;stri<linei;stri++)
         {
         	examplefile<<line[stri];
         	result_line[a1][resulta1++]=line[stri];
			if(stri!=linei-1)
			 examplefile<<"\n";
         }
         if(end!="")
         {
         	examplefile<<"\n"<<end;
         	result_line[a1][resulta1++]=end;
         }        
         if (arg[a1][9]==1)
         {
         	examplefile<<"\n";
         	if(begin!="")
         	{
         		examplefile<<begin<<"\n";
         		result_line[a1][resulta1++]=begin;
         	}
         	
         for(int stri=0;stri<linei;stri++)
         {
         	examplefile<<line[stri];
         	result_line[a1][resulta1++]=line[stri];
			if(stri!=linei-1)
			 examplefile<<"\n";
         }
         if(end!="")
         {
         	examplefile<<"\n"<<end;
         	result_line[a1][resulta1++]=end;
         }         
         } 
         examplefile.close();        //关闭文件 
    } 
    result_linei[a1]=resulta1;
    result_linei[a2]=resulta1;
    
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {   
	    if(result_line[a1][0][0]!='\"'&&result_line[a1][0][0]!='#')
	    {
	    	result_line[a2][0]=result_line[a1][0];
	    	examplefile1<<result_line[a2][0];
	    }
	    else
	    {
	    	result_line[a2][0]=result_line[a1][0];
	    	result_line[a2][0]=';'+result_line[a2][0];
	    	examplefile1<<result_line[a2][0];
	    }
    	for(int stri=1;stri<resulta1;stri++)
    	{
    		if(result_line[a1][stri][0]!='\"'&&result_line[a1][stri][0]!='#')
	    	{
	    	result_line[a2][stri]=result_line[a1][stri];
	    	examplefile1<<"\n"<<result_line[a2][stri];
	    	}
	       else
	    	{
	    	result_line[a2][stri]=result_line[a1][stri];
	    	result_line[a2][stri]=';'+result_line[a2][stri];
	    	examplefile1<<"\n"<<result_line[a2][stri];
	    	}
    	}
    	examplefile1.close(); 
    } 
    
	
	flag[a1]=1;
	flag[a2]=1;
}
void MR1_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
		std::string line[1000];
	std::string begin;
	std::string end;
	line[0] = "b";
	int linei = 1;

	
	switch (arg[a1][1])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][0])
		{
		case 0:
			begin = "and ";	
			break;
		case 1:
			begin = "or ";
			break;
		case 2:
			begin = "if ";
			break;
		case 3:
			begin = "xor ";
			break;
		case 4:
			begin = "lambda ";
			break;
		case 5:
			begin = "=> ";
			break;
		case 6:
			begin = "( ";
			break;
		case 7:
			begin = ") ";
			break;
		case 8:
			begin = "[ ";
			break;
		case 9:
			begin = "] ";
			break;
		case 10:
			begin = "' ";
			break;		
		case 11:
			begin = "` ";
			break;
		case 12:
			begin = ", ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][0])
		{
		case 0:
			line[linei++]= "and ";	
			break;
		case 1:
			line[linei++]= "or ";
			break;
		case 2:
			line[linei++]= "if ";
			break;
		case 3:
			line[linei++]= "xor ";
			break;
		case 4:
		line[linei++]= "lambda ";
			break;
		case 5:
			line[linei++]= "=> ";
			break;
		case 6:
			line[linei++]= "( ";
			break;
		case 7:
			line[linei++]= ") ";
			break;
		case 8:
			line[linei++]= "[ ";
			break;
		case 9:
			line[linei++]= "] ";
			break;
		case 10:
			line[linei++]= "' ";
			break;		
		case 11:
			line[linei++]= "` ";
			break;
		case 12:
			line[linei++]= ", ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][0])
		{
		case 0:
			end = "and ";	
			break;
		case 1:
			end = "or ";
			break;
		case 2:
			end = "if ";
			break;
		case 3:
			end = "xor ";
			break;
		case 4:
			end = "lambda ";
			break;
		case 5:
			end = "=> ";
			break;
		case 6:
			end = "( ";
			break;
		case 7:
			end = ") ";
			break;
		case 8:
			end = "[ ";
			break;
		case 9:
			end = "] ";
			break;
		case 10:
			end = "' ";
			break;		
		case 11:
			end = "` ";
			break;
		case 12:
			end = ", ";
			break;
		}
		break;
	}



	switch (arg[a1][3])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][2])
		{
		case 0:
			begin = "test ";	
			break;
		case 1:
			begin = "test15 ";
			break;
		case 2:
			begin = "AND ";
			break;
		case 3:
			begin = "IF3 ";
			break;
		case 4:
			begin = "lambda7 ";
			break;
		case 5:
			begin = "X15or ";
			break;
		case 6:
			begin = "test	 ";
			break;
		case 7:
			begin = "te?st ";
			break;
		case 8:
			begin = "test. ";
			break;
		case 9:
			begin = "15or ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][2])
		{
		case 0:
			line[linei++]= "test ";	
			break;
		case 1:
			line[linei++]= "test15 ";
			break;
		case 2:
			line[linei++]= "AND ";
			break;
		case 3:
			line[linei++]= "IF3 ";
			break;
		case 4:
			line[linei++]= "lambda7 ";
			break;
		case 5:
			line[linei++]= "X15or ";
			break;
		case 6:
			line[linei++]= "test	 ";
			break;
		case 7:
			line[linei++]= "te?st ";
			break;
		case 8:
			line[linei++]= "test. ";
			break;
		case 9:
			line[linei++]= "15or ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][2])
		{
		case 0:
			end = "test ";	
			break;
		case 1:
			end = "test15 ";
			break;
		case 2:
			end = "AND ";
			break;
		case 3:
			end = "IF3 ";
			break;
		case 4:
			end = "lambda7 ";
			break;
		case 5:
			end = "X15or ";
			break;
		case 6:
			end = "test	 ";
			break;
		case 7:
			end = "te?st ";
			break;
		case 8:
			end = "test. ";
			break;
		case 9:
			end = "15or ";
			break;
		}
		break;
	}



	switch (arg[a1][5])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][4])
		{
		case 0:
			begin = "0 ";	
			break;
		case 1:
			begin = "7 ";
			break;
		case 2:
			begin = "770 ";
			break;
		case 3:
			begin = "777 ";
			break;
		case 4:
			begin = "077 ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][4])
		{
		case 0:
			line[linei++]= "0 ";	
			break;
		case 1:
			line[linei++]= "7 ";
			break;
		case 2:
			line[linei++]= "770 ";
			break;
		case 3:
			line[linei++]= "777 ";
			break;
		case 4:
			line[linei++]= "077 ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][4])
		{
		case 0:
			end = "0 ";	
			break;
		case 1:
			end = "7 ";
			break;
		case 2:
			end = "770 ";
			break;
		case 3:
			end = "777 ";
			break;
		case 4:
			end = "077 ";
			break;
		}
		break;
	}



	std::string special = "";
	switch (arg[a1][7])
		{
		case 0:
			special = " ";
			break;
		case 1:
			special = "te #st";
			break;
		case 2:
			special = "te ;st";
			break;
		case 3:
			special = "te \"st";
			break;	
		case 4:
			special = "te#st";
			break;	
		case 5:
			special = "te;st";
			break;	
		case 6:
			special = "te\"st";
			break;	
		case 7:
			special = "and";
			break;	
		case 8:
			special = "test";
			break;
		case 9:
			special = "te?st";
			break;	
		case 10:
			special = "770";
			break;	
		case 11:
			special = "test	test";
			break;	
		case 12:
			special = "test (";
			break;	
	}

	switch (arg[a1][6])
		{
		case 0:
			special = ";"+special;
			break;
		case 1:
			special = "#"+special;
			break;
		case 2:
			special = "\""+special+"\"";
			break;
		}
	
	
	switch (arg[a1][8])
	{
	case 0:
		break;
	case 1:
		begin = special;	
		break;
	case 2:
		line[linei++]= special;
		break;
	case 3:
		end = special;
		break;
	}
		
	if(arg[a1][10]==1)
	{
		for(int stri=0;stri<begin.length();stri++)
		{
			if(begin[stri]>='a'&&begin[stri]<='z')
			begin[stri]=begin[stri]+'A'-'a';
		}
        for(int stri=0;stri<linei;stri++)
		{
			for(int strj=0;strj<line[stri].length();strj++)
			{
				if(line[stri][strj]>='a'&&line[stri][strj]<='z')
				line[stri][strj]=line[stri][strj]+'A'-'a';
			}
		}
		for(int stri=0;stri<end.length();stri++)
		{
			if(end[stri]>='a'&&end[stri]<='z')
			end[stri]=end[stri]+'A'-'a';
		}
	}	
	int resulta1=0;
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         if(begin!="")
         {
         	examplefile<<begin<<"\n";
         	result_line[a1][resulta1++]=begin;
         }
         
         for(int stri=0;stri<linei;stri++)
         {
         	examplefile<<line[stri];
         	result_line[a1][resulta1++]=line[stri];
			if(stri!=linei-1)
			 examplefile<<"\n";
         }
         if(end!="")
         {
         	examplefile<<"\n"<<end;
         	result_line[a1][resulta1++]=end;
         }        
         if (arg[a1][9]==1)
         {
         	examplefile<<"\n";
         	if(begin!="")
         	{
         		examplefile<<begin<<"\n";
         		result_line[a1][resulta1++]=begin;
         	}
         	
         for(int stri=0;stri<linei;stri++)
         {
         	examplefile<<line[stri];
         	result_line[a1][resulta1++]=line[stri];
			if(stri!=linei-1)
			 examplefile<<"\n";
         }
         if(end!="")
         {
         	examplefile<<"\n"<<end;
         	result_line[a1][resulta1++]=end;
         }         
         } 
         examplefile.close();        //关闭文件 
    } 
    result_linei[a1]=resulta1;
    int resulta2=0;
    
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {   
	    if(result_line[a1][0][0]!=';')
	    {
	    	result_line[a2][resulta2++]=result_line[a1][0];
	    	examplefile1<<result_line[a2][resulta2-1];
	    }
    	for(int stri=1;stri<resulta1;stri++)
    	{
    		if(result_line[a1][stri][0]!=';')
	    	{
	    	result_line[a2][resulta2++]=result_line[a1][stri];
	    	examplefile1<<"\n"<<result_line[a2][resulta2-1];
	    	}
    	}
    	examplefile1.close(); 
    }     
    result_linei[a2]=resulta2;
    
		flag[a1]=1;
	    flag[a2]=1;
	}
	
	if(flag[a1]==1&&flag[a2]!=1)
	{
	int resulta2=0;
    int resulta1=result_linei[a1];
    char filename[200];
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {   
	    if(result_line[a1][0][0]!=';')
	    {
	    	result_line[a2][resulta2++]=result_line[a1][0];
	    	examplefile1<<result_line[a2][resulta2-1];
	    }
    	for(int stri=1;stri<resulta1;stri++)
    	{
    		if(result_line[a1][stri][0]!=';')
	    	{
	    	result_line[a2][resulta2++]=result_line[a1][stri];
	    	examplefile1<<"\n"<<result_line[a2][resulta2-1];
	    	}
    	}
    	examplefile1.close(); 
    }     
    result_linei[a2]=resulta2;
		flag[a2]=1;
	}
}
void MR0_testcase(int a1,int a2)	
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
	std::string line[1000];
	std::string begin;
	std::string end;
	line[0] = "b";
	int linei = 1;

	
	switch (arg[a1][1])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][0])
		{
		case 0:
			begin = "and ";	
			break;
		case 1:
			begin = "or ";
			break;
		case 2:
			begin = "if ";
			break;
		case 3:
			begin = "xor ";
			break;
		case 4:
			begin = "lambda ";
			break;
		case 5:
			begin = "=> ";
			break;
		case 6:
			begin = "( ";
			break;
		case 7:
			begin = ") ";
			break;
		case 8:
			begin = "[ ";
			break;
		case 9:
			begin = "] ";
			break;
		case 10:
			begin = "' ";
			break;		
		case 11:
			begin = "` ";
			break;
		case 12:
			begin = ", ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][0])
		{
		case 0:
			line[linei++]= "and ";	
			break;
		case 1:
			line[linei++]= "or ";
			break;
		case 2:
			line[linei++]= "if ";
			break;
		case 3:
			line[linei++]= "xor ";
			break;
		case 4:
		line[linei++]= "lambda ";
			break;
		case 5:
			line[linei++]= "=> ";
			break;
		case 6:
			line[linei++]= "( ";
			break;
		case 7:
			line[linei++]= ") ";
			break;
		case 8:
			line[linei++]= "[ ";
			break;
		case 9:
			line[linei++]= "] ";
			break;
		case 10:
			line[linei++]= "' ";
			break;		
		case 11:
			line[linei++]= "` ";
			break;
		case 12:
			line[linei++]= ", ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][0])
		{
		case 0:
			end = "and ";	
			break;
		case 1:
			end = "or ";
			break;
		case 2:
			end = "if ";
			break;
		case 3:
			end = "xor ";
			break;
		case 4:
			end = "lambda ";
			break;
		case 5:
			end = "=> ";
			break;
		case 6:
			end = "( ";
			break;
		case 7:
			end = ") ";
			break;
		case 8:
			end = "[ ";
			break;
		case 9:
			end = "] ";
			break;
		case 10:
			end = "' ";
			break;		
		case 11:
			end = "` ";
			break;
		case 12:
			end = ", ";
			break;
		}
		break;
	}



	switch (arg[a1][3])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][2])
		{
		case 0:
			begin = "test ";	
			break;
		case 1:
			begin = "test15 ";
			break;
		case 2:
			begin = "AND ";
			break;
		case 3:
			begin = "IF3 ";
			break;
		case 4:
			begin = "lambda7 ";
			break;
		case 5:
			begin = "X15or ";
			break;
		case 6:
			begin = "test	 ";
			break;
		case 7:
			begin = "te?st ";
			break;
		case 8:
			begin = "test. ";
			break;
		case 9:
			begin = "15or ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][2])
		{
		case 0:
			line[linei++]= "test ";	
			break;
		case 1:
			line[linei++]= "test15 ";
			break;
		case 2:
			line[linei++]= "AND ";
			break;
		case 3:
			line[linei++]= "IF3 ";
			break;
		case 4:
			line[linei++]= "lambda7 ";
			break;
		case 5:
			line[linei++]= "X15or ";
			break;
		case 6:
			line[linei++]= "test	 ";
			break;
		case 7:
			line[linei++]= "te?st ";
			break;
		case 8:
			line[linei++]= "test. ";
			break;
		case 9:
			line[linei++]= "15or ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][2])
		{
		case 0:
			end = "test ";	
			break;
		case 1:
			end = "test15 ";
			break;
		case 2:
			end = "AND ";
			break;
		case 3:
			end = "IF3 ";
			break;
		case 4:
			end = "lambda7 ";
			break;
		case 5:
			end = "X15or ";
			break;
		case 6:
			end = "test	 ";
			break;
		case 7:
			end = "te?st ";
			break;
		case 8:
			end = "test. ";
			break;
		case 9:
			end = "15or ";
			break;
		}
		break;
	}



	switch (arg[a1][5])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][4])
		{
		case 0:
			begin = "0 ";	
			break;
		case 1:
			begin = "7 ";
			break;
		case 2:
			begin = "770 ";
			break;
		case 3:
			begin = "777 ";
			break;
		case 4:
			begin = "077 ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][4])
		{
		case 0:
			line[linei++]= "0 ";	
			break;
		case 1:
			line[linei++]= "7 ";
			break;
		case 2:
			line[linei++]= "770 ";
			break;
		case 3:
			line[linei++]= "777 ";
			break;
		case 4:
			line[linei++]= "077 ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][4])
		{
		case 0:
			end = "0 ";	
			break;
		case 1:
			end = "7 ";
			break;
		case 2:
			end = "770 ";
			break;
		case 3:
			end = "777 ";
			break;
		case 4:
			end = "077 ";
			break;
		}
		break;
	}



	std::string special = "";
	switch (arg[a1][7])
		{
		case 0:
			special = " ";
			break;
		case 1:
			special = "te #st";
			break;
		case 2:
			special = "te ;st";
			break;
		case 3:
			special = "te \"st";
			break;	
		case 4:
			special = "te#st";
			break;	
		case 5:
			special = "te;st";
			break;	
		case 6:
			special = "te\"st";
			break;	
		case 7:
			special = "and";
			break;	
		case 8:
			special = "test";
			break;
		case 9:
			special = "te?st";
			break;	
		case 10:
			special = "770";
			break;	
		case 11:
			special = "test	test";
			break;	
		case 12:
			special = "test (";
			break;	
	}

	switch (arg[a1][6])
		{
		case 0:
			special = ";"+special;
			break;
		case 1:
			special = "#"+special;
			break;
		case 2:
			special = "\""+special+"\"";
			break;
		}
	
	
	switch (arg[a1][8])
	{
	case 0:
		break;
	case 1:
		begin = special;	
		break;
	case 2:
		line[linei++]= special;
		break;
	case 3:
		end = special;
		break;
	}
		
	if(arg[a1][10]==1)
	{
		for(int stri=0;stri<begin.length();stri++)
		{
			if(begin[stri]>='a'&&begin[stri]<='z')
			begin[stri]=begin[stri]+'A'-'a';
		}
        for(int stri=0;stri<linei;stri++)
		{
			for(int strj=0;strj<line[stri].length();strj++)
			{
				if(line[stri][strj]>='a'&&line[stri][strj]<='z')
				line[stri][strj]=line[stri][strj]+'A'-'a';
			}
		}
		for(int stri=0;stri<end.length();stri++)
		{
			if(end[stri]>='a'&&end[stri]<='z')
			end[stri]=end[stri]+'A'-'a';
		}
	}	
	int resulta1=0;
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         if(begin!="")
         {
         	examplefile<<begin<<"\n";
         	result_line[a1][resulta1++]=begin;
         }
         
         for(int stri=0;stri<linei;stri++)
         {
         	examplefile<<line[stri];
         	result_line[a1][resulta1++]=line[stri];
			if(stri!=linei-1)
			 examplefile<<"\n";
         }
         if(end!="")
         {
         	examplefile<<"\n"<<end;
         	result_line[a1][resulta1++]=end;
         }        
         if (arg[a1][9]==1)
         {
         	examplefile<<"\n";
         	if(begin!="")
         	{
         		examplefile<<begin<<"\n";
         		result_line[a1][resulta1++]=begin;
         	}
         	
         for(int stri=0;stri<linei;stri++)
         {
         	examplefile<<line[stri];
         	result_line[a1][resulta1++]=line[stri];
			if(stri!=linei-1)
			 examplefile<<"\n";
         }
         if(end!="")
         {
         	examplefile<<"\n"<<end;
         	result_line[a1][resulta1++]=end;
         }         
         } 
         examplefile.close();        //关闭文件 
    } 
    result_linei[a1]=resulta1;
    result_linei[a2]=resulta1;
    for(int stri=0;stri<resulta1;stri++)
	{
		result_line[a2][stri]=result_line[a1][stri];
		for(int strj=0;strj<result_line[a2][stri].length();strj++)
		{
			
			if(result_line[a2][stri][strj]>='a'&&result_line[a2][stri][strj]<='z')
			{
				result_line[a2][stri][strj]=result_line[a2][stri][strj]+'A'-'a';
			}
		}
	}
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {
    	for(int stri=0;stri<resulta1;stri++)
    	{
    		examplefile1<<result_line[a2][stri];
    		if(stri!=resulta1-1)
    		examplefile1<<"\n";
    	}
    }
    examplefile1.close(); 
    
		flag[a1]=1;
	    flag[a2]=1;
	}
	
	if(flag[a1]==1&&flag[a2]!=1)
	{
		int resulta1=result_linei[a1];
		result_linei[a2]=resulta1;
    for(int stri=0;stri<resulta1;stri++)
	{
		result_line[a2][stri]=result_line[a1][stri];
		for(int strj=0;strj<result_line[a2][stri].length();strj++)
		{
			
			if(result_line[a2][stri][strj]>='a'&&result_line[a2][stri][strj]<='z')
			{
				result_line[a2][stri][strj]=result_line[a2][stri][strj] +'A'-'a';
			}
		}
	}
	char filename[200];
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {
    	for(int stri=0;stri<resulta1;stri++)
    	{
    		examplefile1<<result_line[a2][stri];
    		if(stri!=resulta1-1)
    		examplefile1<<"\n";
    	}
    }
    examplefile1.close(); 
		flag[a2]=1;
	}
	

}
void judgeMR0()
{	
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[i][6]==arg[j][6]&&arg[i][7]==arg[j][7]&&arg[i][8]==arg[j][8]&&arg[i][9]==arg[j][9]&&arg[i][10]==0&&arg[j][10]==1)
            {
            	MR0_testcase(i,j);
            	break;
            }
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[i][6]==arg[j][6]&&arg[i][7]==arg[j][7]&&arg[i][8]==arg[j][8]&&arg[i][9]==arg[j][9]&&arg[i][10]==1&&arg[j][10]==0)
            {
            	MR0_testcase(j,i);
            	break;
            }		
		}
	}
}

void judgeMR1()
{	
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[i][6]==0&&arg[i][8]>0&&arg[j][8]==0&&arg[i][9]==arg[j][9]&&arg[i][10]==arg[j][10])
            {
            	MR1_testcase(i,j);
            	break;
            }
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[j][6]==0&&arg[j][8]>0&&arg[i][8]==0&&arg[i][9]==arg[j][9]&&arg[i][10]==arg[j][10])
            {
            	MR1_testcase(j,i);
            }		
		}
	}
}



void judgeMR2()
{	
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[i][6]>0&&arg[j][6]==0&&arg[i][7]==arg[j][7]&&arg[i][8]==arg[j][8]&&arg[i][8]>0&&arg[i][9]==arg[j][9]&&arg[i][10]==arg[j][10])
            {
            	MR2_testcase(i,j);
            	break;
            }
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[j][6]>0&&arg[i][6]==0&&arg[i][7]==arg[j][7]&&arg[i][8]==arg[j][8]&&arg[j][8]>0&&arg[i][9]==arg[j][9]&&arg[i][10]==arg[j][10])
            {
            	MR2_testcase(j,i);
            	break;
            }		
		}
	}
}


void init()
{
	src_input=0;
	bi=0;
	for(int i=0;i<20000;i++)
	{
		flag[i]=-1;
		result_linei[i]=0;
		for(int j=0;j<5000;j++)
		result_line[i][j]="";
	}	
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "bad args" << std::endl;
	}
	std::ifstream f_in(argv[1]);
	number=argv[2];
	std::string str;
    srand((unsigned int)(time(NULL)));
    init();	
	while (getline(f_in, str))
	{
		int jj=0;
		int ii=0;
		while(ii<11&&jj<str.length())
		{
			if(str[jj]!=' ')
			{
				string temp="";
				temp+=str[jj];
				jj++;
				while(1)
				{
					if(str[jj]==' '||jj>=str.length())
					break;
					else
					{
						temp+=str[jj];
						jj++;
					}
				}
				
				arg[bi][ii]=atoi(temp.c_str());
				ii++;
			}
			while(str[jj]==' ')
			jj++;
		}
		bi++;
    }   
//    judgeMR2();
//	judgeMR0();
//    judgeMR1();
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
    
	std::string line[1000];
	std::string begin;
	std::string end;
	line[0] = "b";
	int linei = 1;

	
	switch (arg[a1][1])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][0])
		{
		case 0:
			begin = "and ";	
			break;
		case 1:
			begin = "or ";
			break;
		case 2:
			begin = "if ";
			break;
		case 3:
			begin = "xor ";
			break;
		case 4:
			begin = "lambda ";
			break;
		case 5:
			begin = "=> ";
			break;
		case 6:
			begin = "( ";
			break;
		case 7:
			begin = ") ";
			break;
		case 8:
			begin = "[ ";
			break;
		case 9:
			begin = "] ";
			break;
		case 10:
			begin = "' ";
			break;		
		case 11:
			begin = "` ";
			break;
		case 12:
			begin = ", ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][0])
		{
		case 0:
			line[linei++]= "and ";	
			break;
		case 1:
			line[linei++]= "or ";
			break;
		case 2:
			line[linei++]= "if ";
			break;
		case 3:
			line[linei++]= "xor ";
			break;
		case 4:
		line[linei++]= "lambda ";
			break;
		case 5:
			line[linei++]= "=> ";
			break;
		case 6:
			line[linei++]= "( ";
			break;
		case 7:
			line[linei++]= ") ";
			break;
		case 8:
			line[linei++]= "[ ";
			break;
		case 9:
			line[linei++]= "] ";
			break;
		case 10:
			line[linei++]= "' ";
			break;		
		case 11:
			line[linei++]= "` ";
			break;
		case 12:
			line[linei++]= ", ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][0])
		{
		case 0:
			end = "and ";	
			break;
		case 1:
			end = "or ";
			break;
		case 2:
			end = "if ";
			break;
		case 3:
			end = "xor ";
			break;
		case 4:
			end = "lambda ";
			break;
		case 5:
			end = "=> ";
			break;
		case 6:
			end = "( ";
			break;
		case 7:
			end = ") ";
			break;
		case 8:
			end = "[ ";
			break;
		case 9:
			end = "] ";
			break;
		case 10:
			end = "' ";
			break;		
		case 11:
			end = "` ";
			break;
		case 12:
			end = ", ";
			break;
		}
		break;
	}



	switch (arg[a1][3])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][2])
		{
		case 0:
			begin = "test ";	
			break;
		case 1:
			begin = "test15 ";
			break;
		case 2:
			begin = "AND ";
			break;
		case 3:
			begin = "IF3 ";
			break;
		case 4:
			begin = "lambda7 ";
			break;
		case 5:
			begin = "X15or ";
			break;
		case 6:
			begin = "test	 ";
			break;
		case 7:
			begin = "te?st ";
			break;
		case 8:
			begin = "test. ";
			break;
		case 9:
			begin = "15or ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][2])
		{
		case 0:
			line[linei++]= "test ";	
			break;
		case 1:
			line[linei++]= "test15 ";
			break;
		case 2:
			line[linei++]= "AND ";
			break;
		case 3:
			line[linei++]= "IF3 ";
			break;
		case 4:
			line[linei++]= "lambda7 ";
			break;
		case 5:
			line[linei++]= "X15or ";
			break;
		case 6:
			line[linei++]= "test	 ";
			break;
		case 7:
			line[linei++]= "te?st ";
			break;
		case 8:
			line[linei++]= "test. ";
			break;
		case 9:
			line[linei++]= "15or ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][2])
		{
		case 0:
			end = "test ";	
			break;
		case 1:
			end = "test15 ";
			break;
		case 2:
			end = "AND ";
			break;
		case 3:
			end = "IF3 ";
			break;
		case 4:
			end = "lambda7 ";
			break;
		case 5:
			end = "X15or ";
			break;
		case 6:
			end = "test	 ";
			break;
		case 7:
			end = "te?st ";
			break;
		case 8:
			end = "test. ";
			break;
		case 9:
			end = "15or ";
			break;
		}
		break;
	}



	switch (arg[a1][5])
	{
	case 0:
		break;
	case 1:
		switch (arg[a1][4])
		{
		case 0:
			begin = "0 ";	
			break;
		case 1:
			begin = "7 ";
			break;
		case 2:
			begin = "770 ";
			break;
		case 3:
			begin = "777 ";
			break;
		case 4:
			begin = "077 ";
			break;
		}
		break;
	
	case 2:
		switch (arg[a1][4])
		{
		case 0:
			line[linei++]= "0 ";	
			break;
		case 1:
			line[linei++]= "7 ";
			break;
		case 2:
			line[linei++]= "770 ";
			break;
		case 3:
			line[linei++]= "777 ";
			break;
		case 4:
			line[linei++]= "077 ";
			break;
		}
		break;
	case 3:
		switch (arg[a1][4])
		{
		case 0:
			end = "0 ";	
			break;
		case 1:
			end = "7 ";
			break;
		case 2:
			end = "770 ";
			break;
		case 3:
			end = "777 ";
			break;
		case 4:
			end = "077 ";
			break;
		}
		break;
	}



	std::string special = "";
	switch (arg[a1][7])
		{
		case 0:
			special = " ";
			break;
		case 1:
			special = "te #st";
			break;
		case 2:
			special = "te ;st";
			break;
		case 3:
			special = "te \"st";
			break;	
		case 4:
			special = "te#st";
			break;	
		case 5:
			special = "te;st";
			break;	
		case 6:
			special = "te\"st";
			break;	
		case 7:
			special = "and";
			break;	
		case 8:
			special = "test";
			break;
		case 9:
			special = "te?st";
			break;	
		case 10:
			special = "770";
			break;	
		case 11:
			special = "test	test";
			break;	
		case 12:
			special = "test (";
			break;	
	}

	switch (arg[a1][6])
		{
		case 0:
			special = ";"+special;
			break;
		case 1:
			special = "#"+special;
			break;
		case 2:
			special = "\""+special+"\"";
			break;
		}
	
	
	
	
	
	switch (arg[a1][8])
	{
	case 0:
		break;
	case 1:
		begin = special;	
		break;
	case 2:
		line[linei++]= special;
		break;
	case 3:
		end = special;
		break;
	}
		
	if(arg[a1][10]==1)
	{
		for(int stri=0;stri<begin.length();stri++)
		{
			if(begin[stri]>='a'&&begin[stri]<='z')
			begin[stri]=begin[stri]+'A'-'a';
		}
        for(int stri=0;stri<linei;stri++)
		{
			for(int strj=0;strj<line[stri].length();strj++)
			{
				if(line[stri][strj]>='a'&&line[stri][strj]<='z')
				line[stri][strj]=line[stri][strj]+'A'-'a';
			}
		}
		for(int stri=0;stri<end.length();stri++)
		{
			if(end[stri]>='a'&&end[stri]<='z')
			end[stri]=end[stri]+'A'-'a';
		}
	}	
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         if(begin!="")
         examplefile<<begin<<"\n";
         for(int stri=0;stri<linei;stri++)
         {
         	examplefile<<line[stri];
			if(stri!=linei-1)
			 examplefile<<"\n";
         }
         if(end!="")
         examplefile<<"\n"<<end;
         if (arg[a1][9]==1)
         {
         	examplefile<<"\n";
         	if(begin!="")
         	examplefile<<begin<<"\n";
         for(int stri=0;stri<linei;stri++)
         {
         	examplefile<<line[stri];
			if(stri!=linei-1)
			 examplefile<<"\n";
         }
         if(end!="")
         examplefile<<"\n"<<end;
         } 
         examplefile.close();        //关闭文件 
    } 
    }
}
	return 0;
}
