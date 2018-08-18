#ifndef NODEARVORENARIA_H
#define NODEARVORENARIA_H

#include <InformacaoDeArvoreNaria.h>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>

using namespace std;

class NoDeArvoreNaria
{
    public:
        NoDeArvoreNaria(unsigned int);

        InformacaoDeArvoreNaria* getInfo(unsigned i) const;
        NoDeArvoreNaria* getPtr(unsigned i);
        unsigned int getQtdNos();
        unsigned int getQtdInfos();

        int haEspaco();
        int ehFolha();

        int procuraInformacao(InformacaoDeArvoreNaria*);

        void inserirInformacao(InformacaoDeArvoreNaria*);
        void removerInformacaoDaPosicao(unsigned int);

        void substituirInformacao(unsigned int,unsigned int,unsigned int);
        bool escolherUmLado(unsigned int);

        void guarde(InformacaoDeArvoreNaria*);

        void exclua(InformacaoDeArvoreNaria *);

        void montaOsArvore(ostream&);
        friend ostream& operator<<(ostream& os, const NoDeArvoreNaria& no);

    private:
        InformacaoDeArvoreNaria ** vetInfo;
        NoDeArvoreNaria ** vetPtr;
        unsigned int n;
        unsigned int qtdInfos;
        unsigned int qtdNos;

};

#endif // NODEARVORENARIA_H
