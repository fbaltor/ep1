#include "Evento.h"

#define TAMANHO 10

using namespace std;

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
};
