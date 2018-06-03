#ifndef _RESPUESTA_H
#define _RESPUESTA_H
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>
class Respuesta{
public:
	Respuesta(int pl);
	struct mensaje *getRequest(void);
	void sendReply(char *respuesta, char *ipCliente, int puertoCliente);
private:
	SocketDatagrama *socketlocal;
	unsigned int requestId;
	int contador;
};
#endif