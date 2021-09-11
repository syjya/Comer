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
void MR0_testcase(int aa1,int aa2)
{
	if(flag[aa1]==1||flag[aa2]==1)
	return;
	
	int l,ll;
	char f0='?'; 
	switch(arg[aa1][0])
	{
		case 0:l=10;
		       break;
		case 1:l=18;
		       break;
		case 2:l=30;
		       break;
	}
	
	switch(arg[aa1][3])
	{
		case 0:ll=1+rand()%10;
		       break;
		case 1:ll=11+rand()%10;
		       break;
		case 2:ll=21+rand()%10;
		       break;
	}
    
    //l1表示数字个数，l2表示特殊符号个数，l3表示字母个数 
    int l1,l2,l3;
    int tempf;
    switch(arg[aa1][1])
	{
		case 0:l1=0;
		       tempf=0;
		       break;
		case 1:l1=l/2;
				tempf=(l+1)/2;
		       break;
		case 2:l1=l/3;
			tempf=(l+1)/3;
		       break;
		case 3:l1=l/4;
			tempf=(l+1)/4;
		       break;
		case 4:l1=l;
			tempf=l+1;
		       break;
	}
	if(tempf>l1)
	{
		int tem=rand()%10;
		f0 ='0'+ tem;
	}
	
	switch(arg[aa1][2])
	{
		case 0:l2=0;
		       tempf=0;
		       break;
		case 1:l2=l/2;
		       tempf=(l+1)/2;
		       break;
		case 2:l2=l/3;
		       tempf=(l+1)/3;
		       break;
		case 3:l2=l/4;
		       tempf=(l+1)/4;
		       break;
		case 4:l2=l;
		       tempf=l+1;
		       break;
	} 
	if(tempf>l2)
	{
		int tem=rand()%6;
		f0= tem+'*';
	}
	
	if(f0=='?')
	{
		int tem=rand()%26;
		f0=tem+'a'; //a-z
	}
    l3=l-l1-l2;
    
    char a[100];
	
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<l1)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<l1+l3)
	{
		int tem=rand()%26;
		a[i++]=tem+'a'; //a-z
	}
	while(i<l)
	{
		int tem=rand()%6;
		a[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	
	for(int j=0;j<l;j++)
	{
		int tem=rand()%l;
		int temp=a[j];
		a[j]=a[tem];
		a[tem]=temp;
	}	
	
	int ll1,ll2,ll3;
    switch(arg[aa1][4])
	{
		case 0:ll1=0;
		       break;
		case 1:ll1=ll/2;
		       break;
		case 2:ll1=ll/3;
		       break;
		case 3:ll1=ll/4;
		       break;
		case 4:ll1=ll;
		       break;
	}
	
	switch(arg[aa1][5])
	{
		case 0:ll2=0;
		       break;
		case 1:ll2=ll/2;
		       break;
		case 2:ll2=ll/3;
		       break;
		case 3:ll2=ll/4;
		       break;
		case 4:ll2=ll;
		       break;
	} 
	
    ll3=ll-ll1-ll2;
    
    char b[100];
	
	i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<ll1)
	{
		int tem=rand()%10;
		b[i++]='0'+ tem;
	}
	while(i<ll1+ll3)
	{
		int tem=rand()%26;
		b[i++]=tem+'a'; //a-z 
	}
	while(i<ll)
	{
		int tem=rand()%6;
		b[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	
	for(int j=0;j<ll;j++)
	{
		int tem=rand()%ll;
		int temp=b[j];
		b[j]=b[tem];
		b[tem]=temp;
	}

	
	char c[500];
	int lll;
	if(arg[aa1][6]==0)
	{
		lll=l+ll-1;
		for(int j=0;j<lll;j++)
		{
		    if(j<l)
			c[j]=a[j];
			else
			c[j]=b[j-l];
	    }
        	
	} 
	else
	{
		lll=l+ll;
		for(int j=0;j<lll;j++)
		{
			if(j<l)
			c[j]=a[j];
			else
			c[j]=b[j-l];
		}
	}
	
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        for(int j=0;j<l;j++)
	{
		examplefile<<a[j];
	} 
	examplefile<<"\n";
		
	for(int j=0;j<ll;j++)
	{
		examplefile<<b[j];
	} 
	examplefile<<"\n";
	
	for(int j=0;j<lll;j++)
	{
		examplefile<<c[j];
	} 
         examplefile.close();        //关闭文件 
    } 
    
    sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile2(filename);
    if (examplefile2.is_open())
    {  
        for(int j=0;j<l;j++)
	{
		examplefile2<<a[j];
	} 
	examplefile2<<f0<<"\n";
		
	for(int j=0;j<ll;j++)
	{
		examplefile2<<b[j];
	} 
	examplefile2<<"\n";
	
	for(int j=0;j<lll;j++)
	{
		examplefile2<<c[j];
	} 
	examplefile2<<f0;
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
			int error=0;
			for(int com=0;com<7;com++)
			{
				if(com==0)
				{
					if(arg[i][com]-arg[j][com]==-1)
						error=0;
					else if(arg[i][com]-arg[j][com]==1)
					    error=-1;
					else
					{
						error=1;
						break;
					}
				}
				else if(arg[i][com]!=arg[j][com])
				{
					error=1;
					break;
				}
			}
				if(error==0)
				{
				   MR0_testcase(i,j);
				   break;
				}	
				if(error==-1)
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
		for(int i=0;i<7;i++)
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
    
    for(int aa1=0;aa1<bi;aa1++)
    {
    if(flag[aa1]==-1)
    {		
	int l,ll;
	switch(arg[aa1][0])
	{
		case 0:l=1+rand()%10;
		       break;
		case 1:l=11+rand()%8;
		       break;
		case 2:l=19+rand()%12;
		       break;
	}
	
	switch(arg[aa1][3])
	{
		case 0:ll=1+rand()%10;
		       break;
		case 1:ll=11+rand()%10;
		       break;
		case 2:ll=21+rand()%10;
		       break;
	}
    
    //l1表示数字个数，l2表示特殊符号个数，l3表示字母个数 
    int l1,l2,l3;
    switch(arg[aa1][1])
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
	
	switch(arg[aa1][2])
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
    
    char a[100];
	
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<l1)
	{
		int tem=rand()%10;
		a[i++]='0'+ tem;
	}
	while(i<l1+l3)
	{
		int tem=rand()%26;
		a[i++]=tem+'a'; //a-z
	}
	while(i<l)
	{
		int tem=rand()%6;
		a[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	
	for(int j=0;j<l;j++)
	{
		int tem=rand()%l;
		int temp=a[j];
		a[j]=a[tem];
		a[tem]=temp;
	}	
	
	int ll1,ll2,ll3;
    switch(arg[aa1][4])
	{
		case 0:ll1=0;
		       break;
		case 1:ll1=ll/2;
		       break;
		case 2:ll1=ll/3;
		       break;
		case 3:ll1=ll/4;
		       break;
		case 4:ll1=ll;
		       break;
	}
	
	switch(arg[aa1][5])
	{
		case 0:ll2=0;
		       break;
		case 1:ll2=ll/2;
		       break;
		case 2:ll2=ll/3;
		       break;
		case 3:ll2=ll/4;
		       break;
		case 4:ll2=ll;
		       break;
	} 
	
    ll3=ll-ll1-ll2;
    
    char b[100];
	
	i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<ll1)
	{
		int tem=rand()%10;
		b[i++]='0'+ tem;
	}
	while(i<ll1+ll3)
	{
		int tem=rand()%26;
		b[i++]=tem+'a'; //a-z 
	}
	while(i<ll)
	{
		int tem=rand()%6;
		b[i++]= tem+'*';//*,+,,,-,.,/ 六种符号 
	}
	
	for(int j=0;j<ll;j++)
	{
		int tem=rand()%ll;
		int temp=b[j];
		b[j]=b[tem];
		b[tem]=temp;
	}

	
	char c[500];
	int lll;
	if(arg[aa1][6]==0)
	{
		lll=l+ll-1;
		for(int j=0;j<lll;j++)
		{
		    if(j<l)
			c[j]=a[j];
			else
			c[j]=b[j-l];
	    }
        	
	} 
	else
	{
		lll=l+ll;
		for(int j=0;j<lll;j++)
		{
			if(j<l)
			c[j]=a[j];
			else
			c[j]=b[j-l];
		}
	}
	
	char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
        for(int j=0;j<l;j++)
	{
		examplefile<<a[j];
	} 
	examplefile<<"\n";
		
	for(int j=0;j<ll;j++)
	{
		examplefile<<b[j];
	} 
	examplefile<<"\n";
	
	for(int j=0;j<lll;j++)
	{
		examplefile<<c[j];
	} 
         examplefile.close();        //关闭文件 
    } 
    } 
    }
} 
