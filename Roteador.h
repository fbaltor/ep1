#ifndef ROTEADOR_H
#define ROTEADOR_H
#define TAMANHO 10

using namespace std;

#include "Datagrama.h"
#include "Evento.h"
class Evento;
#include "Fila.h"
#include "TabelaDeRepasse.h"
class TabelaDeRepasse;

class Roteador {
public:
  Roteador(int endereco);
  ~Roteador();

  bool mapear(int endereco, Roteador *adjacente, int atraso);
  void setPadrao(Roteador *padrao, int atraso);

  int getEndereco();
  void receber(Datagrama *d);
  Evento *processar(int instante);

  void imprimir();

private:
  int endereco;
  TabelaDeRepasse *tabela;
  Fila *fila;
};
#endif
