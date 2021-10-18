#include <string>

using namespace std;

class Datagrama {
public:
  Datagrama(int origem, int destino, string dado);
  ~Datagrama();
  int getOrigem();
  int getDestino();
  string getDado();

  void imprimir();

private:
  int origem;
  int destino;
  string dado;
};
