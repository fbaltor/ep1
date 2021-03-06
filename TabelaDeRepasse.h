#ifndef TABELA_DE_REPASSE_H
#define TABELA_DE_REPASSE_H

using namespace std;

#include "Roteador.h"
class Roteador;
#include <iostream>
#include <string>

class TabelaDeRepasse {
public:
  TabelaDeRepasse(int tamanho); // definir roteador padrão como NULL e atraso
                                // padrão como 0.

  ~TabelaDeRepasse(); // destruir os vetores alocados, mas manter os roteadores
                      // adicionados ao vetor.
  bool mapear(
      int endereco, Roteador *adjacente,
      int atraso); // colocar o endereço como parâmetro do roteador e do atraso.
  // se o endereço já estiver na tabela ou se a tabela já tiver no tamanho max:
  // return false; se o mapeamento ocorrer normalmente: return true;

  Roteador **getAdjacentes(); // retorna um vetor de roteadores (é possível que
                              // um roteador apareça várias vezes no vetor).

  int getQuantidadeDeAdjacentes(); // é a quantidade de elementos do vetor de
                                   // roteadores (quantidade de elementos
                                   // considera repetições).

  void setPadrao(Roteador *padrao,
                 int atraso); // deve definir o roteador padrão (destino p/ end.
                              // não mapeados) da a tabela e seu atraso.

  Roteador *getProximoSalto(
      int endereco,
      int &atraso); // ler o último parágrafo da página 6 do enunciado.

  void imprimir();

private:
  int tamanho; // número máximo de endereços de destino.
  int quantidade;
  int *enderecos;
  int *atrasos;
  Roteador **roteadoresAdjacentes;
  Roteador *roteadorPadrao;
  int atrasoPadrao;
};
#endif
