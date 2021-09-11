#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <climits>
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
	    int x1,x2,x3,x4,x5,x6,x7;
        int y1,y2,y3;
        x1 = 1900 + rand()%120;
        x2 = 1 + rand()%12; 
        //闰年 
		if((x1 % 4 == 0 && x1 % 100 != 0) || (x1 % 400 == 0)) 
		{
			switch (x2)
			{
				case 1:
						x3 = 1+rand()%31;
						break;			
				case 2:
		                x3 = 1+rand()%29;
						break;		
				case 3:
						x3 = 1+rand()%31;
						break;	
				case 4:
						x3 = 1+rand()%30;
						break;	
				case 5:
						x3 = 1+rand()%31;
						break;			
				case 6:
						x3 = 1+rand()%30;
						break;	
				case 7:
						x3 = 1+rand()%31;
						break;	
				case 8:
						x3 = 1+rand()%31;
						break;			
				case 9:
						x3 = 1+rand()%30;
						break;	
				case 10:
						x3 = 1+rand()%31;
						break;	
				case 11:
						x3 = 1+rand()%30;
						break;	
				case 12:
						x3 = 1+rand()%31;
						break;			
			} 
		}
		else
		{
			switch (x2)
			{
				case 1:
						x3 = 1+rand()%31;
						break;			
				case 2:
		                x3 = 1+rand()%28;
						break;		
				case 3:
						x3 = 1+rand()%31;
						break;	
				case 4:
						x3 = 1+rand()%30;
						break;	
				case 5:
						x3 = 1+rand()%31;
						break;			
				case 6:
						x3 = 1+rand()%30;
						break;	
				case 7:
						x3 = 1+rand()%31;
						break;	
				case 8:
						x3 = 1+rand()%31;
						break;			
				case 9:
						x3 = 1+rand()%30;
						break;	
				case 10:
						x3 = 1+rand()%31;
						break;	
				case 11:
						x3 = 1+rand()%30;
						break;	
				case 12:
						x3 = 1+rand()%31;
						break;			
			} 
		}
		x4 = rand()%24;
		x5 = rand()%60;
		x6 = rand()%60;
		x7 = rand()%60;
		
		y1 = rand()%5;
		y2 = rand()%50;
		y3 = rand()%1000000;
		
		char filename[200];
		sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input,".txt");
	    std::ofstream examplefile(filename);
	    if (examplefile.is_open())
	    {  
	         examplefile << x1 << " "<<x2 << " "<<x3 << " "<<x4 << " "<<x5 << " " <<x6 << " "<<x7<<" "<< y1 << " "<<y2 << " "<<y3;
	         examplefile.close();        //关闭文件 
	    }		
    }   
} 
