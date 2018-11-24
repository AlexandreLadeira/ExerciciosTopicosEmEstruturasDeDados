#ifndef GRAFO_H
#define GRAFO_H
#include "MatrizEsparsa.h"
#include "tipoOrientacao.h"
#include <vector>
#include <string.h>

class Grafo
{
    public:
        Grafo(tipoOrientacao);

        void addVertice(char*);
        void delVertice(char*);

        void addAresta(char*,char*,int);
        void delAresta(char*,char*);

        void montaOsGrafo(ostream&) const;
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
