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
int src_input;
int arg[1000][12];
int bi;

int flag[1000];
 
string number;

void MR0_0_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
	
	int k1=1,k2=1,k3=1;
    int num=0,ch=0,no=0;
	switch(arg[a1][1])
	{
		case 0: 
		        break;
		case 1: k1=2;
		        break;
		case 2: k1=5;
		        break;   
	} 
    switch(arg[a1][3])
	{
		case 0: 
		        break;
		case 1: k2=2;
		        break;
		case 2: k2=5;
		        break;   
	} 
	switch(arg[a1][5])
	{
		case 0: 
		        break;
		case 1: k3=2;
		        break;
		case 2: k3=5;
		        break;   
	} 
    
    switch(arg[a1][0])
	{
		case 0: 
		        break;
		case 1: num=5;
		        break;
		case 2: num=6+rand()%5;
		        break;   
	} 
    
    switch(arg[a1][2])
	{
		case 0: 
		        break;
		case 1: ch=1+rand()%5;
		        break;
		case 2: ch=6+rand()%5;
		        break;   
	}
	
	switch(arg[a1][4])
	{
		case 0: 
		        break;
		case 1: no=1+rand()%5;
		        break;
		case 2: no=6+rand()%5;
		        break;   
	}
    
    int n1=num*k1;
    int n2=ch*k2;
    int n3=no*k3;
    int n=n1+n2+n3;

	char a[500];
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<n1)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<n1+n2)
	{
		int tem=rand()%10;
		a[i++]=tem+'a'; //a-j
	}
	while(i<n)
	{
		int tem=rand()%6;
		a[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	
	for(int j=0;j<n;j++)
	{
		int tem=rand()%n;
		int temp=a[j];
		a[j]=a[tem];
		a[tem]=temp;
	}
	
	int q=0;
	char b[5];
	
	int t1;
	int m=0;
	int m1=n/2;
	
	switch(arg[a1][6])
	{
		case 0: t1=rand()%16;
		        b[q++] = 'k'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	b[q++]=a[m];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	b[q++]=a[m1];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 3: b[q++]=a[n-1];
		        break;	    
	}
	
	if(arg[a1][7]==1&&q>1)
	q--;
	 
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		   examplefile<<a[j];
		}
		examplefile<<" ";
        for(int j=0;j<q;j++)
		{
		   examplefile<<b[j];
		}
         examplefile.close();        //关闭文件 
    }
    int tem1=rand()%10;
	a[n++]='0'+ tem1;
	
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		   examplefile1<<a[j];
		}
		examplefile1<<" ";
        for(int j=0;j<q;j++)
		{
		   examplefile1<<b[j];
		}
         examplefile1.close();        //关闭文件 
    }
	flag[a1]=1;
    flag[a2]=1;	
}

void MR0_1_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
			 int k1=1,k2=1,k3=1;
    	int num=0,ch=0,no=0;
	switch(arg[a1][1])
	{
		case 0: 
		        break;
		case 1: k1=2;
		        break;
		case 2: k1=5;
		        break;   
	} 
    switch(arg[a1][3])
	{
		case 0: 
		        break;
		case 1: k2=2;
		        break;
		case 2: k2=5;
		        break;   
	} 
	switch(arg[a1][5])
	{
		case 0: 
		        break;
		case 1: k3=2;
		        break;
		case 2: k3=5;
		        break;   
	} 
    
    switch(arg[a1][0])
	{
		case 0: 
		        break;
		case 1: num=1+rand()%5;
		        break;
		case 2: num=6+rand()%5;
		        break;   
	} 
    
    switch(arg[a1][2])
	{
		case 0: 
		        break;
		case 1: ch=5;
		        break;
		case 2: ch=6+rand()%5;
		        break;   
	}
	
	switch(arg[a1][4])
	{
		case 0: 
		        break;
		case 1: no=1+rand()%5;
		        break;
		case 2: no=6+rand()%5;
		        break;   
	}
    
    int n1=num*k1;
    int n2=ch*k2;
    int n3=no*k3;
    int n=n1+n2+n3;

	char a[500];
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<n1)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<n1+n2)
	{
		int tem=rand()%10;
		a[i++]=tem+'a'; //a-j
	}
	while(i<n)
	{
		int tem=rand()%6;
		a[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	for(int j=0;j<n;j++)
	{
		int tem=rand()%n;
		int temp=a[j];
		a[j]=a[tem];
		a[tem]=temp;
	}
	
	int q=0;
	char b[5];
	
	int t1;
	int m=0;
	int m1=n/2;
	
	switch(arg[a1][6])
	{
		case 0: t1=rand()%16;
		        b[q++] = 'k'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	b[q++]=a[m];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	b[q++]=a[m1];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 3: b[q++]=a[n-1];
		        break;	    
	}
	
	if(arg[a1][7]==1&&q>1)
	q--;
	 
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		   examplefile<<a[j];
		}
		examplefile<<" ";
        for(int j=0;j<q;j++)
		{
		   examplefile<<b[j];
		}
         examplefile.close();        //关闭文件 
    }
    
    int tem1=rand()%10;
	a[n++]=tem1+'a';
	
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		   examplefile1<<a[j];
		}
		examplefile1<<" ";
        for(int j=0;j<q;j++)
		{
		   examplefile1<<b[j];
		}
         examplefile1.close();        //关闭文件 
    }
	flag[a1]=1;
    flag[a2]=1;	
}

void MR0_2_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
			 int k1=1,k2=1,k3=1;
    	int num=0,ch=0,no=0;
	switch(arg[a1][1])
	{
		case 0: 
		        break;
		case 1: k1=2;
		        break;
		case 2: k1=5;
		        break;   
	} 
    switch(arg[a1][3])
	{
		case 0: 
		        break;
		case 1: k2=2;
		        break;
		case 2: k2=5;
		        break;   
	} 
	switch(arg[a1][5])
	{
		case 0: 
		        break;
		case 1: k3=2;
		        break;
		case 2: k3=5;
		        break;   
	} 
    
    switch(arg[a1][0])
	{
		case 0: 
		        break;
		case 1: num=1+rand()%5;
		        break;
		case 2: num=6+rand()%5;
		        break;   
	} 
    
    switch(arg[a1][2])
	{
		case 0: 
		        break;
		case 1: ch=1+rand()%5;
		        break;
		case 2: ch=6+rand()%5;
		        break;   
	}
	
	switch(arg[a1][4])
	{
		case 0: 
		        break;
		case 1: no=5;
		        break;
		case 2: no=6+rand()%5;
		        break;   
	}
    
    int n1=num*k1;
    int n2=ch*k2;
    int n3=no*k3;
    int n=n1+n2+n3;

	char a[500];
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<n1)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<n1+n2)
	{
		int tem=rand()%10;
		a[i++]=tem+'a'; //a-j
	}
	while(i<n)
	{
		int tem=rand()%6;
		a[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	for(int j=0;j<n;j++)
	{
		int tem=rand()%n;
		int temp=a[j];
		a[j]=a[tem];
		a[tem]=temp;
	}
	
	int q=0;
	char b[5];
	
	int t1;
	int m=0;
	int m1=n/2;
	
	switch(arg[a1][6])
	{
		case 0: t1=rand()%16;
		        b[q++] = 'k'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	b[q++]=a[m];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	b[q++]=a[m1];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 3: b[q++]=a[n-1];
		        break;	    
	}
	
	if(arg[a1][7]==1&&q>1)
	q--;
	 
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		   examplefile<<a[j];
		}
		examplefile<<" ";
        for(int j=0;j<q;j++)
		{
		   examplefile<<b[j];
		}
         examplefile.close();        //关闭文件 
    }
    int tem1=rand()%6;
	a[n++]= tem1+'*';
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		   examplefile1<<a[j];
		}
		examplefile1<<" ";
        for(int j=0;j<q;j++)
		{
		   examplefile1<<b[j];
		}
         examplefile1.close();        //关闭文件 
    }	
	flag[a1]=1;
    flag[a2]=1;	
}

void MR1_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
	
	int k1=1,k2=1,k3=1;
    int num=0,ch=0,no=0;
	switch(arg[a1][1])
	{
		case 0: 
		        break;
		case 1: k1=2;
		        break;
		case 2: k1=5;
		        break;   
	} 
    switch(arg[a1][3])
	{
		case 0: 
		        break;
		case 1: k2=2;
		        break;
		case 2: k2=5;
		        break;   
	} 
	switch(arg[a1][5])
	{
		case 0: 
		        break;
		case 1: k3=2;
		        break;
		case 2: k3=5;
		        break;   
	} 
    
    switch(arg[a1][0])
	{
		case 0: 
		        break;
		case 1: num=1+rand()%5;
		        break;
		case 2: num=6+rand()%5;
		        break;   
	} 
    
    switch(arg[a1][2])
	{
		case 0: 
		        break;
		case 1: ch=1+rand()%5;
		        break;
		case 2: ch=6+rand()%5;
		        break;   
	}
	
	switch(arg[a1][4])
	{
		case 0: 
		        break;
		case 1: no=1+rand()%5;
		        break;
		case 2: no=6+rand()%5;
		        break;   
	}
    
    int n1=num*k1;
    int n2=ch*k2;
    int n3=no*k3;
    int n=n1+n2+n3;

	char a[500];
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<n1)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<n1+n2)
	{
		int tem=rand()%10;
		a[i++]=tem+'a'; //a-j
	}
	while(i<n)
	{
		int tem=rand()%6;
		a[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	for(int j=0;j<n;j++)
	{
		int tem=rand()%n;
		int temp=a[j];
		a[j]=a[tem];
		a[tem]=temp;
	}
	
	int q=0;
	char b[5];
	
	int t1;
	int m=0;
	int m1=n/2;
	
	switch(arg[a1][6])
	{
		case 0: t1=rand()%16;
		        b[q++] = 'k'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	b[q++]=a[m];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	b[q++]=a[m1];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 3: b[q++]=a[n-1];
		        break;	    
	}
	
	if(q<2)
	return;
	
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		   examplefile<<a[j];
		}
		examplefile<<" ";
        for(int j=0;j<q;j++)
		{
		   examplefile<<b[j];
		}
         examplefile.close();        //关闭文件 
    } 
    
    q--;
    
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		   examplefile1<<a[j];
		}
		examplefile1<<" ";
        for(int j=0;j<q;j++)
		{
		   examplefile1<<b[j];
		}
         examplefile1.close();        //关闭文件 
    } 
    
	flag[a1]=1;
    flag[a2]=1;	
}	

void judgeMR0_0()
{	
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][1]==0&&arg[i][6]>0)
		{
			for(int j=i+1;j<bi;j++)
			{
				int error=0;
				int com=0;
				for(;com<8;com++)
				{
					if(com==0)
					{
						if(arg[i][com]==arg[j][com]-1)
						{
							error=1;
						}
						else if(arg[i][com]==arg[j][com]+1)
						{
							error=-1;
						}
						else
						break;
					}
					else if(arg[i][com]!=arg[j][com])
					break;
				}
				if(error==1&&com>=8)
				{
				   MR0_0_testcase(i,j);
				   break;
				}
				if(error==-1&&com>=8)
				{
				   MR0_0_testcase(j,i);			    
				   break;
				}			
			}
		}
	}
}

void judgeMR0_1()
{	
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][3]==0&&arg[i][6]>0)
		{
			for(int j=i+1;j<bi;j++)
			{
				int error=0;
				int com=0;
				for(;com<8;com++)
				{
					if(com==2)
					{
						if(arg[i][com]==arg[j][com]-1)
						{
							error=1;
						}
						else if(arg[i][com]==arg[j][com]+1)
						{
							error=-1;
						}
						else
						break;
					}
					else if(arg[i][com]!=arg[j][com])
					break;
				}
				if(error==1&&com>=8)
				{
				   MR0_1_testcase(i,j);
				   
				   break;
				}
				if(error==-1&&com>=8)
				{
				   MR0_1_testcase(j,i);				    
				   break;
				}			
			}
		}
	}
}

void judgeMR0_2()
{	
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][5]==0&&arg[i][6]>0)
		{
			for(int j=i+1;j<bi;j++)
			{
				int error=0;
				int com=0;
				for(;com<8;com++)
				{
					if(com==4)
					{
						if(arg[i][com]==arg[j][com]-1)
						{
							error=1;
						}
						else if(arg[i][com]==arg[j][com]+1)
						{
							error=-1;
						}
						else
						break;
					}
					else if(arg[i][com]!=arg[j][com])
					break;
				}
				if(error==1&&com>=8)
				{
				   MR0_2_testcase(i,j);
				   
				   break;
				}
				if(error==-1&&com>=8)
				{
				   MR0_2_testcase(j,i);				    
				   break;
				}			
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
				int error=0;
				int com=0;
				for(;com<=5;com++)
				{
					if(arg[i][com]!=arg[j][com])
					{
						error=1;
						break;
					}
				}
				if(error==0)
				{
					if(arg[i][6]>0&&arg[i][7]==0&&arg[j][7]==1)
					{
						MR1_testcase(i,j); 	
						break;
					}
				    if(arg[j][6]>0&&arg[j][7]==0&&arg[i][7]==1)
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
		for(int i=0;i<8;i++)
		{
			while(str[jj]==' ')
			jj++;
			if(str[jj]!=' ')
			arg[bi][i]=str[jj]-'0';
			jj++; 
		}
		bi++;
    }
//    judgeMR0_0();
//    judgeMR0_1();
//    judgeMR0_2();
//    judgeMR1();
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
		 int k1=1,k2=1,k3=1;
    	int num=0,ch=0,no=0;
	switch(arg[a1][1])
	{
		case 0: 
		        break;
		case 1: k1=2;
		        break;
		case 2: k1=5;
		        break;   
	} 
    switch(arg[a1][3])
	{
		case 0: 
		        break;
		case 1: k2=2;
		        break;
		case 2: k2=5;
		        break;   
	} 
	switch(arg[a1][5])
	{
		case 0: 
		        break;
		case 1: k3=2;
		        break;
		case 2: k3=5;
		        break;   
	} 
    
    switch(arg[a1][0])
	{
		case 0: 
		        break;
		case 1: num=1+rand()%5;
		        break;
		case 2: num=6+rand()%5;
		        break;   
	} 
    
    switch(arg[a1][2])
	{
		case 0: 
		        break;
		case 1: ch=1+rand()%5;
		        break;
		case 2: ch=6+rand()%5;
		        break;   
	}
	
	switch(arg[a1][4])
	{
		case 0: 
		        break;
		case 1: no=1+rand()%5;
		        break;
		case 2: no=6+rand()%5;
		        break;   
	}
    
    int n1=num*k1;
    int n2=ch*k2;
    int n3=no*k3;
    int n=n1+n2+n3;

	char a[500];
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<n1)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<n1+n2)
	{
		int tem=rand()%10;
		a[i++]=tem+'a'; //a-j
	}
	while(i<n)
	{
		int tem=rand()%6;
		a[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	for(int j=0;j<n;j++)
	{
		int tem=rand()%n;
		int temp=a[j];
		a[j]=a[tem];
		a[tem]=temp;
	}
	
	int q=0;
	char b[5];
	
	int t1;
	int m=0;
	int m1=n/2;
	
	switch(arg[a1][6])
	{
		case 0: t1=rand()%16;
		        b[q++] = 'k'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	b[q++]=a[m];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	b[q++]=a[m1];
		        	if(q==3)
		        	break;
		        }
		        break;
		case 3: b[q++]=a[n-1];
		        break;	    
	}
	
	if(arg[a1][7]==1&&q>1)
	q--;
	 
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
	std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		   examplefile<<a[j];
		}
		examplefile<<" ";
        for(int j=0;j<q;j++)
		{
		   examplefile<<b[j];
		}
         examplefile.close();        //关闭文件 
    } 
}
    }  
} 
