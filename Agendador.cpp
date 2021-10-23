#include "Agendador.h"

Agendador::Agendador(int instanteInicial, Rede *rede, int tamanho)
    : instanteInicial(instanteInicial), rede(rede), tamanho(tamanho) {
  eventos = new Evento *[tamanho];
  quantidade = 0;
  instanteAtual = instanteInicial;
}

Agendador::~Agendador() {}

bool Agendador::agendar(int instante, Roteador *r, Datagrama *d) {
  if (quantidade == tamanho)
    return false;

  Evento *evento = new Evento(instante, r, d);

  eventos[quantidade++] = evento;
  return true;
}

void Agendador::processar() {

  Evento **eventosNaoProcessados = new Evento *[tamanho];
  int novaQuantidade = 0;
  for (int i = 0; i < quantidade; i++) {
    Evento *e = eventos[i];
    if (e->getInstante() != instanteAtual) {
      eventosNaoProcessados[novaQuantidade] = e;
    } else {
      Datagrama *d = e->getDatagrama();
      e->getDestino()->receber(d);

      delete d;
      delete e;
    }
    delete[] eventos;
  }
  eventos = eventosNaoProcessados;
  quantidade = novaQuantidade;

  Roteador **roteadores = rede->getRoteadores();
  int quantidadeDeRoteadores = rede->getQuantidade();
  for (int i = 0; i < quantidadeDeRoteadores; i++) {
    Evento *e = roteadores[i]->processar(instanteAtual);

    eventos[quantidade++] = e;
  }

  instanteAtual++;
}

int Agendador::getInstante() { return instanteAtual; }
