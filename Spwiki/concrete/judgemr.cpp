#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <dirent.h>
#include <stdlib.h>

#define MAX 10000
#define MAX_VALUE 2147483647
using namespace std;
int b[1000][500];
int bi;
int judge[500];   //judge- 
int judge1[500];  //judge. 

int result[1000][4];
int resulti=0;

int point_edge_s0_s1_y[1000][5];
int edge[1000][500][500];
int name[1000];
int kong[1000];

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
	if(point_edge_s0_s1_y[a1][0]==point_edge_s0_s1_y[a2][0]&&point_edge_s0_s1_y[a1][1]==point_edge_s0_s1_y[a2][1])
	{
		 for(int j=0;j<point_edge_s0_s1_y[a1][0];j++)
         {
         	for(int j1=0;j1<point_edge_s0_s1_y[a1][0];j1++)
         	{
         		if(edge[a1][j][j1]!=edge[a2][j][j1])
         		return;
         	}
         }
         if(point_edge_s0_s1_y[a1][2]==point_edge_s0_s1_y[a2][3]&&point_edge_s0_s1_y[a1][3]==point_edge_s0_s1_y[a2][2])
         {
         	result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=0;
			if(point_edge_s0_s1_y[a1][4]==point_edge_s0_s1_y[a2][4]&&kong[a1]!=1&&kong[a2]!=1)
		 result[resulti][3]=1;
		 else
		 result[resulti][3]=0;
		 resulti++;
         }
		 
	}
}
bool change(int a1,int a2,int temp1,int temp2)
{
	bool ret=false;
	for(int i=0;i<point_edge_s0_s1_y[a1][0];i++)
    {
        for(int j=i+1;j<point_edge_s0_s1_y[a1][0];j++)
        {
        	if(i==temp1||i==temp2||j==temp1||j==temp2)
        	{
        		if(i==temp1&&j!=temp2)
        		{
        			if(edge[a1][i][j]!=edge[a2][temp2][j])
						return false;
        		}
				if(i==temp2&&j!=temp1)
        		{
        			if(edge[a1][i][j]!=edge[a2][temp1][j])
						return false;
        		}  
				if(j==temp1&&i!=temp2)
        		{
        			if(edge[a1][i][j]!=edge[a2][i][temp2])
						return false;
        		}  
				if(j==temp2&&i!=temp1)
        		{
        			if(edge[a1][i][j]!=edge[a2][i][temp1])
						return false;
        		}       		
        	}
            else 
            {
            	if(edge[a1][i][j]!=edge[a2][i][j])
						return false;            	
            }
        }
    }
    if(point_edge_s0_s1_y[a1][2]==temp1&&point_edge_s0_s1_y[a2][2]!=temp2)
	return false;
	if(point_edge_s0_s1_y[a1][2]==temp2&&point_edge_s0_s1_y[a2][2]!=temp1)
	return false; 
	if(point_edge_s0_s1_y[a1][3]==temp1&&point_edge_s0_s1_y[a2][3]!=temp2)
	return false;
	if(point_edge_s0_s1_y[a1][3]==temp2&&point_edge_s0_s1_y[a2][3]!=temp1)
	return false; 
    return true;
}
void judgemr1(int a1,int a2)
{
	if(point_edge_s0_s1_y[a1][0]==point_edge_s0_s1_y[a2][0]&&point_edge_s0_s1_y[a1][1]==point_edge_s0_s1_y[a2][1])
	{
		 for(int j=0;j<point_edge_s0_s1_y[a1][0];j++)
         {
         	for(int j1=0;j1<point_edge_s0_s1_y[a1][0];j1++)
         	{
         		if(edge[a1][j][j1]==edge[a2][j][j1]&&edge[a2][j][j1]==MAX)
         		continue;
         		if(edge[a1][j][j1]!=edge[a2][j][j1]*2)
         		return;
         	}
         }
         if(point_edge_s0_s1_y[a1][2]==point_edge_s0_s1_y[a2][2]&&point_edge_s0_s1_y[a1][3]==point_edge_s0_s1_y[a2][3])
         {
         	result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=1;
			if((point_edge_s0_s1_y[a1][4]==point_edge_s0_s1_y[a2][4]*2||(point_edge_s0_s1_y[a1][4]==2147483647&&point_edge_s0_s1_y[a2][4]==2147483647))&&kong[a1]!=1&&kong[a2]!=1)
		    result[resulti][3]=1;
		    else
		    result[resulti][3]=0;
		    resulti++;
         }
		 
	}
}
int main(int argc, char * argv[])
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
    for(int i=0;i<1000;i++)
    {
    	for(int j=0;j<500;j++)
    	b[i][j]=-1;
    }
    for(int i=0;i<1000;i++)
    {
    	kong[i]=-1;
    	for(int j=0;j<4;j++)
    	result[i][j]=-1;
    }
    for (int i = 0; i < files.size(); ++i)
    {
    	string tem=PATH+"/"+files[i];
    	string strname = files[i].substr(0,files[i].length()-4);
    	name[i]=atoi(strname.c_str());
    	
        ifstream f_in(tem.c_str());  
        string str;
        bi=1;
        std::string finalstr; 
        while (getline(f_in, str)){
    	    spl(str,i);
    	    finalstr=str;
        }   
        for(int finali=0;finali<finalstr.length();finali++)
        {
        	if(finalstr[finali]==' ')
        	{
        		kong[i]=1;
        		break;
        	}
        }
    }

	int count = files.size();
	for (int i = 0; i < count; ++i)
    { 
         point_edge_s0_s1_y[i][0]=b[i][1];
         point_edge_s0_s1_y[i][1]=b[i][2];
         point_edge_s0_s1_y[i][2]=b[i][b[i][0]-2];
         point_edge_s0_s1_y[i][3]=b[i][b[i][0]-1];
         point_edge_s0_s1_y[i][4]=b[i][b[i][0]];
         int m=3;
         for(int j=0;j<point_edge_s0_s1_y[i][0];j++)
         {
         	for(int j1=0;j1<point_edge_s0_s1_y[i][0];j1++)
         	{
         		edge[i][j][j1]=MAX;
         	}
         }
         for(int j=0;j<point_edge_s0_s1_y[i][1];j++)
         {
         	edge[i][b[i][m]][b[i][m+1]]=b[i][m+2];
         	edge[i][b[i][m+1]][b[i][m]]=b[i][m+2];
         	m=m+3;
         }
    } 

	for(int i=0;i<files.size()-1;i++)
	{
		for(int j=i+1;j<files.size();j++)
		{
			judgemr0(i,j);
            judgemr1(i,j);
            judgemr1(j,i);
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

