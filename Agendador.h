#ifndef AGENDADOR_H
#define AGENDADOR_H

using namespace std;

#include "Datagrama.h"
#include "Evento.h"
#include "Rede.h"
#include "Roteador.h"

class Agendador {
public:
  Agendador(int instanteInicial, Rede *rede, int tamanho);
  ~Agendador();

  bool agendar(int instante, Roteador *r, Datagrama *d);
  void processar();
  int getInstante();

private:
  int instanteInicial;
  Rede *rede;
  int tamanho;
  Evento **eventos;
  int quantidade;
  int instanteAtual;
};
#endif
