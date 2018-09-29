#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H
#include "ArvoreAVL.h"
#include "Info.h"
#include "Linha.h"
#include "Coluna.h"


class MatrizEsparsa
{
    public:
        MatrizEsparsa(InformacaoDeArvoreAVL*);

        InformacaoDeArvoreAVL* get(unsigned int,unsigned int);
        bool  put(unsigned int,unsigned int,InformacaoDeArvoreAVL*);

    protected:

    private:
        ArvoreAVL linhas;
        InformacaoDeArvoreAVL * padrao;

};

#endif // MATRIZESPARSA_H
