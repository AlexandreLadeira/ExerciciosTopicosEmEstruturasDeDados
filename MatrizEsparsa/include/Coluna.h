#ifndef COLUNA_H
#define COLUNA_H

#include "ArvoreAVL.h"
#include "Info.h"

class Coluna : public InformacaoDeArvoreAVL
{
    public:
        Coluna(unsigned int, InformacaoDeArvoreAVL *);

        unsigned int getValor();
        InformacaoDeArvoreAVL * getInformacao();


        int compareTo(InformacaoDeArvoreAVL*);
        const char* toString();

    protected:

    private:
        unsigned int valor;
        InformacaoDeArvoreAVL * informacao;
};

#endif // COLUNA_H
