#ifndef MINHAINFORMACAO_H
#define MINHAINFORMACAO_H

#include <InformacaoDeArvoreAVL.h>
#include <iostream>
#include <sstream>
#include <string.h>


class MinhaInformacao : public InformacaoDeArvoreAVL
{
    public:
        MinhaInformacao(int);

        int getNumero();
        void setNumero(int);

        int compareTo(InformacaoDeArvoreAVL*);
        const char* toString();


    private:
        int meuNumero;
};

#endif // MINHAINFORMACAO_H
