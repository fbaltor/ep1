#include "Datagrama.h"
#include "Roteador.h"
#include <iostream>

using namespace std;

class Evento {
public:
  Evento(int instante, Roteador *destino,
         Datagrama *d); // recebe o instante em que a passagem do datagrama p/ o
                        // rot ocorre.
  ~Evento();            // não destruir o roteador nem o datagrama.
  int getInstante();
  Roteador *getDestino();
  Datagrama *getDatagrama();
  void imprimir();

private:
  int instante; // quando ocorre o evento de passagem do datagrama para o
                // roteador.
};
