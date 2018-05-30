#include "Respuesta.h"
Respuesta::Respuesta(int pl){
	socketlocal = new SocketDatagrama(pl);
	requestId = 0;
	msg = (struct mensaje *) malloc(sizeof(mensaje));

}
struct mensaje * Respuesta::getRequest(void){
	PaqueteDatagrama pack(sizeof(struct mensaje));
	socketlocal->recibe(&pack);
	msg = (struct mensaje *) pack.obtieneDatos();
	memcpy(msg->IP, pack.obtieneDireccion(), LON_IP);
	msg->puerto = pack.obtienePuerto();
	return msg;
}
void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
	//Llenado de datos
	requestId++;
	msg->messageType = 1;	
	msg->requestId = requestId;	
	memcpy(msg->IP, ipCliente, strlen(ipCliente));
	msg->puerto = puertoCliente;
	msg->operationId = 5;
	int len = strlen(respuesta);
	strcpy(msg->arguments, respuesta);
	//Enviar los datos
	PaqueteDatagrama pack((char *)	msg, 3*sizeof(int)+LON_IP+sizeof(unsigned int)+ len, ipCliente, puertoCliente);
	socketlocal->envia(&pack);
	return;
}