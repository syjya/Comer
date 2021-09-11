#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int src_input;
int arg[2000][12];
int bi;

int flag[2000];
string number;
std::string line[2000];
void MR0_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
	
	int cmd1 = arg[a1][0];
	int attr1 = arg[a1][1];
	
	int cmd2 = arg[a1][2];
	int attr21 = arg[a1][3];
	int attr22 = arg[a1][4];

	int cmd3 = arg[a1][5];

	int cmd4 = arg[a1][6];
	int attr4 = arg[a1][7];

	int cmd5 = arg[a1][8];

	int cmd6 = arg[a1][9];

	int cmd7 = arg[a1][10];

	for(int i=0;i<2000;i++)
	line[i]="";
	int linei=0;
	std::string end = "";	
	std::string begin = "";
	std::string a = "";
	std::string b = "";
    
	if (cmd1!=0){
		switch (attr1)
		{
			case 0:
				a = "1";				
				break;
			case 1:
				a = "2";
				break;			
			case 2:				
				a = "3";
				break;		

		}
		line[linei++]= "1 "+ a;
		if (cmd1 >1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "1 "+ a;
		} 
		    
	}


	if (cmd2!=0){
		switch (attr21)
		{
			case 0:
				a = "1";				
				break;
			case 1:
				a = "2";
				break;			

		}
		switch (attr22)
		{
			case 0:
				b = "0"; 
				break;

			case 1:
				b = "1"; 
				break;
			case 2:	// 0.1
				b ="0.1";		
				break;
			case 3: //0.4
				b ="0.4";		
				break;
			case 4: //0.5
				b ="0.5";				
				break;
			case 5: //0.6
				b ="0.6";		
				break;
			case 6: //0.9
				b ="0.9";		
				break;			
			case 7: // 2
				b ="2";
				break;

		}
		line[linei++]= "2 "+ a+" "+b;
		if (cmd2>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "2 "+ a+" "+b;
		}
			
	}


	if (cmd3!=0){
		line[linei++]= "3";
		if (cmd3>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
				line[linei++]= "3";
		}
			
	}


	if (cmd4!=0){
		switch (attr4)
		{
			case 0:
				b = "0"; 
				break;
			case 1:
				b = "1"; 
				break;
			case 2:	// 0.1
				b ="0.1";				
				break;
			case 3: //0.4
					b ="0.4";		
				break;
			case 4: //0.5
					b ="0.5";		
				break;
			case 5: //0.6
					b ="0.6";		
				break;
			case 6: //0.9
					b ="0.9";		
				break;
			case 7:
				b = "2"; 
				break;
		}

		line[linei++]= "4 "+b;
		if (cmd4>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
				line[linei++]= "4 "+b;
		}
			
	}


	if (cmd5!=0){
		begin= "5";
		if (cmd5>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "5";
		}
		  
	}

	if (cmd6!=0){
		line[linei++]= "6";
		if (cmd6>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "6";
		}
		  
	}

		line[linei++]= "7";
		if (cmd7>0 )
		{
			int temp=2+rand()%9;//[2,10] 
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "7";
		}

    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
//	std::cout<<filename<<endl;
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         examplefile<<begin;
         if(linei>0)
         examplefile<<"\n";
         for(int i=0;i<linei;i++)
	{
		examplefile<<line[i];
		if(i!=linei-1)
		examplefile<<"\n";
	}
         examplefile.close();        //关闭文件 
    } 
    
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile2(filename);
    if (examplefile2.is_open())
    {  
         examplefile2<<"3"<<"\n"<<"4 0.00";
         if(linei>0)
         examplefile2<<"\n";
         for(int i=0;i<linei;i++)
	{
		examplefile2<<line[i];
		if(i!=linei-1)
		examplefile2<<"\n";
	}
         examplefile2.close();        //关闭文件 
    } 
    flag[a1]=1;
    flag[a2]=1;
}

void MR1_testcase(int a1,int a2)
{
	if(flag[a1]==1||flag[a2]==1)
	return;
	
	int cmd1 = arg[a1][0];
	int attr1 = arg[a1][1];
	
	int cmd2 = arg[a1][2];
	int attr21 = arg[a1][3];
	int attr22 = arg[a1][4];

	int cmd3 = arg[a1][5];

	int cmd4 = arg[a1][6];
	int attr4 = arg[a1][7];

	int cmd5 = arg[a1][8];

	int cmd6 = arg[a1][9];

	int cmd7 = arg[a1][10];

		for(int i=0;i<2000;i++)
	line[i]="";
	int linei=0;
	std::string end = "";	
	std::string begin = "";
	std::string a = "";
	std::string b = "";
    
	if (cmd1!=0){
		switch (attr1)
		{
			case 0:
				a = "1";				
				break;
			case 1:
				a = "2";
				break;			
			case 2:				
				a = "3";
				break;		

		}
		begin= "1 "+ a;
		if (cmd1 >1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "1 "+ a;
		} 
		    
	}


	if (cmd2!=0){
		switch (attr21)
		{
			case 0:
				a = "1";				
				break;
			case 1:
				a = "2";
				break;			

		}
		switch (attr22)
		{
			case 0:
				b = "0"; 
				break;

			case 1:
				b = "1"; 
				break;
			case 2:	// 0.1
				b ="0.1";		
				break;
			case 3: //0.4
				b ="0.4";		
				break;
			case 4: //0.5
				b ="0.5";				
				break;
			case 5: //0.6
				b ="0.6";		
				break;
			case 6: //0.9
				b ="0.9";		
				break;			
			case 7: // 2
				b ="2";
				break;

		}
		line[linei++]= "2 "+ a+" "+b;
		if (cmd2>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "2 "+ a+" "+b;
		}
			
	}


	if (cmd3!=0){
		line[linei++]= "3";
		if (cmd3>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
				line[linei++]= "3";
		}
			
	}


	if (cmd4!=0){
		switch (attr4)
		{
			case 0:
				b = "0"; 
				break;
			case 1:
				b = "1"; 
				break;
			case 2:	// 0.1
				b ="0.1";				
				break;
			case 3: //0.4
					b ="0.4";		
				break;
			case 4: //0.5
					b ="0.5";		
				break;
			case 5: //0.6
					b ="0.6";		
				break;
			case 6: //0.9
					b ="0.9";		
				break;
			case 7:
				b = "2"; 
				break;
		}

		line[linei++]= "4 "+b;
		if (cmd4>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
				line[linei++]= "4 "+b;
		}
			
	}


	if (cmd5!=0){
		line[linei++]= "5";
		if (cmd5>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "5";
		}
		  
	}

	if (cmd6!=0){
		line[linei++]= "6";
		if (cmd6>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "6";
		}
		  
	}

		line[linei++]= "7";
		if (cmd7>0 )
		{
			int temp=2+rand()%9;//[2,10] 
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "7";
		}

    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
//	std::cout<<filename<<endl;
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
     examplefile<<begin;
     if(linei>0)
     examplefile<<"\n";
         for(int i=0;i<linei;i++)
	{
		examplefile<<line[i];
		if(i!=linei-1)
		examplefile<<"\n";
	}
         examplefile.close();        //关闭文件 
    } 
    
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
    std::ofstream examplefile2(filename);
    if (examplefile2.is_open())
    {  
         examplefile2<<"1 1"<<"\n"<<"2 1 0.5";
         if(linei>0)
         examplefile2<<"\n";
         for(int i=0;i<linei;i++)
	{
		examplefile2<<line[i];
		if(i!=linei-1)
		examplefile2<<"\n";
	}
         examplefile2.close();       //关闭文件 
    } 
    flag[a1]=1;
    flag[a2]=1;
}

void judgeMR0()
{	
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][5]!=2&&arg[i][6]!=2&&arg[i][8]!=0&&arg[i][7]==0)
		{
			for(int j=i+1;j<bi;j++)
			{
				int error=0;
				for(int com=0;com<11;com++)
				{
					if(com==5||com==6)
					{
						if(arg[i][com]!=arg[j][com]-1)
						{
							error=1;
							break;
						}
					}
					else if(com==8)
					{
						if(arg[i][com]!=arg[j][com]+1)
						{
							error=1;
							break;
						}
					}
					else if(arg[i][com]!=arg[j][com])
					{
						error=1;
						break;
					}
				}
				if(error==0)
				{
				   MR0_testcase(i,j);
				   break;
				}			
			}
		}
	}
} 

void judgeMR1()
{	
	for(int i=0;i<bi-1;i++)
	{
		if(arg[i][0]==1&&arg[i][1]==1&&arg[i][2]!=2&&arg[i][3]==0&&arg[i][4]==4&&flag[i]==-1)
		{
			for(int j=i+1;j<bi;j++)
			{
				int error=0;
				for(int com=0;com<11;com++)
				{
					if(com==0)
					{
						if(arg[j][com]!=1)
						{
							error=1;
							break;
						}
					}
					else if(com==1)
					{
						if(arg[j][com]!=0)
						{
							error=1;
							break;
						}
					}
					else if(com==2)
					{
						if(arg[i][com]!=arg[j][com]-1)
						{
							error=1;
							break;
						}
					}
					else if(arg[i][com]!=arg[j][com])
					{
						error=1;
						break;
					}
				}
				if(error==0)
				{
				   MR1_testcase(i,j);
				   break;
				}			
			}
		}
	}
} 

void init()
{
	src_input=0;
	bi=0;
	for(int i=0;i<2000;i++)
	flag[i]=-1;
}

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
    init();	
	while (getline(f_in, str))
	{       	
		int jj=0;
		for(int i=0;i<11;i++)
		{
			while(str[jj]==' ')
			jj++;
			if(str[jj]!=' ')
			arg[bi][i]=str[jj]-'0';
			jj++; 
		}
		bi++;
    }
//    judgeMR0();
//    judgeMR1();
    
    for(int a1=0;a1<bi;a1++)
    {
    if(flag[a1]==-1)
    {
	int cmd1 = arg[a1][0];
	int attr1 = arg[a1][1];
	
	int cmd2 = arg[a1][2];
	int attr21 = arg[a1][3];
	int attr22 = arg[a1][4];

	int cmd3 = arg[a1][5];

	int cmd4 = arg[a1][6];
	int attr4 = arg[a1][7];

	int cmd5 = arg[a1][8];

	int cmd6 = arg[a1][9];

	int cmd7 = arg[a1][10];

	for(int i=0;i<2000;i++)
	line[i]="";
	int linei=0;
	std::string end = "";	
	std::string begin = "";
	std::string a = "";
	std::string b = "";
    
	if (cmd1!=0){
		switch (attr1)
		{
			case 0:
				a = "1";				
				break;
			case 1:
				a = "2";
				break;			
			case 2:				
				a = "3";
				break;		

		}
		line[linei++]= "1 "+ a;
		if (cmd1 >1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "1 "+ a;
		} 
		    
	}


	if (cmd2!=0){
		switch (attr21)
		{
			case 0:
				a = "1";				
				break;
			case 1:
				a = "2";
				break;			

		}
		switch (attr22)
		{
			case 0:
				b = "0"; 
				break;

			case 1:
				b = "1"; 
				break;
			case 2:	// 0.1
				b ="0.1";		
				break;
			case 3: //0.4
				b ="0.4";		
				break;
			case 4: //0.5
				b ="0.5";				
				break;
			case 5: //0.6
				b ="0.6";		
				break;
			case 6: //0.9
				b ="0.9";		
				break;			
			case 7: // 2
				b ="2";
				break;

		}
		line[linei++]= "2 "+ a+" "+b;
		if (cmd2>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "2 "+ a+" "+b;
		}
			
	}


	if (cmd3!=0){
		line[linei++]= "3";
		if (cmd3>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
				line[linei++]= "3";
		}
			
	}


	if (cmd4!=0){
		switch (attr4)
		{
			case 0:
				b = "0"; 
				break;
			case 1:
				b = "1"; 
				break;
			case 2:	// 0.1
				b ="0.1";				
				break;
			case 3: //0.4
					b ="0.4";		
				break;
			case 4: //0.5
					b ="0.5";		
				break;
			case 5: //0.6
					b ="0.6";		
				break;
			case 6: //0.9
					b ="0.9";		
				break;
			case 7:
				b = "2"; 
				break;
		}

		line[linei++]= "4 "+b;
		if (cmd4>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
				line[linei++]= "4 "+b;
		}
			
	}


	if (cmd5!=0){
		line[linei++]= "5";
		if (cmd5>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "5";
		}
		  
	}

	if (cmd6!=0){
		line[linei++]= "6";
		if (cmd6>1 )
		{
			int temp=2+rand()%9;//[2,10]
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "6";
		}
		  
	}

		line[linei++]= "7";
		if (cmd7>0 )
		{
			int temp=2+rand()%9;//[2,10] 
			for(int i= 0; i<temp-1;i++)
			line[linei++]= "7";
		}

    char filename[200];
	sprintf(filename,"%s%s%d%s",number.c_str(),"/",src_input++,".txt");
//	std::cout<<filename<<endl;
    std::ofstream examplefile(filename);
    if (examplefile.is_open())
    {  
         for(int i=0;i<linei;i++)
	{
		examplefile<<line[i];
		if(i!=linei-1)
		examplefile<<"\n";
	}
         examplefile.close();        //关闭文件 
    } 
    }}
	return 0;
}
