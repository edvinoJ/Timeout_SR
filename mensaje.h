#define TAM_MAX_DATA 4000
#define LON_IP 16
#include <cstdlib>
struct mensaje{
	int messageType;
	unsigned int requestId;
	char IP[LON_IP];
	int puerto;
	int operationId;
	char arguments[TAM_MAX_DATA];
};