#include <iostream>
#include <fstream>

#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <climits>
#include <ctime>
int src_input;
int arg[2000][12];
int bi;

int flag[2000];

std::string number;

int resulta[2000][500];
int resultl[2000];
int add[2000];

void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
		int a[500];
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
	a[n-1-i] = 1+rand();
    
    for(int i=0;i<zero;i++)
	a[n-positive-1-i] = 0;
	//负数
	for(int i=0;i<negative;i++)
	a[i] = (1+rand())/(-1); 
    	//m2为正数中相同的数，m3为负数中相同的数，都不能为1。 
    	int m1 = same - zero;
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
    
    int k=0;
    switch (arg[a1][4])
	    {
		case 0:
				break;
		case 1:
				k=1+rand()%4;
				break;			
		case 2:
                k=5+rand()%5;
				break;					
	    }
    
    for(int i=0;i<n;i++)
    a[i]=a[i]+k;
    
    for(int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[j]<a[i])
    		{
    			int temp=a[j];
    			a[j]=a[i];
    			a[i]=temp;
    		}
    	}
    }    
    
    if(arg[a1][5]==1)
    {
    	for(int i=0;i<n/2;i++)
    	{
    		int temp=a[i];
    		a[i]=a[n-1-i];
    		a[n-1-i]=temp;
    	}
    }
    if(arg[a1][5]==2)
    {
    	for(int i=0;i<n;i++)
       {
    	int tem=rand()%n;
		int temp=a[i];
		a[i]=a[tem];
		a[tem]=temp; 
	   }
    }
    
    for(int i=0;i<n;i++)
    resulta[a1][i]=a[i];    
    resultl[a1]=n;
    add[a1]=k;
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
    
    for(int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[j]<a[i])
    		{
    			int temp=a[j];
    			a[j]=a[i];
    			a[i]=temp;
    		}
    	}
    }    
    
    if(arg[a2][5]==1)
    {
    	for(int i=0;i<n/2;i++)
    	{
    		int temp=a[i];
    		a[i]=a[n-1-i];
    		a[n-1-i]=temp;
    	}
    }
    if(arg[a2][5]==2)
    {
    	for(int i=0;i<n;i++)
       {
    	int tem=rand()%n;
		int temp=a[i];
		a[i]=a[tem];
		a[tem]=temp; 
	   }
    }
    
    for(int i=0;i<n;i++)
    resulta[a2][i]=a[i];    
    resultl[a2]=n;
    add[a2]=k;
    
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         for(int i=0;i<n;i++)
         {
         	examplefile1 << a[i];
         	if(i!=n-1) 
         	examplefile1 << " ";
         }   
         examplefile1.close();        //关闭文件 
    } 
    flag[a1]=1;
    flag[a2]=1;
	}
	
	if(flag[a1]==1&&flag[a2]!=1)
	{
		int n=resultl[a1];
		int a[500];
		for(int i=0;i<n;i++)
        a[i]=resulta[a1][i];  
		
		for(int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[j]<a[i])
    		{
    			int temp=a[j];
    			a[j]=a[i];
    			a[i]=temp;
    		}
    	}
    }    
    
    if(arg[a2][5]==1)
    {
    	for(int i=0;i<n/2;i++)
    	{
    		int temp=a[i];
    		a[i]=a[n-1-i];
    		a[n-1-i]=temp;
    	}
    }
    if(arg[a2][5]==2)
    {
    	for(int i=0;i<n;i++)
       {
    	int tem=rand()%n;
		int temp=a[i];
		a[i]=a[tem];
		a[tem]=temp; 
	   }
    }
    
    for(int i=0;i<n;i++)
    resulta[a2][i]=a[i];    
    resultl[a2]=n;
    add[a2]=add[a1];
    
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
    flag[a2]=1;
	}
	
	if(flag[a1]!=1&&flag[a2]==1)
	{
		int n=resultl[a2];
		int a[500];
		for(int i=0;i<n;i++)
        a[i]=resulta[a2][i];  
		
		for(int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[j]<a[i])
    		{
    			int temp=a[j];
    			a[j]=a[i];
    			a[i]=temp;
    		}
    	}
    }    
    
    if(arg[a1][5]==1)
    {
    	for(int i=0;i<n/2;i++)
    	{
    		int temp=a[i];
    		a[i]=a[n-1-i];
    		a[n-1-i]=temp;
    	}
    }
    if(arg[a1][5]==2)
    {
    	for(int i=0;i<n;i++)
       {
    	int tem=rand()%n;
		int temp=a[i];
		a[i]=a[tem];
		a[tem]=temp; 
	   }
    }
    
    for(int i=0;i<n;i++)
    resulta[a1][i]=a[i];    
    resultl[a1]=n;
    add[a1]=add[a2];
    
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
    flag[a1]=1;
	}
} 

void MR1_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
		int a[500];
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
	a[n-1-i] = 1+rand();
    
    for(int i=0;i<zero;i++)
	a[n-positive-1-i] = 0;
	//负数
	for(int i=0;i<negative;i++)
	a[i] = (1+rand())/(-1); 
    	//m2为正数中相同的数，m3为负数中相同的数，都不能为1。 
    	int m1 = same - zero;
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
    
    int k=0;
    switch (arg[a1][4])
	    {
		case 0:
				break;
		case 1:
				k=1+rand()%4;
				break;			
		case 2:
                k=5+rand()%5;
				break;					
	    }
    
    for(int i=0;i<n;i++)
    a[i]=a[i]+k;
    
    for(int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[j]<a[i])
    		{
    			int temp=a[j];
    			a[j]=a[i];
    			a[i]=temp;
    		}
    	}
    }    
    
    if(arg[a1][5]==1)
    {
    	for(int i=0;i<n/2;i++)
    	{
    		int temp=a[i];
    		a[i]=a[n-1-i];
    		a[n-1-i]=temp;
    	}
    }
    if(arg[a1][5]==2)
    {
    	for(int i=0;i<n;i++)
       {
    	int tem=rand()%n;
		int temp=a[i];
		a[i]=a[tem];
		a[tem]=temp; 
	   }
    }
    
    for(int i=0;i<n;i++)
    resulta[a1][i]=a[i];    
    resultl[a1]=n;
    add[a1]=k;
    
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
    
    for(int i=0;i<n;i++)
    a[i]=a[i]-k;
    
    switch (arg[a2][4])
	    {
		case 0: k=0;
				break;
		case 1:
				k=1+rand()%4;
				break;			
		case 2:
                k=5+rand()%5;
				break;					
	    }
    
    for(int i=0;i<n;i++)
    a[i]=a[i]+k;
    
    for(int i=0;i<n;i++)
    resulta[a2][i]=a[i];    
    resultl[a2]=n;
    add[a2]=k;
    
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         for(int i=0;i<n;i++)
         {
         	examplefile1 << a[i];
         	if(i!=n-1) 
         	examplefile1 << " ";
         }   
         examplefile1.close();        //关闭文件 
    } 
    flag[a1]=1;
    flag[a2]=1;
	}
	
	if(flag[a1]==1&&flag[a2]!=1)
	{
		int n=resultl[a1];
		int a[500];
		for(int i=0;i<n;i++)
        a[i]=resulta[a1][i];  
		int k=add[a1];
		
	for(int i=0;i<n;i++)
    a[i]=a[i]-k;
    
    switch (arg[a2][4])
	    {
		case 0: k=0;
				break;
		case 1:
				k=1+rand()%4;
				break;			
		case 2:
                k=5+rand()%5;
				break;					
	    }
    
    for(int i=0;i<n;i++)
    a[i]=a[i]+k;
    
    for(int i=0;i<n;i++)
    resulta[a2][i]=a[i];    
    resultl[a2]=n;
    add[a2]=k;
    
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
    flag[a2]=1;
	}
	
	if(flag[a1]!=1&&flag[a2]==1)
	{
		int n=resultl[a2];
		int a[500];
		for(int i=0;i<n;i++)
        a[i]=resulta[a2][i];  
		int k=add[a2];
		
	for(int i=0;i<n;i++)
    a[i]=a[i]-k;
    
    switch (arg[a1][4])
	    {
		case 0: k=0;
				break;
		case 1:
				k=1+rand()%4;
				break;			
		case 2:
                k=5+rand()%5;
				break;					
	    }
    
    for(int i=0;i<n;i++)
    a[i]=a[i]+k;
    
    for(int i=0;i<n;i++)
    resulta[a1][i]=a[i];    
    resultl[a1]=n;
    add[a1]=k;
    
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
    flag[a1]=1;
	}
} 

void MR2_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
		int a[500];
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
	a[n-1-i] = 1+rand();
    
    for(int i=0;i<zero;i++)
	a[n-positive-1-i] = 0;
	//负数
	for(int i=0;i<negative;i++)
	a[i] = (1+rand())/(-1); 
    	//m2为正数中相同的数，m3为负数中相同的数，都不能为1。 
    	int m1 = same - zero;
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
    
    int k=0;
    switch (arg[a1][4])
	    {
		case 0:
				break;
		case 1:
				k=1+rand()%4;
				break;			
		case 2:
                k=5+rand()%5;
				break;					
	    }
    
    for(int i=0;i<n;i++)
    a[i]=a[i]+k;
    
    for(int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[j]<a[i])
    		{
    			int temp=a[j];
    			a[j]=a[i];
    			a[i]=temp;
    		}
    	}
    }    
    
    if(arg[a1][5]==1)
    {
    	for(int i=0;i<n/2;i++)
    	{
    		int temp=a[i];
    		a[i]=a[n-1-i];
    		a[n-1-i]=temp;
    	}
    }
    if(arg[a1][5]==2)
    {
    	for(int i=0;i<n;i++)
       {
    	int tem=rand()%n;
		int temp=a[i];
		a[i]=a[tem];
		a[tem]=temp; 
	   }
    }
    
    for(int i=0;i<n;i++)
    resulta[a1][i]=a[i];    
    resultl[a1]=n;
    add[a1]=k;
    
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
    
    for(int i=0;i<n;i++)
    a[i]=a[i]*(-1);
    
    for(int i=0;i<n;i++)
    resulta[a2][i]=a[i];    
    resultl[a2]=n;
    add[a2]=k;
    
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         for(int i=0;i<n;i++)
         {
         	examplefile1 << a[i];
         	if(i!=n-1) 
         	examplefile1 << " ";
         }   
         examplefile1.close();        //关闭文件 
    } 
    flag[a1]=1;
    flag[a2]=1;
	}
	
	if(flag[a1]==1&&flag[a2]!=1)
	{
		int n=resultl[a1];
		int a[500];
		for(int i=0;i<n;i++)
        a[i]=resulta[a1][i];  
		
		for(int i=0;i<n;i++)
        a[i]=a[i]*(-1);
    
    for(int i=0;i<n;i++)
    resulta[a2][i]=a[i];    
    resultl[a2]=n;
    add[a2]=add[a1];
    
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
    flag[a2]=1;
	}
	
	if(flag[a1]!=1&&flag[a2]==1)
	{
		int n=resultl[a2];
		int a[500];
		for(int i=0;i<n;i++)
        a[i]=resulta[a2][i];  
	for(int i=0;i<n;i++)
    a[i]=a[i]*(-1);
    
    for(int i=0;i<n;i++)
    resulta[a1][i]=a[i];    
    resultl[a1]=n;
    add[a1]=add[a2];
    
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
    flag[a1]=1;
	}
} 
	
void judgeMR0()
{	
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]!=arg[j][5])
			{
				   MR0_testcase(i,j);
			}	
		}
	
	}
}

void judgeMR1()
{	
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]!=arg[j][4]&&arg[i][5]==arg[j][5])
			{
				   MR1_testcase(i,j);
			}	
		}
	
	}
}

void judgeMR2()
{	
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][4]==0&&arg[i][1]!=arg[i][2])
		{
			for(int j=i+1;j<bi;j++)
			{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][2]&&arg[i][2]==arg[j][1]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5])
			{
				   MR2_testcase(i,j);
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
		for(int i=0;i<6;i++)
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
//    judgeMR2();
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
    int a[500];
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
	a[n-1-i] = 1+rand();
    
    for(int i=0;i<zero;i++)
	a[n-positive-1-i] = 0;
	//负数
	for(int i=0;i<negative;i++)
	a[i] = (1+rand())/(-1); 
    	//m2为正数中相同的数，m3为负数中相同的数，都不能为1。 
    	int m1 = same - zero;
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
    
    int k=0;
    switch (arg[a1][4])
	    {
		case 0:
				break;
		case 1:
				k=1+rand()%4;
				break;			
		case 2:
                k=5+rand()%5;
				break;					
	    }
    
    for(int i=0;i<n;i++)
    a[i]=a[i]+k;
    
    for(int i=0;i<n-1;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[j]<a[i])
    		{
    			int temp=a[j];
    			a[j]=a[i];
    			a[i]=temp;
    		}
    	}
    }
    
    
    if(arg[a1][5]==1)
    {
    	for(int i=0;i<n/2;i++)
    	{
    		int temp=a[i];
    		a[i]=a[n-1-i];
    		a[n-1-i]=temp;
    	}
    }
    if(arg[a1][5]==2)
    {
    	for(int i=0;i<n;i++)
       {
    	int tem=rand()%n;
		int temp=a[i];
		a[i]=a[tem];
		a[tem]=temp; 
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
} 
