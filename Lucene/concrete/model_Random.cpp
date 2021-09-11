#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <climits>
#include <ctime> 
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "bad args" << std::endl;
	}
	int bi=atoi(argv[1]);
	std::string number=argv[2];
	std::string number1=argv[3];
    srand((unsigned int)(time(NULL)));
    for(int src_input=0;src_input<bi;src_input++)
    {
    	int l=1+rand()%30;
		int l1=1+rand()%5; 
		int l2=1+rand()%5; 
		//0-9,a-z,*,+,,,-,., 
		char a[100];
		for(int i=0;i<l;i++)
		{
			int temp=rand()%42;
			if(temp<10)
			a[i]='0'+ temp;
			else if(temp<36)
			a[i]='a'+ (temp-10);
			else
			a[i]='*'+ (temp-36);
		}
		
		char b[100];
		for(int i=0;i<l1;i++)
		{
			int temp=rand()%42;
			if(temp<10)
			b[i]='0'+ temp;
			else if(temp<36)
			b[i]='a'+ (temp-10);
			else
			b[i]='*'+ (temp-36);
		}
		
		char c[100];
		for(int i=0;i<l2;i++)
		{
			int temp=rand()%42;
			if(temp<10)
			c[i]='0'+ temp;
			else if(temp<36)
			c[i]='a'+ (temp-10);
			else
			c[i]='*'+ (temp-36);
		}
		
		std::string tempj="";
		int temp=rand()%4;
		switch(temp)
		{
			case 0: 
			        break;
			case 1: tempj="OR"; 
			        break;
			case 2: tempj="AND"; 
			        break;
			case 3: tempj="NOT"; 
			        break;	    
		}
		
		char name[200];
		sprintf(name,"%s%s%d%s",number1.c_str(),"/",src_input,".txt");
	    std::ofstream ex(name);
	    if (ex.is_open())
	    {  
	        for(int j=0;j<l;j++)
			{
				ex<<a[j];
			}
			ex<<"\n"; 
	        ex.close();        //关闭文件 
	    } 
    
	    char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
			for(int j=0;j<l1;j++)
			{
				examplefile<<b[j];
			}
		
			if(!tempj.empty())
			{
				examplefile<<"\n"<<tempj;
			}	 
			//std::cout<<std::endl<<q<<std::endl;
			examplefile<<"\n";
			for(int j=0;j<l2;j++)
			{
				examplefile<<c[j];
			}
	         examplefile.close();        //关闭文件 
	    } 
    } 
}
