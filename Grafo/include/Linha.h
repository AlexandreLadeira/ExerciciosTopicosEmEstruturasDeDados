#ifndef LINHA_H
#define LINHA_H

#include <iostream>
#include <stdexcept>
#include <stdlib.h>

#include "ArvoreAVL.h"
#include "Coluna.h"


using namespace std;
template <class T>

class Linha
{
    public:
        Linha(unsigned int);

        unsigned int getIndice();
        Coluna<T> * getColuna(unsigned int);
        ArvoreAVL<T> * getColunas();

        bool insereColuna(unsigned int,T);
        bool excluiColuna(unsigned int);
        bool temColuna(int c);



    protected:

    private:
        unsigned int indice;
        ArvoreAVL<T>* colunas;


};

#include "Linha.cpp"
#endif // LINHA_H
