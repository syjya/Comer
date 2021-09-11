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
	switch(arg[aa1][0])
	{
		case 0:l=0;
		       break;
		case 1:l=4;
		       break;
		case 2:l=5+rand()%5;
		       break;
	}
	
	switch(arg[aa1][3])
	{
		case 0:ll=0;
		       break;
		case 1:ll=1+rand()%4;
		       break;
		case 2:ll=5+rand()%5;
		       break;
	}
    
    //l1表示数字个数，l2表示特殊符号个数，l3表示字母个数 
    int l1,l2,l3;
    int fl1,fl2;
    switch(arg[aa1][1])
	{
		case 0:l1=0;
		       fl1=0;
		       break;
		case 1:l1=l/2;
		       fl1=(l+1)/2;
		       break;
		case 2:l1=l/3;
		       fl1=(l+1)/3;
		       break;
		case 3:l1=l/4;
		       fl1=(l+1)/4;
		       break;
		case 4:l1=l;
		       fl1=l+1;
		       break;
	}
	
	switch(arg[aa1][2])
	{
		case 0:l2=0;
		       fl2=0;
		       break;
		case 1:l2=l/2;
		       fl2=(l+1)/2;
		       break;
		case 2:l2=l/3;
		       fl2=(l+1)/3;
		       break;
		case 3:l2=l/4;
		       fl2=(l+1)/4;
		       break;
		case 4:l2=l;
		       fl2=l+1;
		       break;
	} 
	
    l3=l-l1-l2;
    
    char a[100];
	char fa;
	if(fl1>l1)
	{
		int tem=rand()%5;
		fa = '5' + tem;
	}
	else if(fl2>l2)
	{
		int tem=rand()%6;
		fa = tem+'!';
	} 
	else
	{
		int tem=rand()%10;
		fa = tem+'k';
	}
	int i=0;
	//按顺序将字母、数字和符号放入a中，再乱序。
	while(i<l1)
	{
		int tem=rand()%5;
		a[i++]='0'+ tem;//0-4
	}
	while(i<l1+l3)
	{
		int tem=rand()%10;
		a[i++]=tem+'a'; //a-j
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
		int tem=rand()%5;
		b[i++]='0'+ tem;
	}
	while(i<ll1+ll3)
	{
		int tem=rand()%10;
		b[i++]=tem+'a'; //a-j 
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
         examplefile.close();        //关闭文件 
    } 
	
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile1(filename);
    if (examplefile1.is_open())
    {  
         	for(int j=0;j<l;j++)
	{
		examplefile1<<a[j];
	} 
	examplefile1<<fa;
	examplefile1<<"\n";
	
	for(int j=0;j<ll;j++)
	{
		examplefile1<<b[j];
	} 
         examplefile1.close();        //关闭文件 
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
			if(arg[i][0]==1&&arg[j][0]==2&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5])
			{
				   MR0_testcase(i,j);
				   break;
			}
			if(arg[j][0]==1&&arg[i][0]==2&&arg[i][1]==arg[j][1]&&arg[i][2]==arg[j][2]&&arg[i][3]==arg[j][3]&&arg[i][4]==arg[j][4]&&arg[i][5]==arg[j][5])
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
    
    for(int aa1=0;aa1<bi;aa1++)
    {
    if(flag[aa1]==-1)
    {
	int l,ll;
	switch(arg[aa1][0])
	{
		case 0:l=0;
		       break;
		case 1:l=1+rand()%4;
		       break;
		case 2:l=5+rand()%5;
		       break;
	}
	
	switch(arg[aa1][3])
	{
		case 0:ll=0;
		       break;
		case 1:ll=1+rand()%4;
		       break;
		case 2:ll=5+rand()%5;
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
		int tem=rand()%5;
		a[i++]='0'+ tem;//0-4 
	}
	while(i<l1+l3)
	{
		int tem=rand()%10;
		a[i++]=tem+'a'; //a-j 
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
		int tem=rand()%5;
		b[i++]='0'+ tem;
	}
	while(i<ll1+ll3)
	{
		int tem=rand()%10;
		b[i++]=tem+'a'; //a-j 
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
         examplefile.close();        //关闭文件 
    } 
    } 
	} 
} 
