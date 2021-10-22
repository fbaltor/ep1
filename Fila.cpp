#include "Fila.h"

using namespace std;

Fila::Fila(int tamanho) : tamanho(tamanho) {
  fila = new Datagrama *[tamanho];
  inicio = 0;
  quantidade = 0;
}

Fila::~Fila() {
  for (int i = 0; i < quantidade; i++) {
    int pos = (inicio + i) % tamanho;
    delete fila[pos];
  }
  delete[] fila;
}

bool Fila::enqueue(Datagrama *d) {
  if (quantidade >= tamanho)
    return false;

  quantidade++;
  int final = (inicio + quantidade) % tamanho;
  fila[final] = d;
  return true;
}

Datagrama *Fila::dequeue() {
  if (isEmpty())
    return NULL;

  Datagrama *inicial =
      new Datagrama(fila[inicio]->getOrigem(), fila[inicio]->getDestino(),
                    fila[inicio]->getDado());

  delete fila[inicio];

  inicio = (inicio + 1) % tamanho;
  quantidade--;

  return inicial;
}

bool Fila::isEmpty() { return quantidade; }

int Fila::getSize() { return quantidade; }

void Fila::imprimir() {}
