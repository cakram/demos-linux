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
#include<ace/INET_Addr.h>
#include<ace/SOCK_Stream.h>
#include<ace/SOCK_Connector.h>
#include<ace/Log_Msg.h>
#include<ace/OS_NS_unistd.h>
#include<ace/OS_NS_stdio.h>
#include<stdlib.h> // for EXIT_SUCCESS

/*
 * EXTRA_CMDS=pkg-config --cflags --libs ACE
 */

int ACE_TMAIN(int argc,ACE_TCHAR** argv,ACE_TCHAR** envp) {
	ACE_INET_Addr addr;
	addr.set(20000, ACE_LOCALHOST);
	ACE_SOCK_Connector connector;
	ACE_SOCK_Stream peer;
	int bc;
	static char buf[64];
	ACE_Time_Value timeout(10, 0);
	int i=0;
	if(connector.connect(peer, addr, &timeout) == -1) {
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("%p\n"), ACE_TEXT("Client connect")), 1);
	}
	while(true) {
		bc=peer.recv(buf, sizeof(buf));
		buf[bc]=0;
		if(!bc) {
			printf("End\n");
			break;
		}
		peer.send_n("OK",3,0);
		printf("%2d. %s",++i,buf);
		ACE_OS::sleep(1);
	}
	peer.close();
	return EXIT_SUCCESS;
}
