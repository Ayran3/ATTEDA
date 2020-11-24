#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "writeCSV.h"

using namespace std;

#define ASPAS 34
#define VIRGULA 44

// Se uma celula contém pelo menos uma virgula ela deve receber aspas no inicio e no final
// Assim como o padrão do arquivo csv prevê para essa situação
string verificaSeDeveTerAspas(string celula){
    for(int i = 0; i < celula.size(); i++){
        if(celula[i] == VIRGULA){
            string celulaAlterada;
            celulaAlterada += ASPAS;
            celulaAlterada += celula;
            celulaAlterada += ASPAS;
            return celulaAlterada;
        }
    }
    return celula;
};

// Altera a string das células que tem data, que foram alteradas durante o parser (para ordenação)
// para o formato original do arquivo: AAAA/MM/DD -> DD/MM/AAAA
string retornaDataParaFormatoOriginal(string celula){
    string auxEspelhaData;
    if(celula.size() > 1) {
        auxEspelhaData = celula.substr(8, 2);
        auxEspelhaData += celula.substr(4, 4);
        auxEspelhaData += celula.substr(0, 4);
        auxEspelhaData += celula.substr(10);
        return auxEspelhaData;
    } else {
        return celula;
    }
};

// Tem finalidade de estruturar e retornar como saída um arquivo .csv a partir de uma lista
//  Tem que mudar para receber uma lista duplamente encadeada
void criarArquivoCSV(vector<string>& split){
    ofstream out("tester.csv");
    string varredura;

    int controleDataAdicao = 19;
    int controleDataUltimaReproducao = 20;

    for(int i = 0; i < split.size(); i++){
        varredura = verificaSeDeveTerAspas(split[i]);
        if((i+1)%controleDataAdicao == 0){
            varredura = retornaDataParaFormatoOriginal(varredura);
            controleDataAdicao+=10;
        }
        if((i+1)%controleDataUltimaReproducao == 0){
            varredura = retornaDataParaFormatoOriginal(varredura);
            controleDataUltimaReproducao+=10;
        }
        out << varredura;
        if((i+1)%10 != 0) 
            out << ",";
        else 
            if(i != (split.size() - 1)) out << endl;
    }
};
