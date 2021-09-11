#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <dirent.h>
#include <stdlib.h>

using namespace std;
double b[2000][2000];
double c[800][500][500];
double y[500]; 

int bi;
int judge[500];   //judge- 
int judge1[500];  //judge. 

int result[500][5];
int resulti=0;
int name[1000];
string output[1000];
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
			{
				c[i][j][m]=b[i][l++];
			}
		}
		if(output[i]!="NaN")
		{
			istringstream iss(output[i]);  
			iss >>y[i];
		}
		
	}
}

void judgemr0(int a1,int a2)
{
	int error=0;
	if(c[a1][0][0]==c[a2][0][0]&&c[a1][0][1]==c[a2][0][1]&&c[a1][0][0]==c[a1][0][1])
	{
		
		for(int i=1;i<=c[a1][0][0];i++)
		{
			for(int j=0;j<c[a1][0][1];j++)
			{
				if(c[a1][i][j]!=c[a2][j+1][i-1])
				{
					error=1;
					break;
				}
			}
			if(error==1)
			break;
		}
		if(error==0)
		{
			result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=0;
			result[resulti][4]=0;
			
			if(y[a2]-y[a1]<0.3&&y[a2]-y[a1]>-0.3&&output[a1]!="NaN"&&output[a2]!="NaN")
			result[resulti][4]=1;
			if(output[a1]=="NaN"&&output[a2]=="NaN") 
			result[resulti][4]=1;
			resulti++;
		}
	}
}

void judgemr1(int a1,int a2)
{
	int error=0;
	int tag=-1; 
	double allk=0;
	if(c[a1][0][0]==c[a2][0][0]&&c[a1][0][1]==c[a2][0][1])
	{		
		for(int i=1;i<=c[a1][0][0];i++)
		{
			for(int j=0;j<c[a1][0][1];j++)
			{				
				if(c[a1][i][j]!=c[a2][i][j])
				{				    
					if(tag==-1)
					{
						if(c[a2][i][j]!=0)
						{
							double k=c[a1][i][j]/c[a2][i][j];
                        if(k!=0)
                        {
                        	allk=k;
						//	cout<<c[a1][i][j]<<" "<<c[a2][i][j]<<" "<<allk<<endl; 
						for(int m=1;m<c[a1][0][1];m++)
						{
							if(c[a1][i][m]/c[a2][i][m]!=k&&c[a2][i][m]!=0)
							{								
								error=1;
								break;
							}
							else if(c[a2][i][m]==0&&c[a1][i][m]!=0)
							{   
							//cout<<c[a1][i][m]<<" "<<c[a2][i][m]<<endl;
								error=1;
								break;
							}
						}
						if(error==0)
						{
						 tag=i;	
						}
						
                        }
						}								
					}
					else
					{
						//cout<<i<<" "<<j<<" "<<c[a1][i][j]<<" "<<c[a2][i][j]<<endl;
						error=1;
					    break;
					}
										
				}
				if(error==1)
			    break;
			    if(tag==i)
			    break;
				
			}
			if(error==1)
			break;
		}
		if(error==0&&tag!=-1)
		{
			
			result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=1;
			result[resulti][4]=0;
			if(y[a2]*allk-y[a1]<0.3&&y[a2]*allk-y[a1]>-0.3&&output[a1]!="NaN"&&output[a2]!="NaN")
			result[resulti][4]=1;
			if(output[a1]=="NaN"&&output[a2]=="NaN")
			result[resulti][4]=1;			
			//cout<<y[a2]<<" "<<y[a1]<<" "<<y[a2]*allk-y[a1]<<" "<<result[resulti][4]<<endl;
			resulti++;
		}
	}
}
int main(int argc, char *argv[])
{
	if(argc<2)
	return 1; 
    struct dirent *ptr;    
    DIR *dir;
    //string PATH = "./input";
    string PATH = argv[1];
    string output_txt=argv[2]; 
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
    	for(int j=0;j<2000;j++)
    	b[i][j]=-1;
    }
    for(int i=0;i<500;i++)
    {
    	for(int j=0;j<4;j++)
    	result[i][j]=-1;
    }
    for (int i = 0; i < files.size(); ++i)
    {
    	output[i]="";
    	string tem=PATH+"/"+files[i];
    	string strname = files[i].substr(0,files[i].length()-4);
    	name[i]=atoi(strname.c_str());
    	string str;
        bi=1;
       /* ifstream f_in(tem.c_str());  
        string str;
        bi=1;
        while (getline(f_in, str)){
    	    spl(str,i);
        }   */
         std::ifstream infile;    
         infile.open(tem.c_str());
         while(1)
    	 {
    	 	if(bi>2&&b[i][1]*b[i][2]+3==bi)
			 {
			 	infile>>output[i];
			 	break;
			 } 
        	infile>>b[i][bi];
        	bi++;
        	b[i][0]=bi-1;
        	if(infile.eof())
        	break;
    	 }
    }
     
    int count= files.size();
    setc(count);   
  /*  for(int i=0;i<count;i++)
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
    	cout<<y[i]<<endl;
    }*/
	for(int i=0;i<count-1;i++)
	{
		for(int j=i+1;j<count;j++)
		{
            judgemr0(i,j);
			judgemr1(i,j);		
		}
	}
/*	for(int i=0;i<resulti;i++)
	{
		std::cout<<name[result[i][0]]<<" "<<name[result[i][1]]<<" "<<result[i][2];
	    if(result[i][3]!=-1)
		std::cout<<" "<<result[i][3];
		std::cout<<" "<<result[i][4];
		std::cout<<std::endl;
	}*/
	char filename[200];
	sprintf(filename,"%s",output_txt.c_str());
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<resulti;i++)
	{
		examplefile<<name[result[i][0]]<<" "<<name[result[i][1]]<<" "<<result[i][2];
		if(result[i][3]!=-1)
		examplefile<<" "<<result[i][3];
		examplefile<<" "<<result[i][4];
		examplefile<<"\n";
	}
         examplefile.close();        //关闭文件 
    }
    closedir(dir);
    return 0;
} 
