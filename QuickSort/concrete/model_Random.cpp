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
    	int n= 1 + rand()%20;
    	int a[500];
    	for(int i=0;i<n;i++)
    	a[i]=-500 + rand()%1000;
    	
    	char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
	         for(int i=0;i<n;i++)
	         {
	         	examplefile << a[i];
	         	if(i!=n-1) 
	         	examplefile << " ";
	         }   
	         examplefile.close();        //¹Ø±ÕÎÄ¼þ 
	    } 
    	
    }
} 
