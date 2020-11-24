/* No da Lista Duplamente Encadeada */ 

#include<iostream>
#include <string>

class cNo {
	private:
		std::string 	nomeArtista;
		std::string 	nomeAlbum;
		std::string 	generoAlbum;
		std::string	anoAlbum;
		std::string 	nomeMusica;
		std::string	duracaoMusica;
		std::string	classificacaoMusica;
		std::string	reproducoesMusica;
		std::string 	dataDeAdicao;
		std::string	ultimaReproducao;
		
		cNo* prox;
		cNo* ante;
		
	public:
		cNo();
		cNo(std::string nomeArtista, std::string nomeAlbum, std::string generoAlbum, std::string anoAlbum, std::string nomeMusica, std::string duracaoMusica, std::string classificacaoMusica, std::string reproducoesMusica, std::string dataDeAdicao, std::string ultimaReproducao);
		cNo(const cNo &n);
		~cNo();
		
		void setNomeArtista(std::string nomeArtista);
		void setNomeAlbum(std::string nomeAlbum);
		void setGeneroAlbum(std::string generoAlbum);
		void setAnoAlbum(std::string anoAlbum);
		void setNomeMusica(std::string nomeMusica);
		void setDuracaoMusica(std::string duracaoMusica);
		void setClassificacaoMusica(std::string classificacaoMusica);
		void setReproducoesMusica(std::string reproducoesMusica);
		void setDataDeAdicao(std::string dataDeAdicao);
		void setUltimaReproducao(std::string ultimaReproducao);
		void setProx(cNo* p);
		void setProx();
		void setAnte(cNo* a);
		void setAnte();
		
		std::string 	getNomeArtista();
		std::string 	getNomeAlbum();
		std::string 	getGeneroAlbum();
		std::string 	getAnoAlbum();
		std::string 	getNomeMusica();
		std::string 	getDuracaoMusica();
		std::string 	getClassificacaoMusica();
		std::string 	getReproducoesMusica();
		std::string 	getDataDeAdicao();
		std::string 	getUltimaReproducao();
		cNo* 		getProx();
		cNo* 		getAnte();
		
};

