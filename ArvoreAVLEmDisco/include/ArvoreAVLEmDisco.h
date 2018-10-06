#ifndef ARVOREAVLEMDISCO_H
#define ARVOREAVLEMDISCO_H

#include <fstream>
#include <iostream>

#include "Aluno.h"
#include "No.h"
#include "Indice.h"

using namespace std;

class ArvoreAVLEmDisco
{
    public:
        ArvoreAVLEmDisco(const char*,const char*);
        void inserir(Aluno);
        void excluir(Aluno);

        int procuraNaLista(int);

        bool tem(Aluno);

    protected:

    private:
        const char* caminhoArvore;
        const char* caminhoLista;
        Indice raiz;
        Indice i;




};

#endif // ARVOREAVLEMDISCO_H
