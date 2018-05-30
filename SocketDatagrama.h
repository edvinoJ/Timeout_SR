#ifndef __SOCKETDATAGRAMA_H__
#define __SOCKETDATAGRAMA_H__

#include "PaqueteDatagrama.h"
#include <netinet/in.h>
#include <sys/time.h>
#include <cstdio>
class SocketDatagrama{
	public:
		SocketDatagrama();
		SocketDatagrama(int);
		SocketDatagrama(int, char *);
		~SocketDatagrama();
		//Recibe un paquete tipo datagrama proveniente de este socket
		int recibe(PaqueteDatagrama *p);
		//Envía un paquete tipo datagrama desde este socket
		int envia(PaqueteDatagrama *p);
		void setReusePort(bool);
		int recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos);
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int _s; //ID socket 
};

#endif
