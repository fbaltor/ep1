#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse(int tamanho) : tamanho(tamanho) {
  roteadoresAdjacentes = new Roteador *[tamanho];
  enderecos = new int[tamanho];
  atrasos = new int[tamanho];

  quantidade = 0;

  roteadorPadrao = NULL;
  atrasoPadrao = 0;
}

TabelaDeRepasse::~TabelaDeRepasse() {
  delete[] roteadoresAdjacentes;
  delete[] atrasos;
  delete[] enderecos;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador *adjacente, int atraso) {
  if (quantidade == tamanho)
    return false;

  for (int i = 0; i < quantidade; i++)
    if (enderecos[i] == endereco)
      return false;

  return true;
}

Roteador **TabelaDeRepasse::getAdjacentes() { return roteadoresAdjacentes; }

int TabelaDeRepasse::getQuantidadeDeAdjacentes() { return quantidade; }

void TabelaDeRepasse::setPadrao(Roteador *padrao, int atraso) {
  roteadorPadrao = padrao;
  atrasoPadrao = atraso;
}

Roteador *TabelaDeRepasse::getProximoSalto(int endereco, int &atraso) {
  for (int i = 0; i < quantidade; i++)
    if (enderecos[i] == endereco) {
      atraso = atrasos[i];
      return roteadoresAdjacentes[i];
    }

  atraso = atrasoPadrao;
  return roteadorPadrao;
}

void TabelaDeRepasse::imprimir() {}
