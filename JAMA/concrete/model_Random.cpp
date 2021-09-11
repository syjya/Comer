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
    	int row,column;
    	row=1+rand()%30;
    	column=row;
	
		int n=row*column;
    	int a[500][500];
    	for(int ii=0;ii<row;ii++)
    	{
    		for(int jj=0;jj<column;jj++)
    			a[ii][jj]=-30 + rand()%60;
    	}
    		
	    char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
	        examplefile<<row<<" "<<column<<"\n"; 
		    for(int i=0;i<row;i++)
	    	{
	    		for(int j=0;j<column;j++)
	    		{
	              examplefile << a[i][j];
	              if(j!=column-1)
	              examplefile <<" ";
				}
				if(i!=row-1)
				examplefile<< "\n";
	    	}
	         examplefile.close();        //¹Ø±ÕÎÄ¼þ 
	    } 
    }
}
	 
  
