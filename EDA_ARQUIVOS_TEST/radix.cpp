#include "ListaDup.h"
#include "radix.h"
#include <string.h>
using namespace std;


void invert(cListaDupEnc* Lista) {
  cNo* aux = Lista->getInicio();
  cNo* aux2 = Lista->getFim();
  Lista->setInicio(aux2);
  Lista->setFim(aux);

  while(aux != NULL) {
    cNo* aux3 = aux->getAnte();
    aux->setAnte(aux->getProx());
    aux->setProx(aux3);
    aux = aux->getAnte();
  }
}

void radixGenerico(cListaDupEnc* Lista, int parametroOrdem, int tamanhoEntrada, bool inverte) {
  string stringOrdem; //String pela qual o radix vai ordenar. 
  cNo* baldes[11]; //buckets 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
  int maxTam =  0; //Tamanho da maior string do parametro pra ser ordenado (seja Data Adicao, Ultima Reproducao etc).

  cNo* aux1 = Lista->getInicio(); //Auxiliar para percorrer a lista.

//Toda essa parte so vai servir pra achar a maior string do parametro passado e armazenar em maxTam.
  while(aux1 != NULL) {
    if (parametroOrdem == 1) {
      stringOrdem = aux1->getDataDeAdicao();
    }
    else if(parametroOrdem == 2) {
      stringOrdem = aux1->getUltimaReproducao();
    }
    else if(parametroOrdem == 3) {
      stringOrdem = aux1->getClassificacaoMusica();
    }
    else if(parametroOrdem == 4) {
      stringOrdem = aux1->getReproducoesMusica();
    }
    if(stringOrdem.length() > maxTam) {
      maxTam = stringOrdem.length();
    }
    aux1 = aux1->getProx();
  }
//=========================================================================================================.

  for (int digito = maxTam - 1; digito >= 0; digito--) { //Faz a contagem dos digitos da string, nesse sentido: <------.
    aux1 = Lista->getInicio();    //Sempre que terminar a ordenacao por um digito, aux1 armazena o comeco da lista.
    Lista->setInicio(NULL);       // A lista  e tratada como vazia durando a ordenacao.
    Lista->setFim(NULL);
    Lista->setTamanho(0);
   

    for (int i = 0;i < 11;i++) {   // set todos os buckts para NULL.
      baldes[i] = NULL;
    }

    //Aque set a string pela qual o radix vai ordenar, e ai essa estring e relacionado ao parametro, Data Adicao, Ultima repro etc
    for (int i = 0; i < tamanhoEntrada;i++) {
      if (parametroOrdem == 1) {
      stringOrdem = aux1->getDataDeAdicao();
      }
      else if(parametroOrdem == 2) {
        stringOrdem = aux1->getUltimaReproducao();
      }
      else if(parametroOrdem == 3) {
        stringOrdem = aux1->getClassificacaoMusica();
      }
      else if(parametroOrdem == 4) {
        stringOrdem = aux1->getReproducoesMusica();
      }
      //Se for ordenar pelo parametro 1 e 2, eu verifico se a hora esta no formato 00:00, se estiver em 0:00, eu acrescento um zero, para manter a string uniforme e assim facilita na ordenacao.
      if(parametroOrdem == 2 || parametroOrdem == 1) {
        if(stringOrdem.length() >= 15) {
          stringOrdem.insert(11, "0");
        }
      }
      //Caso seja parametro simples como o 3 e o 4, eu so acresento o 0 para iqualar o tamanho da string tipo, se eu comparo 100 com 6, eu deixo 100 e 006.
      else {
        if(stringOrdem != "" && stringOrdem.length() < maxTam) {
          for (int k = stringOrdem.length(); k < maxTam;k++) {
            stringOrdem = "0" + stringOrdem;
          }
        }
      }

    //Aqui comeca a ordenacao de fato, se a string for vazia, eu jogo o No dela pro final do vetor, na posicao 10.
      if(stringOrdem == "") {
        //Se o vetor n tiver nada na posicao 10, eu coloco o No La.
        if(baldes[10] == NULL) {
          cNo* aux2 = NULL;
          if (aux1 != NULL) {
            cNo* aux2 = aux1->getProx();
            aux1->setProx(NULL);
            aux1->setAnte(NULL);
          }
          baldes[10] = aux1;
          aux1 = aux2;
        }
        else {
          //Se o vetor ja tiver alguma coisa na posicao 10 eu vou percorrendo o prox desse no ate achar um NULL, e ai eu coloco o novo No la, fica tipo assim.
          cNo* aux3 = baldes[10];                     //0:
          cNo* aux2 = aux1 ? aux1->getProx() : NULL;                //1:
          while(aux3->getProx() != NULL) {            //2:
            aux3 = aux3->getProx();                   //3:
          }                                           // ...
          aux1->setProx(NULL);                        //10: No1 -> No2 -> No3 -> No3
          aux1->setAnte(NULL);
          aux3->setProx(aux1);
          aux1 = aux2;
        }
      }
      else {
        //Se a gente n estiver lidando com uma string vazia, primeiro eu verifico se e um digito valido para ser analizado.
        //pq /, :, " " nao entrao na ordenacao.
        if(stringOrdem[digito] == '/' || stringOrdem[digito] == ':' || stringOrdem[digito] == ' ') {
          digito--;
        }
        //E ai eu faco a mesma coisa q eu fiz em cima, so que agora, eu coloco o No na cazinha certinha.
        //Por exemplo: se eu tenho o numero 2017, e eu to analizando o ultimo digito -> 7, ia ficar:

        //Esse if trata o caso em que o buckt ta vazio.
        if(baldes[stringOrdem[digito] - '0'] == NULL) {           //0:
          baldes[stringOrdem[digito] - '0'] = aux1;               //1:
          cNo* aux2 = aux1->getProx();                            //2:
          aux1->setAnte(NULL);                                    //3:
          aux1->setProx(NULL);                                    //...
          aux1 = aux2;                                            //7: No(2017) -> prox -> prox -> pipipipoppopo.
        }
        //Esse trata o caso em que o buck ja tinha uma mine lista.
        else if(baldes[stringOrdem[digito] - '0'] != NULL) {
          cNo* aux3 = baldes[stringOrdem[digito] - '0'];
          cNo* aux2 = aux1->getProx();
          aux1->setProx(NULL);
          aux1->setAnte(NULL);
          while(aux3->getProx() != NULL) {
            aux3 = aux3->getProx();
          }
          aux3->setProx(aux1);
          aux1 = aux2;
        }
      }
      if (aux1 == NULL) {
        aux1 = Lista->getInicio();
        Lista->ImprimirLista();
        if (Lista->getTamanho() == 0) break;
      }
    }
    //Ai aq eu desco a coluna do buckets e vou juntando as mine listas q eu formei, e coloco na lista original
    //a cade digito a lista fica um pouc + ordenada, e quando passa por todos os digitos, ela fica completamente ordenada.
    for(int i = 0; i < 11;i++) {
      
      cNo* aux4;                                             //0:No4                |
      cNo* aux5;                                             //1:No1->No2->No3      |
      if(baldes[i] != NULL) {                                //2:                   |
        aux4 = baldes[i];                                    //3:No5->No6           |
        aux5 = aux4->getProx();                              //...                  |
        Lista->InsereElemFim(aux4);                          //9:No7.               |
        while(aux5 != NULL) {                                //                     v
          aux4 = aux5;
          aux5 = aux5->getProx();
          Lista->InsereElemFim(aux4);                       //listaParcial = No4->No1->No2->No3->No5->No6->No7-> . . .
        }
      }
    }
  }
  if(inverte) {
    invert(Lista);
  }
}
