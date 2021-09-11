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
int arg[2000][20];
int bi;

int flag[2000];
string number;

int testcase[2000][3];

void init()
{
	src_input=0;
	bi=0;
	for(int i=0;i<2000;i++)
	flag[i]=-1;
}

void MR0_testcase(int aa,int aa2)
{
	if(flag[aa]==1&&flag[aa2]==1)
	return;
	
	if(flag[aa]!=1&&flag[aa2]!=1)
	{
		int a,b,c;
    	int a1,a2,b1,b2;
	    while(1)
	    { 
		switch (arg[aa][1])
		{
		case 0:
		      a = 1+rand()%10;
		      a1=1;
		      a2=10;
		      break;
		case 1:
		      a = 11+rand()%40;
		      a1=11;
		      a2=50;
		      break;
		case 2:
		      a = 51+rand()%50;
		      a1=51;
		      a2=100;
		      break;
		}	
		switch (arg[aa][2])
	    {
		case 0:
		      b = 1+rand()%10;
		      b1=1;
		      b2=10;
		      break;
		case 1:
		      b = 11+rand()%40;
		      b1=11;
		      b2=50;
		      break;
		case 2:
		      b = 51+rand()%50;
		      b1=51;
		      b2=100;
		      break;
	    }		
		int c1,c2;
        switch (arg[aa][3])
	    {
		case 0:
			  c = 1+rand()%10;
		      c1=1;
		      c2=10;
		      break;
		case 1:
			   c = 11+rand()%40;
		      c1=11;
		      c2=50;
		      break;
		case 2:
			   c = 51+rand()%50;
		      c1=51;
		      c2=100;
		      break;
	    }
	    
	    if(arg[aa][0]==0&&a<=b&&b<=c&&a+b>c)
	    break;
	    if(arg[aa][0]==1)
	    {
	    	if(a1==b1)
	    	{
	    		b=a;
	    		if(c>b&&a+b>c)
	    		break;
	    	}
	    	else if(b1==c1)
	    	{
	    		b=c;
	    		if(b>a&&a+b>c)
	    		break;
	    	}
	    }
	    if(arg[aa][0]==2&&a<=b&&b<=c&&a+b<c)
	    break;
	    if(arg[aa][0]==3)
	    {
	    	b=a;
	    	c=b;
	    	break;
	    }
	    
	  }	    
       testcase[aa][0]=a;
    	testcase[aa][1]=b;
    	testcase[aa][2]=c;
    	testcase[aa2][0]=b;
    	testcase[aa2][1]=a;
    	testcase[aa2][2]=c;
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << a;
         examplefile << " ";
         examplefile << b;  
         examplefile << " ";
         examplefile << c; 
         examplefile.close();        //关闭文件 
    	} 
    	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile1(filename);
    	if (examplefile1.is_open())
    	{  
         examplefile1 << b;
         examplefile1 << " ";
         examplefile1 << a;  
         examplefile1 << " ";
         examplefile1<< c; 
         examplefile1.close();        //关闭文件 
    	} 
		flag[aa]=1;
        flag[aa2]=1;	
	}
	
	if(flag[aa]==1&&flag[aa2]!=1)
	{
		testcase[aa2][0]=testcase[aa][1];
    	testcase[aa2][1]=testcase[aa][0];
    	testcase[aa2][2]=testcase[aa][2];
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << testcase[aa2][0];
         examplefile << " ";
         examplefile << testcase[aa2][1];  
         examplefile << " ";
         examplefile << testcase[aa2][2]; 
         examplefile.close();        //关闭文件 
    	} 
	    flag[aa2]=1;
    }
	
	if(flag[aa]!=1&&flag[aa2]==1)
	{
		testcase[aa][0]=testcase[aa2][1];
    	testcase[aa][1]=testcase[aa2][0];
    	testcase[aa][2]=testcase[aa2][2];
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << testcase[aa][0];
         examplefile << " ";
         examplefile << testcase[aa][1];  
         examplefile << " ";
         examplefile << testcase[aa][2]; 
         examplefile.close();        //关闭文件 
    	} 
	    flag[aa]=1;
    }
}

void MR1_testcase(int aa,int aa2)
{
	if(flag[aa]==1&&flag[aa2]==1)
	return;
	
	if(flag[aa]!=1&&flag[aa2]!=1)
	{
		int a,b,c;
    	int a1,a2,b1,b2;
	    while(1)
	    { 
		switch (arg[aa][1])
		{
		case 0:
		      a = 1+rand()%10;
		      a1=1;
		      a2=10;
		      break;
		case 1:
		      a = 11+rand()%40;
		      a1=11;
		      a2=50;
		      break;
		case 2:
		      a = 51+rand()%50;
		      a1=51;
		      a2=100;
		      break;
		}	
		switch (arg[aa][2])
	    {
		case 0:
		      b = 1+rand()%10;
		      b1=1;
		      b2=10;
		      break;
		case 1:
		      b = 11+rand()%40;
		      b1=11;
		      b2=50;
		      break;
		case 2:
		      b = 51+rand()%50;
		      b1=51;
		      b2=100;
		      break;
	    }		
		int c1,c2;
        switch (arg[aa][3])
	    {
		case 0:
			  c = 1+rand()%10;
		      c1=1;
		      c2=10;
		      break;
		case 1:
			   c = 11+rand()%40;
		      c1=11;
		      c2=50;
		      break;
		case 2:
			   c = 51+rand()%50;
		      c1=51;
		      c2=100;
		      break;
	    }
	    
	    if(arg[aa][0]==0&&a<=b&&b<=c&&a+b>c)
	    break;
	    if(arg[aa][0]==1)
	    {
	    	if(a1==b1)
	    	{
	    		b=a;
	    		if(c>b&&a+b>c)
	    		break;
	    	}
	    	else if(b1==c1)
	    	{
	    		b=c;
	    		if(b>a&&a+b>c)
	    		break;
	    	}
	    }
	    if(arg[aa][0]==2&&a<=b&&b<=c&&a+b<c)
	    break;
	    if(arg[aa][0]==3)
	    {
	    	b=a;
	    	c=b;
	    	break;
	    }
	    
	  }	    
       testcase[aa][0]=a;
    	testcase[aa][1]=b;
    	testcase[aa][2]=c;
    	testcase[aa2][0]=a;
    	testcase[aa2][1]=c;
    	testcase[aa2][2]=b;
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << a;
         examplefile << " ";
         examplefile << b;  
         examplefile << " ";
         examplefile << c; 
         examplefile.close();        //关闭文件 
    	} 
    	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile1(filename);
    	if (examplefile1.is_open())
    	{  
         examplefile1 << a;
         examplefile1 << " ";
         examplefile1 << c;  
         examplefile1 << " ";
         examplefile1<< b; 
         examplefile1.close();        //关闭文件 
    	} 
		flag[aa]=1;
        flag[aa2]=1;	
	}
	
	if(flag[aa]==1&&flag[aa2]!=1)
	{
		testcase[aa2][0]=testcase[aa][0];
    	testcase[aa2][1]=testcase[aa][2];
    	testcase[aa2][2]=testcase[aa][1];
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << testcase[aa2][0];
         examplefile << " ";
         examplefile << testcase[aa2][1];  
         examplefile << " ";
         examplefile << testcase[aa2][2]; 
         examplefile.close();        //关闭文件 
    	} 
	    flag[aa2]=1;
    }
	
	if(flag[aa]!=1&&flag[aa2]==1)
	{
		testcase[aa][0]=testcase[aa2][0];
    	testcase[aa][1]=testcase[aa2][2];
    	testcase[aa][2]=testcase[aa2][1];
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << testcase[aa][0];
         examplefile << " ";
         examplefile << testcase[aa][1];  
         examplefile << " ";
         examplefile << testcase[aa][2]; 
         examplefile.close();        //关闭文件 
    	} 
	    flag[aa]=1;
    }
}

void MR2_testcase(int aa,int aa2)
{
	if(flag[aa]==1&&flag[aa2]==1)
	return;
	
	if(flag[aa]!=1&&flag[aa2]!=1)
	{
		int a,b,c;
    	int a1,a2,b1,b2;
	    while(1)
	    { 
		switch (arg[aa][1])
		{
		case 0:
		      a = 1+rand()%10;
		      a1=1;
		      a2=10;
		      break;
		case 1:
		      a = 11+rand()%40;
		      a1=11;
		      a2=50;
		      break;
		case 2:
		      a = 51+rand()%50;
		      a1=51;
		      a2=100;
		      break;
		}	
		switch (arg[aa][2])
	    {
		case 0:
		      b = 1+rand()%10;
		      b1=1;
		      b2=10;
		      break;
		case 1:
		      b = 11+rand()%40;
		      b1=11;
		      b2=50;
		      break;
		case 2:
		      b = 51+rand()%50;
		      b1=51;
		      b2=100;
		      break;
	    }		
		int c1,c2;
        switch (arg[aa][3])
	    {
		case 0:
			  c = 1+rand()%10;
		      c1=1;
		      c2=10;
		      break;
		case 1:
			   c = 11+rand()%40;
		      c1=11;
		      c2=50;
		      break;
		case 2:
			   c = 51+rand()%50;
		      c1=51;
		      c2=100;
		      break;
	    }
	    
	    if(arg[aa][0]==0&&a<=b&&b<=c&&a+b>c)
	    break;
	    if(arg[aa][0]==1)
	    {
	    	if(a1==b1)
	    	{
	    		b=a;
	    		if(c>b&&a+b>c)
	    		break;
	    	}
	    	else if(b1==c1)
	    	{
	    		b=c;
	    		if(b>a&&a+b>c)
	    		break;
	    	}
	    }
	    if(arg[aa][0]==2&&a<=b&&b<=c&&a+b<c)
	    break;
	    if(arg[aa][0]==3)
	    {
	    	b=a;
	    	c=b;
	    	break;
	    }
	    
	  }	    
       testcase[aa][0]=a;
    	testcase[aa][1]=b;
    	testcase[aa][2]=c;
    	testcase[aa2][0]=c;
    	testcase[aa2][1]=b;
    	testcase[aa2][2]=a;
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << a;
         examplefile << " ";
         examplefile << b;  
         examplefile << " ";
         examplefile << c; 
         examplefile.close();        //关闭文件 
    	} 
    	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile1(filename);
    	if (examplefile1.is_open())
    	{  
         examplefile1 << c;
         examplefile1 << " ";
         examplefile1 << b;  
         examplefile1 << " ";
         examplefile1<< a; 
         examplefile1.close();        //关闭文件 
    	} 
		flag[aa]=1;
        flag[aa2]=1;	
	}
	
	if(flag[aa]==1&&flag[aa2]!=1)
	{
		testcase[aa2][0]=testcase[aa][2];
    	testcase[aa2][1]=testcase[aa][1];
    	testcase[aa2][2]=testcase[aa][0];
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << testcase[aa2][0];
         examplefile << " ";
         examplefile << testcase[aa2][1];  
         examplefile << " ";
         examplefile << testcase[aa2][2]; 
         examplefile.close();        //关闭文件 
    	} 
	    flag[aa2]=1;
    }
	
	if(flag[aa]!=1&&flag[aa2]==1)
	{
		testcase[aa][0]=testcase[aa2][2];
    	testcase[aa][1]=testcase[aa2][1];
    	testcase[aa][2]=testcase[aa2][0];
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << testcase[aa][0];
         examplefile << " ";
         examplefile << testcase[aa][1];  
         examplefile << " ";
         examplefile << testcase[aa][2]; 
         examplefile.close();        //关闭文件 
    	} 
	    flag[aa]=1;
    }
}

void MR3_testcase(int aa,int aa2)
{
	if(flag[aa]==1&&flag[aa2]==1)
	return;
	
	if(flag[aa]!=1&&flag[aa2]!=1)
	{
		int count=0;
		int a,b,c;
    	int a1,a2,b1,b2;
	    while(1)
	    { 
	    if(count>100)
	    return;
	    count++;
		switch (arg[aa][1])
		{
		case 0:
		      a = 6+rand()%5;
		      a1=6;
		      a2=10;
		      break;
		case 1:
		      a = 26+rand()%25;
		      a1=26;
		      a2=50;
		      break;
		case 2:
		      a = 51+rand()%50;
		      a1=51;
		      a2=100;
		      break;
		}	
		switch (arg[aa][2])
	    {
		case 0:
		      b = 6+rand()%5;
		      b1=6;
		      b2=10;
		      break;
		case 1:
		      b = 26+rand()%25;
		      b1=26;
		      b2=50;
		      break;
		case 2:
		      b = 51+rand()%50;
		      b1=51;
		      b2=100;
		      break;
	    }		
		int c1,c2;
        switch (arg[aa][3])
	    {
		case 0:
			  c = 6+rand()%5;
		      c1=6;
		      c2=10;
		      break;
		case 1:
			   c = 26+rand()%25;
		      c1=26;
		      c2=50;
		      break;
		case 2:
			   c = 51+rand()%50;
		      c1=51;
		      c2=100;
		      break;
	    }
	    
	    if(arg[aa][0]==0&&a<=b&&b<=c&&a+b>c)
	    break;
	    if(arg[aa][0]==1)
	    {
	    	if(a1==b1)
	    	{
	    		b=a;
	    		if(c>b&&a+b>c)
	    		break;
	    	}
	    	else if(b1==c1)
	    	{
	    		b=c;
	    		if(b>a&&a+b>c)
	    		break;
	    	}
	    }
	    if(arg[aa][0]==2&&a<=b&&b<=c&&a+b<c)
	    break;
	    if(arg[aa][0]==3)
	    {
	    	b=a;
	    	c=b;
	    	break;
	    }
	    
	  }	    
       testcase[aa][0]=a;
    	testcase[aa][1]=b;
    	testcase[aa][2]=c;
    	testcase[aa2][0]=2*a;
    	testcase[aa2][1]=2*b;
    	testcase[aa2][2]=2*c;
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << a;
         examplefile << " ";
         examplefile << b;  
         examplefile << " ";
         examplefile << c; 
         examplefile.close();        //关闭文件 
    	} 
    	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile1(filename);
    	if (examplefile1.is_open())
    	{  
         examplefile1 << 2*a;
         examplefile1 << " ";
         examplefile1 << 2*b;  
         examplefile1 << " ";
         examplefile1<< 2*c; 
         examplefile1.close();        //关闭文件 
    	} 
		flag[aa]=1;
        flag[aa2]=1;	
	}
	
	if(flag[aa]==1&&flag[aa2]!=1)
	{
		testcase[aa2][0]=testcase[aa][0]*2;
    	testcase[aa2][1]=testcase[aa][1]*2;
    	testcase[aa2][2]=testcase[aa][2]*2;
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << testcase[aa2][0];
         examplefile << " ";
         examplefile << testcase[aa2][1];  
         examplefile << " ";
         examplefile << testcase[aa2][2]; 
         examplefile.close();        //关闭文件 
    	} 
	    flag[aa2]=1;
    }
	
	if(flag[aa]!=1&&flag[aa2]==1)
	{
		testcase[aa][0]=testcase[aa2][0]/2;
    	testcase[aa][1]=testcase[aa2][1]/2;
    	testcase[aa][2]=testcase[aa2][2]/2;
	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << testcase[aa][0];
         examplefile << " ";
         examplefile << testcase[aa][1];  
         examplefile << " ";
         examplefile << testcase[aa][2]; 
         examplefile.close();        //关闭文件 
    	} 
	    flag[aa]=1;
    }
}

void judgeMR0()
{	
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{

			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][2]&&arg[i][2]==arg[j][1]&&arg[i][3]==arg[j][3])
			{
				   MR0_testcase(i,j);
				   break;					
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
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][3]&&arg[i][3]==arg[j][2])
			{
				   MR1_testcase(i,j);
				   break;					
			}
		}
	}
}

void judgeMR2()
{	
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{

			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][3]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][1])
			{
				   MR2_testcase(i,j);
				   break;					
			}
		}
	}
}

void judgeMR3()
{	
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]&&arg[i][1]+1==arg[j][1]&&arg[i][2]+1==arg[j][2]&&arg[i][3]+1==arg[j][3])
			{
				   MR3_testcase(i,j);					
			}
			if(arg[i][0]==arg[j][0]&&arg[i][1]-1==arg[j][1]&&arg[i][2]-1==arg[j][2]&&arg[i][3]-1==arg[j][3])
			{
				   MR3_testcase(j,i);					
			}
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
	
//    judgeMR3();  //first MR3
//    judgeMR0();
//    judgeMR1();
//    judgeMR2();
    
    for(int aa=0;aa<bi;aa++)
    {
    if(flag[aa]==-1)
    {

        int a,b,c;
    	int a1,a2,b1,b2;
	    while(1)
	    { 
		switch (arg[aa][1])
		{
		case 0:
		      a = 1+rand()%10;
		      a1=1;
		      a2=10;
		      break;
		case 1:
		      a = 11+rand()%40;
		      a1=11;
		      a2=50;
		      break;
		case 2:
		      a = 51+rand()%50;
		      a1=51;
		      a2=100;
		      break;
		}	
		switch (arg[aa][2])
	    {
		case 0:
		      b = 1+rand()%10;
		      b1=1;
		      b2=10;
		      break;
		case 1:
		      b = 11+rand()%40;
		      b1=11;
		      b2=50;
		      break;
		case 2:
		      b = 51+rand()%50;
		      b1=51;
		      b2=100;
		      break;
	    }		
		int c1,c2;
        switch (arg[aa][3])
	    {
		case 0:
			  c = 1+rand()%10;
		      c1=1;
		      c2=10;
		      break;
		case 1:
			   c = 11+rand()%40;
		      c1=11;
		      c2=50;
		      break;
		case 2:
			   c = 51+rand()%50;
		      c1=51;
		      c2=100;
		      break;
	    }
	    
	    if(arg[aa][0]==0&&a<=b&&b<=c&&a+b>c)
	    break;
	    if(arg[aa][0]==1)
	    {
	    	if(a1==b1)
	    	{
	    		b=a;
	    		if(c>b&&a+b>c)
	    		break;
	    	}
	    	else if(b1==c1)
	    	{
	    		b=c;
	    		if(b>a&&a+b>c)
	    		break;
	    	}
	    }
	    if(arg[aa][0]==2&&a<=b&&b<=c&&a+b<c)
	    break;
	    if(arg[aa][0]==3)
	    {
	    	b=a;
	    	c=b;
	    	break;
	    }
	    
	  }	    

	    char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         examplefile << a;
         examplefile << " ";
         examplefile << b;  
         examplefile << " ";
         examplefile << c; 
         examplefile.close();        //关闭文件 
    	} 
    } 
}
}
