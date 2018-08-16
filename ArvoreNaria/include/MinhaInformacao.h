#ifndef MINHAINFORMACAO_H
#define MINHAINFORMACAO_H

#include <InformacaoDeArvoreNaria.h>
#include <iostream>
#include <sstream>
#include <string.h>

class MinhaInformacao : public InformacaoDeArvoreNaria
{
    public:
        MinhaInformacao(int) throw();

        int getNumero() throw();
        void setNumero(int) throw();

        int compareTo(InformacaoDeArvoreNaria*) throw(char*) ;
        const char* toString() throw();
        void printar();


    private:
        int meuNumero;
};

#endif // MINHAINFORMACAO_H
