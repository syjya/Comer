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

        int a,b,c;
        a = 1 + rand()%30;
		b = a + rand()%30;
		c = b - a + 1 + rand()%(2*a-1);
    	
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << a;
         examplefile << " ";
         examplefile << b;  
         examplefile << " ";
         examplefile << c; 
         examplefile.close();        //¹Ø±ÕÎÄ¼þ 
    	} 
    } 
}
