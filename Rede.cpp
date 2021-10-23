#include "Rede.h"

Rede::Rede(int tamanho) : tamanho(tamanho) {
  roteadores = new Roteador *[tamanho];
}

Rede::~Rede() {
  for (int i = 0; i < tamanho; i++)
    delete roteadores[i];

  delete[] roteadores;
}

bool Rede::adicionar(Roteador *r) {
  if (quantidade == tamanho)
    return false;

  for (int i = 0; i < quantidade; i++)
    if (roteadores[i]->getEndereco() == r->getEndereco())
      return false;

  roteadores[quantidade++] = r;
  return true;
}

Roteador *Rede::getRoteador(int endereco) {
  for (int i = 0; i < quantidade; i++)
    if (roteadores[i]->getEndereco() == endereco)
      return roteadores[i];

  return NULL;
}

Roteador **Rede::getRoteadores() { return roteadores; }

int Rede::getQuantidade() { return quantidade; }
