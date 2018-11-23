#ifndef ARVOREAVL_H
#define ARVOREAVL_H

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "NoAVL.h"
#include "InformacaoDeArvoreAVL.h"

using namespace std;
template <class T>
class ArvoreAVL
{
    public:
        ArvoreAVL();

        void inserir(int, T*);
        void excluir(int);

        bool tem(int);
        T * get(int);

        void printa();

        int getQtdNos();

        template <class U>
        friend ostream& operator<< (ostream&, const ArvoreAVL<U>&);

    private:
        bool tem(NoAVL<T> *, int);
        T * get(NoAVL<T>*,int);

        void printa(NoAVL<T> *);

        NoAVL<T> * inserir(NoAVL<T> *, T*,int);
        NoAVL<T> * excluir(NoAVL<T> *, int);

        T * getMaiorInfo(NoAVL<T> *);
        T * getMenorInfo(NoAVL<T> *);


        int getMaiorChave(NoAVL<T> *);
        int getMenorChave(NoAVL<T> *);

        NoAVL<T> * rotacaoParaEsquerda(NoAVL<T> *);
        NoAVL<T> * rotacaoParaDireita(NoAVL<T> *);
        NoAVL<T> * rotacaoDuplaParaEsquerda(NoAVL<T> *);
        NoAVL<T> * rotacaoDuplaParaDireita(NoAVL<T> *);

        NoAVL<T> * balancear(NoAVL<T>*);
        void atualizaEquilibrioAltura(NoAVL<T>*);

        void desenhaArvore(NoAVL<T> *, int , char *, int,ostream& ) const;
        void desenhaArvore(ostream& ) const;

        NoAVL<T> * raiz;
        unsigned int qtdNos;
};

#include "ArvoreAVL.cpp"
#endif // ARVOREAVL_H
