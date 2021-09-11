#include "function.h"
#include <fstream>
//#include <limits.h>
//#include<iostream>
//#include<string>
//#include <dirent.h>
//#include <vector>

int main(int argc, char *argv[])
{
    std::string tem=argv[1];       
    std::string str;
    std::ifstream infile;    
    infile.open(tem.c_str());
    int bi=0;
    int b[500];
    while(!infile.eof())
    {
        infile>>b[bi];
        bi++;
    }
    int end=bi-2;
    int e=b[bi-1];
    int m=BinSearch(b,e,0,end);
	int allmax=-1;
	int allmin=-1;
	if(m!=-1)
	{
	    int* temp=GetRange(b,m,end);	 
		allmin=temp[0];
		allmax=temp[1];  
	}
        std::ofstream write;
        //cout<<tem<<endl;
        char filename[200];
        
        tem.copy(filename,tem.length(),0);
        //cout<<endl;
        *(filename+tem.length())='\0';
        write.open(filename, std::ios::app);                //用ios::app不会覆盖文件内容
        write << std::endl<< allmin<<" "<<allmax;
        write.close();
    return 0;
}
