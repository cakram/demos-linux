/*
	This file is part of the linuxapi project.
	Copyright (C) 2011, 2012 Mark Veltzer <mark.veltzer@gmail.com>

	The linuxapi package is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	The linuxapi package is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with the GNU C Library; if not, write to the Free
	Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
	02111-1307 USA.
*/

#include<firstinclude.h>
#include<sys/types.h> // for recv(2), open(2)
#include<sys/socket.h> // for recv(2)
#include<stdio.h> // for printf(3)
#include<stdlib.h> // for EXIT_SUCCESS
#include<sys/stat.h> // for open(2)
#include<fcntl.h> // for open(2)
#include<us_helper.h> // for CHECK_NOT_M1()

/*
* This example shows that recv(2) cannot be used instead of read for regular
* disk based IO. The error returned is ENOTSOCK.
*/

int main(int argc,char** argv,char** envp) {
	const char* file="/etc/passwd";
	int fd;
	CHECK_NOT_M1(fd=open(file,O_RDONLY));
	const int bufsize=256;
	char buf[bufsize];
	int readBytes;
	CHECK_NOT_M1(readBytes=recv(fd,buf,bufsize,0));
	CHECK_NOT_M1(close(fd));
	return EXIT_SUCCESS;
}