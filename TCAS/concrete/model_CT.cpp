#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

int arg[5000][12];
int bi;

std::string number;
 
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "bad args" << std::endl;
	}
	std::ifstream f_in(argv[1]);
	number=argv[2];
	std::string str;
    srand((unsigned int)(time(NULL)));
    bi=0;
    int src_input=0;
	while (getline(f_in, str))
	{       	
		std::istringstream is(str); 
		int temp_arg;
		int i=0;
		while(is>>temp_arg)
		{
			arg[bi][i++]=temp_arg;
		}
		bi++;
    }
	
	for(int i=0;i<bi;i++){
		
	int arg1 = arg[i][0];
	int arg2 = arg[i][1];
	int arg3 = arg[i][2];
	int arg4 = arg[i][3];
	int arg5 = arg[i][4];
	int arg6 = arg[i][5];
	int arg7 = arg[i][6];
	int arg8 = arg[i][7];
	int arg9 = arg[i][8];
	int arg10 = arg[i][9];
	int arg11 = arg[i][10];
	int arg12 = arg[i][11];
	
    int Cur_Vertical_Sep;
	int High_Confidence;
	int Two_of_Three_Reports_Valid;
	int Own_Tracked_Alt;
	int Own_Tracked_Alt_Rate;
	int Other_Tracked_Alt;
    int Alt_Layer_Value;
	int Up_Separation;
	int Down_Separation;
	int Other_RAC;
	int Other_Capability;
	int Climb_Inhibit;
	switch(arg1)
	{
		case 0:Cur_Vertical_Sep=299;
			break;
		case 1: Cur_Vertical_Sep=300;
		    break;
		case 2: Cur_Vertical_Sep=601;
		    break;
	} 
	
    switch (arg2)
	{
	case 0:High_Confidence=0;
		break;
	case 1:
		High_Confidence=1;
		break;
	}
	
	switch (arg3)
	{
	case 0:Two_of_Three_Reports_Valid=0;
		break;
	case 1:Two_of_Three_Reports_Valid=1;
		break;
	}
	
	switch (arg4)
	{
	case 0:Own_Tracked_Alt=1;
		break;
	case 1:Own_Tracked_Alt=2;
		break;
	}
 
    switch (arg5)
	{
	case 0:Own_Tracked_Alt_Rate=600;
		break;
	case 1:Own_Tracked_Alt_Rate=601;
		break;
	}
    
    switch (arg6)
	{
	case 0:Other_Tracked_Alt=1;
		break;
	case 1:Other_Tracked_Alt=2;
		break;
	}
    
    switch(arg7)
	{
		case 0:Alt_Layer_Value=0;
			break;
		case 1: Alt_Layer_Value=1;
		    break;
		case 2: Alt_Layer_Value=2;
		    break;
		case 3: Alt_Layer_Value=3;
		    break;
	} 
	
	switch(arg8)
	{
		case 0:Up_Separation=0;
			break;
		case 1:Up_Separation=399;
		    break;
		case 2:Up_Separation=400;
		    break;
		case 3:Up_Separation=499;
		    break;
		case 4:Up_Separation=500;
		    break;
		case 5:Up_Separation=639;
			break;
		case 6:Up_Separation=640;
		    break;
		case 7:Up_Separation=739;
		    break;
		case 8:Up_Separation=740;
		    break;
		case 9:Up_Separation=840;
		    break;
	} 
	
	switch(arg9)
	{
		case 0:Down_Separation=0;
			break;
		case 1:Down_Separation=399;
		    break;
		case 2:Down_Separation=400;
		    break;
		case 3:Down_Separation=499;
		    break;
		case 4:Down_Separation=500;
		    break;
		case 5:Down_Separation=639;
			break;
		case 6:Down_Separation=640;
		    break;
		case 7:Down_Separation=739;
		    break;
		case 8:Down_Separation=740;
		    break;
		case 9:Down_Separation=840;
		    break;
	} 
	
	switch(arg10)
	{
		case 0:Other_RAC=0;
			break;
		case 1:Other_RAC=1;
		    break;
		case 2:Other_RAC=2;
		    break;
	} 
	
	switch(arg11)
	{
		case 0:Other_Capability=1;
			break;
		case 1:Other_Capability=2;
		    break;
	} 
	
	switch(arg12)
	{
		case 0:Climb_Inhibit=0;
			break;
		case 1:Climb_Inhibit=1;
		    break;
	} 
    
    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile<<Cur_Vertical_Sep<<" "<<High_Confidence<<" "<<Two_of_Three_Reports_Valid<<" "<<Own_Tracked_Alt<<" "<<Own_Tracked_Alt_Rate<<" "<<Other_Tracked_Alt<<" "<<Alt_Layer_Value<<" "<<Up_Separation<<" "<<Down_Separation<<" "<<Other_RAC<<" "<<Other_Capability<<" "<<Climb_Inhibit;
         examplefile.close();        //¹Ø±ÕÎÄ¼þ 
    }
    
    }
	return 0;
}
