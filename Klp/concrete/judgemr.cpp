#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <dirent.h>
#include <stdlib.h>
using namespace std;
double b[1000][1000];
int c[1000][500][500];

int bi;
int judge[500];   //judge- 
int judge1[500];  //judge. 

int result[500][4];
int resulti=0;
int name[1000];
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
void setc(int len)
{	
	for(int i=0;i<len;i++)
	{   
	    int l=1;
		c[i][0][0]=b[i][l++];		
		c[i][0][1]=b[i][l++];
		for(int j=1;j<=b[i][1];j++)
		{
			for(int m=0;m<b[i][2];m++)
			c[i][j][m]=b[i][l++];
		}
	}
} 

void judgemr0(int a1,int a2)
{
	int error=0;
	if(c[a1][0][0]+1==c[a2][0][0]&&c[a1][0][1]==c[a2][0][1])
	{
		for(int i=1;i<=c[a1][0][0];i++)
		{
			for(int j=0;j<c[a1][0][1];j++)
			{
				if(c[a1][i][j]!=c[a2][i][j])
				{
				     error=1;
				     //cout<<1<<" "<<i<<" "<<j<<endl;
					 return;
				}
			}
		} 
		if(error==0)
		{
			for(int j=0;j<c[a1][0][1];j++)
			{
				if(c[a2][c[a2][0][0]][j]!=0)
				{
					error=1;
					//cout<<2<<" "<<j<<endl;
					return;
				}
			}
			if(error==0)
			{
				
				result[resulti][0]=a1;
			    result[resulti][1]=a2;
			    result[resulti][2]=0;
			    int errori=-1;
			    int yi=3+c[a1][0][0]*c[a1][0][1];
			    int yi2=3+c[a2][0][0]*c[a2][0][1];
                if(b[a1][0]-yi!=b[a2][0]-yi2||b[a1][0]-yi<0)
                errori=1;
                else
                {
                    for(;yi<=b[a1][0];yi++,yi2++)
			        {
				        if(b[a1][yi]!=b[a2][yi2])
				        {
					    errori=1;
					    break;
				        }
			        }
                }		  	    
			    if(errori==-1)
			    result[resulti][3]=1;
			    else
			    result[resulti][3]=0;
			    
			    resulti++;
			    
			}
		}
	}
} 

void judgemr1(int a1,int a2)
{
	int error=0;
	if(c[a1][0][0]==c[a2][0][0]&&c[a1][0][1]+1==c[a2][0][1])
	{
		for(int i=1;i<=c[a1][0][0];i++)
		{
			for(int j=0;j<c[a1][0][1];j++)
			{
				if(c[a1][i][j]!=c[a2][i][j])
				{
				     error=1;
					 return;
				}
			}
		} 
		if(error==0)
		{
			for(int i=1;i<=c[a2][0][0];i++)
			{
				if(c[a2][i][c[a1][0][1]]!=1)
				{
					error=1;
					return;
				}
			}
			if(error==0)
			{
				result[resulti][0]=a1;
			    result[resulti][1]=a2;
			    result[resulti][2]=1;
			    int errori=-1;
			    int yi=3+c[a1][0][0]*c[a1][0][1];
			    int yi2=3+c[a2][0][0]*c[a2][0][1];
                if(b[a1][0]-yi!=b[a2][0]-yi2||b[a1][0]-yi<0)
                errori=1;
                else
                {
                    for(;yi<=b[a1][0];yi++,yi2++)
			        {
				        if(b[a1][yi]!=b[a2][yi2])
				        {
					    errori=1;
					    break;
				        }
			        }
                }		  	    
			    if(errori==-1)
			    result[resulti][3]=1;
			    else
			    result[resulti][3]=0;
			    resulti++;
			}
		}
	}
} 
bool merge(int a1,int yi,int yj,int a2)
{
	for(int j=0;j<c[a1][0][1];j++)
	{
		if(c[a1][yi][j]==1||c[a1][yj][j]==1)
		{
			if(c[a2][c[a2][0][0]][j]!=1)
			return false;
		}
		else
		{
			if(c[a2][c[a2][0][0]][j]!=0)
			return false;
		}
	}
	return true;
}
int main(int argc, char *argv[])
{
    struct dirent *ptr;    
    DIR *dir;
    string PATH = argv[1];
    string out_txt=argv[2];
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
    	for(int j=0;j<1000;j++)
    	b[i][j]=-1;
    }
    for(int i=0;i<500;i++)
    {
    	for(int j=0;j<5;j++)
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
        while (getline(f_in, str)){
    	    spl(str,i);
        }   
    }
     
    int count= files.size();
    setc(count);   
   /* for(int i=0;i<count;i++)
    {
    	for(int j=1;j<=b[i][0];j++)
    	cout<<b[i][j]<<" ";
    	cout<<endl;
    }
   for(int i=0;i<count;i++)
    {
    	cout<<c[i][0][0]<<" "<<c[i][0][1]<<endl;
    	for(int j=1;j<=b[i][1];j++)
    	{
    		for(int m=0;m<b[i][2];m++)
			cout<<c[i][j][m]<<" ";
			cout<<endl;
    	}
    }*/ 
    resulti=0;
	for(int i=0;i<count-1;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			judgemr0(i,j);
			judgemr0(j,i);
			judgemr1(i,j);
			judgemr1(j,i);		
		}
	}
	
	/*for(int i=0;i<resulti;i++)
	{
		std::cout<<name[result[i][0]]<<" "<<name[result[i][1]]<<" "<<result[i][2]<<" "<<result[i][3]<<std::endl;
	}*/
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
