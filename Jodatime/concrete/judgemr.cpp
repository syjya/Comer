#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <dirent.h>
using namespace std;
int b[3000][100];
int bi;
int judge[500];   //judge- 
int judge1[500];  //judge. 

int result[500][4];
int resulti=0;
int name[3000];

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
    for(int i=0;i<3000;i++)
    {
    	for(int j=0;j<100;j++)
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
    }
/*    for(int i=0;i<count;i++)
	{
		for(int j=1;j<=b[i][0];j++)
		std::cout<<b[i][j]<<" ";
		std::cout<<std::endl;
	} */
	int count= files.size(); 
	for(int i=0;i<count-1;i++)
	{
		for(int j=i+1;j<count;j++)
		{   
		    int timei=1;
			for(;timei<=7;timei++) 
			{
				if(b[i][timei]!=b[j][timei])
				break;
			}
			if(timei<=7)
			continue;				
			int iday=b[i][8]*7+b[i][9];
			int jday=b[j][8]*7+b[j][9];
			int isecond=0; 
			int jsecond=0; 
			if(b[i][10]>60*60*24)
			{
				iday+=b[i][10]/(60*60*24);
				isecond=b[i][10]%(60*60*24);
			}
			else
			isecond=b[i][10];
			if(b[j][10]>60*60*24)
			{
				jday+=b[j][10]/(60*60*24);
				jsecond=b[j][10]%(60*60*24);
			}
			else
			jsecond=b[j][10];			
			if(iday==jday&&isecond==jsecond)
			{
				result[resulti][0]=i;
				result[resulti][1]=j;
				result[resulti][2]=0;
				int error=-1;
				if(b[i][0]<17||b[j][0]<17)
				error=1; 
				else{
					for(int tempi=11;tempi<=17;tempi++)
				    {
					if(b[i][tempi]!=b[j][tempi])
					{
						error=1;
						break;
					}
				    } 
				}
				
				if(error==-1)
				result[resulti][3]=1;
				else
				result[resulti][3]=0;
				resulti++;
			}
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
