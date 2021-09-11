#include <iostream>
#include <fstream>

#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <climits>
using namespace std;
string number;
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "bad args" << std::endl;
	}
	std::ifstream f_in(argv[1]);
	number=argv[2];
	
    int src_input=0;
	std::string str;
 
	while (getline(f_in, str))
	{
		int arg[11];
		int jj=0;
		for(int i=1;i<11;i++)
		{
			while(str[jj]==' ')
			jj++;
			if(str[jj]!=' ')
			arg[i]=str[jj]-'0';
			jj++; 
		}
	    int x1,x2,x3,x4,x5,x6,x7;
        int y1,y2,y3;

	//year
	switch (arg[1])
	{
			
		case 0:
				x1 = 1900;
				break;
		case 1:
				x1 = 1998;
				break;			
		case 2:
                x1 = 2000;
				break;		
		case 3:
				x1 = 2008;
				break;	
		case 4:
				x1 = 2009;
				break;
		case 5:
				x1 = 2012;
				break;				
	} 
	
	//month
    switch (arg[2])
	{
			
		case 0:
				x2 = 1;
				break;
		case 1:
				x2 = 2;
				break;			
		case 2:
                x2 = 7;
				break;		
		case 3:
				x2 = 8;
				break;	
		case 4:
				x2 = 9;
				break;
		case 5:
				x2 = 12;
				break;				
	} 
	
	//day
	switch (arg[3])
	{
			
		case 0:
				x3 = 1;
				break;
		case 1:
				x3 = 28;
				break;			
		case 2:
                x3 = 29;
				break;		
		case 3:
				x3 = 30;
				break;	
		case 4:
				x3 = 31;
				break;					
	} 
	
	//hour
	switch (arg[4])
	{
			
		case 0:
				x4 = 0;
				break;
		case 1:
				x4 = 9;
				break;			
		case 2:
                x4 = 13;
				break;		
		case 3:
				x4 = 18;
				break;	
		case 4:
				x4 = 20;
				break;					
	} 
	
	//minute
	switch (arg[5])
	{
			
		case 0:
				x5 = 0;
				break;
		case 1:
				x5 = 5;
				break;			
		case 2:
                x5 = 18;
				break;		
		case 3:
				x5 = 31;
				break;	
		case 4:
				x5 = 50;
				break;					
	} 
	
	//second
	switch (arg[6])
	{			
		case 0:
				x6 = 0;
				break;
		case 1:
				x6 = 5;
				break;			
		case 2:
                x6 = 18;
				break;		
		case 3:
				x6 = 31;
				break;	
		case 4:
				x6 = 50;
				break;				
	} 
	
	//milliseconds
	switch (arg[7])
	{
			
		case 0:
				x7 = 0;
				break;
		case 1:
				x7 = 5;
				break;			
		case 2:
                x7 = 18;
				break;		
		case 3:
				x7 = 31;
				break;	
		case 4:
				x7 = 50;
				break;				
	} 
	
	//week_value
	switch (arg[8])
	{
			
		case 0:
				y1 = 0;
				break;
		case 1:
				y1 = 1;
				break;			
		case 2:
                y1 = 3;
				break;					
	} 
	
	//day_value
	switch (arg[9])
	{
			
		case 0:
				y2 = 0;
				break;
		case 1:
				y2 = 1;
				break;			
		case 2:
                y2 = 2;
				break;
		case 3:
                y2 = 7;
				break;					
	} 
	
	//milliseconds_value
	switch (arg[10])
	{
			
		case 0:
				y3 = 0;
				break;
		case 1:
				y3 = 1;
				break;			
		case 2:
                y3 = 2;
				break;
		case 3:
                y3 = 3;
				break;
		case 4:
                y3 = 604800;
				break;					
	} 
    if((x1==1900||x1==1998||x1==2009)&&x2==2&&(x3==30||x3==31||x3==29))
	cout<<src_input<<endl;
	if((x1==2000||x1==2008||x1==2012)&&x2==2&&(x3==30||x3==31))
	cout<<src_input<<endl;
	if(x2==9&&x3==31)
	cout<<src_input<<endl;

    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile << x1 << " "<<x2 << " "<<x3 << " "<<x4 << " "<<x5 << " " <<x6 << " "<<x7<<" "<< y1 << " "<<y2 << " "<<y3;
         examplefile.close();        //¹Ø±ÕÎÄ¼þ 
    } 	
   } 
   
} 
