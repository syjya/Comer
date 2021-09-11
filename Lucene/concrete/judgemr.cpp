#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <stdlib.h>
using namespace std;
std::string b[2000][2000];
int bi[2000];
int result[500][4];
int resulti=0;
int name[2000];
string allstr[2000];
int allstri=0;

string out[2000];
int kong[2000];
void judgemr0(int a1,int a2)
{
	if(bi[a2]==bi[a1]&&bi[a1]==3)
	{
		if(b[a1][1]=="OR"&&b[a2][1]=="OR")
		{
			if(b[a1][0]==b[a2][2]&&b[a1][2]==b[a2][0])
			{
				result[resulti][0]=a1;
			    result[resulti][1]=a2;
			    result[resulti][2]=0;			    
			    if(out[a1]==out[a2]&&kong[a1]!=1&&kong[a2]!=1)
			    result[resulti][3]=1;
			    else
			    result[resulti][3]=0;
			    resulti++;
			}
		}
	}
}
bool isin(string a1)
{ 
    int l1=a1.length();
    for(int i=0;i<allstri;i++)
    {
    	int l2=allstr[i].length();
    	for(int ii=0;ii<l2;ii++)
		{
			int j1=0;
			int j2=ii;
			while(j1<l1&&j2<l2)
			{
				if(a1[j1]!=allstr[i][j2])
				break;
				else{
					j1++;
					j2++;
				} 
			}
		    if(j1>=l1)
		    return true;
	    }
    }
	return false;
}

void judgemr1(int a1,int a2)
{
	if(bi[a2]==bi[a1]+2&&bi[a2]==3)
	{
		if(b[a2][1]=="OR")
		{
			if(b[a1][0]==b[a2][0])
			{
				if(!isin(b[a2][2])) 
				{
					result[resulti][0]=a1;
			        result[resulti][1]=a2;
			        result[resulti][2]=1;
			        
			        if(out[a1]==out[a2]&&kong[a1]!=1&&kong[a2]!=1)
			        result[resulti][3]=1;
			        else
			        result[resulti][3]=0;
			        resulti++;
				}				
			}
		}
	}
}

void judgemr2(int a1,int a2)
{
	if(bi[a2]==bi[a1]+2&&bi[a2]==3)
	{
		if(b[a2][1]=="NOT")
		{
			if(b[a1][0]==b[a2][0])
			{
				if(!isin(b[a2][2])) 
				{
					result[resulti][0]=a1;
			        result[resulti][1]=a2;
			        result[resulti][2]=2;
			        
			        if(out[a1]==out[a2]&&kong[a1]!=1&&kong[a2]!=1)
			        result[resulti][3]=1;
			        else
			        result[resulti][3]=0;
			        resulti++;
				}				
			}
		}
	}
}

void readtxt(string PATH)
{
	struct dirent *ptr;    
    DIR *dir;
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
    
    for (int i = 0; i < files.size(); ++i)
    {
    	string tem=PATH+"/"+files[i];
    	
        ifstream f_in(tem.c_str());  
        string str;
        while (getline(f_in, str)){
        	if(str.length()>0)
            allstr[allstri++]=str;
        }   
    }
    closedir(dir);
}
int main(int argc, char * argv[])
{
	if(argc<4)
	return 0;
	
	string temppath=argv[1];
	readtxt(temppath);
    struct dirent *ptr;    
    DIR *dir;
    string PATH =argv[2];
    string out_txt = argv[4]; 
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
        int j=0;
        while (getline(f_in, str)){
        	istringstream is(str);
        	while(is>>b[i][j])
			{
				j++; 
			} 
        }   
        bi[i]=j;
        string arg3=argv[3];
        string tem1=arg3+"/"+files[i];
        ifstream f_in1(tem1.c_str());  
        if(!f_in1.is_open())
        kong[i]=1;
        out[i]="";
        while (getline(f_in1, str)){
        	out[i]+=str;
        }   
    }
 /*   for (int i = 0; i < files.size(); ++i)
    { 
         for(int j=0;j<bi[i];j++)
         cout<<b[i][j]<<" ";
		 cout<<endl; 
    }  */


	for(int i=0;i<files.size()-1;i++)
	{
		for(int j=i+1;j<files.size();j++)
		{
             judgemr0(i,j);
             judgemr1(i,j);
             judgemr1(j,i);
             judgemr2(i,j);
             judgemr2(j,i);
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


