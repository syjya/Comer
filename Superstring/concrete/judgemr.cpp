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
int kong[2000];
void judgemr0(int a1,int a2)
{
	if(bi[a2]-bi[a1]==1)
	{
		for(int i=0;i<bi[a1]-1;i++)
		{
			if(b[a1][i]!=b[a2][i])
			return;
		}
		int tag=0;
		for(int i=0;i<bi[a1]-1;i++)
		{
			if(b[a2][bi[a2]-2]==b[a1][i])
			{
				tag=1;
				break;
			}
		}
		if(tag==1)
		{
			result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=0;
			if(b[a2][bi[a2]-1].length()==b[a1][bi[a1]-1].length()&&kong[a1]!=1&&kong[a2]!=1)
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
    string out_txt = argv[2];
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
        int stri=0;
        while (getline(f_in, str)){
        	istringstream is(str);
        	while(is>>b[i][j])
			{
				j++; 
			} 
			stri++;
        }   
        bi[i]=j;
        if(stri==1)
        kong[i]=1;
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
             judgemr0(j,i);
		}
	}
/*	for(int i=0;i<resulti;i++)
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
		examplefile<<name[result[i][0]]<<" "<<name[result[i][1]]<<" "<<result[i][2]<<" "<<result[i][3]<<"\n";
	}
         examplefile.close();        //关闭文件 
    }
      closedir(dir);
    return 0;
}


