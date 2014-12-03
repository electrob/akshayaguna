
/*	Copyright (C) 2014 Samrat Das, samrat48@hotmail.com
 *
 *	This file is part of Akshayguna, IoT Framework
 *
 *	Akshayguna is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Akshayguna is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>
#include<errno.h>
/*
/ for each line in the program , this process is forked
/
/
*/
 
// Template new_function(char * command, char * operation, char * further,int line_no, int total_char)
/*
/ every time execute command calls this function,
/ after lexical analysis, it separates the command and operation code
/ and send it to this function, with the more information as:
/ line_no for the line number of your program
/ total_char is for total number of character was in the line
*/

//-------------------------------------- LOG FUNCTION DEFINATION ---------------------------------------//
int logw(char * message)
{
printf("msg: %s\n",message);
return 0;
}

//------------------======================-EVENT FUNCTION DEFINATION --=----------------------------------//
int event(char * operation, char * nextcmd)
{
printf("Event:%s\n",operation);



return 0;
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=INITSENSOR Fuction Declatation -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
int initsensor(char * command)
{
printf("init %s\n",command);

return 0;
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=INITSENSOR Fuction Declatation -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
int db(char * command)
{
printf("db %s\n",command);

return 0;
}

int mqtt(char * command)
{
printf("MQTT: %s\n",command);


}
