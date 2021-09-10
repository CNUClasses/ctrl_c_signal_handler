//============================================================================
// Name        : ctrl_C_handler.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Run this program from a terminal and you will see that hitting ctrl-c will 
//               cause program to exit
//               see https://stackoverflow.com/questions/4217037/catch-ctrl-c-in-c/54267342
//============================================================================

#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>
#include <unistd.h>
#include <thread>
#include <string.h>

void     INThandler(int);
bool doWork=true;
int  main(void)
{
     signal(SIGINT, INThandler);	//register handler
     while (doWork)
    	 std::this_thread::sleep_for(std::chrono::milliseconds(10));
     return 0;
}

void  INThandler(int sig)
{   
	//this routine is called when user hits ctrl-c
	char buff[]="User hit ctrl-c\n";
	write(1,buff ,strlen(buff) );  
	doWork=false;
}
