#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

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
    	int Cur_Vertical_Sep = 300 + rand()%300;
		int High_Confidence = rand()%2;
		int Two_of_Three_Reports_Valid= rand()%2;
		int Own_Tracked_Alt = 1 + rand()%2;
		int Own_Tracked_Alt_Rate = 300 + rand()%300;
		int Other_Tracked_Alt= 1 + rand()%2;
	    int Alt_Layer_Value= rand()%4;
		int Up_Separation= rand()%840;
		int Down_Separation= rand()%840;
		int Other_RAC= rand()%3;
		int Other_Capability= 1 + rand()%2;
		int Climb_Inhibit= rand()%2;
		
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
	         examplefile<<Cur_Vertical_Sep<<" "<<High_Confidence<<" "<<Two_of_Three_Reports_Valid<<" "<<Own_Tracked_Alt<<" "<<Own_Tracked_Alt_Rate<<" "<<Other_Tracked_Alt<<" "<<Alt_Layer_Value<<" "<<Up_Separation<<" "<<Down_Separation<<" "<<Other_RAC<<" "<<Other_Capability<<" "<<Climb_Inhibit;
	         examplefile.close();        //¹Ø±ÕÎÄ¼þ 
	    }
		
    } 
	return 0;
}
