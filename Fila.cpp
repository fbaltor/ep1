#include "Fila.h"

using namespace std;

Fila::Fila(int tamanho) : tamanho(tamanho) {
  fila = new Datagrama *[tamanho];
  inicio = 0;
  final = 0;
}

Fila::~Fila() {}

bool Fila::enqueue(Datagrama *d) {}

Datagrama *Fila::dequeue() {}

bool Fila::isEmpty() {}

int Fila::getSize() {}

void imprimir() {}
