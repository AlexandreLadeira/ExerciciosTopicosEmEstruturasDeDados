#ifndef ARVOREAVL_H
#define ARVOREAVL_H

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "NoAVL.h"
#include "InformacaoDeArvoreAVL.h"

using namespace std;
class ArvoreAVL
{
    public:
        ArvoreAVL();

        void inserir(InformacaoDeArvoreAVL*);
        void excluir(InformacaoDeArvoreAVL*);

        bool tem(InformacaoDeArvoreAVL *);
        InformacaoDeArvoreAVL * get(InformacaoDeArvoreAVL *);

        friend ostream& operator<< (ostream&, const ArvoreAVL&);

    private:
        bool tem(NoAVL *, InformacaoDeArvoreAVL *);
        InformacaoDeArvoreAVL * get(NoAVL*,InformacaoDeArvoreAVL *);

        NoAVL * inserir(NoAVL *, InformacaoDeArvoreAVL *);
        NoAVL * excluir(NoAVL *, InformacaoDeArvoreAVL *);

        InformacaoDeArvoreAVL * getMaiorInfo(NoAVL *);
        InformacaoDeArvoreAVL * getMenorInfo(NoAVL *);

        NoAVL * rotacaoParaEsquerda(NoAVL *);
        NoAVL * rotacaoParaDireita(NoAVL *);
        NoAVL * rotacaoDuplaParaEsquerda(NoAVL *);
        NoAVL * rotacaoDuplaParaDireita(NoAVL *);

        NoAVL * balancear(NoAVL*);
        void atualizaEquilibrioAltura(NoAVL*);

        void desenhaArvore(NoAVL *, int , char *, int,ostream& ) const;
        void desenhaArvore(ostream& ) const;

        NoAVL * raiz;
        unsigned int qtdNos;
};

#endif // ARVOREAVL_H
