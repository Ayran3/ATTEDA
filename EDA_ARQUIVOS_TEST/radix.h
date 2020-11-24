#ifndef RADIX_H_INCLUDED
#define RADIX_H_INCLUDED

#include "ListaDup.h"


int getMax(cListaDupEnc* Lista, int parametroOrdem);
//ParametroOrdenacao(1 ou 2):
//  1 -> Ordena pela DataAdicao.
//  2 -> Ordena pela UltimaReproducao.
//  3 -> Ordena por Classificação Musical.
//  4 -> Ordena por Reproduções Musicais.
void radixGenerico(cListaDupEnc* Lista, int parametroOrdem, int tamanhoEntrada, bool inverte);

//Investe uma lista
void invert(cListaDupEnc* Lista);

/*Se precisar ordenar por outros parametros é só modificar um pouco das 2 primeiras funções
ou me fala que eu ajeito <3 <3 <3
*/
#endif
