#ifndef MINHAINFORMACAO_H
#define MINHAINFORMACAO_H

#include <InformacaoDeArvoreNaria.h>
#include <iostream>
#include <sstream>
#include <string.h>

class MinhaInformacao : public InformacaoDeArvoreNaria
{
    public:
        MinhaInformacao(int);

        int getNumero();
        void setNumero(int);

        int compareTo(InformacaoDeArvoreNaria*);
        const char* toString();
        void printar();


    private:
        int meuNumero;
};

#endif // MINHAINFORMACAO_H
