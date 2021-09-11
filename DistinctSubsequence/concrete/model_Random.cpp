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
    srand((unsigned int)(time(NULL)));
    for(int src_input=0;src_input<bi;src_input++)
    {
    	int l=rand()%30;
		int l1=0;
		if(l>0)
		l1 = rand()%l; 
		
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
		
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
	        for(int j=0;j<l;j++)
			{
				examplefile<<a[j];
			} 
			examplefile<<"\n";
			
			for(int j=0;j<l1;j++)
			{
				examplefile<<b[j];
			} 
	        examplefile.close();        //¹Ø±ÕÎÄ¼þ 
	    } 
	
	} 
} 
