
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
#include<pthread.h>
#include<string.h>

void main(int argc,char * argv[])
{
pid_t exec_child;
char line[100];
if(argc<=1)
{
while(line[0]!='q')
{
printf(">");
scanf("%s",line);
        exec_child=fork();
        if(exec_child==0)
           	{
                executecmd(line,4);
                exit(0);
                }

}
}
else
{
FILE *file=fopen(argv[1],"r");
if(file == NULL)
{
printf("Program could not be Executed\n");
}
else
{
int xa=0;
 while(fgets(line,sizeof(line),file)!=NULL)
 { xa++;
  if(line[0]!='#')
  {
	exec_child=fork();
	if(exec_child==0)
		{
		executecmd(line,xa);
		exit(0);
		}

  }
 }
fclose(file);
}
}
}
