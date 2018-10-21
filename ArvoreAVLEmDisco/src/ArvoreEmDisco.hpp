#ifndef ARVOREEMDISCO_HPP
#define ARVOREEMDISCO_HPP

#include <iostream>
#include <stdlib.h>
#include "No.hpp"

using namespace std;

template <class T>
class ArvoreEmDisco
{
    public:
       ArvoreEmDisco(string, string, T);
       ~ArvoreEmDisco();

       void inserir(T);
       void excluir(T);

       T get(T);

       void print(ostream&);

    private:
        fstream arquivoTabela;
        fstream arquivoArvore;

        const char* nomeTabela;
        const char* nomeArvore;
        T* valorPadrao;

        int calcularEqulibrio(int);
        int calcularAltura(int);

        void rotacaoParaEsquerda(int);
        void rotacaoParaDireita(int);

        void balancear(int);

        void lerNo(No&,int);
        void escreverNo(No&,int);
        void lerDado(T&,int);
        void escreverDado(T&,int);

        void arrumarIndices(int,int);

        void removerBytes(fstream&,const char*, int,int);



};

#include "ArvoreEmDisco.inl"

#endif // ARVOREAVLEMDISCO_HPP
