#ifndef NODEARVORENARIA_H
#define NODEARVORENARIA_H

#include <InformacaoDeArvoreNaria.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class NoDeArvoreNaria
{
    public:
        NoDeArvoreNaria(unsigned int) throw();

        InformacaoDeArvoreNaria* getInfo(unsigned i) throw (char*);
        NoDeArvoreNaria* getPtr(unsigned i) throw (char*);
        unsigned int getQtdNos() throw();

        int haEspaco() throw();
        int procuraInformacao(InformacaoDeArvoreNaria*) throw (char*);

        void inserirInformacao(InformacaoDeArvoreNaria*) throw(char*);
        void criaNoNaPosicao(unsigned int);

        void printaInfos() throw();
        friend ostream& operator<<(ostream& os, const NoDeArvoreNaria& no);

    private:
        InformacaoDeArvoreNaria ** vetInfo;
        NoDeArvoreNaria ** vetPtr;
        unsigned int n;
        int qtdInfos;
        unsigned int qtdNos;

};

#endif // NODEARVORENARIA_H
