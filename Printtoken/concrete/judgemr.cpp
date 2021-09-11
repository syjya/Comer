#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <dirent.h>
#include <stdlib.h>

using namespace std;
std::string b[35000][100];
std::string b_out[35000][100];
int bi[35000];
int bj[35000];
int result[500000][4];
int resulti=0;
int name[35000];

void judgemr0(int a1,int a2)
{

	  if(bi[a1]!=bi[a2])
	  {	  	
		  return;
	  }
	  
      int i=0; 
	  int tag=0;
	  int error=0;
	  while(i<bi[a1])
	  {	  	 
	  	  int l1=b[a1][i].length();
	  	  int l2=b[a2][i].length();
	  	  if(l1!=l2)
			return;
		  for(int j=0;j<l1;j++)
		  {
		  	 if(b[a2][i][j]==b[a1][i][j]+'A'-'a'&&b[a1][i][j]>='a'&&b[a1][i][j]<='z')
		  	 tag=1;
		  	 else if(b[a2][i][j]!=b[a1][i][j]||(b[a2][i][j]>='a'&&b[a2][i][j]<='z'))
		  	 {
		  	 	error=1;
				break;
		  	 }		  	 
		  } 
		  if(error==1)
		  break;
		  i++;
	  }	  	  
	  if(i>=bi[a1]&&error==0&&tag==1)
	  {
	  	  
	  	 	result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=0;
			int reerror=0;
			for(int rei=0;rei<bj[a2];rei++)
			{
				if(b_out[a2][rei][0]=='k'&&b_out[a2][rei][1]=='e'&&b_out[a2][rei][2]=='y')
				{
					if(b_out[a2][rei][10]!='='&&b_out[a2][rei][11]!='>') 
					{
						reerror=1;
						break;	
					}					
				}
			}
			if(reerror==1)
			result[resulti][3]=0;
			else
			result[resulti][3]=1;
			resulti++;
	  }			
}
void judgemr1(int a1,int a2)
{
      int i=0; 
      int j=0;
	  int tag=0;
	  int error=0;
	  while(i<bi[a1]&&j<bi[a2])
	  {	  	 
	  	  int l1=b[a1][i].length();
	  	  int l2=b[a2][j].length();
	  	  if(b[a1][i][0]==';'&&l1>0)
		  {
		  	 i++;
		  	 tag=1;
		  }
		  else if(l1!=l2)
		  {
		  	error=1;
		  	//std::cout<<b[a1][i]<<"     "<<b[a2][j]<<endl;
		  	break;
		  }
          else if(l1==l2)
          {
          	if(b[a1][i]!=b[a2][j])
          	{
          		error=1;
          	//	std::cout<<b[a1][i]<<"     "<<b[a2][j]<<endl;
          		break;
          	}
          	else
          	{
          		i++;
          		j++;
          	}
          }
          if(j==bi[a2])
          {
          	while(i<bi[a1])
          	{
          	   l1=b[a1][i].length();
          	   if(b[a1][i][0]==';'&&l1>0)
			   {
				  i++;
				  tag=1;
			   }
			   else
			   {
			   	  error=1;
			   	  break;
			   }	
          	}
          }
	  }	  	  
	  //cout<<i<<" "<<j<<endl;
	  if(i>=bi[a1]&&j>=bi[a2]&&error==0&&tag==1)
	  {
	  	 	result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=1;
			int reerror=0;
			if(bj[a1]!=bj[a2])
			reerror=1;
			else
			{
				for(int rei=0;rei<bj[a2];rei++)
				{
					if(b_out[a1][rei]!=b_out[a2][rei])
					{
					reerror=1;
					break;
				    }
				}
			} 
			if(reerror==1)
			result[resulti][3]=0;
			else
			result[resulti][3]=1;
			resulti++;
	  }	
}

void judgemr2(int a1,int a2)
{
      int i=0; 
      int j=0;
	  int tag=0;
	  int error=0;
	  while(i<bi[a1]&&j<bi[a2])
	  {	  	 
	  	  int l1=b[a1][i].length();
	  	  int l2=b[a2][j].length();
	  	  if(b[a1][i][0]==';'&&l1>0)
		  {
		  	 if(l1==l2+1)
		  	 { 
			    int m=1;
		  	 	for(;m<l1;m++)
		  	 	{
		  	 		if(b[a1][i][m]!=b[a2][j][m-1])
		  	 		{
		  	 			error=1;
		  	 			break;
		  	 		}
		  	 	}
		  	 	if(error==0&&m>=l1)
		  	 	tag=1;
		  	 }
             else if(b[a1][i]!=b[a2][j])
             {
             	error=1;
             	break;
             }
		  }
		  else if(b[a1][i]!=b[a2][j])
		  {
		  	    error=1;
             	break;
		  }
		  i++;
		  j++;
      }
	  if(i>=bi[a1]&&j>=bi[a2]&&error==0&&tag==1)
	  {
	  	 	result[resulti][0]=a1;
			result[resulti][1]=a2;
			result[resulti][2]=2;
			int reerror=0;
			if(bj[a1]>bj[a2])
			reerror=1;
			else
			{
				int rej=0;
				for(int rei=0;rei<bj[a1];rei++)
				{
					while(rej<bj[a2])
					{
						if(b_out[a1][rei]!=b_out[a2][rej])
					    rej++;
					    else
					    break;
				    }
				    if(rej>=bj[a2])
				    {
				    	reerror=1;
				    	break;
				    }
				}
			} 
			if(reerror==1)
			result[resulti][3]=0;
			else
			result[resulti][3]=1;
			resulti++;
	  }	
}

int main(int argc, char * argv[])
{
    struct dirent *ptr;    
    DIR *dir;
    //string PATH = "./src_input";
    string PATH = argv[1];
    string PATH2 = argv[2];
    string output_txt=argv[3];
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
    for(int i=0;i<35000;i++)
    {
    	
    	for(int j=0;j<100;j++)
    	{
    		b[i][j]="";
			b_out[i][j]="";
    	}
    	
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
    	    b[i][j]=str;
    	    j++;
        }   
        bi[i]=j;
        //cout<<bi[i]<<endl;
        string tem_out=PATH2+"/"+files[i];
        ifstream f_in_out(tem_out.c_str());         
        string str_out;
        int j1=0;
        while (getline(f_in_out, str_out)){
    	    b_out[i][j1]=str_out;
    	    j1++;
        } 
        bj[i]=j1;
    }
    
   /* for (int i = 0; i < files.size(); ++i)
    { 
         cout<<bi[i]<<endl;
        for(int j=0;j<bi[i];j++)
         cout<<b[i][j]<<endl;
         for(int j=0;j<bj[i];j++)
         cout<<b_out[i][j]<<endl;
    } */


	for(int i=0;i<files.size()-1;i++)
	{
		for(int j=i+1;j<files.size();j++)
		{
			judgemr0(i,j);
	     	judgemr0(j,i);
			judgemr1(i,j);
			judgemr1(j,i);
		    judgemr2(i,j);
			judgemr2(j,i);
		}
	}
    char filename[200];
	sprintf(filename,"%s",output_txt.c_str());
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


