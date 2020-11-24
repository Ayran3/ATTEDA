#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "csvParser.h"

using namespace std;

#define ASPAS 34
#define VIRGULA 44

// Muda um boolean de estado
bool mudaEstado(bool estado) {
    if(estado) return false;
    else return true;
};

// Realiza o espelhamento da data e retorna a string
string espelharData(string celula) {
    string auxEspelhaData;
    if(celula.size() > 1) {
        auxEspelhaData = celula.substr(6, 4);
        auxEspelhaData += celula.substr(2, 4);
        auxEspelhaData += celula.substr(0, 2);
        auxEspelhaData += celula.substr(10);
        return auxEspelhaData;
    } else {
        return celula;
    }
};

// Separa as linhas em células
vector<string> separaEmCelulas(vector<string>& linhas) {
    bool controleDeAspas = false;
    vector<string> splits;
    int tamanho = linhas.size();
    int quantidadeDeCelulas = 0;
    int localDataDeAdicao = 19;
    for(int i = 0; i < tamanho; i++) {
        string linhaLida = linhas[i];
        string celula;
        for(int j = 0; j < linhaLida.size(); j++) {
            if(linhaLida[j] == ASPAS) {
                controleDeAspas = mudaEstado(controleDeAspas);
            }
            if((linhaLida[j] == VIRGULA && !controleDeAspas)) {
                quantidadeDeCelulas++;
                if((quantidadeDeCelulas%(localDataDeAdicao)) == 0) {
                    celula = espelharData(celula);
                    localDataDeAdicao+= 10;
                }
                splits.push_back(celula);
                celula.clear();
            } 
            else {
                if(linhaLida[j] != ASPAS) {
                    celula.push_back(linhaLida[j]);
                }
            }
        }
        quantidadeDeCelulas++;
        if(quantidadeDeCelulas > 10) {
            celula = espelharData(celula);
        }
        splits.push_back(celula);
    }
    return splits;
};

// Lê o arquivo, separa-o em linhas e adiciona-as num vetor
vector<string> splitCSV(ifstream& file) {
    string extrator;
    vector<string> linhas;

    while(getline(file, extrator, '\n')) {
        linhas.push_back(extrator);
    }

    vector<string> celulas = separaEmCelulas(linhas); // cria um vetor com as células do arquivo
    return celulas;
};
