#ifndef NoAVL_H
#define NoAVL_H

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include "InformacaodeArvoreAVL.h"

using namespace std;
template <class T>
class NoAVL
{
    public:
        NoAVL(int,T *);

        NoAVL<T> * getDireita();
        NoAVL<T> * getEsquerda();
        int getEquilibrio();
        int getAltura();
        T * getInfo();
        int getChave();

        void setDireita(NoAVL *);
        void setEsquerda(NoAVL *);
        void setEqulibrio(int);
        void setAltura(int);
        void setInfo(T *);
        void setChave(int);

    private:
        NoAVL<T> * direita;
        NoAVL<T> * esquerda;
        int equilibrio;
        int altura;
        T * info;
        int chave;
};

#include "NoAVL.cpp"
#endif // NoAVL_H
