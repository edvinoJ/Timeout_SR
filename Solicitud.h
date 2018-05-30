#ifndef SOLICITUD_H
#define SOLICITUD_H
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
class Solicitud{
public:
   Solicitud();
char * doOperation(char *IP, int puerto, int operationId, char *arguments); 
private:
	SocketDatagrama *socketlocal; 
	unsigned int requestId;
	struct mensaje * message;
};
#endif