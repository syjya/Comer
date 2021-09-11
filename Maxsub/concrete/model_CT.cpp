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
int arg[1000][12];
int bi;

int flag[1000];
std::string number;

void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;

	int a[MAX];
        int negative,positive,zero,same; 
        while(1)
        {
        	
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
	    switch (arg[a1][1])
	    {
		case 0:
				negative=0;
				break;
		case 1:
				negative=1+rand()%19;
				break;			
		case 2:
                negative=20+rand()%20;
				break;						
	    }
        switch (arg[a1][2])
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
	    switch (arg[a1][3])
	    {
		case 0:
				zero=0;
				break;
		case 1:
				zero=1+rand()%4;
				break;			
		case 2:
                zero=5+rand()%5;
				break;					
	    }
		if(negative+positive+zero>=same&&same>=zero&&same!=zero+1)
        break;
	}
        int n = negative+positive+zero;
        for(int i=0;i<n;i++)
        a[i] = -1;    
        //正数 
        for(int i=0;i<positive;i++)
	    a[n-1-i] = 10000 - 2 * i;
    
        for(int i=0;i<zero;i++)
	    a[n-positive-1-i] = 0;
	    
	    for(int i=0;i<negative;i++)
	    a[i] = -10000 + 2 * i; 
    
    	//m2为正数中相同的数，m3为负数中相同的数，都不能为1。 
    	int m1 = same - zero;
    	
    	if(zero==1)
    	m1=same;
    	
    	int m2 = m1 > positive ? positive : m1;
    	int m3 = m1 > m2 ? (m1-m2) : 0;
    	
    	if(m3==1)
    	{
    		m3++;
    		m2--;
    	}
    	
    	for(int i=0;i<m2-1;i++)
    	a[n-2-i]=a[n-1];
    	
    	if(m3>0)
    	{
    		for(int i=1;i<m3;i++)
    		a[i]=a[0];
    	}
    
    //倒序 
    if(arg[a1][4]==1)
    {
    	for(int i=0,j=n-1;i<=j;i++,j--)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		} 
	} 
		
	//乱序
/*	if(arg6==2)
	{
		int i=0,j=0,tmp;
		int T=50;
	    while(T--)
	    {
		i=rand()%n;
		j=rand()%n;
		tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	   }
	} */
	if(arg[a1][4] ==2)
	{
		for(int i=0,j=n-1;i<=j;i=i+2,j--)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<n;i++)
         {
         	examplefile << a[i];
         	if(i!=n-1) 
         	examplefile << " ";
         }   
         examplefile.close();        //关闭文件 
    }

	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         for(int i=n-1;i>=0;i--)
         {
         	examplefile1 << a[i];
         	if(i!=0) 
         	examplefile1 << " ";
         }   
         examplefile1.close();        //关闭文件 
    }
    flag[a1]=1;
    flag[a2]=1;
}

void judgeMR0()
{
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][4]!=2)
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
}
void init()
{
	src_input=0;
	bi=0;
	for(int i=0;i<1000;i++)
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
//    judgeMR0();
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
	int a[MAX];
        int negative,positive,zero,same; 
        while(1)
        {
        	
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
	    switch (arg[a1][1])
	    {
		case 0:
				negative=0;
				break;
		case 1:
				negative=1+rand()%19;
				break;			
		case 2:
                negative=20+rand()%20;
				break;						
	    }
        switch (arg[a1][2])
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
	    switch (arg[a1][3])
	    {
		case 0:
				zero=0;
				break;
		case 1:
				zero=1+rand()%4;
				break;			
		case 2:
                zero=5+rand()%5;
				break;					
	    }
		if(negative+positive+zero>=same&&same>=zero&&same!=zero+1)
        break;
	}
        int n = negative+positive+zero;
        for(int i=0;i<n;i++)
        a[i] = -1;    
        //正数 
        for(int i=0;i<positive;i++)
	    a[n-1-i] = 10000 - 2 * i;
    
        for(int i=0;i<zero;i++)
	    a[n-positive-1-i] = 0;
	    
	    for(int i=0;i<negative;i++)
	    a[i] = -10000 + 2 * i; 
    
    	//m2为正数中相同的数，m3为负数中相同的数，都不能为1。 
    	int m1 = same - zero;
    	
    	if(zero==1)
    	m1=same;
    	
    	int m2 = m1 > positive ? positive : m1;
    	int m3 = m1 > m2 ? (m1-m2) : 0;
    	
    	if(m3==1)
    	{
    		m3++;
    		m2--;
    	}
    	
    	for(int i=0;i<m2-1;i++)
    	a[n-2-i]=a[n-1];
    	
    	if(m3>0)
    	{
    		for(int i=1;i<m3;i++)
    		a[i]=a[0];
    	}
    
    //倒序 
    if(arg[a1][4]==1)
    {
    	for(int i=0,j=n-1;i<=j;i++,j--)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		} 
	} 
		
	if(arg[a1][4] ==2)
	{
		for(int i=0,j=n-1;i<=j;i=i+2,j--)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<n;i++)
         {
         	examplefile << a[i];
         	if(i!=n-1) 
         	examplefile << " ";
         }   
         examplefile.close();        //关闭文件 
    }
	}    
    }
    return 0;
} 
