#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <dirent.h>
#include <stdlib.h>

using namespace std;
int b[2000][500];
int bi;
int judge[500];   //judge- 
int judge1[500];  //judge. 
int kong[2000];
int result[500][4];
int resulti=0;
int name[2000];

void spl(string a,int count)  //将a划分为整数数组 
{
	for(int i=0;i<500;i++)
	{
		judge[i]=0;
		judge1[i]=-1;
	}
	int b0=0;
    string temp[500];
    for(int i=0;i<500;i++)
    temp[i]="";
    int tempi=0;
    int judge1i=0;
    for(int i=0;i<a.length();i++)
    {
        if((a[i]>='0'&&a[i]<='9')||a[i]=='-'||a[i]=='.')
    	{
    	 	temp[tempi]+=a[i];
    	 	if(a[i]=='-')
    	 	judge[tempi]=1;
    	 	if(a[i]=='.')
    	 	judge1[tempi]=judge1i;
    	 	judge1i++;
    	}
    	if(a[i]==' ')
    	{
    		tempi++;
    		judge1i=0;
    	}
    	if(i==a.length()-1&&a[i]!=' ')
    	    tempi++;
    }
    
    for(int i=0;i<tempi;i++)
    {    	 
         double tempint=0;
         int cheng=1;
         double cheng1=0.1;
         if(judge[i]==0&&judge1[i]==-1)
		 {
		 	for(int j=temp[i].length()-1;j>=0;j--)
    	    {
    	 	 tempint+=(temp[i][j]-'0')*cheng;
    	 	 cheng=cheng*10;
    	    }
    	    b[count][bi++]=tempint;
		 } 
    	 if(judge[i]==1&&judge1[i]==-1)
    	 {
    	 	for(int j=temp[i].length()-1;j>=1;j--)
    	    {
    	 	 tempint+=(temp[i][j]-'0')*cheng;
    	 	 cheng=cheng*10;
    	    }
    	    b[count][bi++]=-tempint;
    	 }
    	 if(judge[i]==0&&judge1[i]!=-1)
    	 {
    	 	for(int j=judge1[i]-1;j>=0;j--)
    	    {
    	 	 tempint+=(temp[i][j]-'0')*cheng;
    	 	 cheng=cheng*10;
    	    }
    	    for(int j=judge1[i]+1;j<temp[i].length();j++)
    	    {
    	 	   tempint+=(temp[i][j]-'0')*cheng1;
    	 	   cheng1=cheng1*0.1;
    	    }
    	    b[count][bi++]=tempint;
    	 }
    	 if(judge[i]==1&&judge1[i]!=-1)
    	 {
    	 	for(int j=judge1[i]-1;j>=1;j--)
    	    {
    	 	 tempint+=(temp[i][j]-'0')*cheng;
    	 	 cheng=cheng*10;
    	    }
    	    for(int j=judge1[i]+1;j<temp[i].length();j++)
    	    {
    	 	   tempint+=(temp[i][j]-'0')*cheng1;
    	 	   cheng1=cheng1*0.1;
    	    }
    	    b[count][bi++]=-tempint;
    	 }
    }
    b0=bi-1;
    b[count][0]=b0;
}
void judgemr0(int a1,int a2)
{
	if(b[a2][0]-b[a1][0]==1)
	{
		int tag=-1;
		for(int i=1;i<b[a1][0];i++)
		{
			if(b[a1][i]!=b[a2][i])
			return;
			if(b[a1][i]==b[a2][b[a1][0]])
			tag=i;
		}
		if(tag>-1)
		{
			result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=0;
			if(b[a1][b[a1][0]]==b[a2][b[a2][0]]&&kong[a1]!=1&&kong[a2]!=1)
			result[resulti][3]=1;
			else
			result[resulti][3]=0;
			resulti++;
		}
	}
}

void judgemr1(int a1,int a2)
{
	if(b[a2][0]-b[a1][0]==0)
	{
		int temp1[500];
		int temp2[500];
		for(int i=1;i<b[a1][0];i++)
	    {
	    	temp1[i]=b[a1][i];
	    	temp2[i]=b[a2][i];
	    }
	    for(int i=1;i<b[a1][0]-1;i++)
	    {
	    	for(int j=i+1;j<b[a1][0];j++)
	    	{
	    		if(temp1[j]<temp1[i])
	    		{
	    			int temp=temp1[j];
	    			temp1[j]=temp1[i];
	    			temp1[i]=temp;
	    		}
	    		if(temp2[j]<temp2[i])
	    		{
	    			int temp=temp2[j];
	    			temp2[j]=temp2[i];
	    			temp2[i]=temp;
	    		}
	    	}
	    }
	    for(int i=1;i<b[a1][0];i++)
	    {
	    	if(temp1[i]!=temp2[i])
	    	return;
	    }
	    result[resulti][0]=a1;
		result[resulti][1]=a2;
		result[resulti][2]=1;
		if(b[a1][b[a1][0]]==b[a2][b[a2][0]]&&kong[a1]!=1&&kong[a2]!=1)
		result[resulti][3]=1;
		else
		result[resulti][3]=0;
		resulti++;
	}
}

int main(int argc, char *argv[])
{
    struct dirent *ptr;    
    DIR *dir;
    string PATH = argv[1];
    string output=argv[2];
    dir=opendir(PATH.c_str());
    vector<string> files;
    while((ptr=readdir(dir))!=NULL)
    {
 
        //跳过'.'和'..'两个目录
        if(ptr->d_name[0] == '.')
            continue;
        //cout << ptr->d_name << endl;
        files.push_back(ptr->d_name);
    }
    for(int i=0;i<2000;i++)
    {
    	kong[i]=-1;
    	for(int j=0;j<500;j++)
    	b[i][j]=-1;
    }
    for (int i = 0; i < files.size(); ++i)
    {
    	string tem=PATH+"/"+files[i];
    	string strname = files[i].substr(0,files[i].length()-4);
    	name[i]=atoi(strname.c_str());
    	
        ifstream f_in(tem.c_str());  
        string str;
        bi=1;
        int stri=0; 
        while (getline(f_in, str)){
    	    spl(str,i);
    	    stri++;
        }   
        if(stri<2)
        kong[i]=1;
    }
    int count= files.size();
/*    cout<<endl;
    for(int i=0;i<count;i++)
    {
    	for(int j=1;j<=b[i][0];j++)
    	cout<<b[i][j]<<" ";
    	cout<<endl;
    }*/
	for(int i=0;i<count-1;i++)
	{
		for(int j=i+1;j<count;j++)
		{
	         judgemr0(i,j); 
	         judgemr0(j,i); 
	         judgemr1(i,j); 
		}
	}
/*	for(int i=0;i<resulti;i++)
	{
		std::cout<<name[result[i][0]]<<" "<<name[result[i][1]]<<" "<<result[i][2]<<" "<<result[i][3]<<std::endl;
	}*/
	char filename[200];
	sprintf(filename,"%s",output.c_str());
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<resulti;i++)
	{
		examplefile<<name[result[i][0]]<<" "<<name[result[i][1]]<<" "<<result[i][2]<<" "<<result[i][3];
		if(i!=resulti-1)
		examplefile<<"\n";
	}
         examplefile.close();        //关闭文件 
    }
      closedir(dir);
      return 0; 
} 
