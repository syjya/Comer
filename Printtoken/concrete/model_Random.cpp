#include <iostream>
#include <fstream> 
#include <cstring>
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
    srand((unsigned int)(time(NULL)));
    for(int src_input=0;src_input<bi;src_input++)
    {
    	string str[28]={"and ","or ","if ","xor ","lambda ","=> ","( ",") ","[ ","] ",", ","test ","test15 ","AND ","IF3 ","lambda7 ","X15or ","test	 ","te?st ","test. ","te#st","15or ","0 ","077 ","7 ","770 ","777 ",";test"}; 
    	string line[200];
    	int n=5+rand()%20;
    	for(int i=0;i<n;i++)
    	line[i]=str[rand()%28];
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
	         for(int stri=0;stri<n;stri++)
	         {
	         	examplefile<<line[stri];
				if(stri!=n-1)
				 examplefile<<"\n";
	         }
	         examplefile.close();        //¹Ø±ÕÎÄ¼þ 
	    } 
	}
	return 0;
}
