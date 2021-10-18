#include "Datagrama.h"
#include <iostream>

Datagrama::Datagrama(int origem, int destino, string dado)
    : origem(origem), destino(destino), dado(dado) {}

Datagrama::~Datagrama() {}

int Datagrama::getOrigem() { return origem; }

int Datagrama::getDestino() { return destino; }

string Datagrama::getDado() { return dado; }

void Datagrama::imprimir() {
  cout << "Datagrama com origem (" << origem << ")"
       << " destino (" << destino << ")"
       << " e dado(" << dado << ")";
}
