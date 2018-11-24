#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
struct Vertice {
    unsigned int indice;
    char* nome;

    Vertice(int i, char* n)
    {
        this->indice = i;
        this->nome = n;
    }


};

#endif
