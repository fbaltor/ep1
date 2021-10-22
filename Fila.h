#include "Datagrama.h"
#include <string>

using namespace std;

class Fila {
public:
  Fila(int tamanho);
  ~Fila();

  bool enqueue(Datagrama *d); // adicionar elemento (fim).
  Datagrama *dequeue();       // remover elemento (início).
  bool isEmpty(); // verificar se a fila está vazia (return true) ou não (return
                  // false).
  int getSize(); // informar o número de datagramas da fila.
  void imprimir();

private:
  int tamanho;
  Datagrama **fila;
  int inicio;
  int final;
};
