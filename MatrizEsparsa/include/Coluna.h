#ifndef COLUNA_H
#define COLUNA_H

#include "ArvoreAVL.h"

template <class T>
class Coluna
{
    public:
        Coluna(unsigned int, T);

        unsigned int getIndice();
        T getInformacao();


        int compareTo(T*);
        const char* toString();

    protected:

    private:
        unsigned int indice;
        T* informacao;
};
#include "Coluna.cpp"

#endif // COLUNA_H
