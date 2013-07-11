/*
 * This file is part of the linuxapi package.
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
#include <unistd.h>	// for sleep(3)
#include <pthread.h>	// for pthread_create(3), pthread_join(3)
#include <us_helper.h>	// for TRACE(), CHECK_ZERO_ERRNO()
#include "mymutex.hh"	// for MyMutex<T>::Object

/*
 * This demos pthread mutex usage.
 * Note that these are actually futexes.
 *
 * EXTRA_LINK_FLAGS=-lpthread
 */

static MyMutex<MT_SYNCH> mylock;

static void *worker(void *p) {
	unsigned int id=*(unsigned int*)p;
	int counter=0;
	while(counter<10) {
		TRACE("%d before lock", id);
		mylock.lock();
		CHECK_ZERO(sleep(1));
		// this simulates a bug. see what this thread is doing using
		// strace on the process or thread id.
		if(id==1 && counter==10) {
			CHECK_ZERO(sleep(1000));
		}
		mylock.unlock();
		counter++;
		TRACE("%d after lock", id);
		CHECK_ZERO(sleep(1));
	}
	return NULL;
}

int main(int argc, char** argv, char** envp) {
	TRACE("initialized the lock...");
	const unsigned int num=2;
	pthread_t threads[num];
	unsigned int ids[num];
	void* rets[num];
	TRACE("starting threads...");
	for(unsigned int i=0; i<num; i++) {
		ids[i]=i;
		CHECK_ZERO_ERRNO(pthread_create(threads + i, NULL, worker, ids + i));
	}
	TRACE("finished creating threads, joining them...");
	for(unsigned int i=0; i<num; i++) {
		CHECK_ZERO_ERRNO(pthread_join(threads[i], rets + i));
	}
	TRACE("joined all threads, destroying the lock...");
	return EXIT_SUCCESS;
}
