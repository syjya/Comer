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
    	int point =1+rand()%20;
		int maxedg = point*(point -1)/2;
		int edge=rand()%(maxedg+1);
		
		int s0 = rand()%point;
		int s1 = rand()%point;
		int a[100][100];
		
		
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
				a[i][j]=-1;
		} 
		
		int m=0;
		int end=-1;
	
		if(edge>0)
		{
		   for(int i=0;i<point;i++)
		   {
		    	for(int j=0;j<point;j++)
			    {
			    	 if(i<j)
				     {
				     	a[i][j]=rand()%100+1;
				     	m++;
				     	if(m==edge)
				     	{
				     	    end=1;	
				     	    break;
				     	}
				     } 
			    }
			    if(end==1)
			    break;
		   }
		}
		
		m=0;
	    end=-1;
	    
	    for(int i=0;i<point;i++)
		{
		    for(int j=0;j<point;j++)
			{
				if(a[i][j]!=-1)
				{
					int t2=rand()%point;
					if(t2==0)
					continue;
					int t1=rand()%t2;
					int temp=a[i][j];
					a[i][j]=a[t1][t2];
					a[t1][t2]=temp;
					m++;
					if(m==edge)
				    {
				     	end=1;	
				     	break;
				    }
				}
	        }
	        if(end==1)
	        break;
	    }
		
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
	        examplefile << point<< " "<<edge;
	        for(int i=0;i<point;i++)
	    	{
	    		for(int j=0;j<point;j++)
	    		{
	    			if(a[i][j]!=-1)
	    			{
	    				examplefile<<"\n"<<i<<" "<<j<<" "<<a[i][j];
	    			}
	    		}
	    	}
		    examplefile<<"\n"<<s0<< " "<<s1;
	        examplefile.close();        //¹Ø±ÕÎÄ¼þ 
	    } 
    
    } 

} 
