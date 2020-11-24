/* No da Lista Duplamente Encadeada */ 

#include <iostream>
#include <string>

#include "No.h"

// ******************************************************

cNo::cNo() {
	nomeArtista = "";
	nomeAlbum = "";
	generoAlbum = "";
	anoAlbum = "";
	nomeMusica = "";
	duracaoMusica = "";
	classificacaoMusica = "";
	reproducoesMusica = "";
	dataDeAdicao = "";
	ultimaReproducao = "";
	prox = NULL;
	ante = NULL;
}

// ******************************************************

cNo::cNo(std::string nomeArtista, std::string nomeAlbum, std::string generoAlbum, std::string anoAlbum, std::string nomeMusica, std::string duracaoMusica, std::string classificacaoMusica, std::string reproducoesMusica, std::string dataDeAdicao, std::string ultimaReproducao) {
	this->nomeArtista = nomeArtista;
	this->nomeAlbum = nomeAlbum;
	this->generoAlbum = generoAlbum;
	this->anoAlbum = anoAlbum;
	this->nomeMusica = nomeMusica;
	this->duracaoMusica = duracaoMusica;
	this->classificacaoMusica = classificacaoMusica;
	this->reproducoesMusica = reproducoesMusica;
	this->dataDeAdicao = dataDeAdicao;
	this->ultimaReproducao = ultimaReproducao;
	this->prox = NULL;
	this->ante = NULL;
}

// ******************************************************

cNo::cNo(const cNo &n) {
	nomeArtista = n.nomeArtista;
	nomeAlbum = n.nomeAlbum;
	generoAlbum = n.generoAlbum;
	anoAlbum = n.anoAlbum;
	nomeMusica = n.nomeMusica;
	duracaoMusica = n.duracaoMusica;
	classificacaoMusica = n.classificacaoMusica;
	reproducoesMusica = n.reproducoesMusica;
	dataDeAdicao = n.dataDeAdicao;
	ultimaReproducao = n.ultimaReproducao;
	prox = NULL;
	ante = NULL;
}

// ******************************************************

cNo::~cNo() {
	
}

// ******************************************************

void cNo::setNomeArtista(std::string d) {
	nomeArtista = d;
}

// ******************************************************

void cNo::setNomeAlbum(std::string d) {
	nomeAlbum = d;
}

// ******************************************************

void cNo::setGeneroAlbum(std::string d) {
	generoAlbum = d;
}

// ******************************************************

void cNo::setAnoAlbum(std::string d) {
	anoAlbum = d;
}

// ******************************************************

void cNo::setNomeMusica(std::string d) {
	nomeMusica = d;
}

// ******************************************************

void cNo::setDuracaoMusica(std::string d) {
	duracaoMusica = d;
}

// ******************************************************

void cNo::setClassificacaoMusica(std::string d) {
	classificacaoMusica = d;
}

// ******************************************************

void cNo::setReproducoesMusica(std::string d) {
	reproducoesMusica = d;
}

// ******************************************************

void cNo::setDataDeAdicao(std::string d) {
	dataDeAdicao = d;
}

// ******************************************************

void cNo::setUltimaReproducao(std::string d) {
	ultimaReproducao = d;
}

// ******************************************************

void cNo::setProx(cNo* p) {
	prox = p;
}

// ******************************************************

void cNo::setProx() { //para ajudar na remoção do ultimo elemento
	prox = NULL;
}

// ******************************************************

void cNo::setAnte(cNo* a) {
	ante = a;
}

// ******************************************************

void cNo::setAnte() { //para ajudar na remoção do primeiro elemento
	ante = NULL;
}

// ******************************************************

std::string  cNo::getNomeArtista(){
	return nomeArtista;
}

// ******************************************************

std::string  cNo::getNomeAlbum(){
	return nomeAlbum;
}

// ******************************************************

std::string  cNo::getGeneroAlbum(){
	return generoAlbum;
}

// ******************************************************

std::string  cNo::getAnoAlbum(){
	return anoAlbum;
}

// ******************************************************

std::string  cNo::getNomeMusica(){
	return nomeMusica;
}

// ******************************************************

std::string  cNo::getDuracaoMusica(){
	return duracaoMusica;
}

// ******************************************************

std::string  cNo::getClassificacaoMusica(){
	return classificacaoMusica;
}

// ******************************************************

std::string  cNo::getReproducoesMusica(){
	return reproducoesMusica;
}

// ******************************************************

std::string  cNo::getDataDeAdicao(){
	return dataDeAdicao;
}

// ******************************************************

std::string  cNo::getUltimaReproducao(){
	return ultimaReproducao;
}

// ******************************************************

cNo*  cNo::getProx() {
	return prox;
}

// ******************************************************

cNo*  cNo::getAnte() {
	return ante;
}

// ******************************************************

