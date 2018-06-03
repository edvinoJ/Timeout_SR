#include "Respuesta.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int main(int argc, char const *argv[]){
	if (argc < 2){
		printf("Error %s -puerto\n", argv[0]);
		return -1;
	}
if (argc < 2){
		printf("Error %s -puerto\n", argv[0]);
		return -1;
	}
	Respuesta servidor(atoi(argv[1]));
	unsigned int nbd = 0;
	int operationID;
	int times= 0;
	struct mensaje * msg;
	char * arg = NULL;
	int len;
	char * res =  NULL;
	unsigned int requestId = 0;
	string temp;
	while(true){
		msg = servidor.getRequest();
		if(msg->requestId == requestId){
			servidor.sendReply(res, msg->IP, msg->puerto);
			continue;
		}
		requestId = msg->requestId;
		arg = NULL;
		arg = (char *) realloc(arg,strlen(msg->arguments));
		strcpy(arg, msg->arguments);
		operationID = msg->operationId;
		temp.clear();
		switch(operationID){
			case 0:
				printf("Error de inconsistencia\n");
				return -1;
			break;
			case 1:
				printf("Consulta de saldo \n");
				temp  = to_string(nbd);
				res = (char *)calloc(0, temp.length());
				strcpy(res, temp.c_str());
			break;
			case 2:
				printf("Deposito\n");
				nbd+=atoi(arg);
				temp  = to_string(nbd);
				res = (char *)calloc(0, temp.length());
				strcpy(res, temp.c_str());
			break;
			default:
				printf("Error \n");
				return -1;
		}
	/*liberar memoria*/
	servidor.sendReply(res, msg->IP, msg->puerto);
	}
	return 0;
}