#ifndef LINHA_H
#define LINHA_H

#include <iostream>
#include <stdexcept>
#include <stdlib.h>

#include "ArvoreAVL.h"
#include "Coluna.h"


using namespace std;

class Linha : public InformacaoDeArvoreAVL
{
    public:
        Linha(unsigned int valor);

        unsigned int getValor();
        Coluna * getColuna(unsigned int);

        bool insereColuna(unsigned int,InformacaoDeArvoreAVL*);
        bool excluiColuna(unsigned int);
        bool temColuna(int c);

        int compareTo(InformacaoDeArvoreAVL*);
        const char* toString();

    protected:

    private:
        unsigned int valor;
        ArvoreAVL colunas;


};

#endif // LINHA_H
