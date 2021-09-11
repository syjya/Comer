#include "function.h"
#include <fstream>

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
        infile>>b[bi++];
    }
    int n=bi-1;
    int m=b[bi-1];
	int num[100];
	int dp[100];
	int count=0;
    for(int j=1;j<=n;j++)
	{
		dp[j]=0;
		num[j]=b[count++];
	}		
    int d=solve(dp,num,n,m);
        
        std::ofstream write;
        //cout<<tem<<endl;
        char filename[200];
        
        tem.copy(filename,tem.length(),0);
        //cout<<endl;
        *(filename+tem.length())='\0';
        write.open(filename, std::ios::app);                //用ios::app不会覆盖文件内容
        write << std::endl<< d;
        write.close();
    return 0;
}
