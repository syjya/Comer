#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <climits>
#include <ctime>
#define MAX 10000
int src_input;
int arg[2000][12];
int bi;

int flag[2000];

std::string number;

int resulta[500][500];
int resultl[500];

void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
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
	if(negative+positive+zero>=same&&zero<=same&&same!=zero+1&&(!(arg[a1][4]==1&&negative+positive+zero<=1)))
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
    
    int e;
    //常数e 
	switch (arg[a1][4])
		{
			
			case 0:
				e=a[0]-1;
				break;
			case 1:
				e=a[n-1]-1;
				break;			
			case 2:
                e=a[n-1];
				break;		
			case 3:
				e=a[n-1]+1;
				break;	
			case 4:
				e=-10000+rand()%20000; 
				break;			
		}
    
    for(int i=0;i<n;i++)
    {
    	resulta[a1][i]=a[i];
    	resulta[a2][i]=a[i];
    }
    resulta[a1][n]=e;
    resulta[a2][n]=e+1;
     resultl[a1]=n;
     resultl[a2]=n;
    
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<n;i++)
         {
         	examplefile << a[i];
         	examplefile << " ";
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
         	examplefile1 << a[i];
         	examplefile1 << " ";
         } 
         examplefile1<<e+1;
         examplefile1.close();        //关闭文件 
    } 
    
	flag[a1]=1;
    flag[a2]=1;
   }
   
   if(flag[a1]==1&&flag[a2]!=1)
   {
   	    int n=resultl[a1];
   	    for(int i=0;i<n;i++)
        {
    		resulta[a2][i]=resulta[a1][i];
    	}
        resulta[a2][n]=resulta[a1][n]+1;
        resultl[a2]=n;
        char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<=n;i++)
         {
         	examplefile << resulta[a2][i];
         	if(i!=n)
         	examplefile << " ";
         } 
         examplefile.close();        //关闭文件 
    } 
    flag[a2]=1;
   }
   
    if(flag[a1]!=1&&flag[a2]==1)
   {
   	    int n=resultl[a2];
   	    for(int i=0;i<n;i++)
        {
    		resulta[a1][i]=resulta[a2][i];
    	}
        resulta[a1][n]=resulta[a2][n]-1;
        resultl[a1]=n;
        char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<=n;i++)
         {
         	examplefile << resulta[a1][i];
         	if(i!=n) 
         	examplefile << " ";
         } 
         examplefile.close();        //关闭文件 
    } 
    flag[a1]=1;
   }
}

void MR1_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
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
				negative=19;
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
	if(negative+positive+zero>=same&&zero<=same&&same!=zero+1&&(!(arg[a1][4]==1&&negative+positive+zero<=1)))
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
    
    int e;
    //常数e 
	switch (arg[a1][4])
		{
			
			case 0:
				e=a[0]-1;
				break;
			case 1:
				e=a[n/2]+1;
				break;			
			case 2:
                e=a[n/2];
				break;		
			case 3:
				e=a[n-1]+1;
				break;	
			case 4:
				e=-10000+rand()%20000; 
				break;			
		}
    
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<n;i++)
         {
         	examplefile << a[i];
         	examplefile << " ";
         } 
         examplefile<<e;
         examplefile.close();        //关闭文件 
    } 
    int f=-1;
    if(a[0]<0)
    f=a[0]-1;
    
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         examplefile1 << f<<" ";
         for(int i=0;i<n;i++)
         {
         	examplefile1 << a[i];
         	examplefile1 << " ";
         } 
         examplefile1<<e;
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
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]-1&&arg[i][4]>0&&arg[i][4]<3)
			{
				   MR0_testcase(i,j);
			}
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]+1&&arg[j][4]>0&&arg[j][4]<3)
			{
				   MR0_testcase(j,i);
			}			
		}
	}
}

void judgeMR1()
{	
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][4]==4)
		{
			for(int j=i+1;j<bi;j++)
			{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]-1&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4])
			{
				   MR1_testcase(i,j);
				   break;
			}
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]+1&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4])
			{
				   MR1_testcase(j,i);
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
	for(int i=0;i<2000;i++)
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
//    judgeMR1();
    
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
	if(negative+positive+zero>=same&&zero<=same&&same!=zero+1&&(!(arg[a1][4]==1&&negative+positive+zero<=1)))
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
    
    int e;
    //常数e 
	switch (arg[a1][4])
		{
			
			case 0:
				e=a[0]-1;
				break;
			case 1:
				e=a[n/2]+1;
				break;			
			case 2:
                e=a[n/2];
				break;		
			case 3:
				e=a[n-1]+1;
				break;	
			case 4:
				e=-10000+rand()%20000; 
				break;			
		}

	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<n;i++)
         {
         	examplefile << a[i];
         	examplefile << " ";
         } 
         examplefile<<e;
         examplefile.close();        //关闭文件 
    } 
    } 
	} 
} 
