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

#include<stdio.h> // for printf(3), fflush(3)
#include<time.h> // for clock_getres(2)
#include<stdlib.h> // for EXIT_SUCCESS
#include<us_helper.h> // for CHECK_NOT_M1()

/*
 * Demo the clock_gettime usage
 *
 * EXTRA_LIBS=-lrt
 */
void print_timespec(const char *msg, struct timespec *ts) {
	printf("%s %ld %ld\r", msg, ts->tv_sec, ts->tv_nsec);
	fflush(stdout);
}


int main(int argc, char **argv, char **envp) {
	//clockid_t clk_id=CLOCK_REALTIME;
	clockid_t clk_id = CLOCK_MONOTONIC;
	struct timespec res;

	CHECK_NOT_M1(clock_getres(clk_id, &res));
	print_timespec("clock resolution is ", &res);
	printf("\n");
	while(true) {
		struct timespec t;
		CHECK_NOT_M1(clock_gettime(clk_id, &t));
		print_timespec("clock time is ", &t);
	}
	return EXIT_SUCCESS;
}
