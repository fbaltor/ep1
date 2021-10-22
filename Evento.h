#ifndef EVENTO_H
#define EVENTO_H

using namespace std;

#include "Datagrama.h"
#include "Roteador.h"
class Roteador;
#include <iostream>

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
                //
  Roteador *destino;
  Datagrama *d;
};
#endif
