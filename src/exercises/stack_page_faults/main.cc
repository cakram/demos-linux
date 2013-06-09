/*
 * This file is part of the linuxapi project.
 * Copyright (C) 2011-2013 Mark Veltzer <mark.veltzer@gmail.com>
 *
 * linuxapi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * linuxapi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with linuxapi. If not, see <http://www.gnu.org/licenses/>.
 */

#include <firstinclude.h>
#include <unistd.h>	// for getpagesize(2), sleep(3)
#include <stdio.h>	// for printf(3)
#include <strings.h>	// for bzero(3)
#include <us_helper.h>	// for CHECK_ZERO()

void myfunc(int arg) {
	int myarray[arg];
	bzero(myarray, arg*sizeof(int));
}

int main(int argc, char** argv, char** envp) {
	myfunc(1024*1024);
	int size=getpagesize();
	const int pagesize=getpagesize();
	while(true) {
		printf("size is %d\n", size);
		myfunc(size);
		CHECK_ZERO(sleep(1));
		size+=pagesize;
	}
	return 0;
}
