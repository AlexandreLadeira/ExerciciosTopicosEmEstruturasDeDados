#ifndef NoAVL_H
#define NoAVL_H

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include "InformacaodeArvoreAVL.h"

using namespace std;

class NoAVL
{
    public:
        NoAVL(InformacaoDeArvoreAVL * );

        NoAVL * getDireita();
        NoAVL * getEsquerda();
        int getEquilibrio();
        int getAltura();
        InformacaoDeArvoreAVL * getInfo();

        void setDireita(NoAVL *);
        void setEsquerda(NoAVL *);
        void setEqulibrio(int);
        void setAltura(int);
        void setInfo(InformacaoDeArvoreAVL *);

    private:
        NoAVL * direita;
        NoAVL * esquerda;
        int equilibrio;
        int altura;
        InformacaoDeArvoreAVL * info;
};

#endif // NoAVL_H
