#include "Solicitud.h"
Solicitud::Solicitud(){
	/*
	Inicializar las variables de informacion del mensaje
	*/
	socketlocal = new SocketDatagrama(7000);
	requestId= 0;
	message = (struct mensaje *) malloc(sizeof(mensaje));
}
char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
	int respuesta = -1;
	int len;
	requestId++;
	for (int i = 0; i < 7; ++i){
		message->messageType = 1;
		message->requestId = requestId;
		strcpy(message->IP, IP);
		message->puerto = puerto;
		message->operationId = operationId;
		len = strlen(arguments);
		strcpy(message->arguments, arguments);
		PaqueteDatagrama pack((char *)message, 3*sizeof(int)+16+sizeof(unsigned int)+ len, IP, puerto);
		socketlocal->envia(&pack);
		/*Liberar memoria*/
		printf("%s\n", message->arguments);
		PaqueteDatagrama pack2(sizeof(struct mensaje));
		respuesta = socketlocal->recibeTimeout(pack2, 2, 500000);
		if(respuesta>0){
			message = (struct mensaje *)pack2.obtieneDatos();
			break;
		}
		/*Liberar memoria*/
	}
	if(respuesta<0){
		printf("No se obtuvo respuesta del servidor\n");
		exit(1);
	}
	return message->arguments;
	
} 