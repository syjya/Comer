#include "function.h"
#include <fstream>

int main(int argc, char *argv[])
{
    std::string tem=argv[1];       
    std::string str;
    std::ifstream infile;    
    infile.open(tem.c_str());
    int bi=0;
    int b[5000];
    while(!infile.eof())
    {
        infile>>b[bi];
        bi++;
    }
    int vertex_num=b[0];
	int edge_num=b[1];
	int source=b[bi-2];
	int zhong=b[bi-1];
	int matrix[100][100];
	for (int ii = 0; ii < vertex_num; ii++)
    for (int j = 0; j < vertex_num; j++)
    {
    	matrix[ii][j] = (ii != j) ? 2147483647 : 0;
	} 
        
    int count=2;
    while(count+2<=bi-3)
    {
    	int p=b[count++];
    	int q=b[count++];
    	int v=b[count++];
    	matrix[p][q]=v;
    	matrix[q][p]=v;
    }
    int *temp=Dijkstra(matrix,source,vertex_num);
        std::ofstream write;
        //cout<<tem<<endl;
        char filename[200];
        
        tem.copy(filename,tem.length(),0);
        //cout<<endl;
        *(filename+tem.length())='\0';
        write.open(filename, std::ios::app);                //用ios::app不会覆盖文件内容
        write << std::endl<< temp[zhong] ;
        write.close();
    return 0;
}
