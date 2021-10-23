#include "Agendador.h"
#include "Datagrama.h"
#include "Evento.h"
#include "Fila.h"
#include "Rede.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include <iostream>
#include <string>

using namespace std;

void rede_enunciado() {
  Roteador *r1 = new Roteador(1);
  Roteador *r2 = new Roteador(2);
  Roteador *r3 = new Roteador(3);
  Roteador *r4 = new Roteador(4);
  Roteador *r5 = new Roteador(5);
  Roteador *r6 = new Roteador(6);

  Rede *rede_enunciado = new Rede(6);

  rede_enunciado->adicionar(r1);
  rede_enunciado->adicionar(r2);
  rede_enunciado->adicionar(r3);
  rede_enunciado->adicionar(r4);
  rede_enunciado->adicionar(r5);
  rede_enunciado->adicionar(r6);

  r1->mapear(2, r2, 2);
  r2->mapear(1, r1, 2);
  r3->mapear(1, r1, 1);
  r3->mapear(5, r5, 2);
  r4->mapear(2, r2, 1);
  r4->mapear(6, r6, 1);
  r5->mapear(6, r6, 2);
  r6->mapear(5, r5, 2);
  r1->setPadrao(r3, 1);
  r2->setPadrao(r4, 1);
  r3->setPadrao(r4, 1);
  r4->setPadrao(r3, 1);
  r5->setPadrao(r3, 2);
  r6->setPadrao(r4, 1);

  // criar agendador

  int numero;
  cout << "Simulador de Rede" << endl;
  cout << "1) Enviar um datagrama" << endl;
  cout << "2) Passar tempo" << endl;
  cout << "0) Sair" << endl;
  cout << "Escolha uma opção:" << endl;
  cin >> numero;
  cout << endl;

  if (numero == 1) {
  }
}
