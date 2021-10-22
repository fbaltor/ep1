#define TAMANHO 10

class Roteador {
public:
  Roteador(int endereco);
  ~Roteador();
  bool mapear(int endereco, Roteador *adjacente, int atraso);
  void setPadrao(Roteador *padrao, int atraso);
  int getEndereco();
  void receber(Datagrama *d);
  Evento *processar(int instante);
  void imprimir();
};
