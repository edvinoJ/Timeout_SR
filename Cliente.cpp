#include "Solicitud.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	if(argc < 4){
		printf("Falta de argumentos %s dirIP puerto n°_operations\n", argv[0]);
		return -1;
	}
	Solicitud cliente1;
	int port = atoi(argv[2]);
	int numOp = atoi(argv[3]);
	int before, after;
	char * valor = (char *)"1";
	char * respuesta;
	for (int i = 0; i < numOp; i++){
		respuesta = NULL;
		respuesta = cliente1.doOperation (argv[1], port, 1, valor);
		printf("Lectura:%s\n", respuesta);
		before = atoi(respuesta);
		respuesta = NULL;
		respuesta = cliente1.doOperation (argv[1], port, 2, valor);
		printf("Escritura:%s\n", respuesta);
		after = atoi(respuesta);
		if((before+1) != after){
			printf("Incocistencia en los datos:\n");
			cliente1.doOperation (argv[1], port, 0, (char *)"0");
			return -1;
			break;
		}
		
	}
	return 0;
}