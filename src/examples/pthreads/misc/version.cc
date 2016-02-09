/*
 * This file is part of the linuxapi package.
 * Copyright (C) 2011-2016 Mark Veltzer <mark.veltzer@gmail.com>
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
#include <stdio.h>	// for printf(3)
#include <unistd.h>	// for confstr(3)
#include <stdlib.h>	// for EXIT_SUCCESS
#include <err_utils.h>	// for CHECK_IN_RANGE()

/*
 * This demp shows how to get the version of the pthread library you are using.
 *
 * EXTRA_LINK_FLAGS=-lpthread
 */

int main(int argc, char** argv, char** envp) {
	char name[256];
	CHECK_IN_RANGE(confstr(_CS_GNU_LIBPTHREAD_VERSION, name, sizeof(name)), 1, sizeof(name));
	printf("confstr(_CS_GNU_LIBPTHREAD_VERSION) returns [%s]\n", name);
	return EXIT_SUCCESS;
}
