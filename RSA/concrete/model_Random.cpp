#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> 
#include <ctime>
#include <cmath>
using namespace std;

int r;
int a[12]; //保存e 

void finde();

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
	int bi=atoi(argv[1]);
	std::string number=argv[2];
    srand((unsigned int)(time(NULL)));
    for(int src_input=0;src_input<bi;src_input++)
    {
    	
        int temp_num[10]={89,97,947,997,2237,2521,2593,2609,2887,2999};
        int p=temp_num[rand()%10];
        int q=temp_num[rand()%10];
    	r= (p-1) * (q-1);
		a[0]=1;
        finde();
        int e = a[rand()%12];
        int m = -50 + rand()%100;
        
        char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
	         examplefile<< p << " "<<q << " "<<e << " "<<m; 
	         examplefile.close();        //关闭文件 
	    }
    }
} 
