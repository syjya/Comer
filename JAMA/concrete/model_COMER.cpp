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

int resultb[500][500][500];
std::string number;

void MR0_testcase(int aa1,int aa2)
{
	if(flag[aa1]!=-1&&flag[aa2]!=-1)
	return;
	if(flag[aa1]==-1&&flag[aa2]==-1)
	{
	int row,column;     
    switch (arg[aa1][0])
	{
		case 0: row=1+rand()%9;
	        	break;
		case 1: row=10+rand()%10;
				break;
		case 2: row=20+rand()%10;
				break;						 
	} 
	
/*	if(arg[4]==1&&row==1)
	row=2+rand()%8;*/
	
	column=row;
	
	int n=row*column;
    int a[500][500];
    for(int i=0;i<row;i++)
    {
    	for(int j=0;j<column;j++)
    	a[i][j]=0;
    }
       
    //初始化为全零矩阵 ,a1为0的个数，a2为正数个数，a3为负数个数。 
	int a1=n;
	int a2=0;
	int a3=0;
	
    switch (arg[aa1][1])
	{
			
		case 0:
			    switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)(n*((rand()%100)/100.0 ));
					        a1=n-a3;
					        break;
					case 1:
						    a2=n/2;
						    a3=(int)((n-a2)*((rand()%100)/100.0 ));
						    a1=n-a2-a3;
						    break;
					case 2: a2=n/3;
					        a3=(int)((n-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 3: a2=n/4;
					        a3=(int)((n-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 4:
						    a2=n;
						    a3=0;
						    a1=0;
						    break;							 
				} 
				break;
		case 1:
				break;			
		case 2:
                switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 1:
						    a2=column/2;
						    a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 2:
						    a2=column/3;
						    a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 3:
						    a2=column/4;
						    a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 4:
						    a2=column;
						    a3=0;
					        a1=0;
						    break;							 
				} 
				break;		
		case 3:
				switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 1:
						    a2=(1+row)*row/2/2;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 2:
						    a2=(1+row)*row/2/3;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 3:
						    a2=(1+row)*row/2/4;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 4:
						    a2=(1+row)*row/2;
						    a3=0;
					        a1=0;
						    break;							 
				} 
				break;	
		case 4:
				switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 1:
						    a2=(1+row)*row/2/2;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 2:
						    a2=(1+row)*row/2/3;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 3:
						    a2=(1+row)*row/2/4;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 4:
						    a2=(1+row)*row/2;
						    a3=0;
					        a1=0;
						    break;							 
				} 
				break;		
	} 
	
	//按顺序产生这些数，但随机位置。 	
	if(arg[aa1][1]==0)
	{   
         int i=0,j=0;
         for(int i1=0;i1<a2;i1++)
         {
         	 a[i][j]=1+rand()%10;
         	 if(j==column-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         for(int i1=0;i1<a3;i1++)
         {
         	 a[i][j]=-1-rand()%10;
         	 if(j==column-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         for(int p=0;p<row;p++)
         {
         	for(int q=0;q<column;q++)
         	{
         		int temp=a[p][q];
         		int p1=rand()%row;
         		int p2=rand()%column;
         		a[p][q]=a[p1][p2];
         		a[p1][p2]=temp;
         	}
         }
	}
	
	//对角 
	if(arg[aa1][1]==2)
	{
        for(int i=0;i<a2;i++)
        a[i][i]=1+rand()%10; 
        for(int i=a2;i<a2+a3;i++)
        a[i][i]=-1-rand()%10;
        for(int i=0;i<row;i++)
        {
        	    int temp=a[i][i];
         		int p1=rand()%row;
         		a[i][i]=a[p1][p1];
         		a[p1][p1]=temp;
        }
	}
	
	//上三角 
	if(arg[aa1][1]==3||arg[aa1][1]==4)
	{        
        int i1=0;
        for(int i=0;i<row;i++)
        {
    	  for(int j=0;j<column;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   	   if(i1<a2)
    	   	   	   {
    	   	   	   	   a[i][j]=1+rand()%10;
    	   	   	   	   i1++;
    	   	   	   }
    	   	   	   else if(i1<a2+a3)
    	   	   	   {
    	   	   	   	    a[i][j]=-1-rand()%10;
    	   	   	   	    i1++;
    	   	   	   }
    	   	   }
    	   }
        }
        
        for(int i=0;i<row;i++)
        {
    	  for(int j=0;j<column;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   int temp=a[i][j];
    	   	   int q=rand()%row;
			   int p;
    	   	   if(q==0)
    	   	   p=0;
    	   	   else
    	   	   p=rand()%q;
    	   	   a[i][j]=a[p][q];
    	   	   a[p][q]=temp;
    	   	   }
    	   	  
    	   }
        }
	}	
	
	//下三角 
	if(arg[aa1][1]==4)
	{
		for(int i=0;i<row;i++)
        {
    	  for(int j=0;j<column;j++)
    	  {
    	  	if(i<j)
    	  	{
    	  	int temp=a[i][j];
    	  	a[i][j]=a[j][i];
    	  	a[j][i]=temp;
    	  	}
    	  }
        }
	}
	
	if(arg[aa1][3]==1)
	{
		int temprow=rand()%row;
		int tempk=2+rand()%9;
		for(int j=0;j<column;j++)
		a[temprow][j]=a[temprow][j]*tempk;
	}
   
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        examplefile<<row<<" "<<column<<"\n"; 
	    for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<column;j++)
    		{
              examplefile << a[i][j];
              if(j!=column-1)
              examplefile <<" ";
			}
			if(i!=row-1)
			examplefile<< "\n";
    	}
         examplefile.close();        //关闭文件 
    } 
    flag[aa1]=row;
    flag[aa2]=row;
    }
    if(flag[aa1]!=-1&&flag[aa2]==-1)
    {
    	flag[aa2]=flag[aa1];
    	    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        examplefile<<flag[aa2]<<" "<<flag[aa2]<<"\n"; 
	    for(int i=0;i<flag[aa2];i++)
    	{
    		for(int j=0;j<flag[aa2];j++)
    		{
              examplefile << resultb[aa1][j][i];
              if(j!=flag[aa2]-1)
              examplefile <<" ";
			}
			if(i!=flag[aa2]-1)
			examplefile<< "\n";
    	}
         examplefile.close();        //关闭文件 
    } 
    }
    if(flag[aa1]==-1&&flag[aa2]!=-1)
    {
    	flag[aa1]=flag[aa2];
    	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        examplefile<<flag[aa2]<<" "<<flag[aa2]<<"\n"; 
	    for(int i=0;i<flag[aa2];i++)
    	{
    		for(int j=0;j<flag[aa2];j++)
    		{
              examplefile << resultb[aa2][j][i];
              if(j!=flag[aa2]-1)
              examplefile <<" ";
			}
			if(i!=flag[aa2]-1)
			examplefile<< "\n";
    	}
         examplefile.close();        //关闭文件 
    } 
    }
} 

void MR1_testcase(int aa1,int aa2)
{
	if(flag[aa1]!=-1||flag[aa2]!=-1)
	return;
	
	int row,column;     
    switch (arg[aa1][0])
	{
		case 0: row=1+rand()%9;
	        	break;
		case 1: row=10+rand()%10;
				break;
		case 2: row=20+rand()%10;
				break;						 
	} 
	
/*	if(arg[4]==1&&row==1)
	row=2+rand()%8;*/
	
	column=row;
	
	int n=row*column;
    int a[500][500];
    for(int i=0;i<row;i++)
    {
    	for(int j=0;j<column;j++)
    	a[i][j]=0;
    }
       
    //初始化为全零矩阵 ,a1为0的个数，a2为正数个数，a3为负数个数。 
	int a1=n;
	int a2=0;
	int a3=0;
	
    switch (arg[aa1][1])
	{
			
		case 0:
			    switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)(n*((rand()%100)/100.0 ));
					        a1=n-a3;
					        break;
					case 1:
						    a2=n/2;
						    a3=(int)((n-a2)*((rand()%100)/100.0 ));
						    a1=n-a2-a3;
						    break;
					case 2: a2=n/3;
					        a3=(int)((n-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 3: a2=n/4;
					        a3=(int)((n-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 4:
						    a2=n;
						    a3=0;
						    a1=0;
						    break;							 
				} 
				break;
		case 1:
				break;			
		case 2:
                switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 1:
						    a2=column/2;
						    a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 2:
						    a2=column/3;
						    a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 3:
						    a2=column/4;
						    a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 4:
						    a2=column;
						    a3=0;
					        a1=0;
						    break;							 
				} 
				break;		
		case 3:
				switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 1:
						    a2=(1+row)*row/2/2;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 2:
						    a2=(1+row)*row/2/3;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 3:
						    a2=(1+row)*row/2/4;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 4:
						    a2=(1+row)*row/2;
						    a3=0;
					        a1=0;
						    break;							 
				} 
				break;	
		case 4:
				switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 1:
						    a2=(1+row)*row/2/2;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 2:
						    a2=(1+row)*row/2/3;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 3:
						    a2=(1+row)*row/2/4;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 4:
						    a2=(1+row)*row/2;
						    a3=0;
					        a1=0;
						    break;							 
				} 
				break;		
	} 
	
	//按顺序产生这些数，但随机位置。 	
	if(arg[aa1][1]==0)
	{   
         int i=0,j=0;
         for(int i1=0;i1<a2;i1++)
         {
         	 a[i][j]=1+rand()%10;
         	 if(j==column-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         for(int i1=0;i1<a3;i1++)
         {
         	 a[i][j]=-1-rand()%10;
         	 if(j==column-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         for(int p=0;p<row;p++)
         {
         	for(int q=0;q<column;q++)
         	{
         		int temp=a[p][q];
         		int p1=rand()%row;
         		int p2=rand()%column;
         		a[p][q]=a[p1][p2];
         		a[p1][p2]=temp;
         	}
         }
	}
	
	//对角 
	if(arg[aa1][1]==2)
	{
        for(int i=0;i<a2;i++)
        a[i][i]=1+rand()%10; 
        for(int i=a2;i<a2+a3;i++)
        a[i][i]=-1-rand()%10;
        for(int i=0;i<row;i++)
        {
        	    int temp=a[i][i];
         		int p1=rand()%row;
         		a[i][i]=a[p1][p1];
         		a[p1][p1]=temp;
        }
	}
	
	//上三角 
	if(arg[aa1][1]==3||arg[aa1][1]==4)
	{        
        int i1=0;
        for(int i=0;i<row;i++)
        {
    	  for(int j=0;j<column;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   	   if(i1<a2)
    	   	   	   {
    	   	   	   	   a[i][j]=1+rand()%10;
    	   	   	   	   i1++;
    	   	   	   }
    	   	   	   else if(i1<a2+a3)
    	   	   	   {
    	   	   	   	    a[i][j]=-1-rand()%10;
    	   	   	   	    i1++;
    	   	   	   }
    	   	   }
    	   }
        }
        
        for(int i=0;i<row;i++)
        {
    	  for(int j=0;j<column;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   int temp=a[i][j];
    	   	   int q=rand()%row;
			   int p;
    	   	   if(q==0)
    	   	   p=0;
    	   	   else
    	   	   p=rand()%q;
    	   	   a[i][j]=a[p][q];
    	   	   a[p][q]=temp;
    	   	   }
    	   	  
    	   }
        }
	}	
	
	//下三角 
	if(arg[aa1][1]==4)
	{
		for(int i=0;i<row;i++)
        {
    	  for(int j=0;j<column;j++)
    	  {
    	  	if(i<j)
    	  	{
    	  	int temp=a[i][j];
    	  	a[i][j]=a[j][i];
    	  	a[j][i]=temp;
    	  	}
    	  }
        }
	}
   
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        examplefile<<row<<" "<<column<<"\n"; 
	    for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<column;j++)
    		{
              examplefile << a[i][j];
              if(j!=column-1)
              examplefile <<" ";
			}
			if(i!=row-1)
			examplefile<< "\n";
    	}
         examplefile.close();        //关闭文件 
    } 
    flag[aa1]=row;
    for(int i=0;i<row;i++)
    {
    	for(int j=0;j<column;j++)
    	{
    		resultb[aa1][i][j]=a[i][j];
    	}
    }
    int temprow=rand()%row;
	int tempk=2+rand()%9;
	for(int j=0;j<column;j++)
	a[temprow][j]=a[temprow][j]*tempk;
    
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
        examplefile1<<row<<" "<<column<<"\n"; 
	    for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<column;j++)
    		{
              examplefile1 << a[i][j];
              if(j!=column-1)
              examplefile1<<" ";
			}
			if(i!=row-1)
			examplefile1<< "\n";
    	}
         examplefile1.close();        //关闭文件 
    } 
    flag[aa2]=row;
    for(int i=0;i<row;i++)
    {
    	for(int j=0;j<column;j++)
    	{
    		resultb[aa2][i][j]=a[i][j];
    	}
    }
} 

void judgeMR0()
{
	for(int i=0;i<bi-1;i++)
	{
		for(int j=i+1;j<bi;j++)
		{
			if(arg[i][0]==arg[j][0]&&arg[i][1]==3&&arg[j][1]==4&&arg[i][2]==arg[j][2]&&arg[j][3]==arg[i][3])
			{
				 MR0_testcase(i,j);
				 break;
			}
			else if(arg[i][0]==arg[j][0]&&arg[i][1]==4&&arg[j][1]==3&&arg[i][2]==arg[j][2]&&arg[j][3]==arg[i][3])
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
			if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==0&&arg[j][3]==1)
			{
				 MR1_testcase(i,j);
				 break;
			}
			else if(arg[i][0]==arg[j][0]&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[j][3]==0&&arg[i][3]==1)
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
    judgeMR1();  
	judgeMR0(); 
	 
    for(int aa1=0;aa1<bi;aa1++)
    {
	if(flag[aa1]==-1)
    {    	
	int row,column;     
    switch (arg[aa1][0])
	{
		case 0: row=1+rand()%9;
	        	break;
		case 1: row=10+rand()%10;
				break;
		case 2: row=20+rand()%10;
				break;						 
	} 
	
/*	if(arg[4]==1&&row==1)
	row=2+rand()%8;*/
	
	column=row;
	
	int n=row*column;
    int a[500][500];
    for(int i=0;i<row;i++)
    {
    	for(int j=0;j<column;j++)
    	a[i][j]=0;
    }
       
    //初始化为全零矩阵 ,a1为0的个数，a2为正数个数，a3为负数个数。 
	int a1=n;
	int a2=0;
	int a3=0;
	
    switch (arg[aa1][1])
	{
			
		case 0:
			    switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)(n*((rand()%100)/100.0 ));
					        a1=n-a3;
					        break;
					case 1:
						    a2=n/2;
						    a3=(int)((n-a2)*((rand()%100)/100.0 ));
						    a1=n-a2-a3;
						    break;
					case 2: a2=n/3;
					        a3=(int)((n-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 3: a2=n/4;
					        a3=(int)((n-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 4:
						    a2=n;
						    a3=0;
						    a1=0;
						    break;							 
				} 
				break;
		case 1:
				break;			
		case 2:
                switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 1:
						    a2=column/2;
						    a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 2:
						    a2=column/3;
						    a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 3:
						    a2=column/4;
						    a3=(int)((row-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 4:
						    a2=column;
						    a3=0;
					        a1=0;
						    break;							 
				} 
				break;		
		case 3:
				switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 1:
						    a2=(1+row)*row/2/2;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 2:
						    a2=(1+row)*row/2/3;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 3:
						    a2=(1+row)*row/2/4;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 4:
						    a2=(1+row)*row/2;
						    a3=0;
					        a1=0;
						    break;							 
				} 
				break;	
		case 4:
				switch (arg[aa1][2])
			    {
			    	case 0: a2=0;
					        a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
					        break;
					case 1:
						    a2=(1+row)*row/2/2;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 2:
						    a2=(1+row)*row/2/3;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 3:
						    a2=(1+row)*row/2/4;
						    a3=(int)(((1+row)*row/2-a2)*((rand()%100)/100.0 ));
					        a1=n-a2-a3;
						    break;
					case 4:
						    a2=(1+row)*row/2;
						    a3=0;
					        a1=0;
						    break;							 
				} 
				break;		
	} 
	
	//按顺序产生这些数，但随机位置。 	
	if(arg[aa1][1]==0)
	{   
         int i=0,j=0;
         for(int i1=0;i1<a2;i1++)
         {
         	 a[i][j]=1+rand()%10;
         	 if(j==column-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         for(int i1=0;i1<a3;i1++)
         {
         	 a[i][j]=-1-rand()%10;
         	 if(j==column-1)
         	 {
         	 	j=0;
         	 	i++;
         	 }
         	 else
         	 j++;
         }
         for(int p=0;p<row;p++)
         {
         	for(int q=0;q<column;q++)
         	{
         		int temp=a[p][q];
         		int p1=rand()%row;
         		int p2=rand()%column;
         		a[p][q]=a[p1][p2];
         		a[p1][p2]=temp;
         	}
         }
	}
	
	//对角 
	if(arg[aa1][1]==2)
	{
        for(int i=0;i<a2;i++)
        a[i][i]=1+rand()%10; 
        for(int i=a2;i<a2+a3;i++)
        a[i][i]=-1-rand()%10;
        for(int i=0;i<row;i++)
        {
        	    int temp=a[i][i];
         		int p1=rand()%row;
         		a[i][i]=a[p1][p1];
         		a[p1][p1]=temp;
        }
	}
	
	//上三角 
	if(arg[aa1][1]==3||arg[aa1][1]==4)
	{        
        int i1=0;
        for(int i=0;i<row;i++)
        {
    	  for(int j=0;j<column;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   	   if(i1<a2)
    	   	   	   {
    	   	   	   	   a[i][j]=1+rand()%10;
    	   	   	   	   i1++;
    	   	   	   }
    	   	   	   else if(i1<a2+a3)
    	   	   	   {
    	   	   	   	    a[i][j]=-1-rand()%10;
    	   	   	   	    i1++;
    	   	   	   }
    	   	   }
    	   }
        }
        
        for(int i=0;i<row;i++)
        {
    	  for(int j=0;j<column;j++)
    	   {
    	   	   if(i<=j)
    	   	   {
    	   	   int temp=a[i][j];
    	   	   int q=rand()%row;
			   int p;
    	   	   if(q==0)
    	   	   p=0;
    	   	   else
    	   	   p=rand()%q;
    	   	   a[i][j]=a[p][q];
    	   	   a[p][q]=temp;
    	   	   }
    	   	  
    	   }
        }
	}	
	
	//下三角 
	if(arg[aa1][1]==4)
	{
		for(int i=0;i<row;i++)
        {
    	  for(int j=0;j<column;j++)
    	  {
    	  	if(i<j)
    	  	{
    	  	int temp=a[i][j];
    	  	a[i][j]=a[j][i];
    	  	a[j][i]=temp;
    	  	}
    	  }
        }
	}
	
	if(arg[aa1][3]==1)
	{
		int temprow=rand()%row;
		int tempk=2+rand()%9;
		for(int j=0;j<column;j++)
		a[temprow][j]=a[temprow][j]*tempk;
	}
   
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        examplefile<<row<<" "<<column<<"\n"; 
	    for(int i=0;i<row;i++)
    	{
    		for(int j=0;j<column;j++)
    		{
              examplefile << a[i][j];
              if(j!=column-1)
              examplefile <<" ";
			}
			if(i!=row-1)
			examplefile<< "\n";
    	}
         examplefile.close();        //关闭文件 
    } 
    
    } 
}
}
	 
  
