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

int main() {
  Roteador *r1 = new Roteador(1);
  Roteador *r2 = new Roteador(2);
  Roteador *r3 = new Roteador(3);
  Roteador *r4 = new Roteador(4);
  Roteador *r5 = new Roteador(5);
  Roteador *r6 = new Roteador(6);

  Rede *rede = new Rede(6);

  rede->adicionar(r1);
  rede->adicionar(r2);
  rede->adicionar(r3);
  rede->adicionar(r4);
  rede->adicionar(r5);
  rede->adicionar(r6);

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

  Agendador *agendador = new Agendador(1, rede, 10);

  int opcao;

  int roteadorOrigem;
  int roteadorDestino;
  int instante;
  string mensagem;
  Datagrama *datagrama;

  int quantidadeDeTempo;
  do {
    cout << "Simulador de Rede" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opção:" << endl;
    cin >> opcao;
    cout << endl;

    if (opcao == 1) {
      cout << "Endereco do roteador de origem: " << endl;
      cin >> roteadorOrigem;
      cout << "Instante: " << endl;
      cin >> instante;
      cout << "Endereco de destino: " << endl;
      cin >> roteadorDestino;
      cout << "Mensagem: " << endl;
      cin >> mensagem;

      if (roteadorOrigem < 1 || roteadorOrigem > 6)
        cout << "Erro: origem desconhecida" << endl;

      Datagrama *datagrama =
          new Datagrama(roteadorOrigem, roteadorDestino, mensagem);

      if (!agendador->agendar(instante, rede->getRoteador(roteadorOrigem),
                              datagrama))
        cout << "Erro: Sem espaco para agendar evento" << endl;
    }

    if (opcao == 2) {
      cout << "Quantidade de tempo: " << endl;
      cin >> quantidadeDeTempo;

      for (int tempo = 1; tempo <= quantidadeDeTempo; tempo++) {
        cout << "Instante " << agendador->getInstante() << endl;
        cout << "---" << endl;
        agendador->processar();
      }
    }

  } while (opcao);

  return 0;
}
