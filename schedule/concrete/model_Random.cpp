#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "bad args" << std::endl;
	}
	int bi=atoi(argv[1]);
	std::string number=argv[2];
	double arg[12];
    srand((unsigned int)(time(NULL)));
    stringstream ss;
    stringstream ss1;
    for(int i=0;i<bi;i++)
    {
    	arg[0]=rand()%11;
    	arg[1]=1+rand()%3;
    	arg[2]=rand()%11;
    	arg[3]=1+rand()%2;
    	
    	double temp4[8]={0, 1, 0.1, 0.4, 0.5, 0.6, 0.9, 2};
    	int rand4=rand()%8;
    	arg[4]=temp4[rand4];
    	
    	arg[5]=rand()%11;
    	arg[6]=rand()%11;
    	
    	double temp7[8]={0, 1, 0.1, 0.4, 0.5, 0.6, 0.9, 2};
    	int rand7=rand()%8;
    	arg[7]=temp7[rand7];
    	
    	arg[8]=rand()%11;
    	arg[9]=rand()%11;
    	
    	arg[10]=1+rand()%10;
    	
    	std::string line = "";

    	ss.clear();
        ss.str("");
    	ss << arg[1];
    	
		for(int j=0;j<(int)arg[0];j++)
		{
			
			line += "1 "+ ss.str() +" ";
		}
		
		ss.clear();
        ss.str("");
    	ss << arg[3];

    	ss1.clear();
        ss1.str("");
    	ss1 << arg[4];
    	
		for(int j=0;j<(int)arg[2];j++)
		{
			line += "2 "+ ss.str() +" "+ss1.str()+" ";
		}
		
		for(int j=0;j<(int)arg[5];j++)
		{
			line += "3 ";
		}
		
		ss.clear();
        ss.str("");
    	ss << arg[7];
    	
		for(int j=0;j<(int)arg[6];j++)
		{
			line += "4 "+ ss.str() +" ";
		}
		
		for(int j=0;j<(int)arg[8];j++)
		{
			line += "5 ";
		}
		
		for(int j=0;j<(int)arg[9];j++)
		{
			line += "6 ";
		}
		
		for(int j=0;j<(int)arg[10];j++)
		{
			line += "7 ";
		}
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",i,".txt");
    	std::ofstream examplefile(filename);
    	if (examplefile.is_open())
    	{  
         	examplefile<<line; 
         	examplefile.close();        //¹Ø±ÕÎÄ¼þ 
    	} 
    }
	return 0;
}
