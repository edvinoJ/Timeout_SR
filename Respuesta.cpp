#include "Respuesta.h"
Respuesta::Respuesta(int pl){
	socketlocal = new SocketDatagrama(pl);
	requestId = 0;
	contador =0;

}
struct mensaje * Respuesta::getRequest(void){
	struct mensaje * msg = (struct mensaje *) malloc(sizeof(mensaje));
	PaqueteDatagrama pack(sizeof(struct mensaje));
	socketlocal->recibe(&pack);
	msg = (struct mensaje *) pack.obtieneDatos();
	memcpy(msg->IP, pack.obtieneDireccion(), LON_IP);
	msg->puerto = pack.obtienePuerto();
	printf("VALUE:%d\n",msg-> operationId);
	printf("ARG:%s\n",msg->arguments);
	requestId = msg->requestId;
	return msg;
}
void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
	//Llenado de datos
	struct mensaje * msg = (struct mensaje *) malloc(sizeof(mensaje));
	msg->messageType = 1;	
	msg->requestId = requestId;	
	if(requestId == 50){
		msg->requestId = 10;
		if (contador>2){
			msg->requestId = 50;
			contador =0;
		}
		contador++;
	}
	printf("REQUEST ID:%d\n", msg->requestId);
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