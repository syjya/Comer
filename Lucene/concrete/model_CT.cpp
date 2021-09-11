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
int txt;
int arg[500][12];
int bi;

int flag[500];
 
string number;
string number1;
char resulta[500][500];
char resultb[500][500];
char resultc[500][500];
string resulttemp[500];
int resultl[500][3];


void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
	int num=0,cha=0,nota=0;
	int k1=1,k2=1,k3=1;
	switch(arg[a1][0])
	{
		case 0:break;
		case 1:num=1+rand()%4;
		       break;
		case 2:num=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][2])
	{
		case 0:break;
		case 1:cha=1+rand()%4;
		       break;
		case 2:cha=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][4])
	{
		case 0:break;
		case 1:nota=1+rand()%4;
		       break;
		case 2:nota=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][1])
	{
		case 0:break;
		case 1:k1=2+rand()%3;
		       break;
		case 2:k1=5+rand()%3;
		       break;	
	}
	switch(arg[a1][3])
	{
		case 0:break;
		case 1:k2=2+rand()%3;
		       break;
		case 2:k2=5+rand()%3;
		       break;	
	}
	switch(arg[a1][5])
	{
		case 0:break;
		case 1:k3=2+rand()%3;
		       break;
		case 2:k3=5+rand()%3;
		       break;	
	}
    num=num*k1;
    cha=cha*k2;
    nota=nota*k3;    
    int n=num+cha+nota;
    
	char a[500];
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<num)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<num+cha)
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
	//std::cout<<n<<std::endl;

	
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
		case 3: if(n>0)
		        b[q++]=a[n-1];
		        break;	    
	}
	
	//std::cout<<std::endl<<q<<std::endl;
	
	int q1=0;
	char c[5];
	
	m=0;
	m1=n/2;
	
	switch(arg[a1][7])
	{
		case 0: t1=rand()%16;
		        c[q1++] = 'h'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	c[q1++]=a[m];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	c[q1++]=a[m1];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 3: if(n>0)
		        c[q1++]=a[n-1];
		        break;	
		case 4: 
		        break;    
	}
	
	std::string tempj="";
	switch(arg[a1][8])
	{
		case 0: 
		        break;
		case 1: tempj="OR"; 
		        break;
		case 2: tempj="AND"; 
		        break;
		case 3: tempj="NOT"; 
		        break;	    
	}
	/*for(int j=0;j<q;j++)
	{
		std::cout<<b[j];
	}*/
	resultl[a1][0]=n;
	resultl[a1][1]=q;
	resultl[a1][2]=q1;
	resulttemp[a1]="OR";
	resultl[a2][0]=n;
	resultl[a2][1]=q1;
	resultl[a2][2]=q;
	resulttemp[a2]="OR";
	
    for(int j=0;j<n;j++)
    {
    	resulta[a1][j]=a[j];
    	resulta[a2][j]=a[j];
    }
    
    for(int j=0;j<q;j++)
    {
    	resultb[a1][j]=b[j];
    	resultc[a2][j]=b[j];
    }
    
    for(int j=0;j<q1;j++)
    {
    	resultc[a1][j]=c[j];
    	resultb[a2][j]=c[j];
    }
    
	char name[200];
	sprintf(name,"%s%s%d%s",number1.c_str(),"/",txt++,".txt");
    std::ofstream ex(name);
    if (ex.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		ex<<a[j];
		}
	
		ex<<"\n"; 
         ex.close();        //关闭文件 
    } 
    
    char filename[200];
	 sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
		for(int j=0;j<q;j++)
		{
			examplefile<<b[j];
		}
	
	if(!tempj.empty())
	{
		examplefile<<"\n"<<tempj;
	}	 
	//std::cout<<std::endl<<q<<std::endl;
	examplefile<<"\n";
	for(int j=0;j<q1;j++)
	{
		examplefile<<c[j];
	}
         examplefile.close();        //关闭文件 
    } 
	
	sprintf(filename,"%s%s%d%s",number1.c_str(),"/",txt++,".txt");
    std::ofstream ex1(name);
    if (ex1.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		ex1<<a[j];
		}
	
		ex1<<"\n"; 
         ex1.close();        //关闭文件 
    } 
    
sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
		for(int j=0;j<q1;j++)
		{
			examplefile1<<c[j];
		}
	
	if(!tempj.empty())
	{
		examplefile1<<"\n"<<tempj;
	}	 
	//std::cout<<std::endl<<q<<std::endl;
	examplefile1<<"\n";
	for(int j=0;j<q;j++)
	{
		examplefile1<<b[j];
	}
         examplefile1.close();        //关闭文件 
    } 
    
	flag[a1]=1;
    flag[a2]=1;	
    }
}

void MR1_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
	int num=0,cha=0,nota=0;
	int k1=1,k2=1,k3=1;
	switch(arg[a1][0])
	{
		case 0:break;
		case 1:num=1+rand()%4;
		       break;
		case 2:num=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][2])
	{
		case 0:break;
		case 1:cha=1+rand()%4;
		       break;
		case 2:cha=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][4])
	{
		case 0:break;
		case 1:nota=1+rand()%4;
		       break;
		case 2:nota=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][1])
	{
		case 0:break;
		case 1:k1=2+rand()%3;
		       break;
		case 2:k1=5+rand()%3;
		       break;	
	}
	switch(arg[a1][3])
	{
		case 0:break;
		case 1:k2=2+rand()%3;
		       break;
		case 2:k2=5+rand()%3;
		       break;	
	}
	switch(arg[a1][5])
	{
		case 0:break;
		case 1:k3=2+rand()%3;
		       break;
		case 2:k3=5+rand()%3;
		       break;	
	}
    num=num*k1;
    cha=cha*k2;
    nota=nota*k3;    
    int n=num+cha+nota;
    
	char a[500];
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<num)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<num+cha)
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
	//std::cout<<n<<std::endl;

	
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
		case 3: if(n>0)
		        b[q++]=a[n-1];
		        break;	    
	}
	
	//std::cout<<std::endl<<q<<std::endl;
	
	int q1=0;
	char c[5];
	
	m=0;
	m1=n/2;
	
	switch(arg[a1][7])
	{
		case 0: t1=rand()%16;
		        c[q1++] = 'h'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	c[q1++]=a[m];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	c[q1++]=a[m1];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 3: if(n>0)
		        c[q1++]=a[n-1];
		        break;	
		case 4: 
		        break;    
	}
	
	std::string tempj="";
	switch(arg[a1][8])
	{
		case 0: 
		        break;
		case 1: tempj="OR"; 
		        break;
		case 2: tempj="AND"; 
		        break;
		case 3: tempj="NOT"; 
		        break;	    
	}
	/*for(int j=0;j<q;j++)
	{
		std::cout<<b[j];
	}*/
	resultl[a1][0]=n;
	resultl[a1][1]=q;
	resultl[a1][2]=q1;
	resulttemp[a1]="OR";
	resultl[a2][0]=n;
	resultl[a2][1]=q;
	resultl[a2][2]=0;
	resulttemp[a2]="";
	
    for(int j=0;j<n;j++)
    {
    	resulta[a1][j]=a[j];
    	resulta[a2][j]=a[j];
    }
    
    for(int j=0;j<q;j++)
    {
    	resultb[a1][j]=b[j];
    	resultb[a2][j]=b[j];
    }
    
    for(int j=0;j<q1;j++)
    {
    	resultc[a1][j]=c[j];
    }
    
	char name[200];
	sprintf(name,"%s%s%d%s",number1.c_str(),"/",txt++,".txt");
    std::ofstream ex(name);
    if (ex.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		ex<<a[j];
		}
	
		ex<<"\n"; 
         ex.close();        //关闭文件 
    } 
    
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
		for(int j=0;j<q;j++)
		{
			examplefile<<b[j];
		}
	
	if(!tempj.empty())
	{
		examplefile<<"\n"<<tempj;
	}	 
	//std::cout<<std::endl<<q<<std::endl;
	examplefile<<"\n";
	for(int j=0;j<q1;j++)
	{
		examplefile<<c[j];
	}
         examplefile.close();        //关闭文件 
    } 
	
	sprintf(filename,"%s%s%d%s",number1.c_str(),"/",txt++,".txt");
    std::ofstream ex1(name);
    if (ex1.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		ex1<<a[j];
		}
	
		ex1<<"\n"; 
         ex1.close();        //关闭文件 
    } 
    
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
		for(int j=0;j<q;j++)
		{
			examplefile1<<b[j];
		}
         examplefile1.close();        //关闭文件 
    } 
    
	flag[a1]=1;
    flag[a2]=1;	
    }
    
    if(flag[a1]==1&&flag[a2]!=1)
    {
    	resultl[a2][0]=resultl[a1][0];
	    resultl[a2][1]=resultl[a1][1];
	    resultl[a2][2]=0;
	    resulttemp[a2]="";
	
        for(int j=0;j<resultl[a2][0];j++)
    	{
    	   resulta[a2][j]=resulta[a1][j];
    	}
    
    	for(int j=0;j<resultl[a2][1];j++)
    	{
           resultb[a2][j]=resultb[a1][j];
    	}
        
    char name[200];
	sprintf(name,"%s%s%d%s",number1.c_str(),"/",txt++,".txt");
    std::ofstream ex(name);
    if (ex.is_open())
    {  
        for(int j=0;j<resultl[a2][0];j++)
		{
		ex<<resulta[a2][j];
		}
	
		ex<<"\n"; 
         ex.close();        //关闭文件 
    } 
    
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
		for(int j=0;j<resultl[a2][1];j++)
		{
			examplefile<<resultb[a2][j];
		}
         examplefile.close();        //关闭文件 
    } 
	 flag[a2]=1;	
    }
}

void MR2_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
	int num=0,cha=0,nota=0;
	int k1=1,k2=1,k3=1;
	switch(arg[a1][0])
	{
		case 0:break;
		case 1:num=1+rand()%4;
		       break;
		case 2:num=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][2])
	{
		case 0:break;
		case 1:cha=1+rand()%4;
		       break;
		case 2:cha=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][4])
	{
		case 0:break;
		case 1:nota=1+rand()%4;
		       break;
		case 2:nota=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][1])
	{
		case 0:break;
		case 1:k1=2+rand()%3;
		       break;
		case 2:k1=5+rand()%3;
		       break;	
	}
	switch(arg[a1][3])
	{
		case 0:break;
		case 1:k2=2+rand()%3;
		       break;
		case 2:k2=5+rand()%3;
		       break;	
	}
	switch(arg[a1][5])
	{
		case 0:break;
		case 1:k3=2+rand()%3;
		       break;
		case 2:k3=5+rand()%3;
		       break;	
	}
    num=num*k1;
    cha=cha*k2;
    nota=nota*k3;    
    int n=num+cha+nota;
    
	char a[500];
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<num)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<num+cha)
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
	//std::cout<<n<<std::endl;

	
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
		case 3: if(n>0)
		        b[q++]=a[n-1];
		        break;	    
	}
	
	//std::cout<<std::endl<<q<<std::endl;
	
	int q1=0;
	char c[5];
	
	m=0;
	m1=n/2;
	
	switch(arg[a1][7])
	{
		case 0: t1=rand()%16;
		        c[q1++] = 'h'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	c[q1++]=a[m];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	c[q1++]=a[m1];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 3: if(n>0)
		        c[q1++]=a[n-1];
		        break;	
		case 4: 
		        break;    
	}
	
	std::string tempj="";
	switch(arg[a1][8])
	{
		case 0: 
		        break;
		case 1: tempj="OR"; 
		        break;
		case 2: tempj="AND"; 
		        break;
		case 3: tempj="NOT"; 
		        break;	    
	}
	/*for(int j=0;j<q;j++)
	{
		std::cout<<b[j];
	}*/
	resultl[a1][0]=n;
	resultl[a1][1]=q;
	resultl[a1][2]=q1;
	resulttemp[a1]="NOT";
	resultl[a2][0]=n;
	resultl[a2][1]=q;
	resultl[a2][2]=0;
	resulttemp[a2]="";
	
    for(int j=0;j<n;j++)
    {
    	resulta[a1][j]=a[j];
    	resulta[a2][j]=a[j];
    }
    
    for(int j=0;j<q;j++)
    {
    	resultb[a1][j]=b[j];
    	resultb[a2][j]=b[j];
    }
    
    for(int j=0;j<q1;j++)
    {
    	resultc[a1][j]=c[j];
    }
    
	char name[200];
	sprintf(name,"%s%s%d%s",number1.c_str(),"/",txt++,".txt");
    std::ofstream ex(name);
    if (ex.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		ex<<a[j];
		}
	
		ex<<"\n"; 
         ex.close();        //关闭文件 
    } 
    
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
		for(int j=0;j<q;j++)
		{
			examplefile<<b[j];
		}
	
	if(!tempj.empty())
	{
		examplefile<<"\n"<<tempj;
	}	 
	//std::cout<<std::endl<<q<<std::endl;
	examplefile<<"\n";
	for(int j=0;j<q1;j++)
	{
		examplefile<<c[j];
	}
         examplefile.close();        //关闭文件 
    } 
	
	sprintf(filename,"%s%s%d%s",number1.c_str(),"/",txt++,".txt");
    std::ofstream ex1(name);
    if (ex1.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		ex1<<a[j];
		}
	
		ex1<<"\n"; 
         ex1.close();        //关闭文件 
    } 
    
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
		for(int j=0;j<q;j++)
		{
			examplefile1<<b[j];
		}
         examplefile1.close();        //关闭文件 
    } 
    
	flag[a1]=1;
    flag[a2]=1;	
    }
    
    if(flag[a1]!=1&&flag[a2]==1)
    {
    	resultl[a1][0]=resultl[a2][0];
	    resultl[a1][1]=resultl[a2][1];
	
        for(int j=0;j<resultl[a1][0];j++)
    	{
    	   resulta[a1][j]=resulta[a2][j];
    	}
    
    	for(int j=0;j<resultl[a1][1];j++)
    	{
           resultb[a1][j]=resultb[a2][j];
    	}
        
        int q1=0;
	    char c[5];
	int t1;
	int m=0;
	int n=resultl[a1][0];
	int m1=n/2;
	
	switch(arg[a1][7])
	{
		case 0: t1=rand()%16;
		        c[q1++] = 'h'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	c[q1++]=resulta[a1][m];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	c[q1++]=resulta[a1][m1];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 3: if(n>0)
		        c[q1++]=resulta[a1][n-1];
		        break;	
		case 4: 
		        break;    
	    }
	char name[200];
	sprintf(name,"%s%s%d%s",number1.c_str(),"/",txt++,".txt");
    std::ofstream ex(name);
    if (ex.is_open())
    {  
        for(int j=0;j<resultl[a1][0];j++)
		{
		ex<<resulta[a1][j];
		}
	
		ex<<"\n"; 
         ex.close();        //关闭文件 
    } 
    
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
		for(int j=0;j<resultl[a1][1];j++)
		{
			examplefile<<resultb[a1][j];
		}
	
	
		examplefile<<"\n"<<"NOT";	 
	//std::cout<<std::endl<<q<<std::endl;
	examplefile<<"\n";
	for(int j=0;j<q1;j++)
	{
		examplefile<<c[j];
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
		if(arg[i][8]==1)
		{
			for(int j=i+1;j<bi;j++)
		   {
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[i][6]==arg[j][7]&&arg[i][7]==arg[j][6]&&arg[i][8]==arg[j][8])
			{
				MR0_testcase(i,j);				    
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
		if(arg[i][8]==1)
		{
			for(int j=i+1;j<bi;j++)
		   {
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[i][6]==arg[j][6]&&arg[i][7]==0&&arg[i][8]==1&&arg[j][7]==4&&arg[j][8]==0)
			{
				MR1_testcase(i,j);				    
				break;			
			}
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[i][6]==arg[j][6]&&arg[j][7]==0&&arg[j][8]==1&&arg[i][7]==4&&arg[i][8]==0)
			{
				MR1_testcase(j,i);				    
				break;			
			}
	        }
		} 
	
	}
}

void judgeMR2()
{	
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][8]==1)
		{
			for(int j=i+1;j<bi;j++)
		   {
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[i][6]==arg[j][6]&&arg[i][7]==0&&arg[i][8]==3&&arg[j][7]==4&&arg[j][8]==0)
			{
				MR2_testcase(i,j);				    
				break;			
			}
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5]&&arg[i][6]==arg[j][6]&&arg[j][7]==0&&arg[j][8]==3&&arg[i][7]==4&&arg[i][8]==0)
			{
				MR2_testcase(j,i);				    
				break;			
			}
	        }
		} 
	
	}
}

void init()
{
	src_input=0;
	txt=0;
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
	number1=argv[3];
	std::string str;
    srand((unsigned int)(time(NULL)));
    init();	
	while (getline(f_in, str))
	{       	
		int jj=0;
		for(int i=0;i<9;i++)
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
    int num=0,cha=0,nota=0;
	int k1=1,k2=1,k3=1;
	switch(arg[a1][0])
	{
		case 0:break;
		case 1:num=1+rand()%4;
		       break;
		case 2:num=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][2])
	{
		case 0:break;
		case 1:cha=1+rand()%4;
		       break;
		case 2:cha=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][4])
	{
		case 0:break;
		case 1:nota=1+rand()%4;
		       break;
		case 2:nota=5+rand()%5;
		       break;	
	} 
	switch(arg[a1][1])
	{
		case 0:break;
		case 1:k1=2+rand()%3;
		       break;
		case 2:k1=5+rand()%3;
		       break;	
	}
	switch(arg[a1][3])
	{
		case 0:break;
		case 1:k2=2+rand()%3;
		       break;
		case 2:k2=5+rand()%3;
		       break;	
	}
	switch(arg[a1][5])
	{
		case 0:break;
		case 1:k3=2+rand()%3;
		       break;
		case 2:k3=5+rand()%3;
		       break;	
	}
    num=num*k1;
    cha=cha*k2;
    nota=nota*k3;    
    int n=num+cha+nota;
    
	char a[500];
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<num)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<num+cha)
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
	//std::cout<<n<<std::endl;

	
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
		case 3: if(n>0)
		        b[q++]=a[n-1];
		        break;	    
	}
	
	//std::cout<<std::endl<<q<<std::endl;
	
	int q1=0;
	char c[5];
	
	m=0;
	m1=n/2;
	
	switch(arg[a1][7])
	{
		case 0: t1=rand()%16;
		        c[q1++] = 'h'+t1;
		        break;
		case 1: for(;m<n;m++)
		        {
		        	c[q1++]=a[m];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 2: for(;m1<n;m1++)
		        {
		        	c[q1++]=a[m1];
		        	if(q1==3)
		        	break;
		        }
		        break;
		case 3: if(n>0)
		        c[q1++]=a[n-1];
		        break;	
		case 4: 
		        break;    
	}
	
	std::string tempj="";
	switch(arg[a1][8])
	{
		case 0: 
		        break;
		case 1: tempj="OR"; 
		        break;
		case 2: tempj="AND"; 
		        break;
		case 3: tempj="NOT"; 
		        break;	    
	}
	/*for(int j=0;j<q;j++)
	{
		std::cout<<b[j];
	}*/
	char name[200];
	sprintf(name,"%s%s%d%s",number1.c_str(),"/",txt++,".txt");
    std::ofstream ex(name);
    if (ex.is_open())
    {  
        for(int j=0;j<n;j++)
		{
		ex<<a[j];
		}
	
		ex<<"\n"; 
         ex.close();        //关闭文件 
    } 
    
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
		for(int j=0;j<q;j++)
		{
			examplefile<<b[j];
		}
	
	if(!tempj.empty())
	{
		examplefile<<"\n"<<tempj;
	}	 
	//std::cout<<std::endl<<q<<std::endl;
	examplefile<<"\n";
	for(int j=0;j<q1;j++)
	{
		examplefile<<c[j];
	}
         examplefile.close();        //关闭文件 
    } 
    }
	} 
} 
