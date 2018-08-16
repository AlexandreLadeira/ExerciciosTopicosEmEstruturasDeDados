#ifndef ARVORENARIA_H
#define ARVORENARIA_H

#include <iostream>

#include "NoDeArvoreNaria.h"
#include "InformacaoDeArvoreNaria.h"

using namespace std;
class ArvoreNaria
{
    public:
        ArvoreNaria(unsigned int) throw(char*);
        NoDeArvoreNaria* getRaiz() throw();
        void guarde(InformacaoDeArvoreNaria*, NoDeArvoreNaria*) throw (char*);
        void printaArvore(NoDeArvoreNaria*) throw();

        friend ostream& operator<< (ostream&, const ArvoreNaria&);
    private:
        NoDeArvoreNaria* raiz;
        unsigned int n;
};

#endif // ARVORENARIA_H
