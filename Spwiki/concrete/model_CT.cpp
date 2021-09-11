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
int arg[1000][12];
int bi;

int flag[1000];

int resultpoint[500][4];
int resulta[500][500][500];

std::string number;

void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
	
	int point =0 ;
	int edge=0;
	int s0=0;
	int s1=0;
	int a[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		a[i][j]=-1;
	} 
    while(1)
    {
    switch (arg[a1][0])
	{
	    case 0:
		      point = 1;
		      break;
		case 1:
		      point = 1+rand()%10;
		      break;
		case 2:
		      point = 10+rand()%11;
		      break;
	} 
	
	int maxedg = point*(point -1)/2;
	
	switch (arg[a1][1])
	{
	    case 0:
		      break;
		case 1:
		      edge = 1;
		      break;
		case 2:
		      edge = 1+rand()%20;
		      break;
		case 3:
		      edge = 20+rand()%21;
		      break;
	}
	if(maxedg>=edge)
	break;
    }
    
	switch (arg[a1][2])
	{
	    case 0:
		      s0 = 0;
		      break;
		case 1:
		      s0 = rand()%point;
		      break;
		case 2:
		      s0 = point-1;
		      break;
	} 
	
	switch (arg[a1][3])
	{
	    case 0:
		      s1 = 0;
		      break;
		case 1:
		      s1 = rand()%point;
		      break;
		case 2:
		      s1 = point-1;
		      break;
	} 
	int k=1; 
	switch (arg[a1][4])
	{
	    case 0:
		      break;
		case 1:
		      k=2;
		      break;
		case 2:
		      k=3;
		      break;
	}
	int m=0;
	int end=-1;
	
	if(edge>0)
	{
	   for(int i=0;i<point;i++)
	   {
	    	for(int j=0;j<point;j++)
		    {
		    	 if(i<j)
			     {
			     	a[i][j]=(rand()%100+1)*k;
			     	m++;
			     	if(m==edge)
			     	{
			     	    end=1;	
			     	    break;
			     	}
			     }
			     
		    }
		    if(end==1)
		    break;
	   }
	}
    
    m=0;
    end=-1;
    
    for(int i=0;i<point;i++)
	{
	    for(int j=0;j<point;j++)
		{
			if(a[i][j]!=-1)
			{
				int t2=rand()%point;
				if(t2==0)
				continue;
				int t1=rand()%t2;
				int temp=a[i][j];
				a[i][j]=a[t1][t2];
				a[t1][t2]=temp;
				m++;
					if(m==edge)
			     	{
			     	    end=1;	
			     	    break;
			     	}
			}
        }
        if(end==1)
        break;
    }
	
	resultpoint[a1][0]=point;
	resultpoint[a1][1]=edge;
	resultpoint[a1][2]=s0;
	resultpoint[a1][3]=s1;
	
	resultpoint[a2][0]=point;
	resultpoint[a2][1]=edge;
	resultpoint[a2][2]=s1;
	resultpoint[a2][3]=s0;
    
	for(int ii=0;ii<point;ii++)
	{
		for(int jj=0;jj<point;jj++)
		{
			resulta[a1][ii][jj]=a[ii][jj];
			resulta[a2][ii][jj]=a[ii][jj];
		}		
	}
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile << point<< " "<<edge;
         for(int i=0;i<point;i++)
    {
    	for(int j=0;j<point;j++)
    	{
    		if(a[i][j]!=-1)
    		{
    			examplefile<<"\n"<<i<<" "<<j<<" "<<a[i][j];
    		}
    	}
    }
	
	     examplefile<<"\n"<<s0<< " "<<s1;
         examplefile.close();        //关闭文件 
    } 
	
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         examplefile1 << point<< " "<<edge;
         for(int i=0;i<point;i++)
    {
    	for(int j=0;j<point;j++)
    	{
    		if(a[i][j]!=-1)
    		{
    			examplefile1<<"\n"<<i<<" "<<j<<" "<<a[i][j];
    		}
    	}
    }
	
	     examplefile1<<"\n"<<s1<< " "<<s0;
         examplefile1.close();        //关闭文件 
    } 
	
	flag[a1]=1;
	flag[a2]=1;
}

void MR1_testcase(int a1,int a2)
{
	if(flag[a1]==1&&flag[a2]==1)
	return;
	
	if(flag[a1]!=1&&flag[a2]!=1)
	{
		int point =0 ;
	int edge=0;
	int s0=0;
	int s1=0;
	int a[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		a[i][j]=-1;
	} 
    while(1)
    {
    switch (arg[a1][0])
	{
	    case 0:
		      point = 1;
		      break;
		case 1:
		      point = 1+rand()%10;
		      break;
		case 2:
		      point = 10+rand()%11;
		      break;
	} 
	
	int maxedg = point*(point -1)/2;
	
	switch (arg[a1][1])
	{
	    case 0:
		      break;
		case 1:
		      edge = 1;
		      break;
		case 2:
		      edge = 1+rand()%20;
		      break;
		case 3:
		      edge = 20+rand()%21;
		      break;
	}
	if(maxedg>=edge)
	break;
    }
    
	switch (arg[a1][2])
	{
	    case 0:
		      s0 = 0;
		      break;
		case 1:
		      s0 = rand()%point;
		      break;
		case 2:
		      s0 = point-1;
		      break;
	} 
	
	switch (arg[a1][3])
	{
	    case 0:
		      s1 = 0;
		      break;
		case 1:
		      s1 = rand()%point;
		      break;
		case 2:
		      s1 = point-1;
		      break;
	} 
	int k=1; 
	switch (arg[a1][4])
	{
	    case 0:
		      break;
		case 1:
		      k=2;
		      break;
		case 2:
		      k=3;
		      break;
	}
	int m=0;
	int end=-1;
	
	if(edge>0)
	{
	   for(int i=0;i<point;i++)
	   {
	    	for(int j=0;j<point;j++)
		    {
		    	 if(i<j)
			     {
			     	a[i][j]=(rand()%100+1)*k;
			     	m++;
			     	if(m==edge)
			     	{
			     	    end=1;	
			     	    break;
			     	}
			     }
			     
		    }
		    if(end==1)
		    break;
	   }
	}
    
    m=0;
    end=-1;
    
    for(int i=0;i<point;i++)
	{
	    for(int j=0;j<point;j++)
		{
			if(a[i][j]!=-1)
			{
				int t2=rand()%point;
				if(t2==0)
				continue;
				int t1=rand()%t2;
				int temp=a[i][j];
				a[i][j]=a[t1][t2];
				a[t1][t2]=temp;
				m++;
					if(m==edge)
			     	{
			     	    end=1;	
			     	    break;
			     	}
			}
        }
        if(end==1)
        break;
    }
	
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile << point<< " "<<edge;
         for(int i=0;i<point;i++)
    {
    	for(int j=0;j<point;j++)
    	{
    		if(a[i][j]!=-1)
    		{
    			examplefile<<"\n"<<i<<" "<<j<<" "<<a[i][j];
    		}
    	}
    }
	
	     examplefile<<"\n"<<s0<< " "<<s1;
         examplefile.close();        //关闭文件 
    } 
	
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         examplefile1 << point<< " "<<edge;
         for(int i=0;i<point;i++)
    {
    	for(int j=0;j<point;j++)
    	{
    		if(a[i][j]!=-1)
    		{
    			examplefile1<<"\n"<<i<<" "<<j<<" "<<a[i][j]*2;
    		}
    	}
    }
	
	     examplefile1<<"\n"<<s0<< " "<<s1;
         examplefile1.close();        //关闭文件 
    } 
	
	flag[a1]=1;
	flag[a2]=1;
	}
	
	if(flag[a1]!=1&&flag[a2]==1)
	{
		char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile << resultpoint[a2][0]<< " "<<resultpoint[a2][1];
         for(int i=0;i<resultpoint[a2][0];i++)
    {
    	for(int j=0;j<resultpoint[a2][0];j++)
    	{
    		if(resulta[a2][i][j]!=-1)
    		{
    			examplefile<<"\n"<<i<<" "<<j<<" "<<resulta[a2][i][j]*2;
    		}
    	}
    }
	
	     examplefile<<"\n"<<resultpoint[a2][2]<< " "<<resultpoint[a2][3];
         examplefile.close();        //关闭文件 
    }
    	flag[a2]=1;
	}
	
		if(flag[a1]==1&&flag[a2]!=1)
	{
		char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile << resultpoint[a1][0]<< " "<<resultpoint[a1][1];
         for(int i=0;i<resultpoint[a1][0];i++)
    {
    	for(int j=0;j<resultpoint[a1][0];j++)
    	{
    		if(resulta[a1][i][j]!=-1)
    		{
    			examplefile<<"\n"<<i<<" "<<j<<" "<<resulta[a1][i][j]/2;
    		}
    	}
    }
	
	     examplefile<<"\n"<<resultpoint[a1][2]<< " "<<resultpoint[a1][3];
         examplefile.close();        //关闭文件 
    }
    	flag[a1]=1;
	}
	
}
void judgeMR0()
{	
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][2]!=arg[i][3])
		{
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][3]&&arg[i][3]==arg[j][2]&&arg[i][4]==arg[j][4])
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
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==0&&arg[j][4]==1)
			{
				   MR1_testcase(i,j);
				   break;
			}
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==1&&arg[j][4]==0)
			{
				   MR1_testcase(j,i);
				   break;
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
//    judgeMR1();
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
    int point =0 ;
	int edge=0;
	int s0=0;
	int s1=0;
	int a[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		a[i][j]=-1;
	} 
    while(1)
    {
    switch (arg[a1][0])
	{
	    case 0:
		      point = 1;
		      break;
		case 1:
		      point = 1+rand()%10;
		      break;
		case 2:
		      point = 10+rand()%11;
		      break;
	} 
	
	int maxedg = point*(point -1)/2;
	
	switch (arg[a1][1])
	{
	    case 0:
		      break;
		case 1:
		      edge = 1;
		      break;
		case 2:
		      edge = 1+rand()%20;
		      break;
		case 3:
		      edge = 20+rand()%21;
		      break;
	}
	if(maxedg>=edge)
	break;
    }
    
	switch (arg[a1][2])
	{
	    case 0:
		      s0 = 0;
		      break;
		case 1:
		      s0 = rand()%point;
		      break;
		case 2:
		      s0 = point-1;
		      break;
	} 
	
	switch (arg[a1][3])
	{
	    case 0:
		      s1 = 0;
		      break;
		case 1:
		      s1 = rand()%point;
		      break;
		case 2:
		      s1 = point-1;
		      break;
	} 
	int k=1; 
	switch (arg[a1][4])
	{
	    case 0:
		      break;
		case 1:
		      k=2;
		      break;
		case 2:
		      k=3;
		      break;
	}
	int m=0;
	int end=-1;
	
	if(edge>0)
	{
	   for(int i=0;i<point;i++)
	   {
	    	for(int j=0;j<point;j++)
		    {
		    	 if(i<j)
			     {
			     	a[i][j]=(rand()%100+1)*k;
			     	m++;
			     	if(m==edge)
			     	{
			     	    end=1;	
			     	    break;
			     	}
			     }
			     
		    }
		    if(end==1)
		    break;
	   }
	}
    
    m=0;
    end=-1;
    
    for(int i=0;i<point;i++)
	{
	    for(int j=0;j<point;j++)
		{
			if(a[i][j]!=-1)
			{
				int t2=rand()%point;
				if(t2==0)
				continue;
				int t1=rand()%t2;
				int temp=a[i][j];
				a[i][j]=a[t1][t2];
				a[t1][t2]=temp;
				m++;
					if(m==edge)
			     	{
			     	    end=1;	
			     	    break;
			     	}
			}
        }
        if(end==1)
        break;
    }
	
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile << point<< " "<<edge;
         for(int i=0;i<point;i++)
    {
    	for(int j=0;j<point;j++)
    	{
    		if(a[i][j]!=-1)
    		{
    			examplefile<<"\n"<<i<<" "<<j<<" "<<a[i][j];
    		}
    	}
    }
	
	     examplefile<<"\n"<<s0<< " "<<s1;
         examplefile.close();        //关闭文件 
    } 
}
	} 
} 
