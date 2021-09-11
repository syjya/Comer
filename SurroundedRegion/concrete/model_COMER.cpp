#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <fstream>
int src_input;
int arg[2000][12];
int bi;

int flag[2000];
std::string number;
void MR0_testcase(int aa1,int aa2)
{
	if(flag[aa1]==1||flag[aa2]==1)
	return;
	
	int row,column; 
    switch(arg[aa1][0])
	{
			case 0:
				row=9;
				break;
			case 1:
				row=19;
				break;			
			case 2:
                row=29;
				break;					
	}
    switch(arg[aa1][1])
	{
			case 0:
				column=1+rand()%9;
				break;
			case 1:
			    column=10+rand()%10;
				break;			
			case 2:
                column=20+rand()%10;
				break;					
	}
		
	if(arg[aa1][2]==2||arg[aa1][2]==3||arg[aa1][2]==4)
	column=row;
	
	int arg1=row;
	int arg2=column; 
	int n=arg1*arg2;
    
    char b[1000][1000];
    
    //a1为X的个数，a2为O的个数 
	int a1,a2,n1; 
	if(arg[aa1][4]==1)
	{
    switch (arg[aa1][2])
	{
				
		case 0:
			    switch (arg[aa1][3])
			    {
			    	case 0: a1=0;
					        break;
					case 1:
						    a1=n/2;
						    break;
					case 2: 
						    a1=n/3;
					        break;
					case 3: 
					        a1=n/4;
					        break;
					case 4:
						    a1=n;
						    break;							 
				} 
				break;
		case 1:
			    a1=0;
				break;			
		case 2:
                switch (arg[aa1][3])
			    {
			    	case 0: a1=0; 
					        break;
					case 1:
						    a1=arg1/2;
						    break;
					case 2:
						    a1=arg1/3;
						    break;
					case 3:
						    a1=arg1/4;
						    break;
					case 4:
						    a1=arg1;
						    break;							 
				} 
				break;		
		case 3:
				n1 = arg1*(arg1+1)/2;
				switch (arg[aa1][3])
			    {
			    	case 0: a1=0;
					        break;
					case 1:
						    a1=n1/2;
						    break;
					case 2:
						    a1=n1/3;
						    break;
					case 3:
						    a1=n1/4;
						    break;
					case 4:
						    a1=n1;
						    break;							 
				} 
				break;	
		case 4:
				n1 = arg1*(arg1+1)/2;
				switch (arg[aa1][3])
			    {
			    	case 0: a1=0;
					        break;
					case 1:
						    a1=n1/2;
						    break;
					case 2:
						    a1=n1/3;
						    break;
					case 3:
						    a1=n1/4;
						    break;
					case 4:
						    a1=n1;
						    break;							 
				} 
				break;			
	} 
	a2=n-a1;
	
	//按顺序产生这些数，但随机位置。 	
	if(arg[aa1][2]==0)
	{   
         int i=0,j=0;
         for(int i1=0;i1<a1;i1++)
         {
         	 b[i][j]='X';
         	 if(j==arg2-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         for(int i1=0;i1<a2;i1++)
         {
         	 b[i][j]='O';
         	 if(j==arg2-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         
         for(int p=0;p<arg1;p++)
         {
         	for(int q=0;q<arg2;q++)
         	{
         		int temp=b[p][q];
         		int p1=rand()%arg1;
         		int p2=rand()%arg2;
         		b[p][q]=b[p1][p2];
         		b[p1][p2]=temp;
         	}
         }
	}
	
	//0 
	if(arg[aa1][2]==1)
	{
		for(int i=0;i<arg1;i++)
        {
    	     for(int j=0;j<arg2;j++)
    	     b[i][j]='O';
        }
	}
	
	//对角 
	if(arg[aa1][2]==2)
	{
		arg2=arg1; 
		for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	  if(i!=j)
    	  b[i][j]='O';
        }
        for(int i=0;i<a1;i++)
        b[i][i]= 'X'; 
        for(int i=a1;i<arg1;i++)
        b[i][i]= 'O';
        for(int i=0;i<arg1;i++)
        {
        	    int temp=b[i][i];
         		int p1=rand()%arg1;
         		b[i][i]=b[p1][p1];
         		b[p1][p1]=temp;
        }
	}
	
	//上三角 
	if(arg[aa1][2]==3||arg[aa1][2]==4)
	{
		arg2=arg1; 
		for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	  {
    	  	if(i>j)
    	    b[i][j]='O';
    	  }
        }
        
        int i1=0;
        for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   	   if(i1<a1)
    	   	   	   {
    	   	   	   	   b[i][j]='X';
    	   	   	   	   i1++;
    	   	   	   }
    	   	   	   else
    	   	   	   {
    	   	   	   	b[i][j]='O';
    	   	   	   }
    	   	   }
    	   }
        }
        
        for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   int temp=b[i][j];
    	   	   int q=rand()%arg1;
			   int p;
    	   	   if(q==0)
    	   	   p=0;
    	   	   else
    	   	   p=rand()%q;
    	   	   b[i][j]=b[p][q];
    	   	   b[p][q]=temp;
    	   	   }
    	   	  
    	   }
        }
	}	
	
	//下三角 
	if(arg[aa1][2]==4)
	{
		arg2=arg1; 
		for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	  {
    	  	if(i<j)
    	  	{
    	  	int temp=b[i][j];
    	  	b[i][j]=b[j][i];
    	  	b[j][i]=temp;
    	  	}
    	  }
        }
	}
    }
        else if(arg[aa1][4]==0)
    {     
	    for(int i=0;i<arg1;i++)
    	{
    		for(int j=0;j<arg2;j++)
    		b[i][j]='O';
    	}
    	if(arg[aa1][2]==0)
    	{
    		int temprand=1+rand()%n;
    		int ni=0;
    		for(int i=0;i<arg1;i++)
    	    {
    		for(int j=0;j<arg2;j++)
    		{
    			b[i][j]='X';
    			ni++;
    			if(ni>=temprand)
    			break;
    		}
    		}
			for(int p=0;p<arg1;p++)
         	{
         	for(int q=0;q<arg2;q++)
         	{
         		int temp=b[p][q];
         		int p1=rand()%arg1;
         		int p2=rand()%arg2;
         		b[p][q]=b[p1][p2];
         		b[p1][p2]=temp;
         	}
         	}	
    	}
    	else if(arg[aa1][2]==2)
    	{
    		int temprand=1+rand()%arg1;
    		int ni=0;
    		for(int i=0;i<arg1;i++)
    	    {
    			b[i][i]='X';
    			ni++;
    			if(ni>=temprand)
    			break;
    		}
			for(int i=0;i<arg1;i++)
        	{
        	    int temp=b[i][i];
         		int p1=rand()%arg1;
         		b[i][i]=b[p1][p1];
         		b[p1][p1]=temp;
        	}	
    	}
    	else if(arg[aa1][2]==3||arg[aa1][2]==4)
    	{
    		int temprand=1+rand()%(n-arg1*(arg1-1)/2);
    		int ni=0;
    		for(int i=0;i<arg1;i++)
    	    {
    		for(int j=i;j<arg2;j++)
    		{
    			b[i][j]='X';
    			ni++;
    			if(ni>=temprand)
    			break;
    		}
    		}
			for(int i=0;i<arg1;i++)
        	{
    	  	for(int j=0;j<arg1;j++)
    	   	{
    	   	   if(i<=j)
    	   	   {
    	   	   int temp=b[i][j];
    	   	   int q=rand()%arg1;
			   int p;
    	   	   if(q==0)
    	   	   p=0;
    	   	   else
    	   	   p=rand()%q;
    	   	   b[i][j]=b[p][q];
    	   	   b[p][q]=temp;
    	   	   }
    	   	  
    	   }
        	}	
    	}
    	if(arg[aa1][2]==4)
    	{
    		for(int i=0;i<arg1;i++)
        	{
    	  for(int j=0;j<arg1;j++)
    	  {
    	  	if(i<j)
    	  	{
    	  	int temp=b[i][j];
    	  	b[i][j]=b[j][i];
    	  	b[j][i]=temp;
    	  	}
    	  }
        	}	
    	}
    }
    	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
    	     examplefile << arg1<<" "<<arg2<<"\n";
            for(int i=0;i<arg1;i++)
        	{
    			for(int j=0;j<arg2;j++)
    			{
              	   examplefile<< b[i][j];
              	   if(j!=arg2-1)
					  examplefile<<" ";
				}
				if(i!=arg1-1)
				examplefile<<"\n";
        	}
         	examplefile.close();        //关闭文件 
    	}
	
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile2(filename);
    	if (examplefile2.is_open())
    	{  
    	     examplefile2 << arg1+1<<" "<<arg2<<"\n";
            for(int i=0;i<arg1+1;i++)
        	{
    			for(int j=0;j<arg2;j++)
    			{
    				if(i==arg1)
    				{
    					examplefile2<< "O";
    					if(j!=arg2-1)
    					examplefile2<<" ";
    				}
    				else
    				{
    					 examplefile2<< b[i][j];
    					 if(j!=arg2-1)
    					 examplefile2<<" ";
    				}
              	   
				}
				if(i!=arg1)
				examplefile2<<"\n";
        	}
         	examplefile2.close();        //关闭文件 
    	}
    flag[aa1]=1;
    flag[aa2]=1;
}

void MR1_testcase(int aa1,int aa2)
{
	if(flag[aa1]==1||flag[aa2]==1)
	return;
	
	int row,column; 
    switch(arg[aa1][0])
	{
			case 0:
				row=1+rand()%9;
				break;
			case 1:
				row=10+rand()%10;
				break;			
			case 2:
                row=20+rand()%10;
				break;					
	}
    switch(arg[aa1][1])
	{
			case 0:
				column=9;
				break;
			case 1:
			    column=19;
				break;			
			case 2:
                column=29;
				break;					
	}
		
	if(arg[aa1][2]==2||arg[aa1][2]==3||arg[aa1][2]==4)
	column=row;
	
	int arg1=row;
	int arg2=column; 
	int n=arg1*arg2;
    
    char b[1000][1000];
    
    //a1为X的个数，a2为O的个数 
	int a1,a2,n1; 
	if(arg[aa1][4]==1)
	{
    switch (arg[aa1][2])
	{
				
		case 0:
			    switch (arg[aa1][3])
			    {
			    	case 0: a1=0;
					        break;
					case 1:
						    a1=n/2;
						    break;
					case 2: 
						    a1=n/3;
					        break;
					case 3: 
					        a1=n/4;
					        break;
					case 4:
						    a1=n;
						    break;							 
				} 
				break;
		case 1:
			    a1=0;
				break;			
		case 2:
                switch (arg[aa1][3])
			    {
			    	case 0: a1=0; 
					        break;
					case 1:
						    a1=arg1/2;
						    break;
					case 2:
						    a1=arg1/3;
						    break;
					case 3:
						    a1=arg1/4;
						    break;
					case 4:
						    a1=arg1;
						    break;							 
				} 
				break;		
		case 3:
				n1 = arg1*(arg1+1)/2;
				switch (arg[aa1][3])
			    {
			    	case 0: a1=0;
					        break;
					case 1:
						    a1=n1/2;
						    break;
					case 2:
						    a1=n1/3;
						    break;
					case 3:
						    a1=n1/4;
						    break;
					case 4:
						    a1=n1;
						    break;							 
				} 
				break;	
		case 4:
				n1 = arg1*(arg1+1)/2;
				switch (arg[aa1][3])
			    {
			    	case 0: a1=0;
					        break;
					case 1:
						    a1=n1/2;
						    break;
					case 2:
						    a1=n1/3;
						    break;
					case 3:
						    a1=n1/4;
						    break;
					case 4:
						    a1=n1;
						    break;							 
				} 
				break;			
	} 
	a2=n-a1;
	
	//按顺序产生这些数，但随机位置。 	
	if(arg[aa1][2]==0)
	{   
         int i=0,j=0;
         for(int i1=0;i1<a1;i1++)
         {
         	 b[i][j]='X';
         	 if(j==arg2-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         for(int i1=0;i1<a2;i1++)
         {
         	 b[i][j]='O';
         	 if(j==arg2-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         
         for(int p=0;p<arg1;p++)
         {
         	for(int q=0;q<arg2;q++)
         	{
         		int temp=b[p][q];
         		int p1=rand()%arg1;
         		int p2=rand()%arg2;
         		b[p][q]=b[p1][p2];
         		b[p1][p2]=temp;
         	}
         }
	}
	
	//0 
	if(arg[aa1][2]==1)
	{
		for(int i=0;i<arg1;i++)
        {
    	     for(int j=0;j<arg2;j++)
    	     b[i][j]='O';
        }
	}
	
	//对角 
	if(arg[aa1][2]==2)
	{
		arg2=arg1; 
		for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	  if(i!=j)
    	  b[i][j]='O';
        }
        for(int i=0;i<a1;i++)
        b[i][i]= 'X'; 
        for(int i=a1;i<arg1;i++)
        b[i][i]= 'O';
        for(int i=0;i<arg1;i++)
        {
        	    int temp=b[i][i];
         		int p1=rand()%arg1;
         		b[i][i]=b[p1][p1];
         		b[p1][p1]=temp;
        }
	}
	
	//上三角 
	if(arg[aa1][2]==3||arg[aa1][2]==4)
	{
		arg2=arg1; 
		for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	  {
    	  	if(i>j)
    	    b[i][j]='O';
    	  }
        }
        
        int i1=0;
        for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   	   if(i1<a1)
    	   	   	   {
    	   	   	   	   b[i][j]='X';
    	   	   	   	   i1++;
    	   	   	   }
    	   	   	   else
    	   	   	   {
    	   	   	   	b[i][j]='O';
    	   	   	   }
    	   	   }
    	   }
        }
        
        for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   int temp=b[i][j];
    	   	   int q=rand()%arg1;
			   int p;
    	   	   if(q==0)
    	   	   p=0;
    	   	   else
    	   	   p=rand()%q;
    	   	   b[i][j]=b[p][q];
    	   	   b[p][q]=temp;
    	   	   }
    	   	  
    	   }
        }
	}	
	
	//下三角 
	if(arg[aa1][2]==4)
	{
		arg2=arg1; 
		for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	  {
    	  	if(i<j)
    	  	{
    	  	int temp=b[i][j];
    	  	b[i][j]=b[j][i];
    	  	b[j][i]=temp;
    	  	}
    	  }
        }
	}
    }
    else if(arg[aa1][4]==0)
    {     
	    for(int i=0;i<arg1;i++)
    	{
    		for(int j=0;j<arg2;j++)
    		b[i][j]='O';
    	}
    	if(arg[aa1][2]==0)
    	{
    		int temprand=1+rand()%n;
    		int ni=0;
    		for(int i=0;i<arg1;i++)
    	    {
    		for(int j=0;j<arg2;j++)
    		{
    			b[i][j]='X';
    			ni++;
    			if(ni>=temprand)
    			break;
    		}
    		}
			for(int p=0;p<arg1;p++)
         	{
         	for(int q=0;q<arg2;q++)
         	{
         		int temp=b[p][q];
         		int p1=rand()%arg1;
         		int p2=rand()%arg2;
         		b[p][q]=b[p1][p2];
         		b[p1][p2]=temp;
         	}
         	}	
    	}
    	else if(arg[aa1][2]==2)
    	{
    		int temprand=1+rand()%arg1;
    		int ni=0;
    		for(int i=0;i<arg1;i++)
    	    {
    			b[i][i]='X';
    			ni++;
    			if(ni>=temprand)
    			break;
    		}
			for(int i=0;i<arg1;i++)
        	{
        	    int temp=b[i][i];
         		int p1=rand()%arg1;
         		b[i][i]=b[p1][p1];
         		b[p1][p1]=temp;
        	}	
    	}
    	else if(arg[aa1][2]==3||arg[aa1][2]==4)
    	{
    		int temprand=1+rand()%(n-arg1*(arg1-1)/2);
    		int ni=0;
    		for(int i=0;i<arg1;i++)
    	    {
    		for(int j=i;j<arg2;j++)
    		{
    			b[i][j]='X';
    			ni++;
    			if(ni>=temprand)
    			break;
    		}
    		}
			for(int i=0;i<arg1;i++)
        	{
    	  	for(int j=0;j<arg1;j++)
    	   	{
    	   	   if(i<=j)
    	   	   {
    	   	   int temp=b[i][j];
    	   	   int q=rand()%arg1;
			   int p;
    	   	   if(q==0)
    	   	   p=0;
    	   	   else
    	   	   p=rand()%q;
    	   	   b[i][j]=b[p][q];
    	   	   b[p][q]=temp;
    	   	   }
    	   	  
    	   }
        	}	
    	}
    	if(arg[aa1][2]==4)
    	{
    		for(int i=0;i<arg1;i++)
        	{
    	  for(int j=0;j<arg1;j++)
    	  {
    	  	if(i<j)
    	  	{
    	  	int temp=b[i][j];
    	  	b[i][j]=b[j][i];
    	  	b[j][i]=temp;
    	  	}
    	  }
        	}	
    	}
    }
    	char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
    	     examplefile << arg1<<" "<<arg2<<"\n";
            for(int i=0;i<arg1;i++)
        	{
    			for(int j=0;j<arg2;j++)
    			{
              	   examplefile<< b[i][j];
              	   if(j!=arg2-1)
    					examplefile<<" ";
				}
				if(i!=arg1-1)
				examplefile<<"\n";
        	}
         	examplefile.close();        //关闭文件 
    	}
	
	    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile2(filename);
    	if (examplefile2.is_open())
    	{  
    	     examplefile2 << arg1<<" "<<arg2+1<<"\n";
            for(int i=0;i<arg1;i++)
        	{
    			for(int j=0;j<arg2+1;j++)
    			{
    				if(j==arg2)
    				examplefile2<< "O";
    				else
              	    examplefile2<< b[i][j]<< " ";
				}
				if(i!=arg1-1)
				examplefile2<<"\n";
        	}
         	examplefile2.close();        //关闭文件 
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
			if(arg[i][0]==arg[j][0]-1&&arg[i][1]==arg[j][1]&&((arg[i][2]==1&&arg[j][2]==1)||(arg[i][2]!=1&&arg[j][2]==0))&&arg[j][4]==0)
			{
				 MR0_testcase(i,j);
				 break;
			}
			else if(arg[j][0]==arg[i][0]-1&&arg[i][1]==arg[j][1]&&((arg[i][2]==1&&arg[j][2]==1)||(arg[j][2]!=1&&arg[i][2]==0))&&arg[i][4]==0)
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
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]-1&&((arg[i][2]==1&&arg[j][2]==1)||(arg[i][2]!=1&&arg[j][2]==0))&&arg[j][4]==0)
			{
				 MR1_testcase(i,j);
				 break;
			}
			else if(arg[j][0]==arg[i][0]&&arg[j][1]==arg[i][1]-1&&((arg[i][2]==1&&arg[j][2]==1)||(arg[j][2]!=1&&arg[i][2]==0))&&arg[i][4]==0)
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
    judgeMR0();
    judgeMR1();
    for(int aa1=0;aa1<bi;aa1++)
    {
    if(flag[aa1]==-1)
    {
		int row,column; 
    switch(arg[aa1][0])
	{
			case 0:
				row=1+rand()%9;
				break;
			case 1:
				row=10+rand()%10;
				break;			
			case 2:
                row=20+rand()%10;
				break;					
	}
    switch(arg[aa1][1])
	{
			case 0:
				column=1+rand()%9;
				break;
			case 1:
			    column=10+rand()%10;
				break;			
			case 2:
                column=20+rand()%10;
				break;					
	}
		
	if(arg[aa1][2]==2||arg[aa1][2]==3||arg[aa1][2]==4)
	column=row;
	
	int arg1=row;
	int arg2=column; 
	int n=arg1*arg2;
    
    char b[1000][1000];
    
    //a1为X的个数，a2为O的个数 
	int a1,a2,n1; 
	if(arg[aa1][4]==1)
	{
    switch (arg[aa1][2])
	{
				
		case 0:
			    switch (arg[aa1][3])
			    {
			    	case 0: a1=0;
					        break;
					case 1:
						    a1=n/2;
						    break;
					case 2: 
						    a1=n/3;
					        break;
					case 3: 
					        a1=n/4;
					        break;
					case 4:
						    a1=n;
						    break;							 
				} 
				break;
		case 1:
			    a1=0;
				break;			
		case 2:
                switch (arg[aa1][3])
			    {
			    	case 0: a1=0; 
					        break;
					case 1:
						    a1=arg1/2;
						    break;
					case 2:
						    a1=arg1/3;
						    break;
					case 3:
						    a1=arg1/4;
						    break;
					case 4:
						    a1=arg1;
						    break;							 
				} 
				break;		
		case 3:
				n1 = arg1*(arg1+1)/2;
				switch (arg[aa1][3])
			    {
			    	case 0: a1=0;
					        break;
					case 1:
						    a1=n1/2;
						    break;
					case 2:
						    a1=n1/3;
						    break;
					case 3:
						    a1=n1/4;
						    break;
					case 4:
						    a1=n1;
						    break;							 
				} 
				break;	
		case 4:
				n1 = arg1*(arg1+1)/2;
				switch (arg[aa1][3])
			    {
			    	case 0: a1=0;
					        break;
					case 1:
						    a1=n1/2;
						    break;
					case 2:
						    a1=n1/3;
						    break;
					case 3:
						    a1=n1/4;
						    break;
					case 4:
						    a1=n1;
						    break;							 
				} 
				break;			
	} 
	a2=n-a1;
	
	//按顺序产生这些数，但随机位置。 	
	if(arg[aa1][2]==0)
	{   
         int i=0,j=0;
         for(int i1=0;i1<a1;i1++)
         {
         	 b[i][j]='X';
         	 if(j==arg2-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         for(int i1=0;i1<a2;i1++)
         {
         	 b[i][j]='O';
         	 if(j==arg2-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         
         for(int p=0;p<arg1;p++)
         {
         	for(int q=0;q<arg2;q++)
         	{
         		int temp=b[p][q];
         		int p1=rand()%arg1;
         		int p2=rand()%arg2;
         		b[p][q]=b[p1][p2];
         		b[p1][p2]=temp;
         	}
         }
	}
	
	//0 
	if(arg[aa1][2]==1)
	{
		for(int i=0;i<arg1;i++)
        {
    	     for(int j=0;j<arg2;j++)
    	     b[i][j]='O';
        }
	}
	
	//对角 
	if(arg[aa1][2]==2)
	{
		arg2=arg1; 
		for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	  if(i!=j)
    	  b[i][j]='O';
        }
        for(int i=0;i<a1;i++)
        b[i][i]= 'X'; 
        for(int i=a1;i<arg1;i++)
        b[i][i]= 'O';
        for(int i=0;i<arg1;i++)
        {
        	    int temp=b[i][i];
         		int p1=rand()%arg1;
         		b[i][i]=b[p1][p1];
         		b[p1][p1]=temp;
        }
	}
	
	//上三角 
	if(arg[aa1][2]==3||arg[aa1][2]==4)
	{
		arg2=arg1; 
		for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	  {
    	  	if(i>j)
    	    b[i][j]='O';
    	  }
        }
        
        int i1=0;
        for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   	   if(i1<a1)
    	   	   	   {
    	   	   	   	   b[i][j]='X';
    	   	   	   	   i1++;
    	   	   	   }
    	   	   	   else
    	   	   	   {
    	   	   	   	b[i][j]='O';
    	   	   	   }
    	   	   }
    	   }
        }
        
        for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   int temp=b[i][j];
    	   	   int q=rand()%arg1;
			   int p;
    	   	   if(q==0)
    	   	   p=0;
    	   	   else
    	   	   p=rand()%q;
    	   	   b[i][j]=b[p][q];
    	   	   b[p][q]=temp;
    	   	   }
    	   	  
    	   }
        }
	}	
	
	//下三角 
	if(arg[aa1][2]==4)
	{
		arg2=arg1; 
		for(int i=0;i<arg1;i++)
        {
    	  for(int j=0;j<arg1;j++)
    	  {
    	  	if(i<j)
    	  	{
    	  	int temp=b[i][j];
    	  	b[i][j]=b[j][i];
    	  	b[j][i]=temp;
    	  	}
    	  }
        }
	}
    }
    
    else if(arg[aa1][4]==0)
    {     
	    for(int i=0;i<arg1;i++)
    	{
    		for(int j=0;j<arg2;j++)
    		b[i][j]='O';
    	}
    	if(arg[aa1][2]==0)
    	{
    		int temprand=1+rand()%n;
    		int ni=0;
    		for(int i=0;i<arg1;i++)
    	    {
    		for(int j=0;j<arg2;j++)
    		{
    			b[i][j]='X';
    			ni++;
    			if(ni>=temprand)
    			break;
    		}
    		}
			for(int p=0;p<arg1;p++)
         	{
         	for(int q=0;q<arg2;q++)
         	{
         		int temp=b[p][q];
         		int p1=rand()%arg1;
         		int p2=rand()%arg2;
         		b[p][q]=b[p1][p2];
         		b[p1][p2]=temp;
         	}
         	}	
    	}
    	else if(arg[aa1][2]==2)
    	{
    		int temprand=1+rand()%arg1;
    		int ni=0;
    		for(int i=0;i<arg1;i++)
    	    {
    			b[i][i]='X';
    			ni++;
    			if(ni>=temprand)
    			break;
    		}
			for(int i=0;i<arg1;i++)
        	{
        	    int temp=b[i][i];
         		int p1=rand()%arg1;
         		b[i][i]=b[p1][p1];
         		b[p1][p1]=temp;
        	}	
    	}
    	else if(arg[aa1][2]==3||arg[aa1][2]==4)
    	{
    		int temprand=1+rand()%(n-arg1*(arg1-1)/2);
    		int ni=0;
    		for(int i=0;i<arg1;i++)
    	    {
    		for(int j=i;j<arg2;j++)
    		{
    			b[i][j]='X';
    			ni++;
    			if(ni>=temprand)
    			break;
    		}
    		}
			for(int i=0;i<arg1;i++)
        	{
    	  	for(int j=0;j<arg1;j++)
    	   	{
    	   	   if(i<=j)
    	   	   {
    	   	   int temp=b[i][j];
    	   	   int q=rand()%arg1;
			   int p;
    	   	   if(q==0)
    	   	   p=0;
    	   	   else
    	   	   p=rand()%q;
    	   	   b[i][j]=b[p][q];
    	   	   b[p][q]=temp;
    	   	   }
    	   	  
    	   }
        	}	
    	}
    	if(arg[aa1][2]==4)
    	{
    		for(int i=0;i<arg1;i++)
        	{
    	  for(int j=0;j<arg1;j++)
    	  {
    	  	if(i<j)
    	  	{
    	  	int temp=b[i][j];
    	  	b[i][j]=b[j][i];
    	  	b[j][i]=temp;
    	  	}
    	  }
        	}	
    	}
    }
    	char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
    	     examplefile << arg1<<" "<<arg2<<"\n";
            for(int i=0;i<arg1;i++)
        	{
    			for(int j=0;j<arg2;j++)
    			{
              	   examplefile<< b[i][j];
              	   if(j!=arg2-1)
    					examplefile<<" ";
				}
				if(i!=arg1-1)
				examplefile<<"\n";
        	}
         	examplefile.close();        //关闭文件 
    	}
    } 
}
} 
