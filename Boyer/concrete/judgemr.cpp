#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <dirent.h>
#include <stdlib.h>

using namespace std;
string b[1000];
string x[1000];
string y[1000];
string tempf[1000];
int f[1000];

int result[1000][5];
int resulti=0;

int name[1000];
int kong[1000];
void calculatey(string a,int count)
{
	if(a[0]=='-'||a=="")
	f[count]=-1;
	else
	{
		int temp=0;
		int cheng=1;
		for(int i=a.length()-1;i>=0;i--)
		{
			temp+=(a[i]-'0')*cheng;
			cheng*=10;
		}
		f[count]=temp;
	} 
}
void judgemr0(int a1,int a2)
{
	if(x[a2].length()==x[a1].length()+1&&y[a2].length()==y[a1].length()&&f[a1]!=-1)
	{
		for(int i=0;i<x[a1].length();i++)
		{
			if(x[a1][i]!=x[a2][i])
			return;
		}
		for(int i=0;i<y[a1].length();i++)
		{
			if(y[a1][i]!=y[a2][i])
			return;
		}
		result[resulti][0]=a1;
		result[resulti][1]=a2;
		result[resulti][2]=0;
		if(f[a1]==f[a2]&&kong[a1]!=1&&kong[a2]!=1)
		result[resulti][3]=1;
		else
		result[resulti][3]=0;
		resulti++;
	}
}

void judgemr1(int a1,int a2)
{
	if(x[a2].length()==x[a1].length()&&y[a2].length()==y[a1].length()-1&&f[a1]!=-1)
	{
		for(int i=0;i<x[a1].length();i++)
		{
			if(x[a1][i]!=x[a2][i])
			return;
		}
		for(int i=0;i<y[a2].length();i++)
		{
			if(y[a1][i]!=y[a2][i])
			return;
		}
		result[resulti][0]=a1;
		result[resulti][1]=a2;
		result[resulti][2]=1;
		if(f[a1]>=f[a2]&&kong[a1]!=1&&kong[a2]!=1)
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
    	b[i]="";
    	kong[i]=-1;
    	tempf[i]="";
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
        int stri=0; 
        while (getline(f_in, str)){
        	if(stri==0)
        	{
        		b[i]+=str;
    	    b[i]+=" ";
    	    stri++;
        	}
        	else
        	{ 
        	tempf[i]=str;
        	stri++; 
        	}     	    
        }   
        if(stri==1)
        kong[i]=1;
    }
    
    for(int i=0; i < files.size(); ++i)
    {
    	x[i]="";
    	y[i]="";
    	f[i]=-1;
    }
    for(int i=0; i < files.size(); ++i)
    {
    	int j=0;
    	while(j<b[i].length())
    	{
    		if(b[i][j]==' ')
    		break;
    		x[i]+=b[i][j];
    		j++;
    	}
    	j++;
    	while(j<b[i].length())
    	{
    		if(b[i][j]==' ')
    		break;
    		y[i]+=b[i][j];
    		j++;
    	}
    	j++;
    
    	calculatey(tempf[i],i);
    }
 /*  for (int i = 0; i < files.size(); ++i)
    { 
         cout<<b[i];
		 cout<<endl;
		 cout<<x[i]<<" "<<y[i]<<" "<<f[i]<<endl; 
    }  */
    
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
	
/*    for(int i=0;i<resulti;i++)
	{
		if(result[i][4]==-1)
		std::cout<<name[result[i][0]]<<" "<<name[result[i][1]]<<" "<<result[i][2]<<" "<<result[i][3]<<std::endl;
	    else 
	    std::cout<<name[result[i][0]]<<" "<<name[result[i][1]]<<" "<<name[result[i][2]]<<" "<<result[i][3]<<" "<<result[i][4]<<std::endl;
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

