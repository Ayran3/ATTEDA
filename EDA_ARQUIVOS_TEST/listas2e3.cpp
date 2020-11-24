#include <iostream>
#include <string>
#include "radix.h"
#include "ListaDup.h"
#include "listas2e3.h"

#define tamanho_playlist 10

using namespace std;

void criarPlaylist2(cListaDupEnc* Lista1, cListaDupEnc* Lista2){ //Funcao para criar playlist 2
	radixGenerico(Lista1, 1, Lista1->getTamanho(), true); //Ordena a lista com todas as musicas pela data de adicao
	cNo* aux=Lista1->getInicio(); //No para percorrer a lista com todas as musicas
	for(int i=0;i<tamanho_playlist;i++){//adiciona a quantidade de elementos do tamanho da playlist
		if(Lista2->InsereElemFim(aux->getNomeArtista(), aux->getNomeAlbum(), aux->getGeneroAlbum(), aux->getAnoAlbum(), aux->getNomeMusica(), aux->getDuracaoMusica(), aux->getClassificacaoMusica(), aux->getReproducoesMusica(), aux->getDataDeAdicao(), aux->getUltimaReproducao())) //cria um novo no na lista da playlist2 com os mesmo valores do no da lista principal
			cout<<"A Musica foi adicionada na playlist2"<<endl;
		else
			cout<<"Nada foi adicionado"<<endl;
		if(aux->getProx() == NULL) //caso o próximo elemento da lista seja null, termina a função
			return;
		else
			aux=aux->getProx(); //continua para o proximo no
	}
}

void criarPlaylist3(cListaDupEnc* Lista1, cListaDupEnc* Lista2){ //Funcao para criar playlist 2
	radixGenerico(Lista1, 2, Lista1->getTamanho(), true); //Ordena a lista com todas as musicas pela ultima reproducao
	int count = 0; //contador para saber quantas musicas foram adicionadas na playlist
	cNo*aux=Lista1->getInicio(); //No para percorrer a lista com todas as musicas
	while(count<tamanho_playlist){//adiciona a quantidade de elementos do tamanho da playlist
		if(aux->getUltimaReproducao() != ""){//só tenta adicionar se a musica tiver sido reproduzida
			if(Lista2->InsereElemFim(aux->getNomeArtista(), aux->getNomeAlbum(), aux->getGeneroAlbum(), aux->getAnoAlbum(), aux->getNomeMusica(), aux->getDuracaoMusica(), aux->getClassificacaoMusica(), aux->getReproducoesMusica(), aux->getDataDeAdicao(), aux->getUltimaReproducao())) //cria um novo no na lista da playlist3 com os mesmo valores do no da lista principal
				cout<<"A Musica foi adicionada na playlist3"<<endl;
			else
				cout<<"Nada foi adicionado"<<endl;
			count++;
		}
		if(aux->getProx() == NULL) //caso o próximo elemento da lista seja null, termina a função
			return;
		else
			aux=aux->getProx(); //= Pegou o elemento atual da playlist e passou para o proximo
	}
}

