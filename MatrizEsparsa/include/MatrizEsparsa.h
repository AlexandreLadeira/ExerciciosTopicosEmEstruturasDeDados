#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H
#include "ArvoreAVL.h"
#include "Linha.h"
#include "Coluna.h"

template <class T>

class MatrizEsparsa
{
    public:
        MatrizEsparsa(T);

        T get(unsigned int,unsigned int);
        void  put( int, int,T);

    protected:

    private:
        ArvoreAVL<Linha<T> >* linhas;
        T  padrao;

};

#include "MatrizEsparsa.cpp"

#endif // MATRIZESPARSA_H
