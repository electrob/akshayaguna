
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
int executecmd(unsigned char * command, int dd)
{
char *func;
char *oper;
char *furt;
int cur=0,cur2=0,ch=0;
while(command[ch++]!='\n');
while(command[cur++]!='%');
cur2=cur;
command[(cur-2)]='\0';
while(command[cur++]!='?');
command[cur -2]='\0';
func=command;		// func is the char pointing to the function, used for passing to function
oper=&command[cur2+1];	// pointing to operation of the function
furt=&command[cur+1];	// pointing to further (if applicable)

if(strcmp(func,"LOG")==0) logw(oper);
else if(strcmp(func,"EVENT")==0) event(oper,furt);
else if(strcmp(func,"INITSENSOR")==0) initsensor(oper);
else if(strcmp(func,"DB")==0) db(oper);
else if(strcmp(func,"MQTT")==0) mqtt(oper);

/* 3) Add new else if according to the above format  */
else printf("Error in Line no. %d, \"%s\" command not found!\n",dd,func);
return 0;
}
