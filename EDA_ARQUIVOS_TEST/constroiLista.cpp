/* Constroi a Lista de Músicas com a base de dados retornada pelo Parser */

#include <iostream>
#include <fstream>
#include <vector>
#include "constroiLista.h"
#include "writeCSV.h"
#include "ListaDup.h"

using namespace std;

void constroiListaComBaseDeDados(vector<string>& celulas, cListaDupEnc* Lista1){
    string 	nomeArtista, nomeAlbum, generoAlbum, anoAlbum, nomeMusica, duracaoMusica,
    classificacaoMusica, reproducoesMusica, dataDeAdicao, ultimaReproducao;
    int controleDeCelulas = 10; // Quantidade de células por linha
    for(int i = 0; i < celulas.size(); i++) {
        switch ((i+1)%controleDeCelulas){
            case 1:
                nomeArtista = celulas[i];
                break;
            case 2:
                nomeAlbum = celulas[i];
                break;
            case 3:
                generoAlbum = celulas[i];
                break;
            case 4:
                anoAlbum = celulas[i];
                break;
            case 5:
                nomeMusica = celulas[i];
                break;
            case 6:
                duracaoMusica = celulas[i];
                break;
            case 7:
                classificacaoMusica = celulas[i];
                break;
            case 8:
                reproducoesMusica = celulas[i];
                break;
            case 9:
                dataDeAdicao = celulas[i];
                break;
            case 0:
                ultimaReproducao = celulas[i];
                Lista1->InsereElemFim(nomeArtista, nomeAlbum, generoAlbum, anoAlbum, 
                nomeMusica, duracaoMusica, classificacaoMusica,reproducoesMusica, 
                dataDeAdicao, ultimaReproducao); // Insere um elemento na lista
                break;     
        default:
            cout << "Erro" << endl;
            break;
        }
    }
};
