#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <climits>
#include <ctime>
#include <fstream>
using namespace std;
int src_input;
int arg[2000][12];
int bi;

int flag[2000];
 
string number;

void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
	
	int a[500][500];
    
    int row,column; 
    
    	switch (arg[a1][0])
		{
		   case 0: row=9;
	        	break;
		   case 1: row=19;
				break;
		   case 2: row=29;
				break;						 
	    } 
	
        switch (arg[a1][1])
	    {
		    case 0: column=1+rand()%9;
	        	break;
		    case 1: column=10+rand()%10;
				break;
		    case 2: column=20+rand()%10;
				break;						 
	    } 
	
    	for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<column;j++)
    		{
    			a[i][j]=0;
    		}
    	}

		    	
    	if(arg[a1][3]==1)
		{
			if(arg[a1][2]==0)
   	 	{
         	for(int j=0;j<column;j++)
         	{
         		int num=rand()%row+1;
         		for(int i=0;i<row;i++)
         		{
         			if(num==0)
         			break;
         			a[i][j]=1;
         			num--;
         		}
         		for(int i=0;i<row;i++)
         		{
         			int temp=a[i][j];
         			int p=rand()%row;
         			a[i][j]=a[p][j];
         			a[p][j]=temp;
         		}
         	}
    	}
    
    	if(arg[a1][2]==1)
    	{
    	for(int i=0;i<row;i++)
       {
    	for(int j=0;j<column;j++)
    	{
    		a[i][j]=1;
    		
    	}
        }
    	}
		} 
		if(arg[a1][3]==0)
		{
		    for(int j=0;j<column;j++)
         	{
         		int num=rand()%row+1;
         		for(int i=0;i<row;i++)
         		{
         			if(num==0)
         			break;
         			a[i][j]=1;
         			num--;
         		}
         		for(int i=0;i<row;i++)
         		{
         			int temp=a[i][j];
         			int p=rand()%row;
         			a[i][j]=a[p][j];
         			a[p][j]=temp;
         		}
         	}
		}  	 	
    	char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
        std::ofstream examplefile(filename);
        //int testcasei=0;
        if (examplefile.is_open())
        {            
            examplefile<< row<<" "<<column<<"\n";
            //testcase[a1][testcasei++]=row;
           // testcase[a1][testcasei++]=column;
           	for(int i=0;i<row;i++)
        	{
    		  for(int j=0;j<column;j++)
    		  {
              	  examplefile << a[i][j];
              	  if(j!=column-1)
              	  examplefile <<" ";
              	  //testcase[a1][testcasei++]=a[i][j];
			  }
			  if(i!=row-1)
			  examplefile <<"\n";
    		}
            examplefile.close();        //关闭文件 
        } 
	 
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
        std::ofstream examplefile1(filename);
        //int testcasei=0;
        row++;
        if (examplefile1.is_open())
        {            
            examplefile1<< row<<" "<<column<<"\n";
            //testcase[a1][testcasei++]=row;
           // testcase[a1][testcasei++]=column;
           	for(int i=0;i<row-1;i++)
        	{
    		  for(int j=0;j<column;j++)
    		  {
              	  examplefile1 << a[i][j];
              	  if(j!=column-1)
              	  examplefile1 <<" ";
              	  //testcase[a1][testcasei++]=a[i][j];
			  }
			  examplefile1 <<"\n";
    		}
    		for(int j=0;j<column;j++)
    		{
    			examplefile1 <<0;
    			if(j!=column-1)
              	  examplefile1 <<" ";
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
	
	int a[500][500];
    
    int row,column; 
    
    	switch (arg[a1][0])
		{
		   case 0: row=1+rand()%9;
	        	break;
		   case 1: row=10+rand()%10;
				break;
		   case 2: row=20+rand()%10;
				break;						 
	    } 
	
        switch (arg[a1][1])
	    {
		    case 0: column=9;
	        	break;
		    case 1: column=19;
				break;
		    case 2: column=29;
				break;						 
	    } 
	
    	for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<column;j++)
    		{
    			a[i][j]=0;
    		}
    	}

		    	
    	if(arg[a1][3]==1)
		{
			if(arg[a1][2]==0)
   	 	{
         	for(int j=0;j<column;j++)
         	{
         		int num=rand()%row+1;
         		for(int i=0;i<row;i++)
         		{
         			if(num==0)
         			break;
         			a[i][j]=1;
         			num--;
         		}
         		for(int i=0;i<row;i++)
         		{
         			int temp=a[i][j];
         			int p=rand()%row;
         			a[i][j]=a[p][j];
         			a[p][j]=temp;
         		}
         	}
    	}
    
    	if(arg[a1][2]==1)
    	{
    	for(int i=0;i<row;i++)
       {
    	for(int j=0;j<column;j++)
    	{
    		a[i][j]=1;
    		
    	}
        }
    	}
		} 
		if(arg[a1][3]==0)
		{
		    for(int j=0;j<column;j++)
         	{
         		int num=rand()%row+1;
         		for(int i=0;i<row;i++)
         		{
         			if(num==0)
         			break;
         			a[i][j]=1;
         			num--;
         		}
         		for(int i=0;i<row;i++)
         		{
         			int temp=a[i][j];
         			int p=rand()%row;
         			a[i][j]=a[p][j];
         			a[p][j]=temp;
         		}
         	}
		}  	
    	char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
        std::ofstream examplefile(filename);
        //int testcasei=0;
        if (examplefile.is_open())
        {            
            examplefile<< row<<" "<<column<<"\n";
            //testcase[a1][testcasei++]=row;
           // testcase[a1][testcasei++]=column;
           	for(int i=0;i<row;i++)
        	{
    		  for(int j=0;j<column;j++)
    		  {
              	  examplefile << a[i][j];
              	  if(j!=column-1)
              	  examplefile <<" ";
              	  //testcase[a1][testcasei++]=a[i][j];
			  }
			  if(i!=row-1)
			  examplefile <<"\n";
    		}
            examplefile.close();        //关闭文件 
        } 
	 
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
        std::ofstream examplefile1(filename);
        //int testcasei=0;
        column++;
        if (examplefile1.is_open())
        {            
            examplefile1<< row<<" "<<column<<"\n";
            //testcase[a1][testcasei++]=row;
           // testcase[a1][testcasei++]=column;
           	for(int i=0;i<row;i++)
        	{
    		  for(int j=0;j<column;j++)
    		  {
    		  	  if(j==column-1)
    		  	  examplefile1 << 1;
    		  	  else
              	  examplefile1 << a[i][j]<<" ";
              	  //testcase[a1][testcasei++]=a[i][j];
			  }
			  if(i!=row-1) 
			  examplefile1 <<"\n";
    		}    		
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
				if(arg[i][0]==arg[j][0]-1&&arg[i][1]==arg[j][1]&&arg[j][3]==0)
				{
					MR0_testcase(i,j);
					break;
				}
				if(arg[i][0]==arg[j][0]+1&&arg[i][1]==arg[j][1]&&arg[i][3]==0)
				{
					MR0_testcase(j,i);
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
				if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]-1&&arg[j][3]==0)
				{
					MR1_testcase(i,j);
					break;
				}
				if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]+1&&arg[i][3]==0)
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
    judgeMR1();
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
		int a[500][500];
    
        int row,column; 
    
        switch (arg[a1][0])
	    {
		   case 0: row=1+rand()%9;
	        	break;
		   case 1: row=10+rand()%10;
				break;
		   case 2: row=20+rand()%10;
				break;						 
	    } 
	
        switch (arg[a1][1])
	    {
		    case 0: column=1+rand()%9;
	        	break;
		    case 1: column=10+rand()%10;
				break;
		    case 2: column=20+rand()%10;
				break;						 
	    } 
	
    	for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<column;j++)
    		{
    			a[i][j]=0;
    		}
    	}
    	
    	if(arg[a1][3]==1)
		{
			if(arg[a1][2]==0)
   	 	{
         	for(int j=0;j<column;j++)
         	{
         		int num=rand()%row+1;
         		for(int i=0;i<row;i++)
         		{
         			if(num==0)
         			break;
         			a[i][j]=1;
         			num--;
         		}
         		for(int i=0;i<row;i++)
         		{
         			int temp=a[i][j];
         			int p=rand()%row;
         			a[i][j]=a[p][j];
         			a[p][j]=temp;
         		}
         	}
    	}
    
    	if(arg[a1][2]==1)
    	{
    	for(int i=0;i<row;i++)
       {
    	for(int j=0;j<column;j++)
    	{
    		a[i][j]=1;
    		
    	}
        }
    	}
		} 
		if(arg[a1][3]==0)
		{
		    for(int j=0;j<column;j++)
         	{
         		int num=rand()%row+1;
         		for(int i=0;i<row;i++)
         		{
         			if(num==0)
         			break;
         			a[i][j]=1;
         			num--;
         		}
         		for(int i=0;i<row;i++)
         		{
         			int temp=a[i][j];
         			int p=rand()%row;
         			a[i][j]=a[p][j];
         			a[p][j]=temp;
         		}
         	}
		}  	 	
    	char filename[200];
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
        std::ofstream examplefile(filename);
        if (examplefile.is_open())
        {  
            
            examplefile<< row<<" "<<column<<"\n";
           	for(int i=0;i<row;i++)
        	{
    		  for(int j=0;j<column;j++)
    		  {
              examplefile << a[i][j];
              if(j!=column-1)
              examplefile << " ";
			  }
			  if(i!=row-1)
			  examplefile <<"\n";
    		}
            examplefile.close();        //关闭文件 
        } 
     }
	}         
}
