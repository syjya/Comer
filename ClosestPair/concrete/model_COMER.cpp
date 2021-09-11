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

void MR0_testcase(int aa1,int aa2)
{
	if(flag[aa1]==1||flag[aa2]==1)
	return;
	
	int n = 10; 
	
	int a1,a2,a3,a4;
	
		switch(arg[aa1][1])
	   {
		case 0:a1=0;
		       break;
		case 1:a1=n/2;
		       break;
		case 2:a1=n/4;
		       break;
		case 3:a1=n/8;
		       break;
		case 4:a1=n;
		       break;
    	}
		switch(arg[aa1][2])
	   {
		case 0:a2=0;
		       break;
		case 1:a2=n/2;
		       break;
		case 2:a2=n/4;
		       break;
		case 3:a2=n/8;
		       break;
		case 4:a2=n;
		       break;
    	}
    	switch(arg[aa1][3])
	   {
		case 0:a3=0;
		       break;
		case 1:a3=n/2;
		       break;
		case 2:a3=n/4;
		       break;
		case 3:a3=n/8;
		       break;
		case 4:a3=n;
		       break;
    	}
    	a4=n-a1-a2-a3;
    	int fx;
    	int fy;
    	if(a1==n)
    	{
    		fx=rand();
    		fy=rand();
    	}
    	else if(a2==n)
    	{
    		fx=rand()/(-1);
    		fy=rand();
    	}
    	else if(a3==n)
    	{
    		fx=rand()/(-1);
    		fy=rand()/(-1);
    	}
    	else{
    		fx=rand();
    		fy=rand()/(-1);
    	}
    	
    	int a[n][2];
    	int i=0;
    	for(int j=0;j<a1;j++)
    	{
    		a[i][0]=rand();
    		a[i][1]=rand();
    		i++;
    	}
    	for(int j=a1;j<a1+a2;j++)
    	{
    		a[i][0]=rand()/(-1);
    		a[i][1]=rand();
    		i++;
    	}
    	for(int j=a1+a2;j<a1+a2+a3;j++)
    	{
    		a[i][0]=rand()/(-1);
    		a[i][1]=rand()/(-1);
    		i++;
    	}
    	for(int j=a1+a2+a3;j<n;j++)
    	{
    		a[i][0]=rand();
    		a[i][1]=rand()/(-1);
    		i++;
    	}
    	char filename[200];
	   sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
        for(int j=0;j<n;j++)
    	{
    		examplefile<<a[j][0]<<" "<<a[j][1];
    		if(j!=n-1)
    		examplefile<<"\n";
    	}
         examplefile.close();        //关闭文件 
    	} 
    	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile1(filename);
    	if (examplefile1.is_open())
    	{  
        for(int j=0;j<n;j++)
    	{
    		examplefile1<<a[j][0]<<" "<<a[j][1]<<"\n";
    	}
    	examplefile1<<fx<<" "<<fy;
         examplefile1.close();        //关闭文件 
    	} 
    	
	flag[aa1]=1;
    flag[aa2]=1;
}
void judgeMR0()
{	
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]-1&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3])
			{
				   MR0_testcase(i,j);
				   break;
			}
			if(arg[i][0]==arg[j][0]+1&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3])
			{
				   MR0_testcase(j,i);
				   break;
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
		for(int i=0;i<4;i++)
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
    
    for(int aa1=0;aa1<bi;aa1++)
    {
    if(flag[aa1]==-1)
    {
	int n = 0; 
	switch(arg[aa1][0])
	{
		case 0:n=1+rand()%10;
		       break;
		case 1:n=11+rand()%10;
		       break;       
	} 
	int a1,a2,a3,a4;
	
		switch(arg[aa1][1])
	   {
		case 0:a1=0;
		       break;
		case 1:a1=n/2;
		       break;
		case 2:a1=n/4;
		       break;
		case 3:a1=n/8;
		       break;
		case 4:a1=n;
		       break;
    	}
		switch(arg[aa1][2])
	   {
		case 0:a2=0;
		       break;
		case 1:a2=n/2;
		       break;
		case 2:a2=n/4;
		       break;
		case 3:a2=n/8;
		       break;
		case 4:a2=n;
		       break;
    	}
    	switch(arg[aa1][3])
	   {
		case 0:a3=0;
		       break;
		case 1:a3=n/2;
		       break;
		case 2:a3=n/4;
		       break;
		case 3:a3=n/8;
		       break;
		case 4:a3=n;
		       break;
    	}
    	a4=n-a1-a2-a3;
    	int a[n][2];
    	int i=0;
    	for(int j=0;j<a1;j++)
    	{
    		a[i][0]=rand();
    		a[i][1]=rand();
    		i++;
    	}
    	for(int j=a1;j<a1+a2;j++)
    	{
    		a[i][0]=rand()/(-1);
    		a[i][1]=rand();
    		i++;
    	}
    	for(int j=a1+a2;j<a1+a2+a3;j++)
    	{
    		a[i][0]=rand()/(-1);
    		a[i][1]=rand()/(-1);
    		i++;
    	}
    	for(int j=a1+a2+a3;j<n;j++)
    	{
    		a[i][0]=rand();
    		a[i][1]=rand()/(-1);
    		i++;
    	}
    	char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
        for(int j=0;j<n;j++)
    	{
    		examplefile<<a[j][0]<<" "<<a[j][1];
    		if(j!=n-1)
			 examplefile<<"\n";
    	}
         examplefile.close();        //关闭文件 
    	} 
    }
	}
}
