#ifndef GRAFO_H
#define GRAFO_H
#include "MatrizEsparsa.h"
#include "tipoOrientacao.h"
#include <vector>
#include <string.h>
struct Vertice {
    unsigned int indice;
    char* nome;

    Vertice(int i, char* n)
    {
        this->indice = i;
        this->nome = n;
    }

    bool operator==(const Vertice& comparado)
    {
        return strcmp(this->nome,comparado.nome);
    }

    friend ostream& operator<<(ostream& os, const Vertice& v)
    {
        os << "{Indice: " << v.indice << ", nome: " << v.nome << " }";

        return os;
    }
};

class Grafo
{
    public:
        Grafo(unsigned int, tipoOrientacao);

        void addVertice(char*);
        void delVertice(char*);

        void addAresta(char*,char*,int);
        void delAresta(char*,char*);

        friend ostream& operator<< (ostream&, const Grafo&);

    protected:

    private:
        std::vector<Vertice> vertices;
        MatrizEsparsa<int>* arestas;
        tipoOrientacao tipo;
        unsigned int maxVertices;
        unsigned int indiceNovoVertice;


        void addNome(char*);
        void delNome(char*);

        int encontraVertice(char *);


};

#endif // GRAFO_H
