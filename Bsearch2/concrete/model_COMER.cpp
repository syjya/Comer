 #include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#define MAX 10000
int src_input;
int arg[500][12];
int bi;

int flag[500];
std::string number;

void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
	if(arg[a2][4]==0)
	{
		int temp=a1;
		a1=a2;
		a2=temp;
	}
	 int a[MAX];
    int positive,zero,same; 
    while(1)
	{
		
    switch (arg[a1][1])
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
	switch (arg[a1][2])
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
	switch (arg[a1][0])
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
	    if((zero+positive>=same)&&(zero<=same)&&(same-zero!=1)&&(!((arg[a1][3]==1)&&(zero+positive<=1))))
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
	switch (arg[a1][3])
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
	switch (arg[a1][4])
		{
			
			case 0:
				square=1;
				break;
			case 1:
				square=2;
				break;							
	}
	
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<n;i++)
		{
		a[i]=pow(a[i],1);
		examplefile << a[i] << "  ";
		}
         examplefile<<e; 
         examplefile.close();        //关闭文件 
    }
    
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         for(int i=0;i<n;i++)
		{
		a[i]=pow(a[i],2);
		examplefile1 << a[i] << "  ";
		}
         examplefile1<<pow(e,2); 
         examplefile1.close();        //关闭文件 
    }
    
    flag[a1]=1;
    flag[a2]=1;
}

void judgeMR0()
{
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{
			int error=0;
			for(int com=0;com<5;com++)
			{
				if(com==4)
				{
					if(arg[i][com]+arg[j][com]!=1)
					{
						error=1;
						break;
					}
				}
				else if(arg[i][com]!=arg[j][com])
				{
					error=1;
					break;
				}
			}
				if(error==0)
				{
				   MR0_testcase(i,j);
				   break;
				}			
			}
		}
}
	

void init()
{
	src_input=0;
	bi=0;
	for(int i=0;i<500;i++)
	flag[i]=-1;
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
		for(int i=0;i<5;i++)
		{
			while(str[jj]==' ')
			jj++;
			if(str[jj]!=' ')
			arg[bi][i]=str[jj]-'0';
			jj++; 
		}
		bi++;
    }
    judgeMR0();
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
    int a[MAX];
    int positive,zero,same; 
        while(1)
	{
		
    switch (arg[a1][1])
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
	switch (arg[a1][2])
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
	switch (arg[a1][0])
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
	    if((zero+positive>=same)&&(zero<=same)&&(same-zero!=1)&&(!((arg[a1][3]==1)&&(zero+positive<=1))))
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
	switch (arg[a1][3])
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
	switch (arg[a1][4])
		{
			
			case 0:
				square=1;
				break;
			case 1:
				square=2;
				break;							
	}
	
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
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

	}	}
} 
