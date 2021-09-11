#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <stdlib.h>

using namespace std;
std::string b[2000][500];
int bi[2000];
int result[2000][4];
int resulti=0;
int name[2000];
void judgemr0(int a1,int a2)
{
	if(b[a1][1]==b[a2][1])
	{
		std::string temp=b[a1][0];
		int l=b[a2][0].length()-1;
		temp+=b[a2][0][l];
		std::string temp1=b[a1][2];
		int l1=b[a2][2].length()-1;
		temp1+=b[a2][2][l1];		
		if(temp!=b[a2][0]||temp1!=b[a2][2]||b[a2][0][l]!=b[a2][2][l1])
		return;
		result[resulti][0]=a1;
	    result[resulti][1]=a2;
	    result[resulti][2]=0;	
		if(b[a2][3]==b[a1][3]&&b[a1][3].length()>0&&b[a2][3].length()>0)
	    result[resulti][3]=1;	
		else
	    result[resulti][3]=0;
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
    	for(int j=0;j<500;j++)
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
    }
 /*   for (int i = 0; i < files.size(); ++i)
    { 
         for(int j=0;j<2;j++)
         cout<<b[i][j]<<" ";
		 cout<<bi[i]<<endl; 
    }*/
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


