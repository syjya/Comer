#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <stdlib.h>

using namespace std;
std::string b[2000][2000];
int rc[2000][2];

int bi[2000];
int result[500][4];
int resulti=0;
int name[2000];
int allj[2000];
int kong[2000];
int change(string a)
{
	int l=a.length();
	int temp=0;
	int cheng=1;
	for(int i=l-1;i>=0;i--)
	{
		temp+=(a[i]-'0')*cheng;
		cheng*=10;
	}
	return temp;
}

void judgemr0(int a1,int a2)
{
	if(rc[a1][0]+1==rc[a2][0]&&rc[a1][1]==rc[a2][1])
	{
		for(int i=3;i<rc[a1][0]*rc[a1][1]+3;i++)
		{
			if(b[a1][i]!=b[a2][i])
			return;
		}
		for(int i=rc[a1][0]*rc[a1][1]+3;i<rc[a1][0]*rc[a1][1]+3+rc[a1][1];i++)
		{
			if(b[a2][i]!="O")
			return;
		}
		result[resulti][0]=a1;
		result[resulti][1]=a2;
		result[resulti][2]=0;
		result[resulti][3]=0;
		if(kong[a1]!=1&&kong[a2]!=1)
		{
		int i=rc[a1][0]*rc[a1][1]+3;
		int j=rc[a2][0]*rc[a2][1]+3;
		int error=-1;
		while(i<2*rc[a1][0]*rc[a1][1]+3)
		{
			if(b[a1][i]!=b[a2][j])
			{
				error=1;
				break;
			}
			i++;
			j++;
		}
		for(int k=1;k<=rc[a2][1];k++)
		{
			if(b[a2][j++]!="O")
			{
				error=1;
				break;
			}
		}	
		if(error==-1)
		result[resulti][3]=1;
	    }
		resulti++;		
	}
}

void judgemr1(int a1,int a2)
{
	if(rc[a1][0]==rc[a2][0]&&rc[a1][1]+1==rc[a2][1])
	{
		int m=0;
		for(int i=3;i<rc[a2][0]*rc[a2][1]+3;i++)
		{
			if((i-2)%rc[a2][1]==0)
			{
				if(b[a2][i]!="O")
			    return;
			    m++;
			}
			else if(b[a1][i-m]!=b[a2][i])
			return;
		}
		result[resulti][0]=a1;
		result[resulti][1]=a2;
		result[resulti][2]=1;
		result[resulti][3]=0;
		if(kong[a1]!=1&&kong[a2]!=1)
		{
		int i=rc[a1][0]*rc[a1][1]+3;
		int j=rc[a2][0]*rc[a2][1]+3;
		int error=-1;
		while(i<2*rc[a1][0]*rc[a1][1]+3)
		{
			if((j-2)%rc[a2][1]==0)
			{
				if(b[a2][j]!="O")
			    error=1;
			    j++;
			}
			else if(b[a1][i]!=b[a2][j])
			{
				error=1;
				break;
			}
			else
			{
				i++;
				j++;
			}
		}
		if(error==-1)
		{
			result[resulti][3]=1;
		} 		
	   }			
		resulti++;		
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
    for(int i=0;i<2000;i++)
    {
    	kong[i]=-1;
    	for(int j=0;j<2000;j++)
    	b[i][j]="";
    }
    
    
    for (int i = 0; i < files.size(); ++i)
    {
    	string tem=PATH+"/"+files[i];
    	string strname = files[i].substr(0,files[i].length()-4);
    	name[i]=atoi(strname.c_str());
    	
        ifstream f_in(tem.c_str());  
        string str;
        int j=1;
        while (getline(f_in, str)){
        	istringstream is(str);
        	while(is>>b[i][j])
			{
				j++; 
			} 
        }
		allj[i]=j;   
    }
 /*   for (int i = 0; i < files.size(); ++i)
    { 
         for(int j=1;j<b[i][0];j++)
         cout<<b[i][j]<<" ";
		 cout<<endl; 
    }*/
    for(int i=0;i<files.size();i++)
    {
    	rc[i][0]=change(b[i][1]);
    	rc[i][1]=change(b[i][2]);
    //	std::cout<<rc[i][0]<<" "<<rc[i][1]<<endl;
        if(allj[i]==rc[i][0]*rc[i][1]+3)
        kong[i]=1;
    }
    
	for(int i=0;i<files.size()-1;i++)
	{
		for(int j=i+1;j<files.size();j++)
		{
             judgemr0(i,j);
             judgemr0(j,i);
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


