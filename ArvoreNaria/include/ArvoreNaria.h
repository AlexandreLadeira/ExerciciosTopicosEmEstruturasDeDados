#ifndef ARVORENARIA_H
#define ARVORENARIA_H

#include <iostream>
#include <stdexcept>

#include "NoDeArvoreNaria.h"
#include "InformacaoDeArvoreNaria.h"

using namespace std;
class ArvoreNaria
{
    public:
        ArvoreNaria(unsigned int);
        NoDeArvoreNaria* getRaiz();

        void guarde(InformacaoDeArvoreNaria*);

        void exclua(InformacaoDeArvoreNaria*);

        friend ostream& operator<< (ostream&, const ArvoreNaria&);
    private:
        NoDeArvoreNaria* raiz;
        unsigned int n;
};

#endif // ARVORENARIA_H
