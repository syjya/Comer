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

void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
	
	int l=0;
	switch(arg[a1][0])
	{
		case 0:l=1+rand()%4; 
		       break;
		case 1:l=5+rand()%5;
		       break;
		case 2:l=10+rand()%5;
		       break;       
	} 
	 
	int al[500]; 
    	std::string b[500];
    if(arg[a1][5]==1)
	{ 
    int l1,l2,l3;
    switch(arg[a1][1])
	{
		case 0:l1=0;
		       break;
		case 1:l1=l/2;
		       break;
		case 2:l1=l/3;
		       break;
		case 3:l1=l/4;
		       break;
		case 4:l1=l;
		       break;
	}
	
	switch(arg[a1][2])
	{
		case 0:l2=0;
		       break;
		case 1:l2=l/2;
		       break;
		case 2:l2=l/3;
		       break;
		case 3:l2=l/4;
		       break;
		case 4:l2=l;
		       break;
	} 
	
    l3=l-l1-l2;
    
    int all_length=0;
    for(int i=0;i<l1;i++)
    {
    	al[i]=1;
    	all_length+=al[i];
    }
    for(int i=l1;i<l1+l2;i++)
    {
    	al[i]=2+rand()%4;
    	all_length+=al[i];
    }   
    for(int i=l1+l2;i<l;i++)
    {
    	al[i]=5+rand()%6;  
		all_length+=al[i];  
    }
   
    //数字，特殊符号和字母的个数 
	char a[500];
	int m1,m2,m3;
    switch(arg[a1][3])
	{
		case 0:m1=0;
		       break;
		case 1:m1=all_length/2;
		       break;
		case 2:m1=all_length/3;
		       break;
		case 3:m1=all_length/4;
		       break;
		case 4:m1=all_length;
		       break;
	}
	
	switch(arg[a1][4])
	{
		case 0:m2=0;
		       break;
		case 1:m2=all_length/2;
		       break;
		case 2:m2=all_length/3;
		       break;
		case 3:m2=all_length/4;
		       break;
		case 4:m2=all_length;
		       break;
	} 
	m3=all_length-m1-m2;
	
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<m1)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<m1+m3)
	{
		int tem=rand()%26;
		a[i++]=tem+'a'; //a-z 
	}
	while(i<all_length)
	{
		int tem=rand()%6;
		a[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	for(int j=0;j<all_length;j++)
	{
		int tem=rand()%all_length;
		int temp=a[j];
		a[j]=a[tem];
		a[tem]=temp;
	}
	

	int char_i=0;
	for(int j=0;j<l;j++)
	{
		b[j]="";
		for(int r=0;r<al[j];r++)
		b[j]+=a[char_i++];
	} 
    }
    std::string fa="";
    if(arg[a1][5]==0)
    {
	    int fl=rand()%l;    	
    	for(int j=0;j<l;j++)
    	{
    		b[j]="";
    		int bl=1+rand()%10;
    		for(int j1=0;j1<bl;j1++)
    		{
    			int tempb=rand()%3;
    			if(tempb==0)
    			{
    				int tem=rand()%26;
		            char tempchar=tem+'a'; //a-z 
		            b[j]+=tempchar;
    			}
    			if(tempb==1)
    			{
    				int tem=rand()%6;
		            char tempchar=tem+'*'; 
		            b[j]+=tempchar;
    			}
    			if(tempb==2)
    			{
    				int tem=rand()%10;
		            char tempchar='0'+ tem;
		            b[j]+=tempchar;
    			}
    		}
    		if(j==fl)
    		{
    			fa=b[j];
    		}
    	}
    }
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int j=0;j<l;j++)
         {
         	examplefile << b[j];
         	if(j!=l-1)
         	examplefile << " ";
         }   
         examplefile.close();        //关闭文件 
    } 
	
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         for(int j=0;j<l;j++)
         {
         	examplefile1 << b[j];
         	examplefile1 << " ";
         } 
		   examplefile1 <<fa;
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
			if(arg[i][0]==arg[j][0]-1&&arg[j][5]==0)
			{
				   MR0_testcase(i,j);
				   break;
			}	
			if(arg[i][0]==arg[j][0]+1&&arg[i][5]==0)
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
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
	    //字符串数组长度,al中保存每个字符的长度 
	int l=0;
	switch(arg[a1][0])
	{
		case 0:l=1+rand()%4; 
		       break;
		case 1:l=5+rand()%5;
		       break;
		case 2:l=10+rand()%5;
		       break;       
	} 
	 
	int al[500]; 
    	std::string b[500];
    if(arg[a1][5]==1)
	{ 
    int l1,l2,l3;
    switch(arg[a1][1])
	{
		case 0:l1=0;
		       break;
		case 1:l1=l/2;
		       break;
		case 2:l1=l/3;
		       break;
		case 3:l1=l/4;
		       break;
		case 4:l1=l;
		       break;
	}
	
	switch(arg[a1][2])
	{
		case 0:l2=0;
		       break;
		case 1:l2=l/2;
		       break;
		case 2:l2=l/3;
		       break;
		case 3:l2=l/4;
		       break;
		case 4:l2=l;
		       break;
	} 
	
    l3=l-l1-l2;
    
    if(l3<0)
    continue;
    
    int all_length=0;
    for(int i=0;i<l1;i++)
    {
    	al[i]=1;
    	all_length+=al[i];
    }
    for(int i=l1;i<l1+l2;i++)
    {
    	al[i]=2+rand()%4;
    	all_length+=al[i];
    }   
    for(int i=l1+l2;i<l;i++)
    {
    	al[i]=5+rand()%6;  
		all_length+=al[i];  
    }
   
    //数字，特殊符号和字母的个数 
	char a[500];
	int m1,m2,m3;
    switch(arg[a1][3])
	{
		case 0:m1=0;
		       break;
		case 1:m1=all_length/2;
		       break;
		case 2:m1=all_length/3;
		       break;
		case 3:m1=all_length/4;
		       break;
		case 4:m1=all_length;
		       break;
	}
	
	switch(arg[a1][4])
	{
		case 0:m2=0;
		       break;
		case 1:m2=all_length/2;
		       break;
		case 2:m2=all_length/3;
		       break;
		case 3:m2=all_length/4;
		       break;
		case 4:m2=all_length;
		       break;
	} 
	m3=all_length-m1-m2;
	
	if(m3<0)
	continue; 
	
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<m1)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<m1+m3)
	{
		int tem=rand()%26;
		a[i++]=tem+'a'; //a-z 
	}
	while(i<all_length)
	{
		int tem=rand()%6;
		a[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	for(int j=0;j<all_length;j++)
	{
		int tem=rand()%all_length;
		int temp=a[j];
		a[j]=a[tem];
		a[tem]=temp;
	}
	

	int char_i=0;
	for(int j=0;j<l;j++)
	{
		b[j]="";
		for(int r=0;r<al[j];r++)
		b[j]+=a[char_i++];
	} 
    }
    
    if(arg[a1][5]==0)
    {
    	
    	for(int j=0;j<l;j++)
    	{
    		b[j]="";
    		int bl=1+rand()%10;
    		for(int j1=0;j1<bl;j1++)
    		{
    			int tempb=rand()%3;
    			if(tempb==0)
    			{
    				int tem=rand()%26;
		            char tempchar=tem+'a'; //a-z 
		            b[j]+=tempchar;
    			}
    			if(tempb==1)
    			{
    				int tem=rand()%6;
		            char tempchar=tem+'*'; 
		            b[j]+=tempchar;
    			}
    			if(tempb==2)
    			{
    				int tem=rand()%10;
		            char tempchar='0'+ tem;
		            b[j]+=tempchar;
    			}
    		}
    	}
    }
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int j=0;j<l;j++)
         {
         	examplefile << b[j];
         	if(j!=l-1)
         	examplefile << " ";
         }   
         examplefile.close();        //关闭文件 
    } 
    }
	} 
} 
