#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <dirent.h>
#include <stdlib.h>

using namespace std;
double b[2000][500];
int bi;
int judge[500];   //judge- 
int judge1[500];  //judge. 

int result[500][4];
int resulti=0;
int name[2000];
std::string out[2000];
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
	if(b[a1][1]==5&&b[a2][1]==3&&b[a2][2]==4&&b[a2][3]-0<0.001&&b[a2][3]-0>-0.001&&b[a1][0]+2==b[a2][0])
	{
		int i=2;
		for(;i<=b[a1][0];i++)
		{
			if(b[a1][i]!=b[a2][i+2])
			break;
		}
		if(i>b[a1][0])
		{
			result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=0;
			result[resulti][3]=0;
			if(out[a1].length()==out[a2].length())
			result[resulti][3]=1;
			resulti++;
		}
	}
	if(b[a2][1]==5&&b[a1][1]==3&&b[a1][2]==4&&b[a1][3]-0<0.001&&b[a1][3]-0>-0.001&&b[a2][0]+2==b[a1][0])
	{
		int i=2;
		for(;i<=b[a2][0];i++)
		{
			if(b[a2][i]!=b[a1][i+2])
			break;
		}
		if(i>b[a2][0])
		{
			result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=0;
			result[resulti][3]=0;
			if(out[a1].length()==out[a2].length())
			result[resulti][3]=1;
			resulti++;
		}
	}
}
void judgemr1(int a1,int a2)
{
	if(b[a1][1]==1&&b[a1][2]==2&&b[a2][1]==1&&b[a2][2]==1&&b[a2][3]==2&&b[a2][4]==1&&b[a2][5]-0.5<0.001&&b[a2][5]-0.5>-0.001&&b[a1][0]+3==b[a2][0])
	{
		int i=3;
		for(;i<=b[a1][0];i++)
		{
			if(b[a1][i]!=b[a2][i+3])
			break;
		}
		if(i>b[a1][0])
		{
			result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=1;
			result[resulti][3]=0;
			if(out[a1].length()==out[a2].length())
			result[resulti][3]=1;
			resulti++;
		}
	}
	if(b[a2][1]==1&&b[a2][2]==2&&b[a1][1]==1&&b[a1][2]==1&&b[a1][3]==2&&b[a1][4]==1&&b[a1][5]-0.5<0.001&&b[a1][5]-0.5>-0.001&&b[a2][0]+3==b[a1][0])
	{
		int i=3;
		for(;i<=b[a2][0];i++)
		{
			if(b[a2][i]!=b[a1][i+3])
			break;
		}
		if(i>b[a2][0])
		{
			result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=1;
			result[resulti][3]=0;
			if(out[a1].length()==out[a2].length())
			result[resulti][3]=1;
			resulti++;
		}
	}
}
int main(int argc, char * argv[])
{
    struct dirent *ptr;    
    DIR *dir;
    string PATH = argv[1];
    string PATH2 = argv[2];
    string out_txt = argv[3];
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
    	out[i]=""; 
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
        while (getline(f_in, str)){
        		spl(str,i);
    	    
        }   
		
		string tem2=PATH2+"/"+files[i];
		ifstream f_in2(tem2.c_str());
		while (getline(f_in2, str)){
    	    out[i]+=str;
        } 		
    }
 /*  for (int i = 0; i < files.size(); ++i)
    { 
         for(int j=1;j<=b[i][0];j++)
         cout<<b[i][j]<<" ";
		 cout<<endl; 
    }   */
	int count =  files.size();
	for(int i=0;i<files.size()-1;i++)
	{
		for(int j=i+1;j<files.size();j++)
		{
			judgemr0(i,j);
			judgemr1(i,j);
		}
	}
//	for(int i=0;i<resulti;i++)
//	{
//		std::cout<<name[result[i][0]]<<" "<<name[result[i][1]]<<" "<<result[i][2]<<" "<<result[i][3]<<std::endl;
//	}
	char filename[200];
	sprintf(filename,"%s",out_txt.c_str());
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

