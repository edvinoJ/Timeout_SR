SOURCES = PaqueteDatagrama.cpp SocketDatagrama.cpp 
OBJECTS = PaqueteDatagrama.o SocketDatagrama.o 
LIB = -std=c++11

all: client server
client: $(OBJECTS) Solicitud.o Respuesta.o
	g++ $(LIB) Cliente.cpp $(OBJECTS) Solicitud.o -o cliente
	g++ $(LIB) Servidor.cpp $(OBJECTS) Respuesta.o -o server
$(OBJECTS):
	g++ -c $(SOURCES)
Solicitud.o:
	g++ -c $(LIB) Solicitud.cpp
Respuesta.o:
	g++ -c $(LIB) Respuesta.cpp
clean:
	rm *.o 
