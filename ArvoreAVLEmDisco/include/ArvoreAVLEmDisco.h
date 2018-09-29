#ifndef ARVOREAVLEMDISCO_H
#define ARVOREAVLEMDISCO_H

#include "Aluno.h"
#include "No.h"

using namespace std;

class ArvoreAVLEmDisco
{
    public:
        ArvoreAVLEmDisco(const char*,const char*);
        virtual ~ArvoreAVLEmDisco();
        void inserir(Aluno);
        void excluir(Aluno);

    protected:

    private:
        const char* caminhoArvore;
        const char* caminhoLista;

};

#endif // ARVOREAVLEMDISCO_H
