#include "Roteador.h"

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

  Datagrama *processado = fila->dequeue();

  if (processado->getDestino() == endereco) {
    delete processado;
    return NULL;
  }

  int atraso = 0;
  Roteador *proximo = tabela->getProximoSalto(processado->getDestino(), atraso);

  if (proximo == NULL) {
    delete processado;
    return NULL;
  }

  return new Evento(instante + atraso, proximo, processado);
}
