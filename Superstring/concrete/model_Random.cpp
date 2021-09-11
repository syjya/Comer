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
    	int l=1+rand()%30;
    	std::string b[500];
    	for(int j=0;j<l;j++)
    	{
    		b[j]="";
    		int bl=1+rand()%10;
    		for(int j1=0;j1<bl;j1++)
    		{
    			int tempb=rand()%3;
    			if(tempb==0)
    			{
    				int tem=rand()%26;
		            char tempchar=tem+'a'; //a-z 
		            b[j]+=tempchar;
    			}
    			if(tempb==1)
    			{
    				int tem=rand()%6;
		            char tempchar=tem+'*'; 
		            b[j]+=tempchar;
    			}
    			if(tempb==2)
    			{
    				int tem=rand()%10;
		            char tempchar='0'+ tem;
		            b[j]+=tempchar;
    			}
    		}
    	}
    	
    	char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
	         for(int j=0;j<l;j++)
	         {
	         	examplefile << b[j];
	         	if(j!=l-1)
	         	examplefile << " ";
	         }   
	         examplefile.close();        //¹Ø±ÕÎÄ¼þ 
	    } 
    	
	}
} 
