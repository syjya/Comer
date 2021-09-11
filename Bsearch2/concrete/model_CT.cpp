#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#define MAX 10000

int main(int argc, char *argv[])
{
    int src_input=0;
	//std::ifstream f_in(".\\input.txt");
	std::ifstream f_in(argv[1]);
	//std::string out=".\\input";
	std::string out=argv[2];
	std::string str;
    srand((unsigned int)(time(NULL)));
	while (getline(f_in, str))
	{
		int arg[6];
		int jj=0;
		for(int i=1;i<6;i++)
		{
			while(str[jj]==' ')
			jj++;
			if(str[jj]!=' ')
			arg[i]=str[jj]-'0';
			jj++; 
		}
    
    int a[MAX];
    int positive,zero,same; 
    while(1)
	{
		
    switch (arg[2])
	{
		case 0:
				positive=0;
				break;
		case 1:
				positive=1+rand()%19;
				break;			
		case 2:
                positive=20+rand()%20;
				break;					
	}
	switch (arg[3])
	{
		case 0:
				zero=0;
				break;
		case 1:
				zero=1+rand()%4;
				break;			
		case 2:
                zero=5+rand()%6;
				break;					
	}		
	switch (arg[1])
	{
		case 0:
				same=0;
				break;
		case 1:
				same=2+rand()%9;
				break;			
		case 2:
                same=10+rand()%10;
				break;					
	 }
	    if((zero+positive>=same)&&(zero<=same)&&(same-zero!=1)&&(!((arg[4]==1)&&(zero+positive<=1))))
		break;  
    }
	int n = positive + zero;
    for(int i=0;i<n;i++)
    a[i] = -1;
    
    for(int i=0;i<zero;i++)
	a[i] = 0;	    
     //正数 
    for(int i=0;i<positive;i++)
	a[zero+i] = 50+2*i;

    	int m1 = same - zero;
    	if(zero==1)
    	m1=same;
    	for(int i=0;i<m1-1;i++)
    	a[n-2-i]=a[n-1];
    
    int e;
    //常数e 
	switch (arg[4])
		{
			
			case 0:
				e=a[0]-1;
				break;
			case 1:
				e=a[0]+1;
				break;			
			case 2:
                e=a[n-1];
				break;		
			case 3:
				e=a[n-1]+1;
				break;				
	}
	int square;
	switch (arg[5])
		{
			
			case 0:
				square=1;
				break;
			case 1:
				square=2;
				break;							
	}
	
    char filename[200];
	sprintf(filename,"%s/%d%s",out.c_str(),src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<n;i++)
		{
		a[i]=pow(a[i],square);
		examplefile << a[i] << "  ";
		}
         examplefile<<e; 
         examplefile.close();        //关闭文件 
    }

	}	
} 
