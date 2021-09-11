#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>
int r;
int a[12]; //保存e 
int src_input;
int arg[2000][12];
int bi;

int flag[2000];
std::string number;
void finde();

int resulta[2000][4];
void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
	int p,q,e,m,m1;
    switch (arg[a1][0])
		{
			
			case 0:
				p = 97;
				break;
			case 1:
				p = 997;
				break;			
			case 2:
                p = 2521;
				break;		
			case 3:
				p = 2999;
				break;				
		}
	
	    switch (arg[a1][1])
		{
			
			case 0:
				q = arg[a1][0]==0 ? 89 : 97 ; 
				break;
			case 1:
				q = arg[a1][0]==1 ? 947 : 997 ; 
				break;		
			case 2:
				q = arg[a1][0]==2 ? 2237 : 2521 ; 
				break;		
			case 3:
				q = arg[a1][0]==3 ? 2887 : 2999 ; 
				break;				
		}
		r= (p-1) * (q-1);
		a[0]=1;
        finde();
        e = a[arg[a1][2]];
        
        if(arg[a1][3]==0&&arg[a2][3]==2)
        {
        	while(1)
        	{
        		m=-1+rand()%(-1);
        		m1=m+p*q;
        		if(m1>0)
        		break;
        	}
        }
        else if(arg[a1][3]==1&&arg[a2][3]==2)
        {
        	m=0;
        	m1=p*q;
        }
        else if(arg[a1][3]==0&&arg[a2][3]==1)
        {
        	m1=0;
        	m=-p*q;
        }
        
        resulta[a1][0]=p;
        resulta[a1][1]=q;
        resulta[a1][2]=e;
        resulta[a1][3]=m;
        resulta[a2][0]=p;
        resulta[a2][1]=q;
        resulta[a2][2]=e;
        resulta[a2][3]=m1;
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile<< p << " "<<q << " "<<e << " "<<m; 
         examplefile.close();        //关闭文件 
    }
    
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    //std::cout<<src_input-1<<std::endl;  
    if (examplefile1.is_open())
    {  
         examplefile1<< p << " "<<q << " "<<e << " "<<m1; 
         examplefile1.close();        //关闭文件 
    }
    flag[a1]=1;
    flag[a2]=1;
    }
    if(flag[a1]==1&&flag[a2]!=1)
	{
		int m1=resulta[a1][3]+resulta[a1][0]*resulta[a1][1];
		if(arg[a2][3]==1&&m1!=0)
		return;
		if(arg[a2][3]==2&&m1<=0)
		return;
		
		resulta[a2][0]=resulta[a1][0];
        resulta[a2][1]=resulta[a1][1];
        resulta[a2][2]=resulta[a1][2];
        resulta[a2][3]=m1;
		
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile<< resulta[a2][0] << " "<<resulta[a2][1] << " "<<resulta[a2][2] << " "<<resulta[a2][3]; 
         examplefile.close();        //关闭文件 
    }
    flag[a2]=1;
    }
    
    if(flag[a1]!=1&&flag[a2]==1)
	{
		int m1=resulta[a1][3]-resulta[a1][0]*resulta[a1][1];
		if(arg[a1][3]==0&&m1>=0)
		return;
		if(arg[a1][3]==1&&m1!=0)
		return;
		
		resulta[a1][0]=resulta[a2][0];
        resulta[a1][1]=resulta[a2][1];
        resulta[a1][2]=resulta[a2][2];
        resulta[a1][3]=m1;
		
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile<< resulta[a1][0] << " "<<resulta[a1][1] << " "<<resulta[a1][2] << " "<<resulta[a1][3]; 
         examplefile.close();        //关闭文件 
    }
    flag[a1]=1;
    }
    
}	

void judgeMR0()
{
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][2]==0)
		{ 
		for(int j=i+1;j<bi;j++)
		{
			int error=0;
			int com=0;
			for(;com<4;com++)
			{
				if(com==3)
				{
					if(arg[i][com]<arg[j][com])
					error=1;
					else if(arg[i][com]>arg[j][com])
					error=-1;
					else 
					break;
				}
				else if(arg[i][com]!=arg[j][com])
				break;
			}
				if(error==1&&com>=4)
				{
				   MR0_testcase(i,j);
				}
				if(error==-1&&com>=4)
				{
				   MR0_testcase(j,i);
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
int gcd(int a,int b)
{
   if(b==0)return a; 
    else return gcd(b,a%b); 
}

//判断两个数是否互质 
bool CoPrime(int a,int b)
        {
            if(gcd(a,b)==1)
            return true;
            return false;
        }

void finde()
{
	for(int i=2,k=1;k<6;i++)
	{
		if(CoPrime(r,i))
		{
			a[k++] = i; 
		} 
	}
	for(int i=r/2;;i++)
	{
		if(CoPrime(r,i))
		{
			a[6] = i; 
			break;
		} 
	}
	for(int i=r-1,k=11;k>6;i--)
	{
		if(CoPrime(r,i))
		{
			a[k--] = i; 
		} 
	}
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
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
         	int p,q,e,m;
    switch (arg[a1][0])
		{
			
			case 0:
				p = 97;
				break;
			case 1:
				p = 997;
				break;			
			case 2:
                p = 2521;
				break;		
			case 3:
				p = 2999;
				break;				
		}
	
	    switch (arg[a1][1])
		{
			
			case 0:
				q = arg[a1][0]==0 ? 89 : 97 ; 
				break;
			case 1:
				q = arg[a1][0]==1 ? 947 : 997 ; 
				break;		
			case 2:
				q = arg[a1][0]==2 ? 2237 : 2521 ; 
				break;		
			case 3:
				q = arg[a1][0]==3 ? 2887 : 2999 ; 
				break;				
		}
		r= (p-1) * (q-1);
		a[0]=1;
        finde();
        e = a[arg[a1][2]];
        
        switch (arg[a1][3])
		{			
			case 0:
				m = -1+rand()%(-1);
				break;
			case 1:
				m = 0 ;
				break;		
			case 2:
				m = 1+rand();
				break;					
		}
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile<< p << " "<<q << " "<<e << " "<<m; 
         examplefile.close();        //关闭文件 
    }
	} 
}
} 
