#include "Roteador.h"
#include <iostream>

Roteador::Roteador(int endereco) : endereco(endereco) {
  tabela = new TabelaDeRepasse(TAMANHO);
  fila = new Fila(TAMANHO);
}

Roteador::~Roteador() {
  delete tabela;
  delete fila;
}

bool Roteador::mapear(int endereco, Roteador *adjacente, int atraso) {
  return tabela->mapear(endereco, adjacente, atraso);
}

void Roteador::setPadrao(Roteador *padrao, int atraso) {
  tabela->setPadrao(padrao, atraso);
}

int Roteador::getEndereco() { return endereco; }

void Roteador::receber(Datagrama *d) {
  if (!fila->enqueue(d))
    cout << "\tFila em " << endereco << " estourou" << endl;
}

Evento *Roteador::processar(int instante) {
  if (fila->isEmpty())
    return NULL;

  cout << "Roteador " << endereco << endl;

  Datagrama *processado = fila->dequeue();

  if (processado->getDestino() == endereco) {
    cout << "\tRecebido: " << processado->getDado() << endl;
    delete processado;
    return NULL;
  }

  int atraso = 0;
  Roteador *proximo = tabela->getProximoSalto(processado->getDestino(), atraso);

  if (proximo == NULL) {
    cout << "\tSem proximo: "
         << "Origem: " << processado->getOrigem() << ", "
         << "Destino: " << processado->getDestino() << ", "
         << processado->getDado() << endl;
    delete processado;
    return NULL;
  }

  int instanteFinal = instante + atraso;
  cout << "\tRepassando para " << proximo << "(instante " << instanteFinal
       << "): "
       << "Origem: " << processado->getOrigem() << ", "
       << "Destino: " << processado->getDestino() << ", "
       << processado->getDado() << endl;

  return new Evento(instanteFinal, proximo, processado);
}
