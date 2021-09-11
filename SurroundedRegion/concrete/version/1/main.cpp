// A C++ program to replace all 'O's with 'X''s if surrounded by 'X' 
#include<iostream> 
#include <fstream>
#include <limits.h>
#include<string>
#include <dirent.h>
#include <vector>
#include "function.h"
using namespace std; 

// Size of given matrix is M X N 

int b[500];
int bi;
int judge[500];   //judge- 
int judge1[500];  //judge. 

void spl(std::string a)  
{
    for (int i = 0;i < 500;i++)
    {
        judge[i] = 0;
        judge1[i] = -1;
    }
    int b0 = 0;

    std::string temp[500];
    for (int i = 0;i < 500;i++)
        temp[i] = "";
    int tempi = 0;
    int judge1i = 0;
    for (int i = 0;i < a.length();i++)
    {
        if ((a[i] >= '0' && a[i] <= '9') || a[i] == '-' || a[i] == '.')
        {
            temp[tempi] += a[i];
            if (a[i] == '-')
                judge[tempi] = 1;
            if (a[i] == '.')
                judge1[tempi] = judge1i;
            judge1i++;
        }
        if (a[i] == ' ')
        {
            tempi++;
            judge1i = 0;
        }
        if (i == a.length() - 1 && a[i] != ' ')
            tempi++;
    }

    for (int i = 0;i < tempi;i++)
    {
        double tempint = 0;
        int cheng = 1;
        double cheng1 = 0.1;
        if (judge[i] == 0 && judge1[i] == -1)
        {
            for (int j = temp[i].length() - 1;j >= 0;j--)
            {
                tempint += (temp[i][j] - '0') * cheng;
                cheng = cheng * 10;
            }
            b[bi++] = tempint;
        }
        if (judge[i] == 1 && judge1[i] == -1)
        {
            for (int j = temp[i].length() - 1;j >= 1;j--)
            {
                tempint += (temp[i][j] - '0') * cheng;
                cheng = cheng * 10;
            }
            b[bi++] = -tempint;
        }
        if (judge[i] == 0 && judge1[i] != -1)
        {
            for (int j = judge1[i] - 1;j >= 0;j--)
            {
                tempint += (temp[i][j] - '0') * cheng;
                cheng = cheng * 10;
            }
            for (int j = temp[i].length() - 1;j > judge1[i];j--)
            {
                tempint += (temp[i][j] - '0') * cheng1;
                cheng1 = cheng1 * 0.1;
            }
            b[bi++] = tempint;
        }
        if (judge[i] == 1 && judge1[i] != -1)
        {
            for (int j = judge1[i] - 1;j >= 1;j--)
            {
                tempint += (temp[i][j] - '0') * cheng;
                cheng = cheng * 10;
            }
            for (int j = temp[i].length() - 1;j > judge1[i];j--)
            {
                tempint += (temp[i][j] - '0') * cheng1;
                cheng1 = cheng1 * 0.1;
            }
            b[bi++] = -tempint;
        }
    }
}

int main(int argc, char *argv[])
{

    std::string tem=argv[1];;
    ifstream f_in(tem.c_str());         
    string str;
    bi=0;
    int tag=0;
    string allstr="";
    while (getline(f_in, str)){
        	if(tag==0)
        	{
        		spl(str);
        		tag=1;
        	}	    
        	else if(tag==1)
			{
				allstr+=str;
			} 
        }   
        int M=b[0];
        int N=b[1];        
        char mat[900][900];
        int mati=0;
        int matj=0;
        int allstri=0;
        while(allstri<allstr.length())
        {
        	if(allstr[allstri]=='X'||allstr[allstri]=='O')
        	{
        		mat[mati][matj]=allstr[allstri];
        		if(matj==N-1)
        		{
        			matj=0;
        			mati++;
        		}
        		else
        		matj++;
        	}
        	allstri++;
        }
        	replaceSurrounded(M,N,mat); 

        std::ofstream write;
        //cout<<tem<<endl;
        char filename[200];
        
        tem.copy(filename,tem.length(),0);
        //cout<<endl;
        *(filename+tem.length())='\0';
        write.open(filename, ios::app);                //用ios::app不会覆盖文件内容
        write << endl; 
        for (int ii=0; ii<M; ii++) 
	{ 
	    for (int j=0; j<N; j++) 
	    {
	    	write << mat[ii][j]; 
	    	if(j!=N-1) 
	    	write<<" ";
		}
		if(ii!=M-1) 		
	    write << endl; 
	} 
        write.close();
   
    return 0;
}

