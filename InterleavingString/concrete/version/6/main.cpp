#include "function.h"
#include <fstream>

int main(int argc, char *argv[])
{
    std::string tem=argv[1];       
    std::string str;
    std::ifstream infile;    
    infile.open(tem.c_str());
    std::string b[500];
    int bi=0;
    while(!infile.eof())
    {
        infile>>b[bi];
        bi++;
    } 
    char* A =&b[0][0];
	char* C =&b[1][0];
	char* D =&b[2][0];
    int temp=isInterleaved(A,C,D);
        std::ofstream write;
        //cout<<tem<<endl;
        char filename[200];
        
        tem.copy(filename,tem.length(),0);
        //cout<<endl;
        *(filename+tem.length())='\0';
        write.open(filename, std::ios::app);                //用ios::app不会覆盖文件内容
        write << std::endl<<temp;
        write.close();
    return 0;
}
