/* Lista Duplamente Encadeada */ 

#include <iostream>
#include <string>
#include "ListaDup.h"

// ******************************************************

cListaDupEnc::cListaDupEnc() { //funcionando
	inicio = NULL;
	fim = NULL;
	numElem = 0;
}

// ******************************************************

cListaDupEnc::cListaDupEnc(const cListaDupEnc &l) {
	if (this != &l)	{ //para não se auto copiar
       	cNo* novoNo = new cNo;
		cNo* noCorrente; //ponteiro pra percorrer a lista

		if (l.inicio == NULL) {
			inicio = NULL;
			fim = NULL;
			numElem = 0;
		}
		else{ //teste começa agr
			noCorrente = l.inicio; //noCorrente aponta pra listar a ser copiada
			numElem = l.numElem;
			inicio = new cNo(*l.inicio); //criar inicio da nova lista
			fim = inicio; //como só possui 1 elemento, fim e inicio são iguais
			noCorrente = noCorrente->getProx(); //noCorrente vai apontar pro proximo elemento da lista a ser copiada
		
	    	//copia o resto da lista
			while (noCorrente != NULL){
				novoNo = new cNo(*noCorrente);
				novoNo->setAnte(fim);
				fim->setProx(novoNo);
				fim = novoNo;
				numElem++;
				noCorrente = noCorrente->getProx();
			}	
	 	}
	}
}	

// ******************************************************

cListaDupEnc::~cListaDupEnc() { //funcionando
	cNo* noCorrente = inicio;
	while( noCorrente != NULL ) {
    	cNo* noProx = noCorrente->getProx();
    	delete noCorrente;
    	noCorrente = noProx;
    	numElem--;
	}
	inicio = NULL;
}

// ******************************************************

bool cListaDupEnc::InsereElemInicio(std::string nomeArtista, std::string nomeAlbum, std::string generoAlbum, std::string anoAlbum, std::string nomeMusica, std::string duracaoMusica, std::string classificacaoMusica, std::string reproducoesMusica, std::string dataDeAdicao, std::string ultimaReproducao) { //recebe todos os parametros
	cNo* noNovo = new cNo(nomeArtista, nomeAlbum, generoAlbum, anoAlbum, nomeMusica, duracaoMusica, classificacaoMusica, reproducoesMusica, dataDeAdicao, ultimaReproducao);
	if(inicio == NULL){
		inicio = noNovo;
		fim = noNovo;
	}
	else{
		inicio->setAnte(noNovo);
		noNovo->setProx(inicio);
		inicio = noNovo;
	}
	numElem++;
	return true;
}

// ******************************************************

bool cListaDupEnc::InsereElemFim(std::string nomeArtista, std::string nomeAlbum, std::string generoAlbum, std::string anoAlbum, std::string nomeMusica, std::string duracaoMusica, std::string classificacaoMusica, std::string reproducoesMusica, std::string dataDeAdicao, std::string ultimaReproducao) { //recebe todos os parametros
	cNo* noNovo = new cNo(nomeArtista, nomeAlbum, generoAlbum, anoAlbum, nomeMusica, duracaoMusica, classificacaoMusica, reproducoesMusica, dataDeAdicao, ultimaReproducao);
	if(inicio == NULL){
		inicio = noNovo;
		fim = noNovo;
	}
	else{
		fim->setProx(noNovo);
		noNovo->setAnte(fim);
		fim = noNovo;
	}
	numElem++;
	return true;
}	

// ******************************************************

bool cListaDupEnc::InsereElemFim(cNo *novo) {
  if(inicio == NULL) {
    novo->setProx(NULL);
    novo->setAnte(NULL);
    inicio = novo;
    fim = novo;
  }
  else {
    novo->setProx(NULL);
    novo->setAnte(fim);
    fim->setProx(novo);
    fim = novo;
  }
  numElem++;
  return true;
}	

// ******************************************************

bool cListaDupEnc::BuscaElem(std::string nomeMusica, cNo** no, cNo** noProx, cNo** noAnte) { //funcionando
	if(inicio == NULL && fim == NULL)
		return false;
	else if(inicio->getNomeMusica() == nomeMusica){
		*no = inicio;
		*noProx = inicio->getProx();
		*noAnte = NULL;
		return true;
	}
	else if(fim->getNomeMusica() == nomeMusica){
		*no = fim;
		*noProx = NULL;
		*noAnte = fim->getAnte();
		return true;
	}
	cNo* noCorrente = inicio->getProx();
	while(noCorrente->getProx() != NULL && noCorrente->getNomeMusica() != nomeMusica){
		noCorrente = noCorrente->getProx();
	}
	if(noCorrente->getNomeMusica() == nomeMusica){
		*no = noCorrente;
		*noProx = noCorrente->getProx();
		*noAnte = noCorrente->getAnte();
		return true;
	}
	return false;
}

// ******************************************************

bool cListaDupEnc::RemoveElem(std::string nomeMusica)	{ //funcionando
	cNo* no;
	cNo* noProx;
	cNo* noAnte;
	if(BuscaElem(nomeMusica, &no, &noProx, &noAnte)){
		if(no == inicio)
			this->RemoveElemInicio();
		else if(no == fim)
			this->RemoveElemFim();
		else{
			noAnte->setProx(noProx);
			noProx->setAnte(noAnte);
			delete no;
		}
		numElem--;
		return true;
	}
	return false;
}

// ******************************************************

bool cListaDupEnc::RemoveElemInicio() { //funcionando
	if(inicio == NULL && fim == NULL)
		return false;
	cNo* no = inicio;
	inicio = inicio->getProx();
	inicio->setAnte();
	numElem--;
	delete no;
	return true;
}

// ******************************************************

bool cListaDupEnc::RemoveElemFim() { //funcionando
	if(inicio == NULL && fim == NULL)
		return false;
	cNo* no = fim;
	fim = fim->getAnte();
	fim->setProx();
	numElem--;
	delete no;
	return true;
}

// ******************************************************

void cListaDupEnc::ImprimirLista() { //funcionando
	std::cout << "\n\tMusica   -    Adicao    -   Ultima Reproducao" << std::endl;
	if(inicio == NULL) 
		std::cout << "\tNão há músicas na lista." << std::endl;
	cNo* noCorrente = inicio;
	while(noCorrente != NULL){
		std::cout << "\t" << noCorrente->getNomeMusica() << " - " << noCorrente->getDataDeAdicao() << " - " << noCorrente->getUltimaReproducao() << std::endl;
		noCorrente = noCorrente->getProx();	
	}
	std::cout << std::endl;
}

// ******************************************************

int cListaDupEnc::getTamanho() {
	return numElem;
}

// ******************************************************

cNo* cListaDupEnc::getInicio(){
	return inicio;
}

// ******************************************************

cNo* cListaDupEnc::getFim(){
	return fim;
	
}

// ******************************************************

void cListaDupEnc::setInicio(cNo *novo) {
  inicio = novo;
}

// ******************************************************

void cListaDupEnc::setFim(cNo *novo) {
  fim = novo;
}

// ******************************************************

void cListaDupEnc::setTamanho(int novo) {
  numElem = novo;
}
