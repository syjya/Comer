#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <dirent.h>
#include <stdlib.h>

using namespace std;
int b[2000][500];
int out[2000];
int bi;
int judge[500];   //judge- 
int judge1[500];  //judge. 

int result[2000][4];
int resulti=0;
int name[2000];

void judgemr0(int a1,int a2)
{
	if(b[a2][0]-b[a1][0]==1)
	{
		for(int i=1;i<b[a1][0];i++)
		{
			if(b[a1][i]!=b[a2][i])
			return;
		}
		if(b[a1][b[a1][0]]!=b[a2][b[a2][0]])
		return;
		result[resulti][0]=a1;
		result[resulti][1]=a2;
		result[resulti][2]=0;
		if(out[a1]<=out[a2]&&out[a1]!=-1&&out[a2]!=-1)
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
    	out[i]=-1;
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
        	stri++;
        	if(stri<3)
        	{
    	    int strl=str.length();
    	    int j=0;
    	    while(j<strl)
    	    {
    	    	while(1)
    	    	{
    	    		if(str[j]!=' '||j>=strl)
    	    		break;
    	    		else
    	    		j++;
    	    	}
    	    	string temp="";
    	    	while(1)
    	    	{
    	    		if(!(((str[j]>='0'&&str[j]<='9')||str[j]=='-')&&(j<strl)))
    	    		break;
    	    		else
    	    		{
    	    			temp+=str[j];
						j++;
    	    		}
    	    	}

				if(temp.length()>0&&temp!="")
				{
                    int input = atoi(temp.c_str());
                    b[i][bi++]=input;
                    b[i][0]=bi-1;
				}
				while(1)
    	    	{
    	    		if(str[j]!=' '||j>=strl)
    	    		break;
    	    		else
    	    		j++;
    	    	}
    	    }
    	   }
    	   else
    	   out[i]=atoi(str.c_str());
        } 
    }
    int count= files.size();

/*    for(int i=0;i<count;i++)
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
