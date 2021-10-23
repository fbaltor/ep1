#ifndef REDE_H
#define REDE_H

using namespace std;

#include "Roteador.h"

class Rede {
public:
  Rede(int tamanho);
  ~Rede();

  bool adicionar(Roteador *r);
  Roteador *getRoteador(int endereco);

  Roteador **getRoteadores();
  int getQuantidade();

  void imprimir();

private:
  int tamanho;
  Roteador **roteadores;
  int quantidade;
};

#endif
