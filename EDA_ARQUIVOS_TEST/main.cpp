#include <map>
#include <functional>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "ListaDup.h"
#include "constroiLista.h"
#include "csvParser.h"
#include "listas2e3.h"

using namespace std;

typedef map<string, function<void(void)> > command_dict;

void refresh() { cout << "recarregou" << endl; /* Inserir Refresh */ }
void quit() { cout << "saiu" << endl; /* Inserir Quit */ }

int main() {
  /* command_dict c;
  c["r"] = &refresh;
  c["q"] = &quit; */

  cListaDupEnc Lista1;
  cListaDupEnc Lista2;// playlist 2
  
  cListaDupEnc Lista3; // playlist 3
  cListaDupEnc Lista4;
  cout << "flag" << endl;
  ifstream file("MusicDataBase-G3.csv"); // Base de dados
  cout << "flag" << endl;
  vector<string> baseDeDados;
  cout << "flag" << endl;
  
  baseDeDados = splitCSV(file);
  cout << "flag" << endl;
  
  constroiListaComBaseDeDados(baseDeDados, &Lista1);
  constroiListaComBaseDeDados(baseDeDados, &Lista4);
  cout << "flag" << endl;
  
  Lista1.RemoveElemInicio();
  radixGenerico(&Lista1, 1, Lista1.getTamanho(), false);
  cNo* aux = Lista1.getInicio();
  int tamanhoPlaylist = 10;
  int contador = 0;
  for (int i = 0; i < Lista1.getTamanho();i++) {
    if(contador <= tamanhoPlaylist) {
      Lista2.InsereElemFim(aux->getNomeArtista(), aux->getNomeAlbum(), aux->getGeneroAlbum(), aux->getAnoAlbum(), aux->getNomeMusica(), aux->getDuracaoMusica(), aux->getClassificacaoMusica(), aux->getReproducoesMusica(), aux->getDataDeAdicao(), aux->getUltimaReproducao());
      contador++;
    }
    aux = aux->getProx();
  }
  cout <<"===================================================================================="<<endl;
  contador = 0;
  cout <<"As faixas mais recentemente incluidas na base de dados"<<endl;
  Lista2.ImprimirLista();


  Lista4.RemoveElemInicio();
  cout <<"Flag antes"<<endl;
  radixGenerico(&Lista4, 2, Lista4.getTamanho(), true);
  cout <<"Flag Depois"<<endl;
  cNo* aux10 = Lista4.getInicio();
  for (int k = 0; k < Lista4.getTamanho();k++) {
      if(contador <= tamanhoPlaylist && aux10->getUltimaReproducao() != "") {
        Lista3.InsereElemFim(aux10->getNomeArtista(), aux10->getNomeAlbum(), aux10->getGeneroAlbum(), aux10->getAnoAlbum(), aux10->getNomeMusica(), aux10->getDuracaoMusica(), aux10->getClassificacaoMusica(), aux10->getReproducoesMusica(), aux10->getDataDeAdicao(), aux10->getUltimaReproducao());
        contador++;
      }
      aux10 = aux10->getProx();
  }
  cout <<"===================================================================================="<<endl;
  cout <<"As faixas que foram reproduzidas mais recentemente."<<endl;
  Lista3.ImprimirLista();


}
